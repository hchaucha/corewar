/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:43:20 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 15:43:21 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int			neg_ind(int num, int mod)
{
	if (mod && num < 0)
		num = 4096 - (-num % IDX_MOD);
	else if (!mod && num < 0)
		num = 4096 - (-num);
	else if (mod && num > 0)
		num %= IDX_MOD;
	return (num);
}

int			get_param(t_tool *tool, int pc, int to_read)
{
	int			i;
	int			ret;
	long int	sub;
	char		*tmp;
	char		*str;

	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	i = -1;
	while (++i < to_read)
	{
		tmp = ft_itoa_base(tool->arena[(pc + i) % MEM_SIZE].value, 16);
		if (tool->arena[(pc + i) % MEM_SIZE].value < 16)
			tmp = ft_straddnchar(tmp, 0, 1, '0');
		str = ft_strjoin_f(&str, tmp);
		free(tmp);
	}
	ft_str_toupper(&str);
	ret = ft_atoi_base(str, 16);
	ft_strdel(&str);
	sub = ft_pow(256, to_read);
	if (ret > (sub / 2))
		ret = ret - sub;
	return (ret);
}

int			*get_param_hexa(t_tool *t, int param, int *reg)
{
	char	*tmp;
	char	*tmp2;
	int		start;
	int		*tab;
	int		add_zero;

	tab = (int *)malloc(sizeof(int) * 4);
	if (reg[param] < 0)
		tmp = ft_itoa_base(4294967296 + reg[param], 16);
	else
		tmp = ft_itoa_base(reg[param], 16);
	if ((add_zero = 8 - (ft_strlen(tmp) % 8)) > 0 && ft_strlen(tmp) != 8)
		tmp = ft_straddnchar(tmp, 0, add_zero, '0');
	t->i = -1;
	start = 0;
	while (++t->i < 4)
	{
		tmp2 = ft_strsub(tmp, start, 2);
		ft_str_toupper(&tmp2);
		tab[t->i] = ft_atoi_base(tmp2, 16);
		start += 2;
		free(tmp2);
	}
	free(tmp);
	return (tab);
}

int			get_param_hexa_b(int param, t_tool *tool)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = -1;
	tmp2 = ft_strnew(1);
	while (++i < 4)
	{
		if (tool->arena[param + i].value < 0)
			tmp = ft_itoa_base(4294967296 + tool->arena[(param + i)
			% MEM_SIZE].value, 16);
		else
			tmp = ft_itoa_base(tool->arena[(param + i) % MEM_SIZE].value, 16);
		if (ft_strlen(tmp) == 1)
			tmp = ft_straddnchar(tmp, 0, 1, '0');
		tmp2 = ft_strjoin_f(&tmp2, tmp);
		free(tmp);
	}
	ft_str_toupper(&tmp2);
	i = ft_atoi_base(tmp2, 16);
	free(tmp2);
	return (i);
}

void		apply_param(t_tool *tool, int pc, int *tmp, int num_champ)
{
	int		neg;

	neg = 0;
	if (tool->param[2] < 0)
		neg = 4096;
	tool->i = -1;
	while (++tool->i < 4)
	{
		tool->arena[(neg + (tool->param[2] + pc + tool->i))
		% MEM_SIZE].value = tmp[tool->i];
		tool->arena[(neg + (tool->param[2] + pc + tool->i))
		% MEM_SIZE].color = num_champ;
	}
}
