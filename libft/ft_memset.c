/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:48:48 by aplank            #+#    #+#             */
/*   Updated: 2023/09/11 19:03:05 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int i, size_t n)
{
	int		x;
	char	c;
	char	*str;

	str = (char *)s;
	c = i;
	x = 0;
	while (n > 0)
	{
		str[x] = c;
		x++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char c = '-';
	int x = 7;
	char für_mem[] = "replace this";
	char s[] = "replace this";
	ft_memset(s, c, x);
	memset(für_mem, c, x);
	printf("%p\n",s);
	printf("%p\n",für_mem);
}*/