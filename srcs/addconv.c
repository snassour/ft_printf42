/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:37:51 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:45:59 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		get_conv(char *s, t_printf *p, int i)
{
	int pos;

	pos = 0;
	while (p->all->cnv[pos] != s[i] && pos < NBCV)
		++pos;
	return (pos);
}

int		get_flags(t_conv *cv, char *s, t_printf *p, int len)
{
	int	i;

	conv_cv(cv);
	i = 0;
	while (i < len && ft_strchr(p->all->fl, s[i]))
	{
		if (s[i] == '0')
			cv->zero = 1 + (++i * 0);
		else if (s[i] == '#')
			cv->htag = 1 + (++i * 0);
		else if (s[i] == '+')
			cv->plus = 1 + (++i * 0);
		else if (s[i] == ' ')
			cv->sp = 1 + (++i * 0);
		else if (s[i] == '-')
			cv->left = 1 + (++i * 0);
		else
			return (-1);
	}
	return (i);
}

int		get_widths(t_conv *cv, char *s, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	cv->minw = 0;
	cv->prec = -1;
	while (i < len && ft_isdigit(s[i]))
		++i;
	tmp = (i > 0 ? ft_strdup_len(s, i) : NULL);
	cv->minw = (tmp && ft_isnum(tmp, &j) ? ft_atoi(tmp) : 0);
	ft_strdel(&tmp);
	if (s[i] == '.' && j >= 0)
	{
		j = ++i;
		cv->prec = 0;
		while (i < len && ft_isdigit(s[i]))
			++i;
		tmp = (i >= 1 ? ft_strdup_len(s + j, i - j) : NULL);
		cv->prec = (tmp && ft_isnum(tmp, &j) ? ft_atoi(tmp) : 0);
		ft_strdel(&tmp);
	}
	return (j >= 0 ? i : -1);
}

int		get_modif(t_conv *cv, char *s, int len, t_printf *p)
{
	int ret;

	cv->modif = 0;
	ret = 0;
	if (len == 0)
		return (0);
	if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
	{
		if (*s == 'h')
			cv->modif = (*(s + 1) == 'h' ? MHH : MH);
		else if (*s == 'l')
			cv->modif = (*(s + 1) == 'l' ? MLL : ML);
		else if (*s == 'j')
			cv->modif = MJ;
		else if (*s == 'z')
			cv->modif = MZ;
		else if (!ft_strchr(p->all->cnv, *s))
			ret = -1;
	}
	return (ret);
}

void	addconv(char *s, t_printf *p, int i, t_pconv tab[NBCV + 1])
{
	t_conv	cv;
	int		pos;
	int		check;
	int		tmp;

	cv.conv = get_conv(s, p, i);
	check = 0;
	pos = 0;
	tmp = 0;
	if (cv.conv == NBCV)
		check = tab[NBCV](p, &cv);
	if (!check && (pos = get_flags(&cv, s, p, i)) < 0)
		check = tab[NBCV](p, &cv);
	tmp = pos;
	if (!check && (pos = get_widths(&cv, s + pos, i)) < 0)
		check = tab[NBCV](p, &cv);
	pos += (pos < 0 ? 0 : tmp);
	if (!check && (pos = get_modif(&cv, s + pos, i, p)) < 0)
		check = tab[NBCV](p, &cv);
	if (check == 0)
		check = tab[cv.conv](p, &cv);
}
