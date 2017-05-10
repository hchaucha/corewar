/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		end_line(char *s1, int i)
{
	while (s1[i])
	{
		if (s1[i] == ' ' || s1[i] == '\t')
			i++;
		else if (s1[i] == '#' || s1[i] == ';' || s1[i] == '\n' || s1[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (1);
}

int		search_virg(char *s1, int i)
{
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	if (s1[i] == ',')
		return (1);
	return (0);
}

int		allowed(char *s1, int i)
{
	if (s1[i] && s1[i] != ' ' && s1[i] != '\t' && s1[i] != ','
		&& s1[i] != '#' && s1[i] != ';')
		return (1);
	return (0);
}

int		label_char(char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= '0' && s1[i] <= '9')
			|| s1[i] == '_')
			i++;
		else
		{
			ft_printf(C_RED"Can't use [%c] in label name : ", s1[i]);
			return (0);
		}
	}
	return (1);
}

int		status(int i)
{
	if (i == 0)
		ft_printf(C_RED"Usage: ./asm <sourcefile.s>\n"C_NONE);
	else if (i == 2)
		ft_printf(C_RED"Fail name/comment\n"C_NONE);
	else if (i == 3)
		ft_printf(C_RED"Exit\n"C_NONE);
	else if (i == 4)
		ft_printf(C_RED"Label not match\n"C_NONE);
	else if (i == 5)
		ft_printf(C_RED"Label not match\n"C_NONE);
	else if (i == 6)
		ft_printf(C_RED"File is empty\n"C_NONE);
	else if (i == 7)
		ft_printf(C_RED"Multi name/comment\n"C_NONE);
	else if (i == 8)
		ft_printf(C_RED"No newline at end of file\n"C_NONE);
	return (0);
}
