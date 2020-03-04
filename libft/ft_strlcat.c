/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 23:03:31 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/14 21:17:08 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	s1;
	size_t	s2;

	s1 = ft_strlen(dest);
	s2 = ft_strlen(src);
	if (size == 0)
		return (s2);
	if (s1 > size - 1)
		return (s2 + size);
	i = s1;
	j = 0;
	while ((i + j < size - 1) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (s1 + s2);
}
