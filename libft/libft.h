/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:26:14 by atoupart          #+#    #+#             */
/*   Updated: 2017/03/09 18:30:25 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/syslimits.h>
# include <fcntl.h>
# include <wchar.h>
# include <stdarg.h>
# include <math.h>
# include <limits.h>
# include <sys/uio.h>

# define BUFF_SIZE 10
# define MAX_SIZE_BUFFER 8000000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	int				numb;
	struct s_list	*next;
	struct s_list	*pre;
}					t_list;

long int			ft_pow(int nb, int power);
int					ft_atoi_base(char *str, int base);
int					ft_size_number(int	nb);
char				*ft_strintercal(const char *s1, const char c,
					const char *s2);
char				*ft_strjoinfree(char const *s1, char const *s2, int i);
char				*ft_strndup(char *str, int n);
int					ft_error(char *str);
int					get_next_line(int const fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_bzero_tab(void *s, size_t n);
char				*ft_memdup(char *file, int i);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strdup_f(char **s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_ltoa(long long n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrstr(const char *s1, const char *s2);
int					ft_stroccu(const char *str, char c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long int		ft_atoi(const char *str);
int					ft_atoi_b(const char *str, int base);
int					ft_ishexa(char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isnumber(const char *s);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_str_tolower(char **str);
void				ft_str_toupper(char **str);
int					ft_isspace(int c);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_f(char **str, unsigned int start, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_f(char **s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int n, int base);
char				*ft_uitoa_base(unsigned long long n, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putlnbr(long long n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*dsl)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstfree(t_list *lst);
void				ft_lstpushback(t_list **lst, void const *content,\
													size_t content_size);
char				*ft_delchar(char *src, char c, int occu);
char				*ft_delchar_f(char *src, char c, int occu);
char				*ft_straddnchar(char *str, int way, int n, char c);
char				*ft_addhexachar(char *str, int ishexa);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_printf(const char *format, ...);

#endif
