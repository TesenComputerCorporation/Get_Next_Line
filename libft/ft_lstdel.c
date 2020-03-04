/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:13:05 by jjerde            #+#    #+#             */
/*   Updated: 2019/04/19 18:00:16 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (del != NULL && *alst != NULL)
	{
		while ((*alst) != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			nxt = (*alst)->next;
			free(*alst);
			*alst = nxt;
		}
	}
}
