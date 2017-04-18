/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 23:54:10 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/09 23:54:18 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_word_number(char *s)
{
	int			n;

	n = 0;
	while (*s)
	{
		if (*s && *s != '%')
			n++;
		while (*s && *s != '%')
			s++;
		if (*s == '%')
		{
			n++;
			s++;
			while (*s && *s != 's' && *s != 'S' && *s != 'p' && \
					*s != 'd' && *s != 'D' && *s != 'i' && *s != 'o' && \
					*s != 'O' && *s != 'u' && *s != 'U' && *s != 'x' && \
					*s != 'X' && *s != 'c' && *s != 'C' && *s != '%')
				s++;
			if (*s)
				s++;
		}
	}
	return (n);
}

int				ft_strchr_f(char c)
{
	char		*str;
	int			i;

	i = 0;
	str = "sSpdDioOuUxXcC%";
	if (!c)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int				ft_add_split(char *s, int z)
{
	if (*s && *s != '%')
		while (s[z] && s[z] != '%')
			z++;
	if (*s && *s == '%')
	{
		z++;
		while (ft_strchr_f(s[z]))
			z++;
		if (*s)
			z++;
	}
	return (z);
}

char			**ft_split_format(char *s)
{
	int			w_n;
	int			i;
	int			z;
	char		**tmp_cut;

	w_n = ft_word_number(s);
	i = 0;
	z = 0;
	if (!(tmp_cut = (char **)malloc(sizeof(char *) * (w_n + 1))))
		return (NULL);
	tmp_cut[w_n] = NULL;
	while (i < w_n)
	{
		z = ft_add_split(s, z);
		tmp_cut[i] = ft_strsub(s, 0, z);
		i++;
		s += z;
		z = 0;
	}
	return (tmp_cut);
}
