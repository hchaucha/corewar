/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 23:56:12 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/09 23:56:14 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert_pcent(t_flags *flags, char *str)
{
	int			len;
	char		*tmp;

	str = ft_strnew(1);
	tmp = str;
	len = 0;
	str = "%";
	str = ft_padding_str(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (len);
}

int				ft_convert_num(va_list ap, t_flags *flags, char *str)
{
	long long	n;
	int			len;
	char		*tmp;

	n = va_arg(ap, long long);
	if (n < 0)
		flags->plus = '\0';
	if (flags->ct == 'd' || flags->ct == 'D' || flags->ct == 'i')
		str = ft_transform_di(flags, n, str);
	else
		str = ft_transform_oux(flags, n, str);
	tmp = str;
	str = ft_padding_num(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (len);
}

int				ft_convert_ptr(va_list ap, t_flags *flags, char *str)
{
	void		*ptr;
	int			len;
	char		*tmp;

	ptr = va_arg(ap, void *);
	flags->pref = 2;
	str = ft_itoa_base((long long)ptr, 16);
	tmp = str;
	str = ft_padding_num(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (len);
}

int				ft_convert_wcharc(va_list ap, t_flags *flags, char *str)
{
	wchar_t		c;
	int			len;
	char		*tmp;

	c = (wchar_t)va_arg(ap, wchar_t);
	if (c == 0)
		return (case_zero_c(flags));
	str = ft_transform_c(c, flags);
	tmp = str;
	str = ft_padding_str(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (len);
}

int				ft_convert_wchars(va_list ap, t_flags *flags, char *str)
{
	wchar_t		*s;
	int			len;
	char		*tmp;

	if (!(s = (wchar_t *)va_arg(ap, wchar_t *)))
	{
		str = "(null)";
		str = ft_padding_str(flags, str);
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
		return (len);
	}
	str = ft_transform_s(s, flags);
	tmp = str;
	str = ft_padding_str(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (len);
}
