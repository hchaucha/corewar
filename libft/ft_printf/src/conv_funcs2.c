/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 10:49:34 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/11 10:49:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_truncate(char **str, t_flags *flags)
{
	char		*tmp;

	tmp = ft_strdup(*str);
	*str = ft_strsub(tmp, 0, flags->prec);
	ft_strdel(&tmp);
}

int				case_zero_c(t_flags *flags)
{
	int			len;
	char		c;

	c = flags->z_pad == 1 ? '0' : ' ';
	len = 1;
	if (flags->ljust == 1)
	{
		if (flags->f_width > 1)
		{
			len = flags->f_width;
			ft_putchar(0);
			while (--flags->f_width)
				ft_putchar(c);
		}
	}
	else if (flags->f_width > 1)
	{
		len = flags->f_width;
		while (--flags->f_width)
			ft_putchar(c);
		ft_putchar(0);
	}
	else
		ft_putchar(0);
	return (len);
}

int				ft_convert_str(va_list ap, t_flags *flags, char *str)
{
	int			len;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	else if (!ft_strcmp("0", str))
		return (case_zero_c(flags));
	len = ft_strlen(str);
	if (flags->prec >= 0 && flags->prec < len)
		ft_truncate(&str, flags);
	str = ft_padding_str(flags, str);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int				ft_convert_char(va_list ap, t_flags *flags, char *str)
{
	char		c;
	int			len;
	char		*tmp;

	str = ft_strnew(1);
	c = va_arg(ap, int);
	if (c == 0)
		return (case_zero_c(flags));
	*str = c;
	tmp = str;
	str = ft_padding_str(flags, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&tmp);
	ft_strdel(&str);
	return (len);
}
