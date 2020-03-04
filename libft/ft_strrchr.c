/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:25:06 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/01 18:38:26 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i == 0)
				r = -1;
			else
				r = i;
		}
		i++;
	}
	if (c == s[i])
		return ((char *)&s[i]);
	if (r == 0)
		return (NULL);
	else if (r == -1)
		r = 0;
	return ((char *)&s[r]);
}
