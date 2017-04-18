/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:31:19 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/27 16:31:20 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int				print_final(int len, int hexa, int fd)
{
	if (len > 0)
		ft_putchar_fd(0, fd);
	else
	{
		ft_putchar_fd(hexa, fd);
		return (1);
	}
	return (0);
}

void			get_hexa_int(intmax_t nb, int nb_octet, int fd)
{
	int			hexa[8];
	t_written	print;
	int			i;

	i = 0;
	print.tmp2 = ft_itoa_base(nb, 16);
	if ((ft_strlen(print.tmp2) % 2) != 0)
		print.tmp2 = ft_straddnchar(print.tmp2, 0, 1, '0');
	print.i = -1;
	print.len = 0;
	while ((print.tmp = ft_strsub(print.tmp2 + i, 0, 2)) && print.tmp[0])
	{
		print.tmp = ft_addhexachar(print.tmp, 1);
		hexa[++print.i] = ft_atoi_b(print.tmp, 16);
		i += 2;
		print.len += 1;
		free(print.tmp);
	}
	print.i = -1;
	i = 0;
	print.len = nb_octet - print.len;
	while (++print.i < nb_octet)
		i += print_final(print.len--, hexa[i], fd);
	ft_strdel(&print.tmp2);
	ft_strdel(&print.tmp);
}

void			get_hexa_char(char *str, int nb_octet, int fd)
{
	int			hexa[8];
	t_written	print;
	int			i;

	if ((ft_strlen(str) % 2) != 0)
		str = ft_straddnchar(str, 0, 1, '0');
	print.i = -1;
	print.len = 0;
	i = 0;
	while ((print.tmp = ft_strsub(str + i, 0, 2)) && print.tmp[0])
	{
		print.tmp = ft_addhexachar(print.tmp, 1);
		hexa[++print.i] = ft_atoi_b(print.tmp, 16);
		i += 2;
		print.len += 1;
		free(print.tmp);
	}
	print.i = -1;
	i = 0;
	print.len = nb_octet - print.len;
	while (++print.i < nb_octet)
		i += print_final(print.len--, hexa[i], fd);
	ft_strdel(&str);
	ft_strdel(&print.tmp);
}
