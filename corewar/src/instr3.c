/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:21:59 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 20:22:03 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	inside_op_or(t_tool *t, t_process *p, t_instr trash)
{
	if (!(p->reg[trash.three - 1] = trash.one | trash.two))
		p->carry = 1;
	else
		p->carry = 0;
	if (t->opt.verbose)
		ft_printf("P %4d | or %d %d r%d\n", p->num_process, trash.one,
			trash.two, trash.three);
}

int		op_or(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 3, 4);
	if (!t->type_arg[2] || t->type_arg[3] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.error_reg = t->param[1] == 1 && (trash.one < 1 ||
		trash.one > REG_NUMBER) ? 1 : 0;
	trash.one = t->param[1] == 1 ? p->reg[trash.one - 1] : trash.one;
	trash.one = t->param[1] == 2 ? get_param(t, (p->pc + neg_ind(trash.one, 1))
		% MEM_SIZE, 4) : trash.one;
	trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, t->param[2]);
	trash.error_reg += t->param[2] == 1 && (trash.two < 1 ||
		trash.two > REG_NUMBER) ? 1 : 0;
	trash.two = t->param[2] == 1 ? p->reg[trash.two - 1] : trash.two;
	trash.two = t->param[2] == 2 ? get_param(t, (p->pc + neg_ind(trash.two, 1))
		% MEM_SIZE, 4) : trash.two;
	trash.three = get_param(t, (p->pc + 2 + t->param[1] + t->param[2]) %
		MEM_SIZE, t->param[3]);
	trash.error_reg += (trash.three < 1 || trash.three > REG_NUMBER) ? 1 : 0;
	if (trash.error_reg > 0)
		return (3 + t->param[1] + t->param[2]);
	inside_op_or(t, p, trash);
	return (3 + t->param[1] + t->param[2]);
}

void	inside_op_xor(t_tool *t, t_process *p, t_instr trash)
{
	if (!(p->reg[trash.three - 1] = trash.one ^ trash.two))
		p->carry = 1;
	else
		p->carry = 0;
	if (t->opt.verbose)
		ft_printf("P %4d | xor %d %d r%d\n", p->num_process, trash.one,
			trash.two, trash.three);
}

int		op_xor(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 3, 4);
	if (!t->type_arg[2] || t->type_arg[3] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.error_reg = t->param[1] == 1 && (trash.one < 1 ||
		trash.one > REG_NUMBER) ? 1 : 0;
	trash.one = t->param[1] == 1 ? p->reg[trash.one - 1] : trash.one;
	trash.one = t->param[1] == 2 ? get_param(t, (p->pc + neg_ind(trash.one, 1))
		% MEM_SIZE, 4) : trash.one;
	trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, t->param[2]);
	trash.error_reg += t->param[2] == 1 && (trash.two < 1 ||
		trash.two > REG_NUMBER) ? 1 : 0;
	trash.two = t->param[2] == 1 ? p->reg[trash.two - 1] : trash.two;
	trash.two = t->param[2] == 2 ? get_param(t, (p->pc + neg_ind(trash.two, 1))
		% MEM_SIZE, 4) : trash.two;
	trash.three = get_param(t, (p->pc + 2 + t->param[1] + t->param[2])
		% MEM_SIZE, t->param[3]);
	trash.error_reg += (trash.three < 1 || trash.three > REG_NUMBER) ? 1 : 0;
	if (trash.error_reg > 0)
		return (3 + t->param[1] + t->param[2]);
	inside_op_xor(t, p, trash);
	return (3 + t->param[1] + t->param[2]);
}

int		op_zjmp(t_tool *t, t_process *p)
{
	t_instr		trash;

	trash.tmp = get_param(t, (p->pc + 1) % MEM_SIZE, 2);
	if (p->carry == 0)
	{
		if (t->opt.verbose)
			ft_printf("P %4d | zjmp %d FAILED\n", p->num_process, trash.tmp);
		return (3);
	}
	if (t->opt.verbose)
		ft_printf("P %4d | zjmp %d OK\n", p->num_process, trash.tmp);
	return (neg_ind(trash.tmp, 1));
}
