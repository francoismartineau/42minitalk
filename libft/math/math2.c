/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:40:46 by francoma          #+#    #+#             */
/*   Updated: 2023/02/14 16:11:50 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_array_min(int *array, int size)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < size)
	{
		min = ft_min(array[i], min);
		i++;
	}
	return (min);
}

// returns first index of min value
int	ft_array_min_index(int *array, int size)
{
	int	min_index;
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
