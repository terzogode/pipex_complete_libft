/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:23:03 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:25 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(const char *s1, char s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2)
			return (42);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	char	*s;
	int		s_index;

	s_index = 0;
	i = 0;
	j = 0;
	if (!set)
		return (ft_strdup(s1));
	while (ft_check(set, s1[i]))
		i++;
	while (ft_check(set, s1[ft_strlen(s1) - j - 1]) && s1[i])
		j++;
	s = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) - i - j + 1));
	if (!s)
		return (NULL);
	while (i < (ft_strlen(s1) - j))
	{
		s[s_index] = s1[i];
		s_index++;
		i++;
	}
	return (s);
}
/* int	main(void)
{
	const char	h[] = " \tyolo\n";
	const char	j[] = " \n\t";
	char 		*g;

	g = ft_strtrim(h, j);
		printf("%s", g);
	//while (g[++b] != '\0')
	//free(g);
	return (0);
} */