/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:38:35 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:17:08 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ab	*ft_min(t_ab *anb, int max)
{
	if (anb->len_a > 2 && max == anb->a[0])
		anb = ft_ra(anb);
	else if (max == anb->a[1])
		anb = ft_rra(anb);
	if (anb->a[0] > anb->a[1])
		anb = ft_sa(anb);
	return (anb);
}

t_ab	*ft_move(t_ab *anb, int md, int len, int max)
{	
	int	index;

	index = 0;
	while (!ft_check_sort(anb->a, anb->len_a) && index < len && anb->len_a > 3)
	{
		if (anb->a[0] <= md && anb->a[0] != max)
		{
			anb = ft_pb(anb);
			++index;
		}
		else if (anb->len_a > 2 && anb->a[anb->len_a - 1] \
		<= md && anb->a[anb->len_a - 1] < anb->a[1])
			anb = ft_rra(anb);
		else if (anb->len_a > 2)
			anb = ft_ra(anb);
	}
	return (anb);
}

t_ab	*ft_find_point(t_ab *anb, int size)
{
	int	r_points;
	int	rr_points;

	r_points = ft_rpoints(anb, size);
	rr_points = ft_rrpoints(anb, size) + 1;
	if (r_points <= rr_points)
		anb = ft_push_r(anb, r_points, size);
	else
		anb = ft_push_rr(anb, rr_points, size);
	return (anb);
}

t_ab	*ft_push_a(t_ab *anb)
{
	int	size;

	size = 0;
	while (anb->len_b)
	{
		if (anb->len_b > 1)
			anb = ft_find_point(anb, size);
		while (anb->b[0] < anb->a[anb->len_a - 1] \
		&& anb->b[0] < anb->a[0] && size > 0)
		{
			anb = ft_rra(anb);
			--size;
		}
		if (anb->b[0] < anb->a[0])
			anb = ft_pa(anb);
		while (anb->len_b && anb->b[0] > anb->a[0])
		{
			anb = ft_ra(anb);
			++size;
		}
	}
	while (size-- > 0)
		anb = ft_rra(anb);
	return (anb);
}

t_ab	*ft_push_b(t_ab *anb, int *sort_a, int md)
{
	int	sort_len;
	int	max;
	int	index;

	index = 0;
	max = sort_a[anb->len_a - 1];
	sort_len = 0;
	while (!ft_check_sort(anb->a, anb->len_a))
	{
		sort_len = ft_sort_len(sort_a, sort_a[md]);
		if (anb->len_a > 3)
			anb = ft_move(anb, sort_a[md], sort_len, sort_a[anb->len_a - 1]);
		else
			anb = ft_min(anb, max);
		sort_a += md + 1;
		md = md / 2;
		++index;
	}
	return (anb);
}
