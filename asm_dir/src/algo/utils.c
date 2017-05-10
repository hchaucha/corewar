/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:57:12 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:57:14 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int				check_line(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		else if (s[i] == '.' || s[i] == '#' || s[i] == ';')
			return (1);
		else if (ft_stroccu(LABEL_CHARS, s[i]))
			return (0);
	}
	return (1);
}

char			*del_comment(const char *s)
{
	int		i;
	char	*tmp;
	char	*ret;

	i = 0;
	tmp = (char *)s;
	ret = NULL;
	while (tmp[i])
	{
		if (tmp[i] == '#' || tmp[i] == ';')
		{
			ret = ft_strsub(tmp, 0, i - 1);
			return (ret);
		}
		i++;
	}
	return (ft_strdup(s));
}

int				thanks_norm(char **tmp, t_tool *tool, char *str)
{
	int		nb;
	char	*temp;

	temp = ft_itoa_base(verif_spec(tool, str), 16);
	if (ft_strlen(temp) > 4 && tool->spec == 4)
		temp = ft_strsub_f(&temp, ft_strlen(temp) - 4, 4);
	else if (ft_strlen(temp) > 8 && tool->spec == 8)
		temp = ft_strsub_f(&temp, ft_strlen(temp) - 8, 8);
	*tmp = temp;
	nb = ft_strlen(*tmp);
	return (nb);
}
