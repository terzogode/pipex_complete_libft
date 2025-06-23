/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:15:24 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:29 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			p;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	p = 0;
	if (!dest && !src)
		return (NULL);
	while (p < n)
	{
		pdest[p] = psrc[p];
		p++;
	}
	return (pdest);
}
/* 
int	main(void)
{
	char	src[] = "abcdefghi";
	char	dest[10];
	int		n;

	n = 5;
	ft_memcpy(dest, src, n);
	printf("src e' %s\n", src);
	printf("dest e' %s", dest);
	return (0);
} */
