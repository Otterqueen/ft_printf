/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_bis.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <mchapard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 13:37:34 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/03 11:06:17 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char *new;

	if (!s1)
		s1 = ft_strnew(1);
	if (!s2)
		return (NULL);
	if (!(new = malloc(ft_strlen(s1) + 2)))
		return (NULL);
	if (new)
	{
		ft_strcpy(new, s1);
		ft_strncat(new, s2, 1);
	}
	//free(s1);
	return (new);
}
