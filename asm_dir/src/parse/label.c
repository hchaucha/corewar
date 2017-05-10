/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	save_label_2(t_lab_check **list, t_lab_check *new, t_lab_check *tmp)
{
	if (*list == NULL)
	{
		new->prev = NULL;
		*list = new;
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
}

void	save_label(char *str, t_lab_check **list)
{
	t_lab_check	*new;
	t_lab_check	*tmp;
	int			i;

	i = 0;
	new = malloc(sizeof(t_lab_check));
	new->next = NULL;
	tmp = NULL;
	new->label_name = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		new->label_name[i] = str[i];
		i++;
	}
	new->label_name[i] = '\0';
	save_label_2(list, new, tmp);
}

char	*check_label_2(char *line, int len, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*str2;

	j = 0;
	k = 0;
	str2 = malloc(sizeof(char) * ft_strlen(line) - len + 1);
	i = len;
	while (line[i] != ' ' && line[i] != '\t')
	{
		i++;
		j++;
	}
	i = i - j;
	while (j--)
		str[k++] = line[i++];
	str[k] = '\0';
	i = 0;
	while (line[len])
		str2[i++] = line[len++];
	str2[i] = '\0';
	return (str2);
}

int		check_label(char *line, char *str, t_reg **list_reg)
{
	int		i;
	int		len;
	char	*str2;

	i = 0;
	str2 = NULL;
	len = ft_strlen(str) + 1;
	epur_space(line, &len, 0);
	if (end_line(line, len))
		return (1);
	str2 = check_label_2(line, len, str);
	if (check_valid_param(str2, str, 0, list_reg))
	{
		free(str2);
		return (1);
	}
	free(str2);
	return (0);
}
