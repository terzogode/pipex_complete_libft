/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:43:42 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:54 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
} */
/* char	ft_letstry(unsigned int c, char s)
{
	int	l;
	l = c % 2;
	if (l == 0)
		s = s - 32;
	else
		return (s);
	return (s);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*k;
	unsigned int	j;

	j = 0;
	if (!s || !f)
		return (NULL);
	k = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!k)
		return (NULL);
	while (j < ft_strlen(s))
	{
		k[j] = f(j, s[j]);
		j++;
	}
	return (k);
}
/* int	main(void)
{
	const char		s[] = "diomerdafunziona";
	char			*l;
	unsigned int	i;

	i = 0;
	l = ft_strmapi(s, ft_letstry);

	printf("l'array allocato e' %s\n", l);
	free(l);

	if (l)
    {
		while (l != NULL)
		{
			printf("l'array allocato e' %c\n", l);
			free(l);
			i++;
		}
		free(l);
	} 
    return 0;
} */