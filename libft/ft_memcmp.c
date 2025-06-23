/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:37:42 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:32 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1a;
	unsigned char	*s2a;
	size_t			i;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > i && (s1a[i] == s2a[i]))
		i++;
	if (i == n)
		return (0);
	return (s1a[i] - s2a[i]);
}
/* int main(void)
{
	char pacciani[] = "\0";
	char vanni[] = "\0";
	unsigned int	n;
	
	n = 20;
	int result1 = memcmp(pacciani, vanni, n);
	unsigned int j = ft_memcmp(pacciani, vanni, n);
	printf("%d\n", j);
	printf("%d", result1);
} */