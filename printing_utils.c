/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <qtran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:05:34 by rkurnava          #+#    #+#             */
/*   Updated: 2023/08/11 16:30:17 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	print_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
	{
		printf("arr == NULL");
		return ;
	}
	while (arr[i])
	{
		printf("%s#\n", arr[i]);
		i++;
	}
	printf("%s#\n", arr[i]);
}
