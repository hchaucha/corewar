/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:21:59 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 20:22:03 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	inside_op_ldi(t_tool *t, t_process *p, t_instr trash)
{
	if (t->opt.verbose)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", p->num_process, trash.one,
			trash.two, trash.three);
		ft_printf("%6s | -> load from %d + %d = %d (with pc and mod %d)\n", " ",
			trash.one, trash.two, trash.one + trash.two, (p->pc +
				((trash.one + trash.two) % IDX_MOD) % MEM_SIZE));
	}
	p->reg[trash.three - 1] = get_param_hexa_b((p->pc +
		neg_ind(trash.one + trash.two, 1)) % MEM_SIZE, t);
}

int		op_ldi(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 3, 2);
	if (!t->type_arg[2] || t->type_arg[2] == 2 || t->type_arg[3] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.error_reg = t->type_arg[1] == 1 && (trash.one < 1 ||
		trash.one > REG_NUMBER) ? 1 : 0;
	trash.one = t->type_arg[1] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.one, 1)) % MEM_SIZE, 4) : trash.one;
	trash.one = t->type_arg[1] == 1 ? p->reg[trash.one - 1] : trash.one;
	trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, t->param[2]);
	trash.error_reg += t->type_arg[2] == 1 && (trash.two < 1 ||
		trash.two > REG_NUMBER) ? 1 : 0;
	trash.two = t->type_arg[2] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.two, 1)) % MEM_SIZE, 4) : trash.two;
	trash.two = t->type_arg[2] == 1 ? p->reg[trash.two - 1] : trash.two;
	trash.three = get_param(t, (p->pc + 2 + t->param[1] + t->param[2])
		% MEM_SIZE, 1);
	trash.error_reg += (trash.three < 1 || trash.three > REG_NUMBER) ? 1 : 0;
	if (trash.error_reg > 0)
		return (3 + t->param[1] + t->param[2]);
	inside_op_ldi(t, p, trash);
	return (3 + t->param[1] + t->param[2]);
}

int		inside_op_sti(t_tool *t, t_process *p, t_instr trash, int *tab)
{
	if (trash.error_reg > 0)
	{
		free(tab);
		return (3 + t->param[2] + t->param[3]);
	}
	trash.tmp = t->param[2];
	t->param[2] = (trash.two + trash.three) % IDX_MOD;
	apply_param(t, p->pc, tab, p->num_champ);
	free(tab);
	if (t->opt.verbose)
	{
		ft_printf("P %4d | sti r%d %d %d\n", p->num_process, trash.one,
			trash.two, trash.three);
		ft_printf("%6s | -> store to %d + %d = %d (with pc and mod %d)\n", " ",
			trash.two, trash.three, trash.two + trash.three, (p->pc +
				((trash.two + trash.three) % IDX_MOD) % MEM_SIZE));
	}
	return (3 + trash.tmp + t->param[3]);
}

int		op_sti(t_tool *t, t_process *p)
{
	t_instr		trash;
	int			*tab;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 3, 2);
	if (t->type_arg[1] != 1 || !t->type_arg[2] ||
		t->type_arg[3] == 2 || !t->type_arg[3])
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, 1);
	trash.error_reg = (trash.one < 1 || trash.one > REG_NUMBER) ? 1 : 0;
	tab = get_param_hexa(t, trash.one - 1, p->reg);
	trash.two = get_param(t, (p->pc + 3) % MEM_SIZE, t->param[2]);
	trash.error_reg += t->type_arg[2] == 1 && (trash.two < 1 ||
		trash.two > REG_NUMBER) ? 1 : 0;
	trash.two = t->type_arg[2] == 1 ? p->reg[trash.two - 1] : trash.two;
	trash.two = t->type_arg[2] == 2 ? get_param(t, (p->pc +
		(trash.two % IDX_MOD)) % MEM_SIZE, 4) : trash.two;
	trash.three = get_param(t, (p->pc + 3 + t->param[2])
		% MEM_SIZE, t->param[3]);
	trash.error_reg += t->type_arg[3] == 1 && (trash.three < 1 ||
		trash.three > REG_NUMBER) ? 1 : 0;
	trash.three = t->type_arg[3] == 1 ? p->reg[trash.three - 1] : trash.three;
	trash.three = t->type_arg[3] == 3 ? get_param(t, (p->pc + 3 + t->param[2])
		% MEM_SIZE, 2) : trash.three;
	return (inside_op_sti(t, p, trash, tab));
}
