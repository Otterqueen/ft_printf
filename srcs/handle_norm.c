/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_norm.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:33:46 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 16:33:49 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char		*process_o_bis(t_printf *print, long next_value)
{
	int		len;
	char	*str;

	str = ft_itoa_base_l(next_value, 8);
	if ((print->diese == 1) && (next_value != 0))
		str = ft_strjoin("0", str);
	len = ft_strlen(str);
	if (!((print->preci == 0) && (print->diese == 1)))
		str = ft_preci(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag_2(print, str, len);
	return (str);
}

t_printf	*handle_nullc(t_printf *print)
{
	print->nbprint = ft_strlen(print->end) + 1;
	write(1, print->end, ft_strlen(print->end));
	write(1, "\0", 1);
	print = init(print);
	free(print->end);
	print->end = ft_strnew(1);
	return (print);
}

/*char		*process_d_bis(t_printf *print, long long next_value, char *str, int neg)
{
	int		len;

	len = ft_intlen_l(next_value);
	str = ft_itoa_l(next_value);
	str = ft_preci(print, str, len);
	len = ft_strlen(str);
	if ((neg == 1) || (print->space == 1) || (print->plus == 1))
		len++;
	if ((neg == 1) && (print->zero == -1))
		str = ft_strjoin("-", str);
	if ((print->plus == 1) && (next_value != -2147483648) && (print->zero == -1))
	{
		if (neg == 0)
			str = ft_strjoin("+", str);
	}
	return (str);
}*/
