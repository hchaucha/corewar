/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:52:32 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 14:52:33 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int			verif_file_champ(char *str)
{
	int		fd;
	int		len;

	len = ft_strlen(str);
	fd = -1;
	if (!ft_strcmp(str + len - 4, ".cor"))
		fd = open(str, O_RDONLY);
	else
	{
		ft_putstr_fd(C_RED"Error: file is not a .cor\n"C_NONE, 2);
		print_help();
	}
	return (fd);
}

void		get_option_d(char **av, int *i, t_tool *tool)
{
	if (tool->opt.dump_close > 0)
		ft_error("Error: -d appears several times");
	if (ft_isnumber(av[*i + 1]) && tool->opt.ncurse == 0 && ++(*i))
		tool->opt.dump_close = ft_atoi(av[*i]);
	else if (!ft_isnumber(av[*i + 1]))
	{
		ft_putstr_fd(C_RED"Error: [ -s ] -> miss a number\n"C_NONE, 2);
		print_help();
	}
	else
		tool->opt.dump_close = 1;
}

void		get_option_s(char **av, int *i, t_tool *tool)
{
	if (tool->opt.dump_break > 0)
		ft_error("Error: -s appears several times");
	if (ft_isnumber(av[*i + 1]) && tool->opt.ncurse == 0 && ++(*i))
		tool->opt.dump_break = ft_atoi(av[*i]);
	else if (!ft_isnumber(av[*i + 1]))
	{
		ft_putstr_fd(C_RED"Error: [ -s ] -> miss a number\n"C_NONE, 2);
		print_help();
	}
	else
		tool->opt.dump_break = 1;
}

int			get_option_p(char **av, int *i, t_tool *tool, int *id_champ)
{
	int		fd;

	if (ft_isnumber(av[*i + 1]))
	{
		if (check_id_champ(tool, ft_atoi(av[*i + 1])))
			*id_champ = ft_atoi(av[*i + 1]);
		else
			ft_error("Error: This number has already been assigned");
		*i += 2;
	}
	else
	{
		ft_putstr_fd(C_RED"Error: [ -p ] -> miss a number\n"C_NONE, 2);
		print_help();
	}
	if ((fd = verif_file_champ(av[*i])) < 0)
		ft_error("Error: fd is not correct");
	return (fd);
}

int			get_option(char **av, int *i, t_tool *tool, int *id_champ)
{
	int		fd;

	fd = -1;
	if (!ft_strcmp(av[*i], "-n") && !tool->opt.dump_break
		&& !tool->opt.dump_close && !tool->opt.verbose
		&& !tool->opt.cycle)
		tool->opt.ncurse = 1;
	else if (!ft_strcmp(av[*i], "-v"))
		tool->opt.verbose = 1;
	else if (!ft_strcmp(av[*i], "-d"))
		get_option_d(av, i, tool);
	else if (!ft_strcmp(av[*i], "-s"))
		get_option_s(av, i, tool);
	else if (!ft_strcmp(av[*i], "-p"))
		fd = get_option_p(av, i, tool, id_champ);
	else if (!ft_strcmp(av[*i], "-c"))
		tool->opt.cycle = 1;
	else if (!ft_strcmp(av[*i], "-j"))
		tool->opt.jump = 1;
	else if ((fd = verif_file_champ(av[*i])) < 0)
		ft_error("Error: fd is not correct");
	return (fd);
}
