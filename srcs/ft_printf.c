/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:25:06 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:25:08 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		parse(t_printf *p, char *s, t_pconv tab[NBCV + 1])
{
	int		len;
	int		i;
	int		j;
	int		check;

	j = -1;
	i = 0;
	check = 0;
	while (s[++j] && p->error == 0)
		if (s[j] == '%')
		{
			check = 0;
			p->prev_conv = p->real_size;
			ft_printf_extend(p, s + i, j - i);
			len = 1;
			while ((check = check_characters(s[j + len], p->all, check)) > 0)
				++len;
			if (check != 0)
				break ;
			addconv(s + j + 1, p, len - 1, tab);
			i = j + len + 1;
			j = i - 1;
		}
	p->error = (check == -1 ? -1 : p->error);
	(s[j] == '\0' ? ft_printf_extend(p, s + i, j - i) : NULL);
}

void		destroy_printf(t_printf *p)
{
	t_strs *a;

	a = p->all;
	ft_strdel(&p->tmp);
	ft_strdel(&(p->str));
	ft_strdel(&a->fl);
	ft_strdel(&a->cnv);
	ft_strdel(&a->prc);
	ft_strdel(&a->mdf);
	free(a);
	free(p);
}

void		init_tab(t_pconv tab[NBCV + 1])
{
	tab[0] = percent;
	tab[1] = string;
	tab[2] = wstring;
	tab[3] = pointer;
	tab[4] = integer;
	tab[5] = linteger;
	tab[6] = integer;
	tab[7] = uoctal;
	tab[8] = uloctal;
	tab[9] = uinteger;
	tab[10] = ulinteger;
	tab[11] = uhex;
	tab[12] = uhex;
	tab[13] = character;
	tab[14] = wcharacter;
	tab[15] = invalid;
}

t_printf	*init_p(void)
{
	t_printf	*p;
	t_strs		*all;

	p = (t_printf *)malloc(sizeof(t_printf));
	if (!p)
		return (NULL);
	p->str = ft_strdup("");
	p->tmp = ft_strdup("");
	if (!p->str)
		return (NULL);
	all = (t_strs *)malloc(sizeof(t_strs));
	init_strs(all);
	p->all = all;
	if (!p->all)
		return (NULL);
	p->real_size = 0;
	p->total_size = 0;
	p->error = 0;
	return (p);
}

int			ft_printf(const char *format, ...)
{
	char		*tmp;
	t_printf	*p;
	int			l;
	t_pconv		tab[NBCV + 1];

	if (!format || !*format)
		return (0);
	p = init_p();
	if (p == NULL)
		return (0);
	va_start(p->ap, format);
	tmp = (char *)format;
	init_tab(tab);
	parse(p, tmp, tab);
	va_end(p->ap);
	l = -1;
	if (p->str && p->error == 0)
		l = write(1, p->str, p->real_size);
	else if (p->str && p->error == -1)
		l = (write(1, p->str, p->prev_conv) * 0) - 1;
	destroy_printf(p);
	return (l);
}
