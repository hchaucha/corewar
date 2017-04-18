/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cor_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:48 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:49 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		print_name(t_tool *tool, const char *s)
{
	int		i;
	int		flush;
	int		nb;

	i = 0;
	ft_putchar_fd(0x00, tool->fd);
	ft_putchar_fd(0xea, tool->fd);
	ft_putchar_fd(0x83, tool->fd);
	ft_putchar_fd(0xf3, tool->fd);
	flush = 0;
	nb = 0;
	while (nb < 128)
	{
		if (s[i] == '"')
			flush++;
		if (flush)
			ft_putchar_fd(0, tool->fd);
		else
			ft_putchar_fd(s[i], tool->fd);
		i++;
		nb++;
	}
}

void		print_comment(t_tool *tool, const char *s)
{
	int		i;
	int		flush;
	int		nb;

	i = 0;
	nb = 0;
	flush = 0;
	while (nb < 2052)
	{
		if (s[i] == '"')
			flush++;
		if (flush)
			ft_putchar_fd(0, tool->fd);
		else
			ft_putchar_fd(s[i], tool->fd);
		i++;
		nb++;
	}
}
