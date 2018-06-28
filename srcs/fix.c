/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fix.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 13:23:52 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 13:23:53 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char	*flag_x(t_printf *print, char *str, int len)
{
	if ((print->zero == 1) && (print->preci == -1) && (print->minus == -1))
		while ((print->width - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->width--;
		}
	else if (print->preci != -1)
	{
		if (print->diese == 1)
			len = len - 2;
		while ((print->preci - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->preci--;
		}
	}
	if (print->diese == 1)
		str = ft_strjoin("0x", str);
	if (print->type == 'X')
		str = ft_str_toupper(str);
	return (str);
}

char	*flag_p(t_printf *print, char *str, int len)
{
	/*if (print->diese == 1)
		len = len - 2;
	while ((print->preci - len) > 0)
	{
		str = ft_strjoin("0", str);
		print->preci--;
	}
	if (print->diese == 1)
		str = ft_strjoin("0x", str);
	return (str);*/
	if ((print->zero == 1) && (print->preci == -1) && (print->minus == -1))
		while ((print->width - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->width--;
		}
	else if (print->preci != -1)
	{
		if (print->diese == 1)
			len = len - 2;
		while ((print->preci - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->preci--;
		}
	}
	str = ft_strjoin("0x", str);
	return (str);
}

void	ft_free_print(t_printf *print)
{
	if (print->size != NULL)
		free(print->size);
	if (print->end != NULL)
		free(print->end);
	free(print);
}

char 	*handle_wchar(char *str, wchar_t wc)
{
	if (wc <= 127)
		str = ft_strjoinchar(str, wc);
	else if (wc <= 2047)
	{
		str = ft_strjoinchar(str, ((wc >> 6) + 0xC0));
		str = ft_strjoinchar(str, ((wc & 0x3F) + 0x80));
	}
	else if (wc <= 65535)
	{
		str = ft_strjoinchar(str, ((wc >> 12) + 0xE0));
		str = ft_strjoinchar(str, (((wc >> 6) & 0x3F) + 0x80));
		str = ft_strjoinchar(str, ((wc & 0x3F) + 0x80));
	}
	else if (wc <= 1114111)
	{
		str = ft_strjoinchar(str, ((wc >> 18) + 0xF0));
		str = ft_strjoinchar(str, (((wc >> 12) & 0x3F) + 0x80));
		str = ft_strjoinchar(str, (((wc >> 6) & 0x3F) + 0x80));
		str = ft_strjoinchar(str, ((wc & 0x3F) + 0x80));
	}
	return(str);
}

char		*process_ss(t_printf *print, va_list param)
{
	wchar_t		*next_value;
	char		*str;

	next_value = va_arg(param, wchar_t *);
	while (next_value != '\0')
	{
		str = handle_wchar(str, *next_value);
		if (*next_value <= 127)
			next_value++;
		else if (*next_value <= 2047)
			next_value = next_value + 2;
		else if (*next_value <= 65535)
			next_value = next_value + 3;
		else if (*next_value <= 1114111)
			next_value = next_value + 4;
		//next_value++;
	}
	return (str);
}
