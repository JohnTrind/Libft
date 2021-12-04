/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmonteir <jmonteir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:47:58 by jmonteir          #+#    #+#             */
/*   Updated: 2021/12/04 16:53:59 by jmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;
	int		size;

	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	mapi = malloc(size + 1);
	if (!mapi)
		return (NULL);
	i = -1;
	while (s[++i])
		mapi[i] = f(i, s[i]);
	mapi[i] = 0;
	return (mapi);
}
