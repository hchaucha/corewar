/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 15:23:20 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/10 15:23:24 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_pad_ljust(t_flags *flags, char *str)
{
	char	*retstr;
	int		i;
	char	c;
	int		sign;

	i = 0;
	sign = (flags->plus) ? 1 : 0;
	c = flags->z_pad == 1 ? '0' : ' ';
	retstr = ft_strnew(flags->len);
	if (flags->pref > 0)
		i = ft_prefix(&retstr, i, flags);
	else if (flags->plus != '\0')
		retstr[i++] = flags->plus;
	if (0 < flags->prec > (int)ft_strlen(str))
		i = ft_c_fill(i, flags->len - flags->prec - sign, '0', &retstr);
	while (i < (int)flags->len && str && *str)
		retstr[i++] = *(str++);
	ft_c_fill(i, flags->len - i - 1, c, &retstr);
	return (retstr);
}

static char	*ft_pad_rjust(t_flags *f, char *str, char *retstr, int i)
{
	retstr = ft_strnew(f->len);
	f->sign = (f->plus != '\0') ? 1 : 0;
	f->c = (f->z_pad == 1) ? '0' : ' ';
	if (f->c == ' ')
	{
		if (f->prec > 0 && f->prec > (int)ft_strlen(str))
			f->l_diff = f->len - f->prec - f->sign - f->pref;
		else
			f->l_diff = f->len - (int)ft_strlen(str) - f->sign - f->pref;
		i = ft_c_fill(i, (f->l_diff - 1), f->c, &retstr);
	}
	if (f->pref > 0)
		i = ft_prefix(&retstr, i, f);
	if (f->plus)
		retstr[i++] = f->plus;
	if (f->c == '0')
	{
		f->l_diff = f->len - ft_strlen(str) - f->sign - f->pref;
		while (i < (int)f->len && f->l_diff-- > 0)
			retstr[i++] = f->c;
	}
	str--;
	while (i < (int)f->len && ++str && *str != '\0')
		retstr[i++] = *str;
	return (retstr);
}

static char	*ft_add_padding_num2(t_flags *flags, char *str, char *ret)
{
	char	*retstr;
	int		i;

	i = 0;
	retstr = NULL;
	flags->len = ft_strlen(str) + flags->pref;
	if (0 <= flags->prec > (int)flags->len)
		flags->len = flags->prec;
	if (flags->plus != '\0')
		flags->len++;
	if (flags->f_width > (int)flags->len)
		flags->len = flags->f_width;
	if (flags->ljust == 1)
		ret = ft_pad_ljust(flags, str);
	else
		ret = ft_pad_rjust(flags, str, retstr, i);
	return (ret);
}

static char	*ft_add_padding_num1(t_flags *flags, char *str)
{
	if (flags->ct != 'p')
	{
		if (ft_strcmp(str, "0") == 0)
		{
			if (flags->prec == 0 && (flags->ct == 'o' || flags->ct == 'O') \
			&& flags->pref == 0)
				str = ft_strdup("");
			flags->pref = 0;
			if (flags->prec == 0 && (flags->ct == 'x' || flags->ct == 'X' \
			|| flags->ct == 'd' || flags->ct == 'D' || flags->ct == 'i' \
			|| flags->ct == 'u' || flags->ct == 'U'))
				str = ft_strdup("");
		}
		else if ((flags->ct == 'o' || flags->ct == 'O') && flags->prec > 1)
			flags->pref = 0;
	}
	return (str);
}

char		*ft_padding_num(t_flags *flags, char *str)
{
	int		l_diff;
	char	*ret;
	char	*tmp;

	ret = NULL;
	str = ft_add_padding_num1(flags, str);
	if (*str == '-')
		str++;
	l_diff = flags->prec - (int)ft_strlen(str);
	if (l_diff > 0)
	{
		str = ft_num_prec(l_diff, str);
		tmp = str;
	}
	ret = ft_add_padding_num2(flags, str, ret);
	if (l_diff > 0)
		ft_strdel(&tmp);
	return (ret);
}
