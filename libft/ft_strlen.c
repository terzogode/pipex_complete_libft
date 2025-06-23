/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:35:30 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:59 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\0')
	{
		len++;
	}
	return (len);
}
/* int main (void)
{
	int b;

	char k[10] = "cicocico";
	b = ft_strlen(k);
	printf("%d\n", b);
	return (0);
} */
