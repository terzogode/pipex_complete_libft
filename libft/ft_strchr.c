/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:44:57 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:23:59 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	f;

	f = 0;
	while (s[f] != '\0')
	{
		if (s[f] == (char)c)
			return ((char *)&s[f]);
		f++;
	}
	if (s[f] == (char)c)
		return ((char *)&s[f]);
	return (NULL);
}
/* int main (void)
{
	const char	s[] = "Please kill me";
	int			c = 'a';
	int			pos;

	char *k = ft_strchr(s, c);
	pos = k - s;
	printf("la prima occorrenza di %c in e' a %s\n", c, k);
	printf("La posizione è: %d\n", pos);
} */