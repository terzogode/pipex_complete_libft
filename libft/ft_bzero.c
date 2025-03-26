/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:46:52 by mbrighi           #+#    #+#             */
/*   Updated: 2024/11/19 15:54:21 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/* 
int	main(void)
{
	char	s[18] = "perfavorefunziona";
	size_t n = 9;
	int i = 0;

	ft_bzero(s, n);
	while (i < 18)
		{
			write(1, &s[i], 1);
			i++;
		}
	return(0);
} */