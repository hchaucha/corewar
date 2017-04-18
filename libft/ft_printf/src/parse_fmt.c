/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 15:30:17 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/10 15:30:21 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initialize_flags(t_flags *flags)
{
	flags->len = 0;
	flags->pref = 0;
	flags->ljust = 0;
	flags->plus = 0;
	flags->f_width = 0;
	flags->z_pad = 0;
	flags->prec = -1;
	flags->modifier = '\0';
	flags->ct = '\0';
	flags->p_cut = 0;
}

void		ft_add_get_flags(t_flags *flags, char **format)
{
	if (ft_isdigit(**format))
	{
		flags->f_width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format && **format == '.')
	{
		(*format)++;
		if (**format && ft_isdigit(**format))
		{
			flags->prec = ft_atoi(*format);
			while (**format && ft_isdigit(**format))
				(*format)++;
		}
		else
			flags->prec = 0;
	}
}

void		ft_get_flags(t_flags *flags, char **format)
{
	while (**format)
	{
		if (**format == '#')
			flags->pref = 1;
		else if (**format == ' ' && flags->plus != '+')
			flags->plus = ' ';
		else if (**format == '+')
			flags->plus = '+';
		else if (**format == '-')
		{
			flags->z_pad = 0;
			flags->ljust = 1;
		}
		else if (**format == '0')
		{
			if (flags->ljust == 0)
				flags->z_pad = 1;
		}
		else
			break ;
		(*format)++;
	}
	ft_add_get_flags(flags, format);
}

int			ft_add_get_mod_conv(t_flags *flags, char *format, size_t len)
{
	if (len > 1)
	{
		if (len > 3)
			return (-1);
		if (*format == 'h' && *(format + 1) && *(format + 1) == 'h')
		{
			flags->modifier = 'H';
			format += 2;
		}
		else if (*format == 'l' && *(format + 1) && *(format + 1) == 'l')
		{
			flags->modifier = 'L';
			format += 2;
		}
		else if (ft_strchr("lhjz", *format))
		{
			flags->modifier = *format;
			format++;
		}
		else
			return (-1);
	}
	return (0);
}

int			ft_get_mod_conv(t_flags *flags, char *format)
{
	size_t	len;

	len = ft_strlen(format);
	flags->ct = *(format + len - 1);
	if (flags->ct == 'i')
		flags->ct = 'd';
	if (ft_add_get_mod_conv(flags, format, len) == -1)
		return (-1);
	if (flags->plus != '\0' && flags->ct != 'd')
		flags->plus = '\0';
	if (flags->pref == 1)
	{
		if (flags->ct == 'x' || flags->ct == 'X')
			flags->pref = 2;
		else if (flags->ct != 'o' && flags->ct != 'O')
			flags->pref = 0;
	}
	if (flags->prec != -1 && flags->ct != '%')
		flags->z_pad = 0;
	return (0);
}
