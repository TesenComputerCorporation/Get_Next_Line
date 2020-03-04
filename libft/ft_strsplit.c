/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:31:51 by jjerde            #+#    #+#             */
/*   Updated: 2019/03/30 19:17:32 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear_array(void **array, int size)
{
	int	i;

	i = 0;
	if (!array || size < 1)
		return (NULL);
	while (i < size)
		free(array[i++]);
	free(array);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	int		k;
	char	**arr;
	int		wordlen;

	i = 0;
	k = -1;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(arr = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++k < words)
	{
		while (s[i] == c)
			i++;
		wordlen = ft_strclen(&s[i], c);
		if (!(arr[k] = ft_strnew(wordlen)))
			return (ft_clear_array((void **)arr, k));
		ft_memmove(arr[k], &s[i], wordlen);
		i += wordlen;
	}
	arr[k] = NULL;
	return (arr);
}
