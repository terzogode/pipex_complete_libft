/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:23:29 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:25:21 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(num * size);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < num * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
/* int	main(void)
{
	size_t	num = 3;
	size_t	size = 5;

	char *k = ft_calloc(num, size);
	num = 0;
	while (k[num++] != '\0')
		printf("l'array allocato e' %d\n", k[num]);
	free(k);
} */