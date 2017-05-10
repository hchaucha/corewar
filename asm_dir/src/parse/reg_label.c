/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_if_reg_2(char *line, int **i, int end, t_reg **list_reg)
{
	char	*str;
	int		j;

	j = **i;
	while (allowed(line, j))
		j++;
	str = malloc(sizeof(char) * j + 1);
	j = 0;
	while (allowed(line, **i))
	{
		str[j++] = line[**i];
		**i = **i + 1;
		if ((end == 1 && end_line(line, **i))
			|| (end == 0 && search_virg(line, **i)))
		{
			str[j] = '\0';
			save_reg_label(str, list_reg);
			free(str);
			return (1);
		}
		else if (line[**i] == '\0' || line[**i] == '\n')
			break ;
	}
	free(str);
	return (0);
}

int		check_if_reg_label(char *line, t_reg **list_reg, int **i, int end)
{
	int		ret;

	ret = 0;
	if (line[**i] == ':')
	{
		**i = **i + 1;
		ret = check_if_reg_2(line, i, end, list_reg);
	}
	return (ret);
}

void	save_reg_label_2(t_reg **list_reg, t_reg *new, t_reg *tmp)
{
	if (*list_reg == NULL)
	{
		new->prev = NULL;
		*list_reg = new;
	}
	else
	{
		tmp = *list_reg;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
}

void	save_reg_label(char *str, t_reg **list_reg)
{
	t_reg	*new;
	t_reg	*tmp;
	int		i;

	i = 0;
	new = malloc(sizeof(t_reg));
	new->next = NULL;
	tmp = NULL;
	new->reg_label_name = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		new->reg_label_name[i] = str[i];
		i++;
	}
	new->reg_label_name[i] = '\0';
	save_reg_label_2(list_reg, new, tmp);
}
