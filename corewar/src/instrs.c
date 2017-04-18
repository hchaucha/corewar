/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:19:58 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/09 11:20:01 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		inside_live(t_tool *t, t_process *p, t_champ *tmp)
{
	t_champ		*tmp2;

	p->live = 1;
	tmp2 = t->champ;
	while (tmp2)
	{
		if (tmp2->live_on == 1)
			tmp2->live_on = 0;
		tmp2 = tmp2->next;
	}
	tmp->live_on = 1;
	// if (!t->opt.ncurse && !t->opt.verbose &&
	// 	!t->opt.dump_close && !t->opt.dump_break)
	// 	ft_printf("Un processus dit que le joueur %d(%s) est en vie\n",
	// 		tmp->id_champ, tmp->name);
}

int			op_live(t_tool *t, t_process *p)
{
	t_champ		*tmp;
	t_instr		trash;

	trash.one = get_param(t, (p->pc + 1) % MEM_SIZE, 4);
	if (t->opt.verbose)
		ft_printf("P %4d | live %d\n", p->num_process, trash.one);
	tmp = t->champ;
	while (tmp)
	{
		if (trash.one == tmp->id_champ)
		{
			inside_live(t, p, tmp);
			return (5);
		}
		tmp = tmp->next;
	}
	p->live = 1;
	return (5);
}

int			op_ld(t_tool *t, t_process *p)
{
	t_instr		trash;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 2, 4);
	if (t->type_arg[1] == 1 || t->type_arg[2] != 1)
		return (t->ret + 2);
	trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, t->param[1]);
	trash.one = t->param[1] == 2 ? get_param(t, (p->pc +
		neg_ind(trash.one, 1)) % MEM_SIZE, 4) : trash.one;
	if ((trash.two = get_param(t, (p->pc + 2 + t->param[1]) % MEM_SIZE, 1)) < 1
		|| trash.two > REG_NUMBER)
		return (3 + t->param[1]);
	if (!(p->reg[trash.two - 1] = trash.one))
		p->carry = 1;
	else
		p->carry = 0;
	if (t->opt.verbose)
		ft_printf("P %4d | ld %d r%d\n", p->num_process, trash.one, trash.two);
	return (3 + t->param[1]);
}

int			inside_op_st(t_tool *t, t_instr trash, t_process *p, int *tab)
{
	if (trash.tmp == 1)
	{
		if (trash.two < 1 || trash.two > REG_NUMBER)
		{
			free(tab);
			return (4);
		}
		p->reg[trash.two - 1] = p->reg[trash.one - 1];
	}
	else
		apply_param(t, p->pc, tab, p->num_champ);
	free(tab);
	if (t->opt.verbose)
		t->param[1] == 2 ? ft_printf("P %4d | st r%d r%d\n", p->num_process,
			trash.one, trash.two) : ft_printf("P %4d | st r%d %d\n",
				p->num_process, trash.one, trash.two);
	return (0);
}

int			op_st(t_tool *t, t_process *p)
{
	t_instr	trash;
	int		*tab;

	t->ret = descript_ocp(t, t->arena[(p->pc + 1) % MEM_SIZE].value, 2, 4);
	if (t->type_arg[1] != 1 || t->type_arg[2] == 3 || !t->type_arg[2])
		return (t->ret + 2);
	if ((trash.one = get_param(t, (p->pc + 2) % MEM_SIZE, 1)) < 1
		|| trash.one > REG_NUMBER)
		return (3 + t->param[2]);
	tab = get_param_hexa(t, trash.one - 1, p->reg);
	trash.two = get_param(t, (p->pc + 3) % MEM_SIZE, t->param[2]);
	trash.tmp = t->param[2];
	t->param[2] = trash.two % IDX_MOD;
	if (inside_op_st(t, trash, p, tab) > 0)
		return (4);
	return (3 + trash.tmp);
}
