/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:38:30 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:38:34 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_atoi(const char *str)
{
	int		out;
	int		i;
	int		negative;

	i = 0;
	out = 0;
	negative = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
					str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		negative = i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
		out = out * 10 + (str[i++] - '0');
	if (str[negative] == '-')
		out = -out;
	return (out);
}
