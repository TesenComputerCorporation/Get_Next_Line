/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:41:42 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/01 19:15:14 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)&str[0]);
	while (str[i] != '\0' && size > i)
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && str[i + j] && to_find[j] &&
					i + j <= size)
				j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}
