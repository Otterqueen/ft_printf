/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_l.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mchapard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 22:37:14 by mchapard     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 22:37:16 by mchapard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		nbrlen_base_l(unsigned long value, int base)
{
	int			len;

	len = 1;
	if (value == 0)
		return (1);
	while (value / base != 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base_l(unsigned long n, int base)
{
	char		*s;
	int			len;

	len = nbrlen_base_l(n, base) + 1;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	s[len - 1] = '\0';
	len--;
	while (len >= 0)
	{
		if (base <= 10 || (base > 10 && (n % base) < 10))
			s[len - 1] = (n % base) + '0';
		else
			s[len - 1] = (n % base) - 10 + 'a';
		n /= base;
		len--;
	}
	return (s);
}
