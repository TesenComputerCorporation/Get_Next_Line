/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:23:32 by jjerde            #+#    #+#             */
/*   Updated: 2019/03/30 18:56:26 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	if (!content || !content_size)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		if (!(result->content = malloc(sizeof(content_size))))
		{
			ft_lstdel((t_list **)content, &ft_clearone);
			return (NULL);
		}
		result->content = ft_memcpy((result->content), content, content_size);
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
