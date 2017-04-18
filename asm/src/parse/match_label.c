/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		undeclared(char *label)
{
	ft_printf(C_RED"No label '%s' declared\n", label, C_NONE);
	return (0);
}

int		match_label(t_lab_check **list, t_reg **list_reg)
{
	t_reg			*data_reg;
	t_lab_check		*data;

	data_reg = *list_reg;
	while (data_reg)
	{
		data = *list;
		if (data_reg && !data)
			return (undeclared(data_reg->reg_label_name));
		while (data && ft_strcmp(data_reg->reg_label_name, data->label_name))
		{
			if (data->next == NULL)
				return (undeclared(data_reg->reg_label_name));
			data = data->next;
		}
		if (data_reg->next == NULL)
			return (1);
		data_reg = data_reg->next;
	}
	return (1);
}
