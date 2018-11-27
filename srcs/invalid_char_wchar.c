/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_char_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:23:38 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:23:48 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		invalid(t_printf *p, t_conv *cv)
{
	cv->conv = NBCV;
	p->len = -1;
	p->error = -1;
	return (-1);
}

void	addchar(t_printf *p, wint_t c, t_conv *cv)
{
	char	*new;
	char	*tmp;
	int		len;

	len = wintlen(c);
	if (len == -1)
	{
		p->error = -1;
		p->real_size = p->prev_conv;
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		tmp[len] = '\0';
		wintcpy(c, tmp, 0);
		new = str_fl(p, tmp, cv, len);
		if (p->len > 0)
			ft_printf_extend(p, new, p->len);
		ft_strdel(&tmp);
		ft_strdel(&new);
	}
}

int		wcharacter(t_printf *p, t_conv *cv)
{
	wint_t	c;

	c = (wint_t)va_arg(p->ap, wint_t);
	if (c < 0)
	{
		p->error = -1;
		return (-1);
	}
	addchar(p, c, cv);
	return (p->len);
}

int		character(t_printf *p, t_conv *cv)
{
	wint_t	c;
	char	bis;

	c = (wint_t)va_arg(p->ap, wint_t);
	bis = (char)c;
	addchar(p, cv->modif == ML ? c : (wint_t)bis, cv);
	return (p->len);
}

int		percent(t_printf *p, t_conv *cv)
{
	addchar(p, (wint_t)'%', cv);
	return (p->len);
}
