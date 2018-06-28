/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:23 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:19:23 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*cpy;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if (!(cpy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
