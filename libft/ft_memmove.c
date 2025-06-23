/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:33:48 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:25 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			k;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (pd > ps && pd < ps + n)
	{
		k = n;
		while (k > 0)
		{
			pd[k - 1] = ps[k - 1];
			k--;
		}
		return ((void *)dest);
	}
	k = 0;
	while (k < n)
	{
		pd[k] = ps[k];
		k++;
	}
	return ((void *)dest);
}
/* int	main(void)
{
	char	src[] = "Voglio la liberta";
	char	dest[4] = "";
	size_t	n;
	
	n = 5;
	ft_memmove(dest, src, n);
	//memmove(dest, src, n);
	printf("Destinazione %s\n", dest);
} */