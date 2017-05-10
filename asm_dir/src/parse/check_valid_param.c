/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_valid_param(char *line, char *str, int r, t_reg **list_reg)
{
	if (r == 2)
		return (check_label(line, str, list_reg));
	else if (!ft_strcmp(str, "live") || !ft_strcmp(str, "zjmp")
		|| !ft_strcmp(str, "lfork") || !ft_strcmp(str, "fork"))
		return (check_live_zjmp_lfork(line, str, list_reg));
	else if (!ft_strcmp(str, "ld") || !ft_strcmp(str, "lld"))
		return (check_ld_lld(line, str, list_reg));
	else if (!ft_strcmp(str, "st"))
		return (check_st(line, str, list_reg));
	else if (!ft_strcmp(str, "add") || !ft_strcmp(str, "sub"))
		return (check_add_sub(line, str));
	else if (!ft_strcmp(str, "and") || !ft_strcmp(str, "or")
		|| !ft_strcmp(str, "xor"))
		return (check_and_or_xor(line, str, list_reg));
	else if (!ft_strcmp(str, "ldi"))
		return (check_ldi(line, str, list_reg));
	else if (!ft_strcmp(str, "sti"))
		return (check_sti(line, str, list_reg));
	else if (!ft_strcmp(str, "lldi"))
		return (check_lldi(line, str, list_reg));
	else if (!ft_strcmp(str, "aff"))
		return (check_aff(line, str));
	return (0);
}
