/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:20:52 by mbrighi           #+#    #+#             */
/*   Updated: 2025/06/23 22:59:01 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_printf(const char *ptr, ...);
int	ft_hexlowercase(unsigned int n);
int	ft_hexuppercase(unsigned int n);
int	ft_putptr(void *ptr);
int	ft_putunsnbr(unsigned int n);
int	printf_body(int fd, const char *ptr, va_list *args);
int	printf_debug(const char *str, ...);
int	fd_printf(int fd, const char *str, ...);
int	ft_printf(const char *str, ...);

#endif
