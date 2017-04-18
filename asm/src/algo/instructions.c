/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:18 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:20 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			live(t_tool *tool, int instr, int total)
{
	char	*str;

	tool->spec = 8;
	str = tool->instr[instr] + 4;
	write_dir(tool, str, total);
	return (4);
}

int			ld(t_tool *tool, int instr, int total)
{
	int		nbw;
	char	*str;
	int		i;

	nbw = print_fd(tool, tool->ocp[instr]);
	str = tool->instr[instr] + 2;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		tool->spec = 8;
		if (str[i] == 'r' && (nbw += write_reg(tool, str + i + 1)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (str[i] == '%' && (nbw +=
			write_dir(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (((str[i] == ':' || str[i] == '-' || ft_isdigit(str[i]))
			&& (str[i - 1] != '%' || str[i - 1] != 'r')) && (tool->spec = 4)
			&& (nbw += write_ind(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		i++;
	}
	return (nbw);
}

int			st(t_tool *tool, int instr, int total)
{
	int		nbw;
	char	*str;
	int		i;

	nbw = print_fd(tool, tool->ocp[instr]);
	str = tool->instr[instr] + 2;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == 'r' && (nbw += write_reg(tool, str + i + 1)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		else if (((str[i] == ':' || str[i] == '-' || ft_isdigit(str[i]))
			&& (str[i - 1] != '%' || str[i - 1] != 'r')) && (tool->spec = 4)
			&& (nbw += write_ind(tool, str + i, total)))
			while (i < (int)ft_strlen(str) && str[i] != ',')
				i++;
		i++;
	}
	return (nbw);
}

int			add(t_tool *tool, int instr, int total)
{
	int		nbw;
	char	*str;
	int		i;

	nbw = print_fd(tool, tool->ocp[instr]);
	str = tool->instr[instr] + 3;
	i = 0;
	total = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == 'r' && (nbw += write_reg(tool, str + i + 1)))
			while (str[i] && str[i] != ',')
				i++;
		i++;
	}
	return (4);
}
