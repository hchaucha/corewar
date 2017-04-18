/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:55:52 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:55:54 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static int	move_on(char *tmp, int j)
{
	while (tmp[j] != '\0' && tmp[j] != ',')
		j++;
	return (j);
}

static int	calc_hex(int ocp, int index)
{
	if (!ocp)
	{
		ocp = index;
		ocp = ocp << 2;
	}
	else
	{
		ocp = ocp | index;
		ocp = ocp << 2;
	}
	return (ocp);
}

int			get_number_index(char *tmp, int *tab)
{
	int j;
	int ocp;
	int deca;

	j = 0;
	ocp = 0x0;
	deca = 3;
	while (tmp[j])
	{
		if (tmp[j] == 'r' && tmp[j - 1] != 'o' && tmp[j + 1] != 'k'
		&& ft_isdigit(tmp[j + 1])
		&& (j = move_on(tmp, j)) && deca-- && ++tab[0])
			ocp = calc_hex(ocp, 1);
		else if (tmp[j] == '%' && (j = move_on(tmp, j)) && deca-- && ++tab[1])
			ocp = calc_hex(ocp, 2);
		else if (((tmp[j] == '-' && tmp[j - 1] != '%') || ft_isdigit(tmp[j])
			|| tmp[j] == ':') && (j = move_on(tmp, j)) && deca-- && ++tab[2])
			ocp = calc_hex(ocp, 3);
		else
			j++;
	}
	ocp = ocp << (2 * deca);
	return (ocp);
}

void		get_ocp_index(t_tool *tool)
{
	int		i;
	int		y;
	char	*tmp;

	tool->ocp = (int*)malloc(sizeof(int) * (tool->nb_instr + 1));
	tool->arg_ocp = (int**)malloc(sizeof(int*) * (tool->nb_instr + 1));
	i = -1;
	while (++i < tool->nb_instr)
	{
		tool->arg_ocp[i] = (int*)malloc(sizeof(int) * 3);
		y = -1;
		while (++y < 3)
			tool->arg_ocp[i][y] = 0;
	}
	i = 0;
	while (tool->instr[i])
	{
		tmp = tool->instr[i];
		tool->ocp[i] = get_number_index(tmp, tool->arg_ocp[i]);
		i++;
	}
}
