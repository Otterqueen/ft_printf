/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 14:06:46 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 09:33:41 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_SIZE 1024

typedef struct	s_printf
{
	int			diese;
	int			minus;
	int			zero;
	int			space;
	int			plus;
	int			width;
	int			preci;
	char		*size;
	char		type;
	char		*end;
	int			char0;
	int			nbprint;
}				t_printf;

int				ft_printf(const char *format, ...);
int				process(char *format, t_printf *print, va_list params);
char			*parse(char *format, t_printf *print);
char			*traitement(t_printf *print, va_list params, char *attribut);
t_printf		*new_struct();
char			*process_s(t_printf *print, va_list param);
char			*get_flag(char *attribu, t_printf *print);
char			*get_width(char *attribu, t_printf *print);
char			*get_prec(char *attribu, t_printf *print);
char			*get_size(char *attribu, t_printf *print);
char			*get_type(char *attribut, t_printf *print);
char			*process_c(t_printf *print, va_list param);
char			*process_d(t_printf *print, va_list param);
char			*process_u(t_printf *print, va_list param);
char			*process_o(t_printf *print, va_list param);
char			*process_x(t_printf *print, va_list param);
char			*process_p(t_printf *print, va_list param);
char			*process_ss(t_printf *print, va_list param);
t_printf		*init(t_printf *old);
char			*process_dd(t_printf *print, va_list param);
char			*process_pe(t_printf *print);
char			*process_b(t_printf *print, va_list param);
char			*ft_process_flag(t_printf *print, char *str, int len);
char			*ft_process_flag_2(t_printf *print, char *str, int len);
char			*ft_preci(t_printf *print, char *str, int len);
char			*flag_x(t_printf *print, char *str, int len);
char			*flag_p(t_printf *print, char *str, int len);
void			ft_free_print(t_printf *print);
char			*process_other(t_printf *print, va_list param, char *attribut);
char			*handle_wchar(char *str, wchar_t wc);
char			*process_o_bis(t_printf *print, long next_value);
t_printf		*handle_nullc(t_printf *print);
char			*process_d_bis(t_printf *print, long long next_value, char *str, int neg);
#endif
