/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:50:10 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/18 17:04:03 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char			*one;
	char			*two;

	if (dest == source)
		return (dest);
	one = (char *)dest;
	two = (char *)source;
	while (n--)
		*one++ = *two++;
	return (dest);
}
