/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:55:36 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 16:55:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	the_dump(t_mem *arena, int i, char *tmp)
{
	if (arena[i].value == 0)
		ft_printf("00");
	else
	{
		tmp = ft_itoa_base(arena[i].value, 16);
		if (ft_strlen(tmp) == 1)
			tmp = ft_straddnchar(tmp, 0, 1, '0');
		ft_printf("%s", tmp);
		free(tmp);
	}
}

void	dump_memory_stdout(t_mem *arena, int on)
{
	int		i;
	int		nb_written;
	char	*tmp;

	nb_written = 0;
	tmp = NULL;
	ft_printf("0x%.4x : ", nb_written / 2);
	i = -1;
	while (++i < 4096)
	{
		if (nb_written > 0 && (nb_written % 2) == 0 && (nb_written % 64) != 0)
			ft_printf(" ");
		else if (nb_written > 0 && (nb_written % 64) == 0)
			ft_printf(C_NONE" \n0x%.4x : ", nb_written / 2);
		if (arena[i].here_process == 1)
			color_stdout(8);
		else
			color_stdout(arena[i].color);
		the_dump(arena, i, tmp);
		nb_written += 2;
		ft_printf("\033[0m");
	}
	ft_putendl(" ");
	if (on)
		exit(1);
}

void	on_off(int on, t_mem *arena, int i)
{
	if (on)
	{
		if (arena[i].here_process)
			attron(A_BOLD | COLOR_PAIR(6));
		else
			attron(A_BOLD | COLOR_PAIR(arena[i].color + 1));
	}
	else
	{
		if (arena[i].here_process)
			attroff(A_BOLD | COLOR_PAIR(6));
		else
			attroff(A_BOLD | COLOR_PAIR(arena[i].color + 1));
	}
}

int		the_dump_ncurse(char *tmp, int value, int line, int col)
{
	tmp = ft_itoa_base(value, 16);
	if (ft_strlen(tmp) == 1)
		tmp = ft_straddnchar(tmp, 0, 1, '0');
	mvprintw(line, col, "%s", tmp);
	free(tmp);
	return (2);
}

void	dump_memory_ncurse(int i, t_mem *arena)
{
	int		col;
	int		line;
	int		nb_written;
	char	*tmp;

	col = 5;
	line = 3;
	nb_written = 0;
	i = -1;
	tmp = NULL;
	while (++i < 4096)
	{
		on_off(1, arena, i);
		if (nb_written > 0 && (nb_written % 2) == 0 && (nb_written % 128) != 0)
			col += 1;
		else if (nb_written > 0 && (nb_written % 128) == 0 && (line += 1))
			col = 5;
		if (arena[i].value == 0 && mvprintw(line, col, "00"))
			col += 2;
		else
			col += the_dump_ncurse(tmp, arena[i].value, line, col);
		nb_written += 2;
		on_off(0, arena, i);
	}
	refresh();
}
