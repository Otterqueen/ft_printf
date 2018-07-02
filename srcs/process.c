/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 13:00:11 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 14:11:55 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char		*process_s(t_printf *print, va_list param)
{
	char	*next_value;
	int		len;

	next_value = va_arg(param, char *);
	if (next_value == NULL)
	{
		if ((print->preci >= 0) || (print->width > 0))
			next_value = ft_strnew(1);
		else
			return (ft_strdup("(null)"));
	}
	len = ft_strlen(next_value);
	if (print->preci >= 0)
	{
		if (len > print->preci)
		{
			next_value = ft_strcut(next_value, print->preci);
		}
	}
	len = ft_strlen(next_value);
	next_value = ft_process_flag_2(print, next_value, len);
	return (next_value);
}

char		*process_c(t_printf *print, va_list param)
{
	int		next_value;
	char	*ret;
	int		len;

	ret = ft_strdup("\0");
	if (print->size != NULL)
	{
		if (ft_strstr(print->size, "l"))
			print->type = 'C';
	}
	next_value = va_arg(param, int);
	if (next_value == 0)
		print->char0 = 1;
	if (ft_strchr("C", print->type) != NULL)
		ret = handle_wchar(ret, next_value);
	else
		ret = ft_strjoinchar(ret, next_value);
	len = ft_strlen(ret);
	if (next_value == 0)
		len = len + 1;
	ret = ft_process_flag_2(print, ret, len);
	return (ret);
}

char		*process_d(t_printf *print, va_list param)
{
	long long	next_value;
	char		*str;
	int			len;
	int			neg;

	neg = 0;
	next_value = va_arg(param, long long);
	if (print->size != NULL)
	{
		if (ft_strstr(print->size, "h"))
			next_value = (short int)next_value;
		if (ft_strstr(print->size, "hh"))
			next_value = (signed char)next_value;
		if (ft_strstr(print->size, "l"))
			next_value = (long int)next_value;
		if (ft_strstr(print->size, "j"))
			next_value = (intmax_t)next_value;
		if (ft_strstr(print->size, "z"))
			next_value = (size_t)next_value;
	}
	else
		next_value = (int)next_value;
	if ((next_value < 0) && (next_value != -2147483648))
	{
		next_value = -next_value;
		neg = 1;
	}
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
	str = ft_process_flag_2(print, str, len);
	if ((neg == 1) && (print->zero != -1))
		str = ft_strjoin("-", str);
	if ((print->plus == 1) && (next_value != -2147483648) && (print->zero != -1))
	{
		if (neg == 0)
			str = ft_strjoin("+", str);
	}
	else if ((print->space == 1) && (neg == 0) && (print->plus == -1)) 
		str = ft_strjoin(" ", str);
	return (str);
}

char		*process_u(t_printf *print, va_list param)
{
	unsigned long	next_value;
	char			*str;
	int				len;

	next_value = va_arg(param, unsigned long);
	if ((print->size != NULL) && (ft_strchr("U", print->type) == NULL))
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
		if (ft_strchr("U", print->type) != NULL)
			next_value = (long unsigned int)next_value;
		else
			next_value = (unsigned int)next_value;
	}
	str = ft_itoa_u(next_value);
	len = ft_strlen(str);
	str = ft_preci(print, str, len);
	len = ft_strlen(str);
	str = ft_process_flag_2(print, str, len);
	return (str);
}

char		*process_dd(t_printf *print, va_list param)
{
	long	next_value;
	char	*str;
	int		len;
	int		neg;

	next_value = va_arg(param, long);
	if (next_value < 0)
	{
		next_value = -next_value;
		neg = 1;
	}
	len = ft_intlen_l(next_value);
	str = ft_itoa_l(next_value);
	str = ft_preci(print, str, len);
	str = ft_process_flag_2(print, str, len);
	if (neg == 1)
		str = ft_strjoin("-", str);
	if (print->plus == 1)
	{
		if (next_value >= 0)
			str = ft_strjoin("+", str);
	}
	else if ((print->space == 1) && (print->width <= 0))
		str = ft_strjoin(" ", str);
	return (str);
}
