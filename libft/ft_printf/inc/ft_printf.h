/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 23:42:13 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/09 23:43:16 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"

typedef struct		s_flags {

	int				sign;
	int				l_diff;
	char			c;
	size_t			pref;
	size_t			len;
	size_t			ljust;
	char			plus;
	int				z_pad;
	int				f_width;
	int				prec;
	char			ct;
	char			modifier;
	int				p_cut;
}					t_flags;

/*
**				split_fmt.c
*/

char				**ft_split_format(char *format);

/*
**				parse_fmt.c
*/

void				ft_initialize_flags(t_flags *flags);
void				ft_get_flags(t_flags *flags, char **format);
int					ft_get_mod_conv(t_flags *flags, char *format);

/*
**				conv_funcs.c
*/

int					ft_convert_pcent(t_flags *flags, char *str);
int					ft_convert_ptr(va_list ap, t_flags *flags, char *str);
int					ft_convert_num(va_list ap, t_flags *flags, char *str);
int					ft_convert_wcharc(va_list ap, t_flags *flags, char *str);
int					ft_convert_wchars(va_list ap, t_flags *flags, char *str);

/*
**				conv_funcs2.c
*/

int					case_zero_c(t_flags *flags);
int					ft_convert_str(va_list ap, t_flags *flags, char *str);
int					ft_convert_char(va_list ap, t_flags *flags, char *str);

/*
**				ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
**				padding.c
*/

char				*ft_padding_num(t_flags *flags, char *str);
char				*ft_padding(t_flags *flags, char *str);

/*
**				padding2.c
*/

char				*ft_padding_str(t_flags *flags, char *str);
int					ft_prefix(char **retstr, int i, t_flags *flags);
int					ft_c_fill(int i, int len, char c, char **str);
char				*ft_num_prec(int n, char *str);

/*
**				transform.c
*/

char				*ft_transform_oux(t_flags *f, long long n, char *s);
char				*ft_transform_di(t_flags *f, long long n, char *s);
char				*ft_transform_s(wchar_t *s, t_flags *flags);

/*
**				transform2.c
*/

char				*ft_transform_c(wchar_t c, t_flags *flags);

#endif
