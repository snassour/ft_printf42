/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:51:14 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:51:20 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strrevcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (j > i)
		return (NULL);
	while (j > 0)
		dest[--i] = src[--j];
	return (dest);
}

char	*ft_strnrevcpy(char *dest, char *src, int len)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = len;
	if (j > i)
		return (NULL);
	while (j > 0)
		dest[--i] = src[--j];
	return (dest);
}
