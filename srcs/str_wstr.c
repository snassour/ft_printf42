/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:16:17 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:17:36 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		wstringlen(wchar_t *src, t_conv *cv)
{
	int		len;
	int		i;
	int		j;
	int		last_char;
	wint_t	a;

	len = 0;
	i = -1;
	j = 0;
	last_char = 0;
	while ((a = (wint_t)src[++i]) && len != -1)
	{
		j = wintlen(a);
		if (j == -1 && cv->prec > -1 && cv->prec == len)
			return (len);
		len = (j == -1 ? j : j + len);
		if (len != -1 && cv->prec > 0 && cv->prec >= len)
			last_char = len;
	}
	if (cv->prec == -1 && len > 0)
		last_char = len;
	return (len == -1 ? len : last_char);
}

char	*conv_wstring(wchar_t *src, int *len, t_conv *cv)
{
	char	*new;
	int		i;
	int		j;
	int		c;

	*len = wstringlen(src, cv);
	if (*len == -1)
		return (NULL);
	new = (char	*)malloc((*len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = -1;
	while (i < *len && ++j < *len && i > -1)
	{
		c = wintcpy((wint_t)src[j], new, i);
		i = (c > -1 ? i + c : -1);
	}
	if (i == -1)
		return (NULL);
	return (new);
}

int		wstring(t_printf *p, t_conv *cv)
{
	char	*s;
	wchar_t	*tmp;
	char	*new;
	int		len;

	len = 0;
	tmp = (wchar_t *)va_arg(p->ap, wchar_t *);
	len = (!(char *)tmp ? 6 : len);
	new = (!(char *)tmp ? ft_strdup("(null)") : conv_wstring(tmp, &len, cv));
	if (len == -1)
	{
		p->error = -1;
		return (-1);
	}
	s = str_fl(p, new, cv, len);
	if (p->len > 0)
		ft_printf_extend(p, s, p->len);
	ft_strdel(&s);
	ft_strdel(&new);
	return (p->len);
}

int		get_string(t_printf *p, t_conv *cv)
{
	char	*s;
	char	*tmp;
	int		len;
	int		null;

	tmp = (char *)va_arg(p->ap, char *);
	null = 0;
	if (!tmp)
		tmp = ft_strdup("(null)") + (++null * 0);
	len = ft_strlen(tmp);
	s = str_fl(p, tmp, cv, len);
	if (p->len > 0)
		ft_printf_extend(p, s, p->len);
	ft_strdel(&s);
	if (null == 1)
		ft_strdel(&tmp);
	return (p->len);
}

int		string(t_printf *p, t_conv *cv)
{
	int i;

	i = (cv->modif == ML ? wstring(p, cv) : get_string(p, cv));
	return (p->len);
}
