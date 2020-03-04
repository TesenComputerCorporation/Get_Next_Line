/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:21:40 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/05 14:42:38 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	int		i;
	char	*one;
	int		nnum;

	i = 0;
	nnum = (int)num;
	one = (char *)memptr;
	while (i < nnum)
	{
		one[i] = val;
		i++;
	}
	return (memptr);
}
