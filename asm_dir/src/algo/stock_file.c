/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:25:31 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/10 15:25:34 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		stock_file(int ac, char **av, t_tool *tool)
{
	int		fd;
	char	*line;
	int		nb_line_file;
	int		i;

	fd = open(av[ac - 1], O_RDONLY);
	nb_line_file = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		nb_line_file++;
		free(line);
	}
	close(fd);
	tool->file = (char **)malloc(sizeof(char*) * (nb_line_file + 1));
	i = 0;
	fd = open(av[ac - 1], O_RDONLY);
	while (get_next_line(fd, &line))
		tool->file[i++] = ft_strdup_f(&line);
	tool->file[i] = NULL;
	close(fd);
}
