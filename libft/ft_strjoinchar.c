/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinchar.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 21:03:12 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 21:03:14 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char *s1, char c)
{
    char *new;
    
    if (!s1)
        s1 = ft_strnew(1);
    if (!(new = malloc(ft_strlen(s1) + 2)))
        return (NULL);
    if (new)
    {
        ft_strcpy(new, s1);
        ft_strncat(new, &c, 1);
    }
    return (new);
}
