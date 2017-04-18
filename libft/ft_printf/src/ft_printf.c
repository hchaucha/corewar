/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 23:51:09 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/09 23:51:16 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_add_add_int(t_flags *flags, char *format, char *str)
{
	int			len;

	len = 0;
	if (flags->f_width > 0)
		flags->f_width += 1;
	str = ft_padding_str(flags, format);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int				ft_add_int(t_flags *flags, char *format, char *str, va_list ap)
{
	int			len;

	len = 0;
	format++;
	ft_get_flags(flags, &format);
	ft_get_mod_conv(flags, format);
	if (flags->ct == '%')
		len = ft_convert_pcent(flags, str);
	else if (flags->ct == 'p')
		len = ft_convert_ptr(ap, flags, str);
	else if (flags->ct == 'S' || (flags->ct == 's' && flags->modifier == 'l'))
		len = ft_convert_wchars(ap, flags, str);
	else if (flags->ct == 'C' || (flags->ct == 'c' && flags->modifier == 'l'))
		len = ft_convert_wcharc(ap, flags, str);
	else if (flags->ct == 's')
		len = ft_convert_str(ap, flags, str);
	else if (flags->ct == 'c')
		len = ft_convert_char(ap, flags, str);
	else if (flags->ct == 'u' || flags->ct == 'U' || flags->ct == 'd' || \
			flags->ct == 'D' || flags->ct == 'i' || flags->ct == 'o' || \
			flags->ct == 'O' || flags->ct == 'x' || flags->ct == 'X')
		len = ft_convert_num(ap, flags, str);
	else
		len = ft_add_add_int(flags, format, str);
	return (len);
}

int				ft_interpret(char *format, va_list ap)
{
	int			len;
	t_flags		*flags;
	char		*str;

	str = NULL;
	len = 0;
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	ft_initialize_flags(flags);
	if (*format && *format == '%')
	{
		if (!*(format + 1))
			return (0);
		len = ft_add_int(flags, format, str, ap);
	}
	else
	{
		str = ft_strdup(format);
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
	}
	free(flags);
	flags = NULL;
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**cut_format;
	char		**tmp;
	int			ret;

	ret = 0;
	va_start(ap, format);
	if (!(cut_format = ft_split_format((char *)format)))
		return (0);
	tmp = cut_format;
	while (cut_format && *cut_format)
	{
		ret += ft_interpret(*cut_format, ap);
		ft_strdel(cut_format);
		cut_format++;
	}
	free(tmp);
	va_end(ap);
	return (ret);
}
