/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		strclen(char *s1, char s2)
{
	int		i;

	i = 0;
	while (s1[i] && s1[i] != s2)
		i++;
	return (i);
}

int		ft_space_tab_newline(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_space_tab(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_space_tab_str_2(char *s, int *i, int *ret, int name)
{
	if (s[*i] == ' ' || s[*i] == '\t')
	{
		*i = *i + 1;
		return (1);
	}
	else if (s[*i] == '"' && *ret == 1)
		return (0);
	else if (s[*i] == '"')
	{
		*i = *i + 1;
		if (s[*i] == '"' && name == 1)
			return (0);
		while (s[*i] != '"')
		{
			if (s[*i] == '\0' || s[*i] == '\n')
				return (0);
			*i = *i + 1;
		}
		*ret = 1;
		*i = *i + 1;
		if (end_line(s, *i))
			return (1);
	}
	return (3);
}

int		ft_space_tab_str(char *s, char *value, int name)
{
	int		i;
	int		j;
	int		ret;
	int		space;

	i = 0;
	j = 0;
	ret = 0;
	space = 0;
	while (s[i])
	{
		space = ft_space_tab_str_2(s, &i, &ret, name);
		if (space == 0)
			return (0);
		else if (space == 1)
			return (1);
		else if (s[i] == value[j])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	return (ret);
}
