/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:25 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:19:25 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*str2;

	i = 0;
	if (s)
	{
		len = ft_strlen((char*)s);
		if (!(str2 = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			str2[i] = f(i, s[i]);
			i++;
		}
		str2[i] = '\0';
		return (str2);
	}
	return (NULL);
}
