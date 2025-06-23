/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:04:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:37 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;

	ps = (const unsigned char *)s;
	while (n > 0)
	{
		if (*ps == (unsigned char)c)
			return ((void *)ps);
		ps++;
		n--;
	}
	return (NULL);
}
/* 
int main (void)
{
	const char	s[] = "Please kill me";
	int			c = 'k';
	size_t		n = 8;
	int			pos;

	char *k = ft_memchr(s, c, n);
	pos = k - s;
	printf("la prima occorrenza di %c in e' a %s\n", c, k);
	printf("La posizione è: %d\n", pos);
} */
