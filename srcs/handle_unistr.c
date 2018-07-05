/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_unistr.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <mchapard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 13:00:11 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/03 09:49:10 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char	*process_ss(t_printf *print, va_list param)
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

// a rajouter dans process_s

/*if (ft_strchr("S", print->type) != NULL)
	{
		next_value = process_ss(print, param);
	}
	else
	{*/
/* ---------- process_s -------------- */
//}
