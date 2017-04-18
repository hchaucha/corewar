/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:21:59 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/13 17:12:05 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		begining_ending(t_tool *tool)
{
	t_champ		*champ;

	champ = tool->champ;
	if (tool->opt.ncurse != 1)
	{
		ft_printf("Introducing contestants...\n");
		while (champ)
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n"
		, champ->id_champ * -1, champ->nb_octet, champ->name, champ->comment);
			champ = champ->next;
		}
	}
}

int			main(int ac, char **av)
{
	t_tool		tool;
	t_champ		*champ;

	initialisation(ac, av, &tool);
	begining_ending(&tool);
	go_corewar(&tool);
	if (tool.opt.ncurse)
	{
		endwin();
		close_screen();
	}
	champ = tool.champ;
	while (champ->next)
	{
		if (champ->live_on == 1)
			break ;
		champ = champ->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		champ->id_champ * -1, champ->name);
	free_things(&tool);
	return (1);
}
