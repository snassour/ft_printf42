/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:36:56 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:37:02 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		signed_len(t_conv *cv, char *s)
{
	int	len;
	int	toto;

	len = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	toto = cv->negative ? 1 : cv->sp + cv->plus;
	len += toto;
	if (cv->prec > -1)
		len = (len > cv->prec ? len : cv->prec + toto);
	else if (cv->zero && cv->minw)
		len = (len >= cv->minw ? len : cv->minw);
	return (len);
}

int		unsigned_len_hex(t_conv *cv, char *s)
{
	int len;

	len = ft_strlen(s);
	cv->htag *= 2;
	cv->zero = (cv->left ? 0 : cv->zero);
	if (s[0] == '0' && cv->conv != 3)
		cv->htag = 0;
	if (cv->prec > -1)
		len = (len >= cv->prec ? len : cv->prec) + cv->htag;
	else
	{
		len += cv->htag;
		if (cv->zero && cv->minw)
			len = (len >= cv->minw ? len : cv->minw);
	}
	if (cv->null == 1 && cv->prec == 0 && cv->conv != 3)
		len = 0;
	return (len);
}

void	hex_fl(t_printf *p, char *s, t_conv *cv)
{
	char	*new;
	int		len;
	char	*new2;

	if (!s)
		return ;
	s[0] = (cv->prec == 0 && cv->null == 1 ? '\0' : s[0]);
	len = unsigned_len_hex(cv, s);
	if (!(new2 = ft_strnew(len)))
		return ;
	new2[len] = '\0';
	ft_fill(new2, '0', len);
	if (cv->htag && (len > 2 || cv->conv == 3))
		new2[1] = 'x';
	ft_strrevcpy(new2, s);
	new = (cv->minw > len ? ft_strnew(cv->minw) : ft_strdup_len(new2, len));
	(cv->minw > len ? ft_fill(new, ' ', cv->minw) : NULL);
	if (cv->minw > len)
		cv->left ? ft_strncpy(new, new2, len) : ft_strrevcpy(new, new2);
	cv->conv == 12 ? ft_allcaps(new) : NULL;
	ft_strdel(&new2);
	ft_printf_extend(p, new, cv->minw > len ? cv->minw : len);
	ft_strdel(&new);
}

void	ptr_fl(t_printf *p, char *s, t_conv *cv)
{
	cv->htag = 1;
	hex_fl(p, s, cv);
}
