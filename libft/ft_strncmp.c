/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:37 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:48 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1a;
	unsigned char	*s2a;
	size_t			i;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1a[i] != '\0' && s2a[i] != '\0' && (s1a[i] == s2a[i]) && n > i)
		i++;
	if (i == n)
		return (0);
	return (s1a[i] - s2a[i]);
}

/* int main(void)
{
	char *pacciani = "se ni' mondo esistesse un po' di bene";
	char *vanni = "se ni' mpndo esistesse un po' di bene";
	unsigned int	n;
	
	n = 15;
	//int result1 = strncmp(pacciani, vanni, n);
	unsigned int j = ft_strncmp(pacciani, vanni, n);
	printf("%d\n", j);
	//printf("%d", result1);
} */