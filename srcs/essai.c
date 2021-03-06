/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   essai.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 22:58:27 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 11:20:26 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*print;
	char		*str;
	int			nb;
	va_list		params;
	char		c;

	va_start(params, format);
	print = new_struct();
	str = ft_strdup((char *)format);
	nb = process(str, print, params);
	write(1, print->end, nb);
	free(str);
	ft_free_print(print);
	return (nb + print->nbprint);
}

int		process(char *format, t_printf *print, va_list params)
{
	char *attribut;
	char *str;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print = init(print);
			attribut = parse(format, print);
			str = traitement(print, params, attribut);
			print->end = ft_strjoin(print->end, str);
			if (print->char0 == 1)
				print = handle_nullc(print);
			format = format + ft_strlen(attribut);
			//free(str);
			free(attribut);
		}
		else
		{
			print->end = ft_strjoin_bis(print->end, format);
			format++;
		}
	}
	return (ft_strlen(print->end));
}

char	*parse(char *format, t_printf *print)
{
	char	*attribut;
	char	*tmp;

	attribut = NULL;
	while (ft_strchr("sSpdDoiOuUxXcCb%", *format) == NULL)
	{
		attribut = ft_strjoin_bis(attribut, format);
		format++;
	}
	attribut = ft_strjoin_bis(attribut, format++);
	tmp = attribut;
	tmp = get_flag(tmp, print);
	tmp = get_width(tmp, print);
	tmp = get_prec(tmp, print);
	tmp = get_size(tmp, print);
	tmp = get_type(tmp, print);
	if (ft_strchr("sSpdDoiOuUxXcCb%", print->type) == NULL)
	{
		print = init(print);
		attribut = ft_strnew(1);
		//return(NULL);
	}
	return (attribut);
}

char	*traitement(t_printf *print, va_list params, char *attribut)
{
	char *str;

	if ((print->type == 's') || (print->type == 'S'))
		str = process_s(print, params);
	else if ((print->type == 'c') || (print->type == 'C'))
		str = process_c(print, params);
	else if ((print->type == 'd') || (print->type == 'i'))
		str = process_d(print, params);
	else if ((print->type == 'u') || (print->type == 'U'))
		str = process_u(print, params);
	else if (print->type == 'D')
		str = process_dd(print, params);
	else if ((print->type == 'o') || (print->type == 'O'))
		str = process_o(print, params);
	else if ((print->type == 'x') || (print->type == 'X'))
		str = process_x(print, params);
	else if (print->type == 'p')
		str = process_p(print, params);
	else if (print->type == 'b')
		str = process_b(print, params);
	else
		str = process_other(print, params, attribut);
	return (str);
}
