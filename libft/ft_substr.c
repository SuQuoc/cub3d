/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:01:28 by aplank            #+#    #+#             */
/*   Updated: 2023/09/11 19:02:30 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		x;

	if (s == 0)
		return (0);
	x = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (len > 0 && s[start])
	{
		substr[x] = s[start];
		start++;
		len--;
		x++;
	}
	substr[x] = '\0';
	return (substr);
}

/* int	main(void)
{

//    char arr[] = "there is a nyancat under your bed...";

	printf ("%s", ft_substr("tripouille", 400, 42000));
} */

/* int	main(void)
{
	char *str = "i just want this part #############";
	size_t size = 22;
	printf("%s\n", ft_substr(str, 0, size));
} */