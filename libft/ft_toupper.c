/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:21:40 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:21:56 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	else
	{
		return (c);
	}
	return (c);
}
/* int	main (void)
{
	unsigned char	a = '1';
	unsigned char	b = 'a';
	unsigned char	c = '!';
	
	printf("Letsgoski %c\n", ft_toupper(a));
	printf("Letsgoski %c\n", ft_toupper(b));
	printf("Letsgoski %c\n", ft_toupper(c));
} */