/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_reg(char *line, int *i, int end)
{
	int		j;

	j = 0;
	epur_space(line, i, 0);
	if (line[*i] == 'r')
	{
		*i = *i + 1;
		while (ft_isdigit(line[*i]) && line[*i] != '-')
		{
			*i = *i + 1;
			j++;
			if (end == 1 && j <= 2 && end_line(line, *i))
				return (1);
			else if (end == 0 && j <= 2 && !ft_isdigit(line[*i])
				&& search_virg(line, *i))
				return (1);
		}
	}
	return (0);
}

int		check_dir(char *line, int *i, int end, t_reg **list_reg)
{
	epur_space(line, i, 0);
	if (line[*i] == '%')
	{
		*i = *i + 1;
		if (check_if_reg_label(line, list_reg, &i, end))
			return (1);
		while (ft_isdigit(line[*i]))
		{
			*i = *i + 1;
			if (end == 1 && end_line(line, *i))
				return (1);
			else if (end == 0 && !ft_isdigit(line[*i]) && search_virg(line, *i))
				return (1);
		}
	}
	return (0);
}

int		check_ind(char *line, int *i, int end, t_reg **list_reg)
{
	epur_space(line, i, 0);
	if (line[*i] == ':')
	{
		if (check_if_reg_label(line, list_reg, &i, end))
			return (1);
	}
	while (ft_isdigit(line[*i]))
	{
		*i = *i + 1;
		if (end == 1 && end_line(line, *i))
			return (1);
		else if (end == 0 && !ft_isdigit(line[*i]) && search_virg(line, *i))
			return (1);
	}
	return (0);
}
