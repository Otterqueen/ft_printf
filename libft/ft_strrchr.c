/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:27 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:19:27 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = -1;
	a = c;
	while (s[i])
	{
		if (s[i] == a)
			j = i;
		i++;
	}
	if (s[i] == a)
		return ((char*)s + i);
	if (j == -1)
		return (NULL);
	return ((char*)s + j);
}
