/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:24:27 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/20 11:36:31 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_transform_oux(t_flags *f, long long int arg, char *str)
{
	if (f->modifier == 'h' && f->ct != 'U')
		arg = (unsigned short)arg;
	else if (f->modifier == 'H' && f->ct != 'U' && f->ct != 'O')
		arg = (unsigned char)arg;
	else if (f->modifier == 'l')
		arg = (unsigned long)arg;
	else if (f->modifier == 'L')
		arg = (unsigned long long)arg;
	else if (f->modifier == 'j' && f->ct != 'U')
		arg = (unsigned long long)arg;
	else if (f->modifier == 'z')
		arg = (size_t)arg;
	else if (f->ct != 'U' && f->ct != 'O')
		arg = (unsigned int)arg;
	if (f->ct == 'o' || f->ct == 'O')
		str = ft_uitoa_base(arg, 8);
	else if (f->ct == 'u' || f->ct == 'U')
		str = ft_uitoa_base(arg, 10);
	else if (f->ct == 'x' || f->ct == 'X')
	{
		str = ft_uitoa_base(arg, 16);
		if (f->ct == 'X')
			ft_str_toupper(&str);
	}
	return (str);
}

static char	*ft_add_di(t_flags *flags, long long arg, char *str, int lg)
{
	if (flags->modifier == 'z')
		str = ft_itoa_base(arg, 10);
	else if (lg == 0)
		str = ft_itoa(arg);
	else
		str = ft_itoa_base(arg, 10);
	if (str && *str && *str == '-')
		flags->plus = '-';
	return (str);
}

char		*ft_transform_di(t_flags *flags, long long arg, char *str)
{
	size_t	lg;

	lg = 0;
	if (flags->modifier == 'h' && flags->ct != 'D')
		arg = (short)arg;
	else if (flags->modifier == 'H' && flags->ct != 'D')
		arg = (signed char)arg;
	else if (flags->modifier == 'l' || flags->ct == 'D')
	{
		lg = 1;
		arg = (long)arg;
	}
	else if (flags->modifier == 'L')
	{
		lg = 1;
		arg = (long long int)arg;
	}
	else if (flags->modifier == 'j')
	{
		lg = 1;
		arg = (intmax_t)arg;
	}
	else if (flags->modifier == 'z')
		arg = (long long int)arg;
	return (ft_add_di(flags, arg, str, lg));
}

char		*ft_transform_s(wchar_t *s, t_flags *flags)
{
	char	*str;
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	str = ft_strdup("");
	if (flags->prec >= 0)
		k = flags->prec;
	while (s[i])
	{
		tmp = ft_transform_c(s[i], flags);
		k -= flags->p_cut;
		if (k < 0)
		{
			ft_strdel(&tmp);
			break ;
		}
		str = ft_strjoin_f(&str, tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (str);
}
