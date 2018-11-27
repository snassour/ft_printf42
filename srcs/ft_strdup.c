/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:48:09 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:48:13 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1) + 1;
	dest = NULL;
	dest = (char *)malloc(sizeof(char) * i);
	if (dest)
		dest[i - 1] = 0;
	if (dest)
		while (--i > -1)
			dest[i] = s1[i];
	return (dest);
}
