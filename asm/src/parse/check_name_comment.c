/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:16:01 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:28:48 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_name(char **line, int *name)
{
	if (ft_space_tab_str(*line, ".name", 1) == 1)
		*name = 1;
	else
	{
		free(*line);
		return (0);
	}
	return (1);
}

int		check_comment(char **line, int *comment)
{
	if (ft_space_tab_str(*line, ".comment", 0) == 1)
		*comment = 1;
	else
	{
		free(*line);
		return (0);
	}
	return (1);
}

int		check_next_line(int fd, char **line, int comment, int name)
{
	free(*line);
	if (!get_next_line(fd, line))
	{
		if (comment == 1 && name == 1)
			return (2);
		if (comment == 1 || name == 1)
			return (3);
		return (0);
	}
	return (1);
}

int		check_name_comment(int fd, char **line)
{
	int		comment;
	int		name;

	comment = 0;
	name = 0;
	while (comment == 0 || name == 0)
	{
		if (diez(*line))
			;
		else if (!comment && ft_strnstr(*line, ".comment", strclen(*line, '"')))
		{
			if (!check_comment(line, &comment))
				return (0);
		}
		else if (!name && ft_strnstr(*line, ".name", strclen(*line, '"')))
		{
			if (!check_name(line, &name))
				return (0);
		}
		else if ((!ft_space_tab_newline(*line)) && (comment == 0 || name == 0))
			return (0);
		if (check_next_line(fd, line, comment, name) != 1)
			return (check_next_line(fd, line, comment, name));
	}
	return (1);
}
