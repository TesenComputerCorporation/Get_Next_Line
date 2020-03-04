/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:54:15 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/05 19:15:33 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;
	unsigned char	cc;

	i = 0;
	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	cc = (unsigned char)c;
	while (i < len)
	{
		dst[i] = src[i];
		if (dst[i] == cc)
			return ((void *)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
