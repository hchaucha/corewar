/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:56:02 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:56:04 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int					get_length_label(t_tool *tool, int begin_instr,
					char **tmp, char *label)
{
	long long int	len;
	t_label			*s;
	int				i;

	s = tool->label;
	i = 0;
	while (label[i] && label[i] != ',')
		i++;
	label = ft_strsub(label, 0, i);
	while (ft_strcmp(label, s->name_label))
		s = s->next;
	if (begin_instr > 0)
		begin_instr -= 1;
	len = s->adresse_label - begin_instr;
	if (len < 0 && tool->spec == 8)
		len = 4294967296 + len;
	else if (len < 0 && tool->spec == 4)
		len = 65536 + len;
	*tmp = ft_itoa_base(len, 16);
	len = ft_strlen(*tmp);
	free(label);
	return (len);
}

int					write_reg(t_tool *tool, char *str)
{
	int				i;

	i = ft_atoi(str);
	ft_putchar_fd(i, tool->fd);
	return (1);
}

int					write_ind(t_tool *tool, char *str, int begin_instr)
{
	int				len;
	char			*tmp;

	if (str[0] == ':')
		len = 4 - get_length_label(tool, begin_instr, &tmp, str + 1);
	else
		len = 4 - thanks_norm(&tmp, tool, str);
	if (ft_strlen(tmp) > 8)
		tmp = ft_strsub_f(&tmp, ft_strlen(tmp) - 4, 4);
	get_hexa_char(tmp, 2, tool->fd);
	return (2);
}

int					write_dir(t_tool *tool, char *str, int begin_instr)
{
	char			*tmp;
	int				len;
	int				i;

	i = 0;
	if (str[1] == ':')
		len = tool->spec - get_length_label(tool, begin_instr, &tmp, str + 2);
	else
		len = tool->spec - thanks_norm(&tmp, tool, str + 1);
	if (ft_strlen(tmp) > 4 && tool->spec == 4)
		tmp = ft_strsub_f(&tmp, ft_strlen(tmp) - tool->spec, tool->spec);
	else if (ft_strlen(tmp) > 8 && tool->spec == 8)
		tmp = ft_strsub_f(&tmp, ft_strlen(tmp) - tool->spec, tool->spec);
	get_hexa_char(tmp, tool->spec / 2, tool->fd);
	return (tool->spec / 2);
}

long long int		verif_spec(t_tool *tool, char *str)
{
	long long int	nb;

	nb = ft_atoi(str);
	if (tool->spec == 4 && nb > 4294967296)
		nb = 65535;
	else if (nb < 0)
		nb = 4294967296 + nb;
	return (nb);
}
