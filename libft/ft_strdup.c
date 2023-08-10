/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:01:04 by aplank            #+#    #+#             */
/*   Updated: 2023/08/10 17:00:45 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		x;

	if (s == NULL)
		return (NULL);
	x = 0;
	str = (char*)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (0);
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

/* int	main(void)
{
    char *str = "kfl";

    printf("%s", ft_strdup(str));
} */