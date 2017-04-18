/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_label_instr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:55:42 by atoupart          #+#    #+#             */
/*   Updated: 2017/02/23 12:55:44 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char			*get_occurence_instr(const char *s,
	char *(*f)(const char *, const char *))
{
	char	*tmp;

	if ((tmp = (f)(s, "zjmp")) && (tmp[4] == ' '
		|| tmp[4] == '\t' || tmp[4] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "lldi")) && (tmp[4] == ' '
		|| tmp[4] == '\t' || tmp[4] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "sti")) && (tmp[3] == ' ' || tmp[3] == '\t'))
		return (tmp);
	else if ((tmp = (f)(s, "lfork")) && (tmp[5] == ' '
		|| tmp[5] == '\t' || tmp[5] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "ldi")) && (tmp[3] == ' ' || tmp[3] == '\t'))
		return (tmp);
	else if ((tmp = (f)(s, "lld")) && (tmp[3] == ' '
		|| tmp[3] == '\t' || tmp[3] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "fork")) && (tmp[4] == ' '
		|| tmp[4] == '\t' || tmp[4] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "live")) && (tmp[4] == ' '
		|| tmp[4] == '\t' || tmp[4] == '%'))
		return (tmp);
	return (get_occurence_instr_bis(s, *f));
}

char			*get_occurence_instr_bis(const char *s,
	char *(*f)(const char *, const char *))
{
	char	*tmp;

	if ((tmp = (f)(s, "aff")) && (tmp[3] == ' ' || tmp[3] == '\t'))
		return (tmp);
	else if ((tmp = (f)(s, "ld")) && (tmp[2] == ' '
		|| tmp[2] == '\t' || tmp[2] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "st")) && (tmp[2] == ' ' || tmp[2] == '\t'))
		return (tmp);
	else if ((tmp = (f)(s, "add")) && (tmp[3] == ' ' || tmp[3] == '\t'))
		return (tmp);
	else if ((tmp = (f)(s, "sub")) && (tmp[3] == ' '
		|| tmp[3] == '\t' || tmp[3] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "and")) && (tmp[3] == ' '
		|| tmp[3] == '\t' || tmp[3] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "xor")) && (tmp[3] == ' '
		|| tmp[3] == '\t' || tmp[3] == '%'))
		return (tmp);
	else if ((tmp = (f)(s, "or")) && (tmp[2] == ' '
		|| tmp[2] == '\t' || tmp[2] == '%'))
		return (tmp);
	else
		return (NULL);
}

int				exists_label(const char *s, t_label *label)
{
	t_label		*tmp;

	tmp = label;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name_label, s))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				get_nb_label(const char *s, t_tool *tool, int i, int n)
{
	char		*tmp;

	while (s[++i])
	{
		if (s[i] == ':' && ft_stroccu(LABEL_CHARS, s[i - 1]))
		{
			while (s[n] == ' ' || s[n] == '\t')
				n++;
			tmp = NULL;
			tmp = ft_strsub(s, n, i);
			if (!exists_label(tmp, tool->label))
			{
				tool->nb_label += 1;
				add_to_labellst(&tool->label, tmp, tool->nb_instr);
				free(tmp);
				return (i);
			}
			else
			{
				free(tmp);
				return (i);
			}
		}
	}
	return (0);
}

void			get_nb_label_instr(t_tool *tool)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	while (tool->file[i] != NULL)
	{
		if (check_line(tool->file[i]))
			i++;
		else
		{
			tmp = NULL;
			tmp = del_comment(tool->file[i]);
			n = get_nb_label(tmp, tool, -1, 0);
			tool->nb_instr += (get_occurence_instr(tmp + n, ft_strstr)) ? 1 : 0;
			free(tmp);
			i++;
		}
	}
}
