/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:49:31 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:49:36 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_ulltoa_base(unsigned long long nb, int base, t_conv *cv)
{
	char				tab[17];
	char				*str;
	int					len;
	unsigned long long	tmp;

	ft_strncpy(tab, "0123456789abcdef", 16);
	tab[16] = 0;
	len = (nb == 0 ? 1 : 0);
	tmp = nb;
	cv->null = (nb == 0 ? 1 : 0);
	while (tmp)
		tmp /= base + 0 * ++len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	cv->len_cv = len;
	while (len--)
	{
		str[len] = tab[nb % base];
		nb /= base;
	}
	return (str);
}

char	*ft_ulltoa(unsigned long long nb, t_conv *cv)
{
	return (ft_ulltoa_base(nb, 10, cv));
}
