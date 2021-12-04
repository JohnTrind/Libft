/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmonteir <jmonteir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:47:58 by jmonteir          #+#    #+#             */
/*   Updated: 2021/12/04 16:56:32 by jmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	delimiter_counter(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**jarsenio;
	int		j;
	int		end;
	int		start;

	if (!s)
		return (0);
	jarsenio = malloc(sizeof(char *) * delimiter_counter(s, c) + 1);
	if (!jarsenio)
		return (0);
	start = 0;
	end = 0;
	j = 0;
	while (s[end])
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		if (end > start)
			jarsenio[j++] = ft_substr(s, start, end - start);
	}
	jarsenio[j] = NULL;
	return (jarsenio);
}
