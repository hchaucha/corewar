/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:27:13 by nlagache          #+#    #+#             */
/*   Updated: 2017/04/12 11:27:16 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define C_BLUE		"\033[34m"
# define C_YEL		"\033[33m"
# define C_RED		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_NONE		"\033[0m"
# define C_BROWN	"\033[38;5;208m"
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# include "op.h"
# include <ncurses.h>
# include "../../libft/libft.h"
# define KEY_PAUSE 	32
# define KEY_ESC	27

typedef struct			s_process
{
	int					*reg;
	int					pc;
	int					carry;
	int					value_op;
	int					num_champ;
	int					num_process;
	int					cycle_no_live;
	int					cycle_to_wait;
	int					live;
	struct s_process	*next;
}						t_process;

typedef struct			s_cycle
{
	int					cycle_to_die;
	int					cycle;
	int					nbr_live;
	int					max_checks;
	int					key;
	int					sleep;
}						t_cycle;

typedef struct			s_mem
{
	int					value;
	int					color;
	int					here_process;
}						t_mem;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	int					id_champ;
	int					nb_octet;
	int					live_on;
	char				*file;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_trash
{
	char				*name;
	char				*comment;
	int					id_champ;
	char				*file;
	int					nb_octet;
}						t_trash;

typedef struct			s_opt
{
	int					ncurse;
	int					verbose;
	int					dump_close;
	int					dump_break;
	int					cycle;
	int					jump;
}						t_opt;

typedef struct			s_instr
{
	int					one;
	int					two;
	int					three;
	int					tmp;
	int					error_reg;
}						t_instr;

typedef struct			s_tool
{
	int					nb_champ;
	t_opt				opt;
	t_mem				*arena;
	t_process			*process;
	struct s_champ		*champ;
	int					*param;
	int					*type_arg;
	int					add;
	int					i;
	int					total_cycle;
	int					ret;
}						t_tool;

/*
**			#################################################
**			#####				FONCTIONS			   #####
**			#################################################
*/

/*
**						main.c
*/

void					begining_ending(t_tool *tool);
int						main(int ac, char **av);

/*
**						go_corewar.c
*/

int						change_time(int key, int sleep);
void					make_option(t_tool *t, t_cycle *go);
void					kill_process(t_tool *tool, t_cycle *go);
void					end_cycle(t_tool *tool, t_cycle *go);
void					go_corewar(t_tool *tool);

/*
**						make_process.c
*/

void					give_cycle_to_wait(t_process *tmp, int value_op);
int						make_instr(t_tool *t, t_process *tmp, int total_live);
int						make_process(t_tool *tool);

/*
**						parse.c
*/

t_mem					*init_memory(void);
void					parsing(int ac, char **av, t_tool *tool);
void					init_tool(t_tool *tool);
void					initialisation(int ac, char **av, t_tool *tool);

/*
**						champlst.c
*/

t_champ					*new_champlst(t_trash *trash);
void					add_to_champlst(t_champ **lst, t_trash *trash);

/*
**						read_file.c
*/

void					verif_size_champs(t_champ *champ, int ret, int fd);
void					read_file(int fd, t_champ **champ, int id_champ);
char					*get_champion_file(char *file, int nb_octet,
						int i, int champ_len);
int						get_nb_octet(char *file, int i);
void					get_champion_header(char *file, int champ_len,
						t_champ **champ, int id_champ);

/*
**						utils_options.c
*/

void					color_stdout(int color);
void					init_option(t_opt *opt);
void					check_opt(t_tool *tool);
int						check_id_champ(t_tool *tool, int id_champ);
void					print_help(void);

/*
**						options.c
*/

int						verif_file_champ(char *str);
void					get_option_d(char **av, int *i, t_tool *tool);
void					get_option_s(char **av, int *i, t_tool *tool);
int						get_option_p(char **av, int *i, t_tool *tool,
						int *id_champ);
int						get_option(char **av, int *i, t_tool *tool,
						int *id_champ);

/*
**						display.c
*/

void					init_screen(void);
void					close_screen(void);
void					display_info_menu(t_tool *tool, int cycle_to_die,
						int sleep);
void					display_players_header(t_tool *tool);

/*
**						dump_memory.c
*/

void					the_dump(t_mem *arena, int i, char *tmp);
void					dump_memory_stdout(t_mem *arena, int on);
void					on_off(int on, t_mem *arena, int i);
int						the_dump_ncurse(char *tmp, int value, int line,
						int col);
void					dump_memory_ncurse(int i, t_mem *arena);

/*
**						memory.c
*/

void					place_champ(t_tool *tool);
t_process				*add_new_process(t_process *process, int pc,
						t_process *tmp);
void					init_process(t_tool *tool);
void					del_process_suite(t_tool *tool, t_process *tmp,
						t_process *to_del, int ctd);
t_process				*del_process(t_tool *tool, t_process *process,
						t_process *to_del, int ctd);

/*
**						param.c
*/

int						neg_ind(int num, int mod);
int						get_param(t_tool *tool, int pc, int to_read);
int						*get_param_hexa(t_tool *tool, int param, int *reg);
int						get_param_hexa_b(int param, t_tool *tool);
void					apply_param(t_tool *tool, int pc, int *tmp,
						int num_champ);

/*
**						descript_ocp.c
*/

int						math_this(t_tool *tool, int nb_param, int ocp,
						char **s);
int						is_register(t_tool *tool, int p);
int						descript_ocp(t_tool *tool, int ocp, int nb_param,
						int label_size);

/*
**						free_things.c
*/

void					free_things_2(t_tool *tool);
void					free_things(t_tool *tool);
void					free_trash(t_trash *trash);

/*
**						instr/2/3/4/5/6.c
*/

int						op_add(t_tool *tool, t_process *process);
int						op_aff(t_tool *tool, t_process *process);
int						op_and(t_tool *tool, t_process *process);
int						op_fork(t_tool *tool, t_process *process);
int						op_ld(t_tool *tool, t_process *process);
int						op_ldi(t_tool *tool, t_process *process);
int						op_lfork(t_tool *tool, t_process *process);
int						op_live(t_tool *tool, t_process *process);
int						op_lld(t_tool *tool, t_process *process);
int						op_lldi(t_tool *tool, t_process *process);
int						op_or(t_tool *tool, t_process *process);
int						op_st(t_tool *tool, t_process *process);
int						op_sti(t_tool *tool, t_process *process);
int						op_sub(t_tool *tool, t_process *process);
int						op_xor(t_tool *tool, t_process *process);
int						op_zjmp(t_tool *tool, t_process *process);

typedef struct			s_opfunc
{
	int					op;
	int					(*func)(t_tool *, t_process *);
}						t_opfunc;

static const t_opfunc	g_opfunc[] =
{
	{1, &op_live},
	{2, &op_ld},
	{3, &op_st},
	{4, &op_add},
	{5, &op_sub},
	{6, &op_and},
	{7, &op_or},
	{8, &op_xor},
	{9, &op_zjmp},
	{10, &op_ldi},
	{11, &op_sti},
	{12, &op_fork},
	{13, &op_lld},
	{14, &op_lldi},
	{15, &op_lfork},
	{16, &op_aff}
};

#endif
