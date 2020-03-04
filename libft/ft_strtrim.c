/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:42:42 by jjerde            #+#    #+#             */
/*   Updated: 2019/03/10 15:35:50 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	int				k;
	char			*str;
	int				len;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	len -= i;
	if (len < 0)
		len = 0;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	k = -1;
	while (++k < len)
		str[k] = s[i++];
	str[k] = '\0';
	return (str);
}
