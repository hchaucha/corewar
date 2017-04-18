/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:56:34 by atoupart          #+#    #+#             */
/*   Updated: 2017/04/10 20:56:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		place_champ(t_tool *tool)
{
	t_champ		*champ;
	int			i;
	int			n;
	int			color;

	champ = tool->champ;
	n = 0;
	color = 1;
	while (champ)
	{
		i = 0;
		tool->arena[n].here_process = 1;
		while (i < champ->nb_octet)
		{
			tool->arena[n].color = color;
			if (champ->file[i] < 0)
				tool->arena[n].value = 256 + champ->file[i++];
			else
				tool->arena[n].value = champ->file[i++];
			n++;
		}
		n += MEM_SIZE / tool->nb_champ - i;
		champ = champ->next;
		color++;
	}
}

t_process	*add_new_process(t_process *process, int pc, t_process *tmp)
{
	t_process		*new;
	static int		nb = 0;
	int				i;

	new = ft_memalloc(sizeof(t_process));
	new->cycle_to_wait = 0;
	new->pc = pc;
	new->num_process = ++nb;
	new->cycle_no_live = tmp->cycle_no_live;
	new->carry = tmp->carry;
	new->num_champ = tmp->num_champ;
	new->reg = ft_memalloc(sizeof(int) * REG_NUMBER);
	new->next = NULL;
	i = -1;
	while (++i < 16)
		new->reg[i] = tmp->reg[i];
	if (process == NULL)
		return (new);
	else
	{
		new->next = process;
		process = new;
	}
	return (process);
}

void		init_process(t_tool *tool)
{
	t_champ		*tmp;
	t_process	*tmp_pro;

	tmp_pro = ft_memalloc(sizeof(t_process));
	tmp_pro->pc = 0;
	tmp_pro->carry = 0;
	tmp_pro->cycle_no_live = 0;
	tmp_pro->reg = ft_memalloc(sizeof(int) * REG_NUMBER);
	tool->i = 0;
	tmp = tool->champ;
	while (tool->i < tool->nb_champ)
	{
		tmp_pro->reg[0] = tmp->id_champ;
		tool->i++;
		tmp_pro->num_champ = tool->i;
		tool->process = add_new_process(tool->process, tmp_pro->pc, tmp_pro);
		tmp_pro->pc += MEM_SIZE / tool->nb_champ;
		tmp = tmp->next;
	}
	free(tmp_pro->reg);
	free(tmp_pro);
}

void		del_process_suite(t_tool *tool, t_process *tmp,
				t_process *to_del, int ctd)
{
	t_process	*tmp2;

	if (tmp->next == NULL)
	{
		if (tool->opt.cycle)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			to_del->num_process, to_del->cycle_no_live, ctd);
		free(tmp->reg);
		free(tmp);
		tmp = NULL;
	}
	else
	{
		if (tool->opt.cycle)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			to_del->num_process, to_del->cycle_no_live, ctd);
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		free(tmp2->reg);
		free(tmp2);
	}
}

t_process	*del_process(t_tool *tool, t_process *process,
	t_process *to_del, int ctd)
{
	t_process	*tmp;

	tmp = process;
	if (to_del == tmp)
	{
		if (tool->opt.cycle)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				to_del->num_process, to_del->cycle_no_live, ctd);
		free(tmp->reg);
		free(tmp);
		return ((process = process->next));
	}
	while (tmp->next != to_del)
		tmp = tmp->next;
	del_process_suite(tool, tmp, to_del, ctd);
	return (process);
}
