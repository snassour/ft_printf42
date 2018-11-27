/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:47:54 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:47:57 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char		*ft_lltoa(long long nb, t_conv *cv)
{
	char		*str;
	int			len;
	long long	tmp;

	len = (nb <= 0 ? 1 : 0);
	tmp = nb;
	while (tmp)
		tmp /= 10 + 0 * ++len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	cv->len_cv = len;
	tmp = nb;
	while (nb)
	{
		if (len - 1 >= 0)
			str[--len] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	str[0] = (tmp < 0 ? '-' : str[0]);
	str[0] = (tmp == 0 ? '0' : str[0]);
	return (str);
}
