/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_norme2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <mchapard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 23:52:08 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/03 19:33:36 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

unsigned char	is_max(unsigned long next_value)
{
	if (next_value == USHRT_MAX)
		next_value = 65535;
	else
		next_value = (unsigned char)next_value;
	return (next_value);
}

char			*process_u_bis(t_printf *print, unsigned long n_v, char *str)
{
	int				len;

	str = ft_itoa_u(n_v);
	len = ft_strlen(str);
	str = ft_preci(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag_2(print, str, len);
	return (str);
}

char			*process_x_bis(t_printf *print, unsigned long n_v, char *str)
{
	int		len;

	str = ft_itoa_base_l(n_v, 16);
	len = ft_strlen(str);
	if (print->diese == 1)
		len = len + 2;
	str = flag_x(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag(print, str, len);
	return (str);
}

char			*preci_null(t_printf *print, char *str)
{
	str = ft_strnew(1);
	if (print->width)
		while ((print->width) > 0)
		{
			str = ft_strjoin(" ", str);
			print->width--;
		}
	return (str);
}

char			*is_overflow(t_printf *print, unsigned long n_v, char *str)
{
	if (n_v > 4294967295)
		str = ft_strdup("100000000");
	if (n_v > 9223372036854775806)
		str = ft_strdup("7fffffffffffffff");
	if (print->preci == 0)
		str = preci_null(print, str);
	else if (n_v == 0)
		str = ft_strdup("0");
	else
		str = process_x_bis(print, n_v, str);
	return (str);
}
