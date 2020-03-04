/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:26:08 by jjerde            #+#    #+#             */
/*   Updated: 2019/02/18 13:08:18 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int			i;
	int			s;
	long int	result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (result != (result * 10 + str[i] - 48) / 10)
		{
			s = s < 0 ? 0 : -1;
			return (s);
		}
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result *= s);
}
