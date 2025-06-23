/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:04:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:23:48 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_letstry(unsigned int c, char *s)
{
	int	l;
	l = c % 2;
	if (l == 0)
		*s = *s - 32;
}  */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/* int	main(void)
{
	char		s[] = "";

	ft_striteri(s, ft_letstry);

	printf("l'array allocato e' %s\n", s);
} */
