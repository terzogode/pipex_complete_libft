/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:23:05 by mbrighi           #+#    #+#             */
/*   Updated: 2024/11/19 15:55:50 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/* 
int	main(void)
{
	int		c;
	char	s[18]= "perfavorefunziona";
	size_t	n;
	n = 9;
	c = 'D';

	ft_memset(s, c, n);
	printf("Risultato: %s\n", s);
	return(0);
}  */