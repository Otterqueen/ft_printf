/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:54 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 14:05:01 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_toupper (int c);
int				ft_tolower (int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strncat(char *dest, char *src, int nb);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *dest, char *src);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putnbr(int nb);
void			ft_putendl(char const *str);
void			ft_putchar(char c);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_fillstr(char *str, char const *s, int j, int i);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
int				ft_len_mot(char *str, int i, char c);
int				ft_nb_mot(char *str, char c);
int				ft_len_int(int n);
int				ft_intlen(int n);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			**ft_strsplit(char const *str, char c);
char			*ft_strjoin_bis(char *s1, char *s2);
char			*ft_itoa_u(unsigned long n);
int				ft_intlen_u(unsigned long n);
int				ft_intlen_l(long n);
char			*ft_itoa_l(long n);
char			*ft_itoa_base(long n, int base);
char			*ft_str_toupper(char *str);
char			*ft_strcut(char *str, int i);
char			*ft_itoa_base_l(unsigned long n, int base);
char			*ft_strjoinchar(char *str, char c);
#endif
