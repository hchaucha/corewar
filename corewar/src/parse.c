/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:57:07 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 14:57:08 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_mem		*init_memory(void)
{
	t_mem	*arena;

	arena = (t_mem *)ft_memalloc(sizeof(t_mem) * 4096);
	if (arena == NULL)
		ft_error("Error: memory allocation failed");
	return (arena);
}

void		create_champ(t_tool *tool, int id_champ, int fd)
{
	int		tmp;

	if (++tool->nb_champ > 4)
		ft_error("Error : Too many champions.\n");
	tmp = -1;
	if (id_champ == -1)
	{
		while (!check_id_champ(tool, tmp))
			tmp -= 1;
		id_champ = tmp;
	}
	read_file(fd, &tool->champ, id_champ);
	close(fd);
}

void		parsing(int ac, char **av, t_tool *tool)
{
	int		i;
	int		fd;
	int		id_champ;

	tool->nb_champ = 0;
	tool->champ = NULL;
	init_option(&tool->opt);
	if (ac < 2)
		print_help();
	i = 0;
	while (++i <= ac - 1)
	{
		id_champ = -1;
		fd = get_option(av, &i, tool, &id_champ);
		if (fd >= 0)
			create_champ(tool, id_champ, fd);
	}
	check_opt(tool);
}

void		init_tool(t_tool *tool)
{
	tool->nb_champ = 0;
	tool->arena = init_memory();
	tool->param = ft_memalloc(sizeof(int) * 4);
	tool->type_arg = ft_memalloc(sizeof(int) * 4);
	tool->total_cycle = 0;
	tool->process = NULL;
	tool->champ = NULL;
}

void		initialisation(int ac, char **av, t_tool *tool)
{
	int		c;

	init_tool(tool);
	parsing(ac, av, tool);
	place_champ(tool);
	init_process(tool);
	if (tool->opt.ncurse > 0)
	{
		init_screen();
		display_info_menu(tool, CYCLE_TO_DIE, 20000);
		display_players_header(tool);
		dump_memory_ncurse(tool->i, tool->arena);
		c = 0;
		while (c != 32 && c != 10)
			c = getch();
	}
}
