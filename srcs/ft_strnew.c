/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:49:16 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:49:20 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	j;

	str = NULL;
	str = (char *)malloc(sizeof(char) * (size + 1));
	j = 0;
	if (str)
		while (j < size + 1)
		{
			str[j] = 0;
			++j;
		}
	return (str);
}
