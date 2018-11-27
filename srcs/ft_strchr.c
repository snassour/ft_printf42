/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:47:24 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:47:27 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	if (!*str && c == *str)
		return (str);
	if (!*str)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0 && c != 0)
		return (NULL);
	return (str + i);
}
