/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:49:10 by mbrighi           #+#    #+#             */
/*   Updated: 2024/12/21 15:10:45 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkfiletype(va_list argp, const char ptr, int *counter)
{
	if (ptr == 'c')
		*counter += ft_putchar(va_arg(argp, int));
	if (ptr == 's')
		*counter += ft_putstr(va_arg(argp, char *));
	if (ptr == 'd' || ptr == 'i')
		*counter += ft_putnbr(va_arg(argp, int));
	if (ptr == 'x')
		*counter += ft_hexlowercase(va_arg(argp, unsigned int));
	if (ptr == 'X')
		*counter += ft_hexuppercase(va_arg(argp, unsigned int));
	if (ptr == 'p')
		*counter += ft_putptr(va_arg(argp, void *));
	if (ptr == 'u')
		*counter += ft_putunsnbr(va_arg(argp, unsigned int));
	if (ptr == '%')
		*counter += write(1, "%", 1);
}

int	ft_printf(const char *ptr, ...)
{
	int		counter;
	va_list	argp;

	counter = 0;
	if (!ptr)
		return (-1);
	va_start(argp, ptr);
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			ft_checkfiletype(argp, *ptr, &counter);
			ptr++;
		}
		else
		{
			ft_putchar(*ptr);
			ptr++;
			counter++;
		}
	}
	va_end(argp);
	return (counter);
}
