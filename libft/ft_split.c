/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:28:42 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:05 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **array, size_t k_idx)
{
	while (k_idx > 0)
		free(array[--k_idx]);
	free(array);
	return (NULL);
}

static size_t	ft_count(const char *s, const char h)
{
	size_t	counter;
	int		i;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == h)
			i++;
		if (s[i] && s[i] != h)
		{
			counter++;
			while (s[i] && s[i] != h)
				i++;
		}
	}
	return (counter);
}

static int	ft_len(const char *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**k;
	int		j;
	size_t	k_idx;
	int		h;
	size_t	counter;

	counter = ft_count(s, c);
	j = 0;
	k_idx = 0;
	k = ft_calloc((counter + 1), sizeof(char *));
	if (!k)
		return (NULL);
	while (k_idx < counter)
	{
		h = 0;
		while (s[j] == c)
			j++;
		k[k_idx] = ft_calloc((ft_len(&s[j], c) + 1), sizeof(char));
		if (!k[k_idx])
			return (ft_free_all(k, k_idx));
		while (s[j] != '\0' && s[j] != c)
			k[k_idx][h++] = s[j++];
		k_idx++;
	}
	return (k);
}

/* int	main(void)
{
	const char	s[] = ",   , diig ,,";
	char		c = ',';
	char		**l;
	int			i;

	i = 0;
	l = ft_split(s, c);

	(void)i;

	//printf("l'array allocato e' %s\n", l[1]);

	if (l)
    {
		while (l[i] != NULL)
		{
			printf("l'array allocato e' %s\n", l[i]);
			free(l[i]);
			i++;
		}
		free(l);
	}
    return 0;
} */
