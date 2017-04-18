/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/04 18:54:20 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			before_while(char **str, char **line)
{
	char *tmp;

	if (*str && (tmp = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, tmp - *str);
		*str = ft_strsub_f(str, tmp + 1 - *str, (*str + ft_strlen(*str)) - tmp);
		return (1);
	}
	*line = NULL;
	return (0);
}

int			inside_while(int ret, char **buf, char **str, char **line)
{
	char *tmp;

	buf[0][ret] = '\0';
	*str = ft_strjoin_f(str, *buf);
	if ((tmp = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, tmp - *str);
		*str = ft_strsub_f(str, tmp + 1 - *str, (*str + ft_strlen(*str)) - tmp);
		ft_strdel(buf);
		return (1);
	}
	else if (ret != BUFF_SIZE)
	{
		*line = ft_strdup_f(str);
		ft_strdel(buf);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buf;
	static char		*str[OPEN_MAX];

	if (line == NULL || fd < 0)
		return (-1);
	if (before_while(&(str[fd]), line))
		return (1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if (str[fd] && inside_while(ret, &buf, &(str[fd]), line))
			return (1);
	ft_strdel(&buf);
	if (str[fd] && ret == 0 && *str[fd] != '\n' && *str[fd] != '\0')
	{
		*line = ft_strdup_f(&str[fd]);
		return (1);
	}
	if (ret == -1)
		return (-1);
	ft_strdel(&str[fd]);
	return (0);
}
