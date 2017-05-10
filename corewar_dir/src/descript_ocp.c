/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descript_ocp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:26:41 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 13:26:43 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int			math_this(t_tool *tool, int nb_param, int ocp, char **s)
{
	int len;

	len = 0;
	tool->i = 0;
	ft_bzero_tab(tool->param, 4);
	ft_bzero_tab(tool->type_arg, 4);
	if (ocp)
		*s = ft_itoa_base(ocp, 2);
	if (!ocp || (len = ft_strlen(*s) - 2) < (7 - (2 * nb_param)))
		return (0);
	len -= (2 * (3 - nb_param));
	return (len);
}

int			is_register(t_tool *tool, int p)
{
	tool->param[p] = 1;
	tool->type_arg[p] = 1;
	tool->i++;
	return (1);
}

int			descript_ocp(t_tool *t, int ocp, int nb_param, int label_size)
{
	char	*s;
	int		len;
	int		total_size;
	int		p;

	s = NULL;
	p = 1;
	total_size = 0;
	len = math_this(t, nb_param, ocp, &s);
	if (len % 2 != 0 && (total_size += is_register(t, p)))
		p++;
	while (p <= nb_param && t->i < len)
	{
		if (s[t->i] == '1' && s[t->i + 1] == '0' && (t->type_arg[p] = 3))
			t->param[p] = label_size;
		else if (s[t->i] == '1' && s[t->i + 1] == '1' && (t->type_arg[p] = 2))
			t->param[p] = 2;
		else if (s[t->i] == '0' && s[t->i + 1] == '1' && (t->type_arg[p] = 1))
			t->param[p] = 1;
		total_size += t->param[p];
		p++;
		t->i += 2;
	}
	free(s);
	return (total_size);
}
