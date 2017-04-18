/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:25:10 by nlagache          #+#    #+#             */
/*   Updated: 2017/02/09 11:37:52 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define C_BLUE	"\033[34m"
# define C_YEL	"\033[33m"
# define C_RED	"\033[31m"
# define C_NONE	"\033[0m"
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# include "../../libft/libft.h"

typedef struct			s_tool
{
	char				**file;
	int					nb_label;
	struct s_label		*label;
	int					nb_instr;
	char				**instr;
	int					**arg_ocp;
	int					*ocp;
	int					*op;
	int					nb_octet;
	int					fd;
	int					spec;
}						t_tool;

typedef struct			s_written
{
	int					nb_written;
	int					to_write;
	int					param[3];
	int					len;
	int					i;
	char				*tmp;
	char				*tmp2;
}						t_written;

typedef struct			s_label
{
	char				*name_label;
	int					nb_pre;
	int					adresse_label;
	struct s_label		*next;
}						t_label;

typedef struct			s_lab_check
{
	struct s_lab_check	*prev;
	struct s_lab_check	*next;
	char				*label_name;
	char				*reg_label_name;
}						t_lab_check;

typedef struct			s_reg
{
	struct s_reg		*prev;
	struct s_reg		*next;
	char				*reg_label_name;
}						t_reg;

/*
** *****************************************************************************
**				directory : Parsing
** *****************************************************************************
*/

int						parse(int ac, char **av);
int						check_name_comment(int fd, char **line);
int						check_valid_param(char *line, char *str, int r,
						t_reg **list_reg);
int						check_operand(char *line, t_lab_check **list,
						t_reg **list_reg, int *empty);
int						check_live_zjmp_lfork(char *line, char *str,
						t_reg **list_reg);
int						check_ld_lld(char *line, char *str, t_reg **list_reg);
int						check_st(char *line, char *str, t_reg **list_reg);
int						check_add_sub(char *line, char *str);
int						check_and_or_xor(char *line, char *str,
						t_reg **list_reg);
int						check_ldi(char *line, char *str, t_reg **list_reg);
int						check_sti(char *line, char *str, t_reg **list_reg);
int						check_lldi(char *line, char *str, t_reg **list_reg);
int						check_aff(char *line, char *str);
int						check_reg(char *line, int *i, int end);
int						check_dir(char *line, int *i, int end,
						t_reg **list_reg);
int						check_ind(char *line, int *i, int end,
						t_reg **list_reg);
int						check_label(char *line, char *str, t_reg **list_reg);
void					save_label(char *str, t_lab_check **list);
int						check_if_reg_label(char *line, t_reg **list_reg,
						int **i, int end);
void					save_reg_label(char *str, t_reg **list_reg);
int						match_label(t_lab_check **list, t_reg **list_reg);
char					*search_word(char *line);
int						label_char(char *s1);
int						strclen(char *s1, char s2);
int						diez(char *s1);
int						search_virg(char *s1, int i);
int						end_line(char *s1, int i);
int						allowed(char *s1, int i);
int						status(int i);
void					epur_space(char *line, int *i, int virg);
int						ft_space_tab_str(char *s, char *value, int name);
int						ft_space_tab_newline(char *s);
int						ft_space_tab(char *s);
void					free_list(t_lab_check **list, t_reg **list_reg);

/*
** *****************************************************************************
**				directory : Algo
** *****************************************************************************
*/

/*
**						algo.c
*/

void					algo(int ac, char **av, t_tool *tool);

/*
**						stock_file.c
*/

void					stock_file(int ac, char **av, t_tool *tool);

/*
**						get_nb_label_in_str.c
*/

int						exists_label(const char *s, t_label *label);
int						get_nb_label(const char *s, t_tool *tool, int i, int n);
void					get_nb_label_instr(t_tool *tool);
char					*get_occurence_instr_bis(const char *s,
						char *(*f)(const char *, const char *));
char					*get_occurence_instr(const char *s,
						char *(*f)(const char *, const char *));

/*
**						add_to_labellst.c
*/

void					add_to_labellst(t_label **lst, const char *s, int pre);
t_label					*new_labellst(const char *s, int pre);
t_label					*del_labellst(t_label *lst);

/*
**						init.c
*/

void					init_struct(t_tool *tool);

/*
**						utils.c
*/

int						check_line(const char *s);
char					*del_comment(const char *s);
int						thanks_norm(char **tmp, t_tool *tool, char *str);

/*
**						get_hexa.c
*/

int						print_final(int len, int hexa, int fd);
void					get_hexa_int(intmax_t nb, int nb_octet, int fd);
void					get_hexa_char(char *str, int nb_octet, int fd);

/*
**						create_tab_instruction.c
*/

int						get_op_code(const char *s);
int						get_op_code_bis(const char *s);
int						calc_diff(char *tmp, char *tmp2);
void					create_tab_instruction(t_tool *tool);

/*
**						get_ocp_index.c
*/

int						get_number_index(char *tmp, int *tab);
void					get_ocp_index(t_tool *tool);

/*
**						get_label_index.c
*/

int						search_octet_instr_bis(const char *s, char *(*f)
						(const char *, const char *, size_t), t_tool *tool,
						int i);
int						search_octet_instr(const char *s, char *(*f)
						(const char *, const char *, size_t), t_tool *tool,
						int i);
int						get_octet_instr(t_tool *tool, int i, int dir);
void					get_label_index(t_tool *tool);

/*
**						get_value_param.c
*/

int						get_length_label(t_tool *tool,
						int total, char **tmp, char *label);
int						write_reg(t_tool *tool, char *str);
int						write_dir(t_tool *tool, char *str, int b_i);
int						write_ind(t_tool *tool, char *str, int b_i);
long long int			verif_spec(t_tool *tool, char *str);

/*
**						create_cor_file.c
*/

char					*get_good_path(char *s);
void					write_core_file(t_tool *tool);
void					create_cor_file(t_tool *tool, int ac, char **av);

/*
**						print_cor_head.c
*/

void					print_name(t_tool *tool, const char *s);
void					print_comment(t_tool *tool, const char *s);

/*
**						print_cor_instr.c
*/

int						print_fd(t_tool *tool, int nb);
void					print_instr(t_tool *tool, int i, int total_written);

/*
**						instructions.c
*/

int						live(t_tool *tool, int instr, int total);
int						ld(t_tool *tool, int instr, int total);
int						st(t_tool *tool, int instr, int total);
int						add(t_tool *tool, int instr, int total);

/*
**						instructions2.c
*/

int						sub(t_tool *tool, int instr, int total);
int						i_and(t_tool *tool, int instr, int total);
int						i_or(t_tool *tool, int instr, int total);
int						i_xor(t_tool *tool, int instr, int total);

/*
**						instructions3.c
*/

int						zjmp(t_tool *tool, int instr, int total);
int						ldi(t_tool *tool, int instr, int total);
int						sti(t_tool *tool, int instr, int total);
int						i_fork(t_tool *tool, int instr, int total);

/*
**						instructions4.c
*/

int						lld(t_tool *tool, int instr, int total);
int						lldi(t_tool *tool, int instr, int total);
int						lfork(t_tool *tool, int instr, int total);
int						aff(t_tool *tool, int instr, int total);

/*
**						free_things.c
*/

void					free_things(t_tool *tool);

#endif
