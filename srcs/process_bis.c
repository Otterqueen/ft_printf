/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_bis.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 14:27:54 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 14:27:56 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char		*process_o(t_printf *print, va_list param)
{
	long	next_value;

	next_value = va_arg(param, long);
	if (print->size != NULL)
	{
		if (ft_strstr(print->size, "h"))
			next_value = (unsigned short int)next_value;
		if (ft_strstr(print->size, "hh"))
		{
			if(next_value == USHRT_MAX)
				next_value = 65535;
			else
				next_value = (unsigned char)next_value;
		}
		if (ft_strstr(print->size, "l"))
			next_value = (unsigned long int)next_value;
		if (ft_strstr(print->size, "j"))
			next_value = (uintmax_t)next_value;
		if (ft_strstr(print->size, "z"))
			next_value = (size_t)next_value;
	}
	else
	{
		if (ft_strchr("O", print->type))
			next_value = (long unsigned int)next_value;
		else
			next_value = (unsigned int)next_value;
	}
	return(process_o_bis(print, next_value));
}

char		*process_x(t_printf *print, va_list param)
{
	long	next_value;
	char	*str;
	int		len;

	next_value = va_arg(param, long long);
	if (print->size != NULL)
	{
		if (ft_strstr(print->size, "h"))
			next_value = (unsigned short int)next_value;
		if (ft_strstr(print->size, "hh"))
			next_value = (unsigned char)next_value;
		if (ft_strstr(print->size, "l"))
			next_value = (unsigned long int)next_value;
		if (ft_strstr(print->size, "ll"))
			next_value = (unsigned long long)next_value;
		if (ft_strstr(print->size, "j"))
			next_value = (uintmax_t)next_value;
		if (ft_strstr(print->size, "z"))
			next_value = (size_t)next_value;
	}
	else
		next_value = (unsigned int)next_value;
	if (next_value > 4294967295)
		str = ft_strdup("100000000");
	if (next_value > 9223372036854775806)
		str = ft_strdup("7fffffffffffffff");
	if (print->preci == 0)
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
	if (next_value == 0)
		return (ft_strdup("0"));
	str = ft_itoa_base_l(next_value, 16);
	len = ft_strlen(str);
	if (print->diese == 1)
		len = len + 2;
	str = flag_x(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag(print, str, len);
	return (str);
}

char		*process_p(t_printf *print, va_list param)
{
	long	next_value;
	char	*str;
	int		len;

	next_value = va_arg(param, long);
	if (print->preci == 0)
	{
		str = ft_strdup("0x");
		if (print->width)
			while ((print->width) > 0)
			{
				str = ft_strjoin(" ", str);
				print->width--;
			}
		return (str);
	}
	str = ft_itoa_base_l(next_value, 16);
	len = ft_strlen(str);
	if (print->diese == 1)
		len = len + 2;
	str = flag_p(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag(print, str, len);
	return (str);
}

char		*process_pe(t_printf *print)
{
	char	*str;
	int		len;

	str = ft_strdup("%");
	len = ft_strlen(str);
	str = ft_process_flag_2(print, str, len);
	return (str);
}

char		*process_b(t_printf *print, va_list param)
{
	long	next_value;
	char	*str;
	int		len;

	next_value = va_arg(param, long);
	str = ft_itoa_base(next_value, 2);
	len = ft_strlen(str);
	if (print->diese == 1)
		len = len + 2;
	if (print->zero == 1)
		while ((print->width - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->width--;
		}
	if (print->diese == 1)
		str = ft_strjoin("0b", str);
	len = ft_strlen(str);
	str = ft_process_flag(print, str, len);
	return (str);
}
