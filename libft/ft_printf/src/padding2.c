/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 11:09:30 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/11 11:09:34 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_prefix(char **retstr, int i, t_flags *flags)
{
	if (flags->ct == 'x' || flags->ct == 'p')
	{
		(*retstr)[i++] = '0';
		(*retstr)[i++] = 'x';
	}
	else if (flags->ct == 'X')
	{
		(*retstr)[i++] = '0';
		(*retstr)[i++] = 'X';
	}
	else if (flags->ct == 'o' || flags->ct == 'O')
		(*retstr)[i++] = '0';
	return (i);
}

int			ft_c_fill(int i, int len, char c, char **str)
{
	int	j;

	j = 0;
	while (j <= len)
	{
		(*str)[i + j] = c;
		j++;
	}
	return (i + j);
}

char		*ft_num_prec(int n, char *str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_strnew(n);
	i = 0;
	if (*str == '-')
	{
		tmp[i++] = '-';
		(*str)++;
	}
	while (i < n)
		tmp[i++] = '0';
	tmp2 = ft_strdup(str);
	str = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}

char		*ft_padding_str(t_flags *flags, char *str)
{
	char	*retstr;
	int		i;
	int		len;
	char	c;

	i = -1;
	len = ft_strlen(str);
	c = flags->z_pad == 1 ? '0' : ' ';
	if (flags->f_width > (int)len)
		len = flags->f_width;
	retstr = ft_strnew(len);
	if (flags->ljust == 1)
	{
		while (++i < len && str && str[i])
			retstr[i] = str[i];
		while (i < len)
			retstr[i++] = c;
		return (retstr);
	}
	while (++i < (int)(flags->f_width - ft_strlen(str)))
		retstr[i] = c;
	str--;
	while (i < len && str++ && *str)
		retstr[i++] = *str;
	return (retstr);
}
