/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:48:28 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 16:48:33 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_strdup_len(char *s, int len)
{
	char	*new;
	int		i;

	new = NULL;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
