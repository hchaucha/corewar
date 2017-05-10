/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_st(char *line, char *str, t_reg **list_reg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	epur_space(line, &i, 0);
	while (line[i] == str[j])
	{
		i++;
		j++;
	}
	if (check_reg(line, &i, 0))
	{
		epur_space(line, &i, 1);
		if (check_ind(line, &i, 1, list_reg) || check_reg(line, &i, 1))
			return (1);
	}
	ft_printf(C_RED"Wrong param (T_REG, T_IND || T_REG) => %s\n", line, C_NONE);
	return (0);
}
