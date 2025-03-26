/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexuppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:14 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/18 17:56:48 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexuppercase(unsigned int n)
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
			c = n - 10 + 'A';
		write(1, &c, 1);
		i++;
	}
	else
	{
		i += ft_hexuppercase(n / 16);
		i += ft_hexuppercase(n % 16);
	}
	return (i);
}
