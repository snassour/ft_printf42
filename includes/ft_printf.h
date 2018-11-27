/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:26:20 by snassour          #+#    #+#             */
/*   Updated: 2018/07/04 17:26:24 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "ft_printf_struct.h"

# define CV "%sSpdDioOuUxXcC"
# define NBCV 15
# define FLAGS "# +-0"
# define MODIF "hljz"
# define PREC ".0123456789"

# define MHH 1
# define MH 2
# define ML 3
# define MLL 4
# define MJ 5
# define MZ 6

# define L2 16
# define MASK2 0b1100000010000000
# define EMPT2 0b0010000001000000

# define L3 24
# define MASK3 0b111000001000000010000000
# define EMPT3 0b000100000100000001000000

# define L4 32
# define MASK4 0b11110000100000001000000010000000
# define EMPT4 0b00001000010000000100000001000000

typedef struct s_conv	t_conv;
typedef struct s_printf	t_printf;
typedef struct s_strs	t_strs;
typedef int		(*t_pconv)(t_printf *p, t_conv *conv);

int			ft_printf(const char *format, ...);
char		*ft_printf_extend(t_printf *p, char *s, int len);
void		destroy_printf(t_printf *p);
void		init_tab(t_pconv tab[NBCV + 1]);
void		init_strs(t_strs *all);
t_printf	*init_p(void);
void		parse(t_printf *p, char *s, t_pconv tab[NBCV + 1]);

int			check_characters(char c, t_strs *all, int check);
int			ft_isnum(char *str, int *check);
char		*udecider(t_printf *p, t_conv *cv, int base);
char		*hexdecider(t_printf *p, t_conv *cv, int base);

int			get_conv(char *s, t_printf *p, int i);
void		conv_cv(t_conv *cv);
int			get_flags(t_conv *cv, char *s, t_printf *p, int len);
int			get_widths(t_conv *cv, char *s, int len);
int			get_modif(t_conv *cv, char *s, int len, t_printf *p);
void		addconv(char *s, t_printf *p, int i, t_pconv tab[NBCV + 1]);

int			wintcpy(wint_t c, char *src, int i);
int			wintlen(wint_t c);

void		addchar(t_printf *p, wint_t c, t_conv *cv);
int			percent(t_printf *p, t_conv *cv);
int			invalid(t_printf *p, t_conv *cv);
int			wcharacter(t_printf *p, t_conv *cv);
int			character(t_printf *p, t_conv *cv);

int			wstringlen(wchar_t *src, t_conv *cv);
char		*conv_wstring(wchar_t *src, int *len, t_conv *cv);
int			get_string(t_printf *p, t_conv *cv);
int			string(t_printf *p, t_conv *cv);
int			wstring(t_printf *p, t_conv *cv);

int			uhex(t_printf *p, t_conv *cv);
int			unsigned_len_hex(t_conv *cv, char *s);
int			ulinteger(t_printf *p, t_conv *cv);
int			uinteger(t_printf *p, t_conv *cv);
int			uloctal(t_printf *p, t_conv *cv);
int			uoctal(t_printf *p, t_conv *cv);

int			pointer(t_printf *p, t_conv *cv);
int			linteger(t_printf *p, t_conv *cv);
int			integer(t_printf *p, t_conv *cv);

char		*str_fl(t_printf *p, char *s, t_conv *cv, int len);
void		oct_fl(t_printf *p, char *s, t_conv *cv);
void		hex_fl(t_printf *p, char *s, t_conv *cv);
int			unsigned_len(t_conv *cv, char *s);
void		udec_fl(t_printf *p, char *s, t_conv *cv);
void		ptr_fl(t_printf *p, char *s, t_conv *cv);
void		handle_prec_negative(char *str, t_conv *cv, int mode);
char		*short_char_nb(int nb, t_conv *cv);
void		treat_int(t_printf *p, t_conv *cv);
int			signed_len(t_conv *cv, char *s);

void		ft_allcaps(char *s);
int			ft_atoi(const char *str);
void		ft_fill(char *s, char c, int len);
int			ft_isdigit(int c);
char		*ft_lltoa(long long nb, t_conv *cv);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strdup_len(char *s, int len);
size_t		ft_strlen(const char *str);
char		*ft_strnew(size_t size);
char		*ft_strrevcpy(char *dest, char *src);
char		*ft_strnrevcpy(char *dest, char *src, int len);
char		*ft_ulltoa(unsigned long long nb, t_conv *cv);
char		*ft_ulltoa_base(unsigned long long nb, int base, t_conv *cv);
char		*ft_strncpy(char *dst, const char *src, size_t n);

#endif
