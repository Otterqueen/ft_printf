/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_param.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 13:42:20 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 09:56:29 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

char	*get_flag(char *attribu, t_printf *print)
{
	while (ft_strchr("#0- +", *attribu) != NULL)
	{
		if (*attribu == '#')
			print->diese = 1;
		else if (*attribu == '0')
			print->zero = 1;
		else if (*attribu == '-')
			print->minus = 1;
		else if (*attribu == ' ')
			print->space = 1;
		else if (*attribu == '+')
			print->plus = 1;
		attribu++;
	}
	return (attribu);
}

char	*get_width(char *attribu, t_printf *print)
{
	char *width;

	width = ft_strnew(1);
	while (*attribu >= '0' && *attribu <= '9')
	{
		width = ft_strjoin_bis(width, attribu);
		attribu++;
	}
	if (width != NULL)
	{
		print->width = ft_atoi(width);
		free(width);
	}
	return (attribu);
}

char	*get_prec(char *attribu, t_printf *print)
{
	char *prec;

	prec = ft_strnew(1);
	if (*attribu == '.')
	{
		attribu++;
		while (*attribu >= '0' && *attribu <= '9')
		{
			prec = ft_strjoin_bis(prec, attribu);
			attribu++;
		}
	}
	else
	{
		free(prec);
		print->preci = -1;
		return (attribu);
	}
	if (prec != NULL)
	{
		print->preci = ft_atoi(prec);
		free(prec);
	}
	return (attribu);
}

char	*get_size(char *attribu, t_printf *print)
{
	char *size;

	size = NULL;
	if (ft_strchr("hljz", *attribu) != NULL)
	{
		size = ft_strjoin_bis(size, attribu);
		attribu++;
		if (ft_strchr("hl", *attribu) != NULL)
		{
			size = ft_strjoin_bis(size, attribu);
			attribu++;
		}
		print->size = size;
		//free(size);
	}
	return (attribu);
}

char	*get_type(char *attribu, t_printf *print)
{
	if (ft_strchr("sSpdDoiOuUxXcCb%", *attribu) != NULL)
	{
		print->type = *attribu;
	}
	return (attribu);
}
