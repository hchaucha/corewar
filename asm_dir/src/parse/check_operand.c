/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_if_label(char *line, char *str, t_lab_check **list)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!label_char(str))
		return (0);
	if (line[len] == ':')
	{
		save_label(str, list);
		return (2);
	}
	return (0);
}

int		check_ret(char *line, char *str, int ret, t_reg **list_reg)
{
	if (ret >= 1)
		ret = check_valid_param(line, str, ret, list_reg);
	else
		ft_printf(C_RED"Wrong command at this line => %s\n", line, C_NONE);
	return (ret);
}

void	init_tab(char **name)
{
	name[0] = "live";
	name[1] = "ld";
	name[2] = "st";
	name[3] = "add";
	name[4] = "sub";
	name[5] = "and";
	name[6] = "or";
	name[7] = "xor";
	name[8] = "zjmp";
	name[9] = "ldi";
	name[10] = "sti";
	name[11] = "fork";
	name[12] = "lld";
	name[13] = "lldi";
	name[14] = "lfork";
	name[15] = "aff";
}

int		check_operand(char *line, t_lab_check **list, t_reg **list_reg, int *e)
{
	char	*name[16];
	int		i;
	char	*str;
	int		ret;

	init_tab(name);
	str = NULL;
	i = 0;
	ret = 1;
	if (ft_space_tab_newline(line) || diez(line))
		return (ret);
	*e = *e + 1;
	str = search_word(line);
	while (ft_strcmp(str, name[i]) || line[ft_strlen(str)] == ':')
	{
		i++;
		if (i == 16)
		{
			ret = check_if_label(line, str, list);
			break ;
		}
	}
	ret = check_ret(line, str, ret, list_reg);
	free(str);
	return (ret);
}
