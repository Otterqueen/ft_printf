/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_l.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 20:24:45 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 20:24:55 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*testmax(long n, char *s)
{
	if (n == LONG_MIN)
	{
		s = (char*)malloc(sizeof(char) * 19);
		return (s = "9223372036854775808");
	}
	if (n == LONG_MAX)
	{
		s = (char*)malloc(sizeof(char) * 19);
		return (s = "9223372036854775807");
	}
	else
		return (NULL);
}

char			*ft_itoa_l(long n)
{
	char	*s;
	size_t	len;

	s = testmax(n, s);
	if (s == NULL)
	{
		len = ft_intlen_l(n) + 1;
		if (!(s = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		if (n == 0)
			s[0] = '0';
		if (n < 0)
		{
			s[0] = '-';
			n = -n;
		}
		s[len - 1] = '\0';
		while (n)
		{
			len--;
			s[len - 1] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (s);
}
