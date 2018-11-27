/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:21:36 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:21:40 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	handle_prec_negative(char *str, t_conv *cv, int mode)
{
	int	i;

	i = -1;
	if (str && mode == 0)
	{
		if (str[0] == '-')
		{
			cv->negative = 1;
			while (str[++i])
				str[i] = str[i + 1];
		}
		cv->zero = cv->prec > -1 ? 0 : cv->zero;
		cv->zero = cv->left ? 0 : cv->zero;
		cv->sp = cv->plus ? 0 : cv->sp;
		if (cv->null == 1 && cv->prec == 0 && cv->conv != 3)
			str[0] = '\0';
	}
	else if (str && mode == 1 && str[0])
	{
		str[0] = cv->sp ? ' ' : str[0];
		str[0] = cv->plus ? '+' : str[0];
		str[0] = cv->negative ? '-' : str[0];
	}
}

void	treat_int(t_printf *p, t_conv *cv)
{
	char	*new;
	int		len;
	char	*tmp;

	handle_prec_negative(p->toto, cv, 0);
	len = (p->toto ? signed_len(cv, p->toto) : 0);
	tmp = ft_strnew(len);
	ft_fill(tmp, '0', len);
	handle_prec_negative(tmp, cv, 1);
	ft_strrevcpy(tmp, p->toto);
	ft_strdel(&(p->toto));
	new = ft_strnew(cv->minw);
	if (cv->minw > len)
	{
		ft_fill(new, ' ', cv->minw);
		cv->left ? ft_strncpy(new, tmp, len) : ft_strrevcpy(new, tmp);
		ft_printf_extend(p, new, cv->minw);
	}
	else
		ft_printf_extend(p, tmp, len);
	ft_strdel(&new);
	ft_strdel(&tmp);
}

int		integer(t_printf *p, t_conv *cv)
{
	long long	nb;

	if (cv->modif == MLL && (nb = (long long)va_arg(p->ap, long long)))
		p->toto = ft_lltoa(nb, cv);
	else if (cv->modif == ML && (nb = va_arg(p->ap, long)))
		p->toto = ft_lltoa((long)nb, cv);
	else if (cv->modif == MH && (nb = va_arg(p->ap, int)))
		p->toto = short_char_nb(nb, cv);
	else if (cv->modif == MHH && (nb = va_arg(p->ap, int)))
		p->toto = short_char_nb(nb, cv);
	else if (cv->modif == MZ && (nb = va_arg(p->ap, ssize_t)))
		p->toto = ft_lltoa((ssize_t)nb, cv);
	else if (cv->modif == MJ && (nb = va_arg(p->ap, intmax_t)))
		p->toto = ft_lltoa((intmax_t)nb, cv);
	else if (cv->modif == 0 && (nb = va_arg(p->ap, int)))
		p->toto = ft_lltoa((int)nb, cv);
	cv->null = (nb == 0 ? 1 : 0);
	p->toto = (nb == 0 ? ft_lltoa(0, cv) : p->toto);
	p->error = (!p->toto ? -1 : p->error);
	cv->sp = cv->plus ? 0 : cv->sp;
	treat_int(p, cv);
	return (p->error == 0 ? 1 : -1);
}

int		linteger(t_printf *p, t_conv *cv)
{
	cv->conv = 4;
	cv->modif = ML;
	return (integer(p, cv));
}

int		pointer(t_printf *p, t_conv *cv)
{
	unsigned long	nb;
	char			*tmp;

	nb = va_arg(p->ap, unsigned long);
	tmp = ft_ulltoa_base((unsigned long)nb, 16, cv);
	ptr_fl(p, tmp, cv);
	ft_strdel(&tmp);
	return (p->error == 0 ? 1 : -1);
}
