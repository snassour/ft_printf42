/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_printf_cv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:33:15 by snassour          #+#    #+#             */
/*   Updated: 2018/07/05 17:33:19 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	conv_cv(t_conv *cv)
{
	cv->zero = 0;
	cv->htag = 0;
	cv->plus = 0;
	cv->sp = 0;
	cv->left = 0;
	cv->negative = 0;
	cv->modif = 0;
	cv->null = 0;
	cv->len_cv = 0;
}

void	init_strs(t_strs *all)
{
	all->prc = ft_strdup(PREC);
	all->mdf = ft_strdup(MODIF);
	all->fl = ft_strdup(FLAGS);
	all->cnv = ft_strdup(CV);
}
