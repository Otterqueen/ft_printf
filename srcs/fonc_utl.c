/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonc_utl.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:17:52 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 14:18:03 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

t_printf		*new_struct(void)
{
	t_printf	*new;

	new = ft_memalloc(sizeof(t_printf));
	new->diese = -1;
	new->minus = -1;
	new->zero = -1;
	new->space = -1;
	new->plus = -1;
	new->width = -1;
	new->preci = -1;
	new->size = NULL;
	new->type = -1;
	new->end = ft_strnew(1);
	new->char0 = 0;
	new->nbprint = 0;
	return (new);
}

t_printf		*init(t_printf *old)
{
	old->diese = -1;
	old->minus = -1;
	old->zero = -1;
	old->space = -1;
	old->plus = -1;
	old->width = -1;
	old->preci = -1;
	if (old->size != NULL)
		free(old->size);
	old->size = NULL;
	old->type = -1;
	old->char0 = 0;
	return (old);
}

char			*ft_process_flag(t_printf *print, char *str, int len)
{
	if (print->width != -1)
	{
		if (print->minus == 1)
		{
			while ((print->width - len) > 0)
			{
				str = ft_strjoin(str, " ");
				print->width--;
			}
		}
		else
		{
			while ((print->width - len) > 0)
			{
				str = ft_strjoin(" ", str);
				print->width--;
			}
		}
	}
	return (str);
}

char			*ft_process_flag_2(t_printf *print, char *str, int len)
{
	if (print->width != -1)
	{
		if (print->minus == 1)
		{
			while ((print->width - len) > 0)
			{
				str = ft_strjoin(str, " ");
				print->width--;
			}
		}
		else
		{
			while ((print->width - len) > 0)
			{
				if ((print->zero == 1) && ((print->preci == -1) || \
					(print->type == 'c') || (print->type == 's') || \
					(print->type == '%')))
					str = ft_strjoin("0", str);
				else
					str = ft_strjoin(" ", str);
				print->width--;
			}
		}
	}
	return (str);
}

char			*ft_preci(t_printf *print, char *str, int len)
{
	if (!((print->type == 'o') || (print->type == 'O') || (print->type == 'x') \
							|| (print->type == 'X')))
		len = ft_len_int(ft_atoi(str));
	if (print->preci == 0)
	{
		if ((print->type == 'd') || (print->type == 'i') || \
									(print->type == 'D'))
		{
			if (ft_strstr("0", str) != NULL)
				return (ft_strnew(1));
			else
				return (str);
		}
		else
			return (ft_strnew(1));
	}
	if ((print->preci != -1) && (len < print->preci))
	{
		while ((print->preci - len) > 0)
		{
			str = ft_strjoin("0", str);
			print->preci--;
		}
	}
	return (str);
}
