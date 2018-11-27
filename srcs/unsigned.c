/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:23:19 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:23:24 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		uoctal(t_printf *p, t_conv *cv)
{
	char	*s;

	s = udecider(p, cv, 8);
	oct_fl(p, s, cv);
	ft_strdel(&s);
	return (p->len);
}

int		uloctal(t_printf *p, t_conv *cv)
{
	unsigned long	nb;
	char			*s;

	nb = va_arg(p->ap, unsigned long);
	s = ft_ulltoa_base(nb, 8, cv);
	oct_fl(p, s, cv);
	ft_strdel(&s);
	return (p->len);
}

int		uinteger(t_printf *p, t_conv *cv)
{
	char	*s;

	s = udecider(p, cv, 10);
	udec_fl(p, s, cv);
	ft_strdel(&s);
	return (p->len);
}

int		ulinteger(t_printf *p, t_conv *cv)
{
	unsigned long	nb;
	char			*s;

	nb = va_arg(p->ap, unsigned long);
	if (nb == 0)
		cv->null = 1;
	s = ft_ulltoa_base(nb, 10, cv);
	udec_fl(p, s, cv);
	ft_strdel(&s);
	return (p->len);
}

int		uhex(t_printf *p, t_conv *cv)
{
	char	*s;

	s = udecider(p, cv, 16);
	hex_fl(p, s, cv);
	ft_strdel(&s);
	return (p->len);
}
