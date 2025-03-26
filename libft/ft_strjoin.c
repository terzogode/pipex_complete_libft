/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:33:32 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/11 17:15:21 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				is1;
	int				is2;
	int				i;
	unsigned char	*l;

	is1 = 0;
	is2 = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen (s1) + ft_strlen(s2);
	l = malloc(sizeof(char) * (i + 1));
	if (!l)
		return (NULL);
	while (s1[is1])
	{
		l[is1] = s1[is1];
		is1++;
	}
	while (s2[is2])
	{
		l[is1 + is2] = s2[is2];
		is2++;
	}
	l[is1 + is2] = '\0';
	return ((char *)l);
}
/* int main(void)
{
	const char		s1[] = "\0";
	const char		s2[] = "di andare al lavoro";
	char 			*k;
	unsigned int	i;
	
	i = -1;
	k = ft_strjoin(s1, s2);
	while (k[++i])
		printf("%c", k[i]);
	free(k);
} */
