/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:26:28 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:26:31 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H
# include <ft_printf.h>

struct	s_strs
{
	char	*fl;
	char	*cnv;
	char	*prc;
	char	*mdf;
};

struct	s_conv
{
	int conv;
	int	zero;
	int	htag;
	int	left;
	int plus;
	int sp;
	int minw;
	int prec;
	int modif;
	int	negative;
	int null;
	int	len_cv;
};

struct	s_printf
{
	char			*str;
	va_list			ap;
	struct s_strs	*all;
	int				len;
	char			*toto;
	char			*tmp;
	int				real_size;
	int				total_size;
	int				error;
	int				prev_conv;
	int				final_length;
};

#endif
