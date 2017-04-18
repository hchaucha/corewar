/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:55:09 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:55:11 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char			*verif_label(char *str, int nb)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ':' && ft_stroccu(LABEL_CHARS, str[i - 1]))
		{
			if (get_occurence_instr(str + i, ft_strstr) && nb == 0)
				return (str);
			else if (nb == 1)
				return (ft_strsub_f(&str, i + 1, ft_strlen(str) - i));
			else
				return (0);
		}
	}
	return (str);
}

int				get_op_code_bis(const char *s)
{
	if (!ft_strncmp(s, "sub", 3))
		return (5);
	else if (!ft_strncmp(s, "and", 3))
		return (6);
	else if (!ft_strncmp(s, "lfork", 5))
		return (15);
	else if (!ft_strncmp(s, "fork", 4))
		return (12);
	else if (!ft_strncmp(s, "xor", 3))
		return (8);
	else if (!ft_strncmp(s, "or", 2))
		return (7);
	else if (!ft_strncmp(s, "zjmp", 4))
		return (9);
	else if (!ft_strncmp(s, "aff", 3))
		return (16);
	return (0);
}

int				get_op_code(const char *s)
{
	if (!ft_strncmp(s, "live", 4))
		return (1);
	else if (!ft_strncmp(s, "lldi", 4))
		return (14);
	else if (!ft_strncmp(s, "lld", 3))
		return (13);
	else if (!ft_strncmp(s, "ldi", 3))
		return (10);
	else if (!ft_strncmp(s, "ld", 2))
		return (2);
	else if (!ft_strncmp(s, "sti", 3))
		return (11);
	else if (!ft_strncmp(s, "st", 2))
		return (3);
	else if (!ft_strncmp(s, "add", 3))
		return (4);
	else
		return (get_op_code_bis(s));
}

void			create_tab_instruction(t_tool *tool)
{
	int			i;
	int			nb;
	char		*tmp;

	tool->instr = (char**)ft_memalloc(sizeof(char*) * (tool->nb_instr + 1));
	tool->instr[tool->nb_instr] = NULL;
	tool->op = (int*)ft_memalloc(sizeof(int) * (tool->nb_instr + 1));
	tool->op[tool->nb_instr] = 0;
	i = 0;
	nb = 0;
	while (tool->file[i])
	{
		if (check_line(tool->file[i]) || !verif_label(tool->file[i], 0))
			i++;
		else
		{
			tmp = del_comment(tool->file[i]);
			tmp = verif_label(tmp, 1);
			tmp = ft_delchar_f(tmp, ' ', ft_stroccu(tmp, ' '));
			tool->instr[nb] = ft_delchar_f(tmp, '\t', ft_stroccu(tmp, '\t'));
			tool->op[nb] = get_op_code(tool->instr[nb]);
			nb++;
			i++;
		}
	}
}
