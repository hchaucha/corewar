/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	free_list_2(t_reg **list_reg)
{
	t_reg	*tmp;
	t_reg	*del;

	if (*list_reg != NULL)
	{
		tmp = (*list_reg);
		while (tmp != NULL)
		{
			del = tmp;
			free(del->reg_label_name);
			tmp = tmp->next;
			free(del);
		}
		*list_reg = NULL;
	}
}

void	free_list(t_lab_check **list, t_reg **list_reg)
{
	t_lab_check		*tmp;
	t_lab_check		*del;

	if (*list != NULL)
	{
		tmp = (*list);
		while (tmp != NULL)
		{
			del = tmp;
			free(del->label_name);
			tmp = tmp->next;
			free(del);
		}
		*list = NULL;
	}
	free_list_2(list_reg);
}

char	*search_word(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	epur_space(line, &i, 0);
	j = i;
	while (allowed(line, j) && line[j] != ':')
	{
		j++;
		k++;
	}
	str = malloc(sizeof(char) * j + 1);
	j = 0;
	while (k--)
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

void	epur_space(char *line, int *i, int virg)
{
	if (virg == 0)
	{
		while (line[*i] == ' ' || line[*i] == '\t')
			*i = *i + 1;
	}
	else
	{
		while (line[*i] == ' ' || line[*i] == '\t' || line[*i] == ',')
			*i = *i + 1;
	}
}

int		diez(char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != ' ' && s1[i] != '\t' && s1[i] != '\n' &&
			s1[i] != '#' && s1[i] != ';')
			return (0);
		if (s1[i] == '#' || s1[i] == ';')
			return (1);
		i++;
	}
	return (0);
}
