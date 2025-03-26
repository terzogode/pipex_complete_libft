/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:04:13 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/18 15:38:20 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlowercase(unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 0 && n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = n - 10 + 'a';
		write(1, &c, 1);
		i++;
	}
	else
	{
		i += ft_hexlowercase(n / 16);
		i += ft_hexlowercase(n % 16);
	}
	return (i);
}
