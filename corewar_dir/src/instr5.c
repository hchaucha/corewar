/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:21:59 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 20:22:03 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	inside_op_fork(t_instr trash, t_process *p, t_tool *t, int tmp)
{
	trash.one = trash.one % IDX_MOD;
	t->process = add_new_process(t->process, (p->pc + trash.one) % MEM_SIZE, p);
	if (t->opt.verbose)
		ft_printf("P %4d | fork %d (%d)\n", p->num_process, tmp,
			(p->pc + trash.one) % MEM_SIZE);
}

int		op_fork(t_tool *t, t_process *p)
{
	t_instr		trash;
	int			tmp;

	trash.one = get_param(t, (p->pc + 1) % MEM_SIZE, 2);
	tmp = trash.one;
	if (trash.one < 0)
	{
		trash.one *= -1;
		trash.one = trash.one % IDX_MOD;
		trash.tmp = -trash.one;
		trash.one = (4096 - trash.one);
		t->process = add_new_process(t->process, (p->pc + trash.one)
			% MEM_SIZE, p);
		if (t->opt.verbose)
			ft_printf("P %4d | fork %d (%d)\n", p->num_process, tmp,
				p->pc + trash.tmp);
	}
	else
		inside_op_fork(trash, p, t, tmp);
	return (3);
}

int		op_lld(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 2, 4);
	if (t->type_arg[1] == 1 || t->type_arg[2] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.one = t->type_arg[1] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.one, 0)) % MEM_SIZE, 2) : trash.one;
	if ((trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, 1)) < 1
		|| trash.two > REG_NUMBER)
		return (3 + t->param[1]);
	if (!(p->reg[trash.two - 1] = trash.one))
		p->carry = 1;
	else
		p->carry = 0;
	if (t->opt.verbose)
		t->param[1] == 1 ? ft_printf("P %4d | lld r%d r%d\n", p->num_process,
			trash.one, trash.two) : ft_printf("P %4d | lld %d r%d\n",
				p->num_process, trash.one, trash.two);
	return (3 + t->param[1]);
}

void	inside_lldi(t_tool *t, t_process *p, t_instr trash)
{
	if (t->opt.verbose)
	{
		ft_printf("P %4d | lldi %d %d r%d\n", p->num_process, trash.one,
			trash.two, trash.three);
		ft_printf("%6s | -> load from %d + %d = %d (with pc %d)\n", " ",
			trash.one, trash.two, trash.one + trash.two, p->pc +
				trash.one + trash.two);
	}
	if ((p->reg[trash.three - 1] = get_param_hexa_b((p->pc +
		neg_ind(trash.one + trash.two, 0)) % MEM_SIZE, t)) == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

int		op_lldi(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 3, 2);
	if (!t->type_arg[2] || t->type_arg[2] == 2 || t->type_arg[3] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.error_reg = t->type_arg[1] == 1 && (trash.one < 1 ||
		trash.one > REG_NUMBER) ? 1 : 0;
	trash.one = t->type_arg[1] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.one, 0)) % MEM_SIZE, 4) : trash.one;
	trash.one = t->type_arg[1] == 1 ? p->reg[trash.one - 1] : trash.one;
	trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, t->param[2]);
	trash.error_reg += t->type_arg[2] == 1 &&
		(trash.two < 1 || trash.two > REG_NUMBER) ? 1 : 0;
	trash.two = t->type_arg[2] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.two, 0)) % MEM_SIZE, 4) : trash.two;
	trash.two = t->type_arg[2] == 1 ? p->reg[trash.two - 1] : trash.two;
	trash.three = get_param(t, (p->pc + 2 + t->param[1] + t->param[2])
		% MEM_SIZE, 1);
	trash.error_reg += (trash.three < 1 || trash.three > REG_NUMBER) ? 1 : 0;
	if (trash.error_reg > 0)
		return (3 + t->param[1] + t->param[2]);
	inside_lldi(t, p, trash);
	return (3 + t->param[1] + t->param[2]);
}
