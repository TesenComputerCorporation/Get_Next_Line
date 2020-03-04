/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:35:17 by jjerde            #+#    #+#             */
/*   Updated: 2019/04/28 19:20:20 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char const *s1, char const *s2)
{
	int		i;
	int		ii;
	char	*ss;

	if (!s1 || !s2)
		return (NULL);
	if (!(ss = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii])
	{
		ss[i + ii] = s2[ii];
		ii++;
	}
	free((void *)s1);
	ss[i + ii] = '\0';
	return (ss);
}
