/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:03:55 by aplank            #+#    #+#             */
/*   Updated: 2023/09/11 19:03:37 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(char *arr, unsigned long int n, int x)
{
	int		remain;
	char	i;

	while (n > 0)
	{
		remain = n % 10;
		n = n / 10;
		i = remain + '0';
		arr[x] = i;
		x--;
	}
	return (arr);
}

static int	how_many_digits(unsigned long int n)
{
	int	x;

	x = 0;
	while (n != 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*zero;
	char	*arr;
	int		x;

	if (n == 0)
	{
		zero = (char *)malloc(2 * sizeof(char));
		if (!zero)
			return (0);
		zero[0] = '0';
		zero[1] = 0;
		return (zero);
	}
	x = how_many_digits(n);
	arr = (char *)malloc(x + 1 * sizeof(char));
	if (!arr)
		return (0);
	arr[x] = '\0';
	x--;
	return (ft_convert(arr, n, x));
}

int	ft_unsigned_decimal(unsigned int n)
{
	char	*nbr;
	int		len;

	nbr = ft_unsigned_itoa(n);
	len = ft_string(nbr);
	free(nbr);
	return (len);
}
