/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:44:59 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:20:10 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_size_split(char **av)
{
	int	index;

	index = 0;
	while (av[index])
		index++;
	return (index);
}

int	*ft_sort(int *a, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			++j;
		}
		++i;
	}
	return (a);
}

int	ft_check_sort(int *a, int len)
{
	int	index;

	index = 0;
	while (len > index + 1)
	{
		if (a[index] > a[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int	*ft_copy_a(int *a, t_ab *anb)
{
	int	index;

	index = 0;
	while (index < anb->len_a)
	{
		a[index] = anb->a[index];
		index++;
	}
	return (a);
}

int	ft_sort_len(int *sort_a, int md)
{
	int	index;

	index = 0;
	while (sort_a[index] != md)
		++index;
	return (index + 1);
}
