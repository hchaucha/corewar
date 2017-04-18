/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_zjmp_lfork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_live_zjmp_lfork(char *line, char *str, t_reg **list_reg)
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
	epur_space(line, &i, 0);
	if (check_dir(line, &i, 1, list_reg))
		return (1);
	ft_printf(C_RED"Wrong param, not a T_DIR => %s\n", line, C_NONE);
	return (0);
}
