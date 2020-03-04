/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:57:04 by jjerde            #+#    #+#             */
/*   Updated: 2019/04/29 18:13:25 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	*ft_linedelone(t_line *start, t_line *todel)
{
	t_line	*tmp;

	if (!start || !todel)
		return (NULL);
	tmp = todel;
	todel = start;
	while (todel->next && todel->next != tmp)
		todel = todel->next;
	if (todel->next == NULL)
		return (NULL);
	todel->next = tmp->next;
	if (tmp->line)
		free(tmp->line);
	ft_memdel((void **)&tmp);
	tmp = NULL;
	return (todel);
}
