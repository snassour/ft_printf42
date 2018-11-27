/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:37:21 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:37:26 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_fill(char *s, char c, int len)
{
	int i;

	i = -1;
	if (len > 0)
		while (++i < len)
			s[i] = c;
}