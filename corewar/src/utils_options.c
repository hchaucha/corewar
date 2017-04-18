/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:56:52 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 14:56:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void			color_stdout(int color)
{
	if (color == 1)
		ft_printf("\033[31m");
	else if (color == 2)
		ft_printf("\033[32m");
	else if (color == 3)
		ft_printf("\033[34m");
	else if (color == 4)
		ft_printf("\033[33m");
	else if (color == 8)
		ft_printf("\033[96m");
	else if (color == 0)
		ft_printf("\033[0m");
}

void			init_option(t_opt *opt)
{
	opt->ncurse = 0;
	opt->verbose = 0;
	opt->dump_close = 0;
	opt->dump_break = 0;
	opt->cycle = 0;
}

void			check_opt(t_tool *tool)
{
	if (tool->opt.ncurse > 0)
	{
		tool->opt.dump_close = -1;
		tool->opt.dump_break = -1;
		tool->opt.cycle = 0;
		tool->opt.jump = 0;
		tool->opt.verbose = 0;
	}
	else if (tool->opt.dump_close > 0)
		tool->opt.dump_break = -1;
	if (!tool->champ)
	{
		ft_putstr_fd(C_RED"Error: miss at least one champion.\n"C_NONE, 2);
		print_help();
	}
}

int				check_id_champ(t_tool *tool, int id_champ)
{
	t_champ		*tmp;

	tmp = tool->champ;
	while (tmp)
	{
		if (tmp->id_champ == id_champ)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			print_help(void)
{
	ft_printf("----------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	ft_printf("|  %-15s  |   %-89s  |\n", "usage: ",
	"./corewar [-d Num | -s Num | -n | -c | -v] [ [-p Num] <champion1.cor> ]");
	ft_printf("----------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	ft_printf("|  %-15s  |   %-20s %-60s          |\n",
	"parameters: ", "--dump [ -d Number ]",
	": Dumps memory after Number cycles then exits");
	ft_printf("|  %-15s  |   %-20s %-60s          |\n",
	"", "--shut [ -s Number ]",
	": Runs Number cycles, dumps memory, pauses, then repeats");
	ft_printf("|  %-15s  | -------------------------------------------", "");
	ft_printf("------------------------------------------------- |\n");
	ft_printf("|  %-15s  |   %-20s %-60s          |\n",
	"", "--ncurse [ -n ]", ": Ncurses output mode");
	ft_printf("|  %-15s  |   %-20s %-60s          |\n",
	"", "--verbose [ -v ]", ": Verbose output mode");
	ft_printf("|  %-15s  |   %-20s %-60s          |\n",
	"", "--cycle [ -c ]", ": Cycle output mode");
	ft_printf("----------------------------------------------------------");
	ft_printf("----------------------------------------------------------\n");
	exit(1);
}
