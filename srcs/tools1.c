/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:15:28 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:15:45 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_isnum(char *str, int *check)
{
	int	i;
	int	len;

	i = 0;
	*check = 0;
	if (!str)
		return (0);
	if (!*str)
		return (0);
	len = ft_strlen(str);
	while (str[i] == '0')
		++i;
	if (i != 0 && len > 1)
	{
		*check = -1;
		return (0);
	}
	return (1);
}

char	*short_char_nb(int nb, t_conv *cv)
{
	short	nb1;
	char	nb2;

	nb1 = (short)nb;
	nb2 = (char)nb;
	if (cv->modif == MH)
		return (ft_lltoa((short)nb1, cv));
	return (ft_lltoa((char)nb2, cv));
}

int		check_characters(char c, t_strs *all, int check)
{
	if (c == 0)
		return (-2);
	if (ft_strchr(all->fl, c) && check <= 1)
		return (1);
	else if (ft_strchr(all->prc, c) && check <= 2)
		return (2);
	else if (ft_strchr(all->mdf, c) && check <= 3)
		return (3);
	else if (ft_strchr(all->cnv, c))
		return (0);
	return (-1);
}

char	*hexdecider(t_printf *p, t_conv *cv, int base)
{
	char				*s;
	long long			nb;

	if (cv->modif == MLL && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((unsigned long long)nb, base, cv);
	if (cv->modif == ML && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((unsigned long)nb, base, cv);
	if (cv->modif == MH && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((unsigned short)nb, base, cv);
	if (cv->modif == MHH && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((unsigned char)nb, base, cv);
	if (cv->modif == MJ && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((uintmax_t)nb, base, cv);
	if (cv->modif == MZ && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((size_t)nb, base, cv);
	if (cv->modif == 0 && (nb = va_arg(p->ap, long long)) > 0)
		s = ft_ulltoa_base((unsigned int)nb, base, cv);
	if (nb == 0)
		s = ft_strdup("0");
	if (!s)
		p->error = -1;
	return (s);
}

char	*udecider(t_printf *p, t_conv *cv, int base)
{
	char				*s;
	unsigned long long	nb;

	if (cv->modif == MLL && (nb = va_arg(p->ap, unsigned long long)) > 0)
		s = ft_ulltoa_base(nb, base, cv);
	if (cv->modif == ML && (nb = va_arg(p->ap, unsigned long long)) > 0)
		s = ft_ulltoa_base((unsigned long)nb, base, cv);
	if (cv->modif == MH && (nb = va_arg(p->ap, unsigned int)) > 0)
		s = ft_ulltoa_base((unsigned short)nb, base, cv);
	if (cv->modif == MHH && (nb = va_arg(p->ap, unsigned int)) > 0)
		s = ft_ulltoa_base((unsigned char)nb, base, cv);
	if (cv->modif == MJ && (nb = va_arg(p->ap, uintmax_t)) > 0)
		s = ft_ulltoa_base((uintmax_t)nb, base, cv);
	if (cv->modif == MZ && (nb = va_arg(p->ap, size_t)) > 0)
		s = ft_ulltoa_base((size_t)nb, base, cv);
	if (cv->modif == 0 && (nb = va_arg(p->ap, unsigned int)) > 0)
		s = ft_ulltoa_base((unsigned int)nb, base, cv);
	if (nb == 0)
		s = ft_ulltoa_base(0, 10, cv);
	if (!s)
		p->error = -1;
	return (s);
}
