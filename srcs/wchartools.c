/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchartools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:15:56 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:16:00 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		wintlen(wint_t c)
{
	if (c >= 0xD800 && c <= 0xDFFF)
		return (-1);
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF && MB_CUR_MAX > 1)
		return (2);
	if (c <= 0xFFFF && MB_CUR_MAX > 1)
		return (3);
	if (c <= 0x10FFFF && MB_CUR_MAX > 1)
		return (4);
	if (c <= 255 && MB_CUR_MAX == 1)
		return (1);
	return (-1);
}

int		wintcpy(wint_t c, char *src, int i)
{
	int	len;

	len = wintlen(c);
	src[0 + i] = (len == 1 ? (char)c : src[0 + i]);
	if (len == 2)
	{
		src[0 + i] = (char)((c >> 6) + 0xC0);
		src[1 + i] = (char)((c & 0x3F) + 0x80);
	}
	else if (len == 3)
	{
		src[0 + i] = (char)((c >> 12) + 0xE0);
		src[1 + i] = (char)(((c >> 6) & 0x3F) + 0x80);
		src[2 + i] = (char)((c & 0x3F) + 0x80);
	}
	else if (len == 4)
	{
		src[0 + i] = (char)((c >> 18) + 0xF0);
		src[1 + i] = (char)(((c >> 12) & 0x3F) + 0x80);
		src[2 + i] = (char)(((c >> 6) & 0x3F) + 0x80);
		src[3 + i] = (char)((c & 0x3F) + 0x80);
	}
	return (len);
}
