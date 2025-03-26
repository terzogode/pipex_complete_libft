/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:49:43 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/18 15:38:42 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexp(unsigned long n)
{
	char	c;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 16)
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
		i += ft_hexp(n / 16);
		i += ft_hexp(n % 16);
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_hexp((unsigned long)ptr);
	return (count);
}
