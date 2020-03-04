/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:57:36 by jjerde            #+#    #+#             */
/*   Updated: 2019/04/15 16:28:10 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	i;
	char	*one;
	char	*two;

	i = -1;
	if (!dest && !source)
		return (NULL);
	one = (char *)dest;
	two = (char *)source;
	if (one < two)
	{
		while (++i < n)
			one[i] = two[i];
	}
	else
	{
		while (n > 0)
		{
			n--;
			one[n] = two[n];
		}
	}
	return (dest);
}
