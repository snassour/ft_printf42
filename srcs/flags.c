/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:24:30 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:24:33 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*str_fl(t_printf *p, char *s, t_conv *cv, int l)
{
	char	*new;
	char	*t;
	char	*r;

	if (!s)
		return (ft_strdup(""));
	if ((cv->conv == 1 || cv->conv == 2) && cv->prec >= 0 && cv->prec < l)
		l = cv->prec;
	new = ft_strdup_len(s, l);
	t = ft_strnew(cv->minw);
	if (cv->minw > l)
	{
		cv->zero = (cv->left ? 0 : cv->zero);
		ft_fill(t, cv->zero ? '0' : ' ', cv->minw);
		r = (cv->left ? ft_strncpy(t, new, l) : ft_strnrevcpy(t, new, l));
	}
	r = (cv->minw > l ? ft_strdup_len(r, cv->minw) : ft_strdup_len(new, l));
	ft_strdel(&new);
	ft_strdel(&t);
	p->len = (cv->minw > l ? cv->minw : l);
	return (r);
}

int		handle_zero_unsigned(t_conv *cv)
{
	if (cv->conv == 7 || cv->conv == 8)
	{
		if (cv->htag && cv->prec > -1)
			return (cv->prec == 0 ? 1 : cv->prec);
		if (cv->prec > -1)
			return (cv->prec);
		if (cv->zero && cv->minw)
			return (cv->htag >= cv->minw ? cv->htag : cv->minw);
		return (1);
	}
	if (cv->conv == 9 || cv->conv == 10)
	{
		cv->htag = 0;
		cv->zero = (cv->prec > -1 ? 0 : cv->zero);
		if (cv->prec > -1)
			return (cv->prec);
		if (cv->zero && cv->minw)
			return (cv->minw);
		return (1);
	}
	return (1);
}

int		unsigned_len(t_conv *cv, char *s)
{
	int len;

	len = ft_strlen(s);
	if (cv->null == 1)
		len = handle_zero_unsigned(cv);
	else if (cv->prec > -1)
		len = (len >= cv->prec ? len + cv->htag : cv->prec);
	else
	{
		len += cv->htag;
		if (cv->zero && cv->minw)
			len = (len >= cv->minw ? len : cv->minw);
	}
	return (len);
}

void	oct_fl(t_printf *p, char *s, t_conv *cv)
{
	char	*new;
	int		len;
	char	*tmp;

	if (!s)
		return ;
	cv->zero = (cv->left ? 0 : cv->zero);
	len = unsigned_len(cv, s);
	tmp = ft_strnew(len);
	ft_fill(tmp, '0', len);
	ft_strrevcpy(tmp, s);
	if (cv->minw > len)
	{
		new = ft_strnew(cv->minw);
		ft_fill(new, ' ', cv->minw);
		cv->left ? ft_strncpy(new, tmp, len) : ft_strrevcpy(new, tmp);
	}
	else
		new = ft_strdup_len(tmp, len);
	ft_printf_extend(p, new, cv->minw > len ? cv->minw : len);
	ft_strdel(&tmp);
	ft_strdel(&new);
}

void	udec_fl(t_printf *p, char *s, t_conv *cv)
{
	char	*new;
	int		len;
	char	*tmp;

	if (!s)
		return ;
	cv->htag = 0;
	cv->zero = (cv->left ? 0 : cv->zero);
	if (cv->null == 1 && cv->prec == 0)
		s[0] = '\0';
	len = unsigned_len(cv, s);
	tmp = ft_strnew(len);
	ft_fill(tmp, '0', len);
	ft_strrevcpy(tmp, s);
	new = (cv->minw > len ? ft_strnew(cv->minw) : ft_strdup_len(tmp, len));
	cv->minw > len ? ft_fill(new, ' ', cv->minw) : NULL;
	if (cv->minw > len)
		cv->left ? ft_strncpy(new, tmp, len) : ft_strrevcpy(new, tmp);
	ft_strdel(&tmp);
	ft_printf_extend(p, new, cv->minw > len ? cv->minw : len);
	ft_strdel(&new);
}
