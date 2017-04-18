/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:55:21 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 16:55:23 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	init_screen(void)
{
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	attron(A_BOLD | COLOR_PAIR(7));
	box(stdscr, ACS_VLINE, ACS_HLINE);
	mvhline(2, 1, '-', COLS - 2);
	attroff(A_BOLD | COLOR_PAIR(7));
	start_color();
	use_default_colors();
	init_pair(1, 245, -1);
	init_pair(2, COLOR_RED, -1);
	init_pair(3, COLOR_GREEN, -1);
	init_pair(4, COLOR_BLUE, -1);
	init_pair(5, COLOR_YELLOW, -1);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, -1);
	refresh();
}

void	display_info_menu(t_tool *tool, int cycle_to_die, int sleep)
{
	int		col;

	col = 200;
	attron(COLOR_PAIR(7));
	mvvline(3, col, '|', LINES - 4);
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(0));
	mvprintw(9, 250, "sleep:  %d", sleep);
	sleep = (1000000 / sleep);
	mvprintw(10, 250, "SPEED:  %d %c", sleep, '%');
	mvprintw(15, 250, "CYCLE_TO_DIE:  %d", cycle_to_die);
	mvprintw(16, 250, "CYCLE:  %d", tool->total_cycle);
	attroff(COLOR_PAIR(0));
	refresh();
}

void	display_players_header(t_tool *tool)
{
	int			i;
	int			col;
	t_champ		*tmp;

	col = 1;
	i = 0;
	tmp = tool->champ;
	while (tmp && ++i)
	{
		attron(A_BOLD | COLOR_PAIR(i + 1));
		mvprintw(1, col, "Player -%d: \"%s\" -> \"%s\"",
			i, tmp->name, tmp->comment);
		attroff(A_BOLD | COLOR_PAIR(i));
		col = (COLS / tool->nb_champ) * i;
		tmp = tmp->next;
	}
	col = 1;
	refresh();
}

void	close_screen(void)
{
	echo();
	nocbreak();
	endwin();
}
