/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:21:30 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:08 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	else
		return (c);
	return (c);
}
/* 
int	main (void)
{
	unsigned char	a = '1';
	unsigned char	b = 'a';
	unsigned char	c = '!';
	
	printf("Letsgoski %c\n", ft_tolower(a));
	printf("Letsgoski %c\n", ft_tolower(b));
	printf("Letsgoski %c\n", ft_tolower(c));
}  */