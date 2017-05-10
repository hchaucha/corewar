/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:23:54 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/15 10:12:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		parse_comment(int *comment, int fd, char **line, int *ret)
{
	*comment = check_name_comment(fd, line);
	if (*comment == 0)
		*ret = 2;
	if (*comment == 2)
		*ret = 6;
	if (*comment == 3)
		*ret = 7;
	return (*comment);
}

int		begin_parse(int fd, t_lab_check **list, t_reg **list_reg)
{
	int		comment;
	char	*line;
	int		ret;
	int		empty;

	ret = 1;
	comment = 0;
	empty = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!comment && parse_comment(&comment, fd, &line, &ret) != 1)
			return (ret);
		if (check_operand(line, list, list_reg, &empty) != 1)
		{
			ret = 4;
			break ;
		}
		free(line);
	}
	if (!empty)
		ret = 6;
	if (ret == 1 && !match_label(list, list_reg))
		ret = 4;
	return (ret);
}

int		check_entry(int *fd, int ac, char **av)
{
	char	*line;

	line = NULL;
	if (ac < 2)
		exit(status(0));
	else if ((*fd = open(av[ac - 1], O_RDONLY)) == -1)
	{
		ft_printf(C_RED"Can't read source file '%s'\n", av[ac - 1], C_NONE);
		return (1);
	}
	else if (!(av[ac - 1][ft_strlen(av[ac - 1]) - 1] == 's' &&
			av[ac - 1][ft_strlen(av[ac - 1]) - 2] == '.'))
	{
		ft_printf(C_RED"file '%s' is not a .s\n", av[ac - 1], C_NONE);
		return (1);
	}
	else if (!get_next_line(open(av[ac - 1], O_RDONLY), &line))
	{
		free(line);
		status(6);
		return (1);
	}
	free(line);
	return (0);
}

int		check_newline(char *file, int fd)
{
	int		file_len;
	int		ret;
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];

	fd = open(file, O_RDONLY);
	file_len = 0;
	while ((ret = read(fd, buffer, 1)) > 0)
		file_len += ret;
	file = (char *)malloc(sizeof(char) * file_len + 1);
	*(file + file_len) = '\0';
	lseek(fd, 0, SEEK_SET);
	read(fd, file, file_len);
	tmp = ft_strrchr(file, '\n');
	free(file);
	if (!end_line(tmp, 1))
		return (0);
	return (1);
}

int		parse(int ac, char **av)
{
	int			fd;
	char		*line;
	int			ret;
	t_lab_check	*list;
	t_reg		*list_reg;

	ret = 0;
	list = NULL;
	list_reg = NULL;
	line = NULL;
	fd = 0;
	if (check_entry(&fd, ac, av))
		status(3);
	else if (check_newline(av[ac - 1], fd) == 0)
		status(8);
	else
		status(ret = begin_parse(fd, &list, &list_reg));
	free(line);
	free_list(&list, &list_reg);
	return (ret);
}
