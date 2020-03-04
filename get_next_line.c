/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:08:31 by jjerde            #+#    #+#             */
/*   Updated: 2019/04/29 18:12:08 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	clear(void *content, int flag)
{
	if (content)
	{
		free(content);
		return (flag);
	}
	return (-1);
}

int	read_file(const int fd, t_line *data)
{
	char			*buff;
	int				bites;

	if (!(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while ((bites = read(fd, buff, BUFF_SIZE)))
	{
		if (bites == -1)
			return (clear((void *)buff, -1));
		buff[bites] = '\0';
		if (data->line == NULL || (ft_strlen(data->line) == 1 &&
				data->line[0] == '\n'))
		{
			ft_memdel((void **)&data->line);
			if (!(data->line = ft_memalloc(sizeof(char))))
				return (clear((void *)buff, -1));
		}
		if (!(data->line = ft_strrejoin(data->line, buff)))
			return (clear((void *)buff, -1));
		if (ft_strchr(data->line, 10))
			return (clear((void *)buff, bites));
	}
	return (clear((void *)buff, 0));
}

int	getnextline_part2(const int fd, char **line, t_line *data, t_line *current)
{
	int				returned;
	size_t			size;
	char			*tmp;

	returned = -1;
	if (current->line == NULL || ft_strsearch(current->line, '\n') == -1)
	{
		if ((returned = read_file(fd, current)) == -1)
		{
			ft_linedelone(data, current);
			return (-1);
		}
		if (returned == 0 && (!current->line || current->line[0] == 0))
		{
			ft_linedelone(data, current);
			return (0);
		}
	}
	size = ft_strclen(current->line, '\n');
	*line = ft_strsub(current->line, 0, size);
	tmp = current->line;
	current->line = ft_strsub(current->line, size + 1, ft_strlen(current->line)
			- size);
	free(tmp);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static t_line	*data;
	t_line			*current;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!data)
	{
		if (!(data = (t_line *)ft_memalloc(sizeof(t_line))))
			return (-1);
		data->fd = fd;
	}
	current = data;
	while (current->fd != fd)
	{
		if (!(current->next))
		{
			if (!(current->next = (t_line *)ft_memalloc(sizeof(t_line))))
				return (-1);
			current->next->fd = fd;
		}
		current = current->next;
	}
	return (getnextline_part2(fd, line, data, current));
}
