/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:45:14 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/05 17:20:40 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	cc;

	i = 0;
	ch = (unsigned char *)b;
	cc = (unsigned char)c;
	while (i < len)
	{
		if (ch[i] == cc)
			return ((void *)&b[i]);
		i++;
	}
	return (NULL);
}
