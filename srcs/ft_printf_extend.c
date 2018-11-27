/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:47:06 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:47:09 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_printf_extend(t_printf *p, char *s, int len)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	new = p->str + p->real_size;
	if (p->total_size <= p->real_size + len - 1)
	{
		while (p->total_size <= (p->real_size + len - 1))
			p->total_size += 100;
		new = ft_strnew(p->total_size);
		if (p->real_size > 0)
			ft_strncpy(new, p->str, p->real_size);
		i = p->real_size - 1;
		free(p->str);
		p->str = new;
	}
	j = -1;
	while (++j < len)
		new[++i] = s[j];
	p->real_size += len;
	return (new);
}
