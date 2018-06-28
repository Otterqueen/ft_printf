/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcut.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 10:25:05 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 10:25:21 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *str, int i)
{
	int		j;
	char	*new;

	j = 0;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	return (new);
}
