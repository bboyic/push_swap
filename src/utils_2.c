/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:10:08 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/13 03:38:14 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_freeAv(char **av)
{
	free(av[0]);
	free(av);
	return (0);
}

int	*ft_sortACreate(t_ab *anb, int argc)
{
	int		*a;

	a = (int *)malloc(sizeof(int) * (argc + 1));
	a = ft_copy_a(a, anb);
	a = ft_sort(a, anb->len_a);
	return (a);
}

void	ft_free(t_ab *anb, int *a, int ac, char **av)
{
	if (ac == 1)
		ft_freeAv(av);
	free(anb->a);
	free(anb->b);
	free(anb);
	free(a);
}
