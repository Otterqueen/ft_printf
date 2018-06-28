/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:27 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:19:27 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split2(char **ret, char const *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		if (str[i])
		{
			j = 0;
			if (!(ret[k] = (char*)malloc(sizeof(str) *
							ft_len_mot((char*)str, i, c) + 1)))
				return (NULL);
			while (str[i] != c && str[i])
				ret[k][j++] = str[i++];
			ret[k++][j] = '\0';
		}
		ret[k] = NULL;
	}
	return (ret);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**ret;

	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		if (!(ret = (char**)malloc(sizeof(ret))))
			return (NULL);
		ret[0] = NULL;
		return (ret);
	}
	if (!(ret = (char**)malloc(sizeof(ret) * ft_nb_mot((char*)str, c) + 1)))
		return (NULL);
	return (ft_split2(ret, str, c));
}
