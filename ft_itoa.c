/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmonteir <jmonteir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:47:58 by jmonteir          #+#    #+#             */
/*   Updated: 2021/12/04 16:53:59 by jmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = length(n);
	s = malloc(size + 1);
	if (!s)
		return (0);
	s[size] = '\0';
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (s);
}
