/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:54:55 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:54:58 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char		*get_good_path(char *s)
{
	char	*path;
	int		size_path;

	size_path = ft_strlen(s);
	path = ft_strnew(size_path + 2);
	ft_strncpy(path, s, size_path - 1);
	ft_strcpy(path + size_path - 1, "cor");
	return (path);
}

void		write_core_file(t_tool *tool)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (ft_strstr(tool->file[i], ".name") == NULL)
		i++;
	tmp = ft_strchr(tool->file[i], '"') + 1;
	print_name(tool, tmp);
	get_hexa_int(tool->nb_octet, 8, tool->fd);
	i = 0;
	while (ft_strstr(tool->file[i], ".comment") == NULL)
		i++;
	tmp = ft_strchr(tool->file[i], '"') + 1;
	print_comment(tool, tmp);
	print_instr(tool, 0, 0);
}

void		create_cor_file(t_tool *tool, int ac, char **av)
{
	char	*path;

	path = get_good_path(av[ac]);
	if ((tool->fd = open(path, O_TRUNC | O_WRONLY)) == -1)
		tool->fd = open(path, O_CREAT | O_WRONLY, 0644);
	free(path);
	write_core_file(tool);
}
