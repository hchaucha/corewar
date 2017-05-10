/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_corewar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:19:15 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 12:19:19 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int			change_time(int key, int sleep)
{
	if (key == 45 && (sleep + 1000) <= 1000000)
	{
		if (sleep >= 200000)
			sleep += 200000;
		else if (sleep >= 100000)
			sleep += 10000;
		else if (sleep >= 5000)
			sleep += 5000;
		else
			sleep += 1000;
	}
	if (key == 43 && (sleep - 1000) > 0)
	{
		if (sleep >= 400000)
			sleep -= 200000;
		else if (sleep >= 100000)
			sleep -= 10000;
		else if (sleep >= 50000)
			sleep -= 5000;
		else
			sleep -= 1000;
	}
	return (sleep);
}

void		make_option(t_tool *t, t_cycle *go)
{
	if (t->opt.ncurse > 0)
	{
		go->key = getch();
		go->sleep = change_time(go->key, go->sleep);
		if (go->key == 32 || go->key == 10)
			while (1)
			{
				if ((go->key = getch()) == 32 || go->key == 10)
					break ;
				go->sleep = change_time(go->key, go->sleep);
				display_info_menu(t, go->cycle_to_die, go->sleep);
			}
		display_info_menu(t, go->cycle_to_die, go->sleep);
		dump_memory_ncurse(t->i, t->arena);
		usleep(go->sleep);
	}
	if (t->opt.dump_break > 0 && (t->total_cycle % t->opt.dump_break) == 0)
	{
		dump_memory_stdout(t->arena, 0);
		while (1)
			if ((go->key = getchar()) == 32 || go->key == 10)
				break ;
	}
	else if (t->opt.dump_close == t->total_cycle)
		dump_memory_stdout(t->arena, 1);
}

void		kill_process(t_tool *tool, t_cycle *go)
{
	t_process *tmp;

	tmp = tool->process;
	while (tmp)
	{
		tool->arena[tool->process->pc].here_process = 0;
		if (tmp && tmp->cycle_no_live >= go->cycle_to_die &&
	!(tool->process = del_process(tool, tool->process, tmp, go->cycle_to_die)))
			tmp = tool->process;
		if (tmp)
			tmp = tmp->next;
	}
}

void		end_cycle(t_tool *tool, t_cycle *go)
{
	++go->max_checks;
	if (go->nbr_live >= NBR_LIVE || go->max_checks == MAX_CHECKS)
	{
		go->max_checks = 0;
		go->cycle_to_die -= CYCLE_DELTA;
		if (tool->opt.cycle)
			ft_printf("Cycle to die is now %d\n", go->cycle_to_die);
	}
	if ((go->cycle = go->cycle_to_die + 1) < 0)
		go->cycle = 2;
}

void		go_corewar(t_tool *tool)
{
	t_cycle go;

	go.cycle_to_die = CYCLE_TO_DIE;
	go.max_checks = -1;
	go.sleep = 20000;
	go.nbr_live = 0;
	while (go.cycle_to_die)
	{
		end_cycle(tool, &go);
		go.nbr_live = 0;
		while (--go.cycle)
		{
			tool->total_cycle += 1;
			if (!tool->process)
				return ;
			if (tool->opt.cycle)
				ft_printf("It is now cycle %d\n", tool->total_cycle);
			go.nbr_live += make_process(tool);
			make_option(tool, &go);
		}
		kill_process(tool, &go);
	}
}
