/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:50:53 by jjerde            #+#    #+#             */
/*   Updated: 2019/03/30 18:56:25 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	new = f(lst);
	start = new;
	if (lst != NULL && f != NULL)
	{
		while (lst->next)
		{
			lst = lst->next;
			if (!(new->next = f(lst)))
			{
				ft_lstdel(&start, &ft_clearone);
				return (NULL);
			}
			new = new->next;
		}
	}
	return (start);
}
