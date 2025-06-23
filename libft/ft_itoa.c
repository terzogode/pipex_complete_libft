/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:00:48 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:24:42 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*h;
	int		j;
	long	num;

	num = n;
	j = len (num);
	h = ft_calloc(sizeof(char), (j + 1));
	if (!h)
		return (NULL);
	if (num < 0)
	{
		h[0] = '-';
		num = -num;
	}
	if (num == 0)
		h[0] = '0';
	while (num != 0)
	{
		h[--j] = num % 10 + '0';
		num = num / 10;
	}
	return (h);
}

/*  int	main(void)
 {
	char	*k;
	
 	k = ft_itoa(-2147483648);
	printf("%s\n", k);
	free(k);
 	return (0);
 } */