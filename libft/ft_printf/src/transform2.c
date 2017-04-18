/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:17:48 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/11 11:17:50 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*wchar_1(wchar_t c, char *str, t_flags *flags)
{
	flags->p_cut = 1;
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static char	*wchar_2(wchar_t c, char *str, t_flags *flags)
{
	flags->p_cut = 2;
	str = (char *)malloc(sizeof(char) * 3);
	str[0] = ((c >> 6) + 0xC0);
	str[1] = ((c & 0x3F) + 0x80);
	str[2] = '\0';
	return (str);
}

static char	*wchar_3(wchar_t c, char *str, t_flags *flags)
{
	flags->p_cut = 3;
	str = (char *)malloc(sizeof(char) * 4);
	str[0] = ((c >> 12) + 0xE0);
	str[1] = (((c >> 6) & 0x3F) + 0x80);
	str[2] = ((c & 0x3F) + 0x80);
	str[3] = '\0';
	return (str);
}

static char	*wchar_4(wchar_t c, char *str, t_flags *flags)
{
	flags->p_cut = 4;
	str = (char *)malloc(sizeof(char) * 5);
	str[0] = ((c >> 18) + 0xF0);
	str[1] = (((c >> 12) & 0x3F) + 0x80);
	str[2] = (((c >> 6) & 0x3F) + 0x80);
	str[3] = ((c & 0x3F) + 0x80);
	str[4] = '\0';
	return (str);
}

char		*ft_transform_c(wchar_t c, t_flags *flags)
{
	char	*str;

	str = NULL;
	if (c <= 0x7F)
		str = wchar_1(c, str, flags);
	else if (c <= 0x7FF)
		str = wchar_2(c, str, flags);
	else if (c <= 0xFFFF)
		str = wchar_3(c, str, flags);
	else if (c <= 0x10FFFF)
		str = wchar_4(c, str, flags);
	else
		return (ft_strnew(0));
	return (str);
}
