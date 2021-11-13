/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:31:56 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:16:13 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_points(t_ab *anb, int ev, int index)
{
	int	points;
	int	top;
	int	bot;

	top = 0;
	bot = anb->len_a - 1;
	points = 0;
	while (ev < anb->a[bot] && ev < anb->a[top] && index > 0)
	{
		--bot;
		++points;
		--index;
	}
	while (ev > anb->a[top])
	{
		++top;
		++points;
	}
	return (points);
}

int	ft_rpoints(t_ab *anb, int size)
{
	int	points;
	int	temp;
	int	index;

	index = 0;
	points = index + ft_points(anb, anb->b[index], size);
	++index;
	while (index < anb->len_b)
	{
		temp = index + ft_points(anb, anb->b[index], size);
		if (temp < points)
			points = temp;
		++index;
	}
	return (points);
}

int	ft_rrpoints(t_ab *anb, int size)
{
	int	points;
	int	temp;
	int	index;

	index = 0;
	points = index + ft_points(anb, anb->b[(anb->len_b - 1) - index], size);
	++index;
	while (index < anb->len_b)
	{
		temp = index + ft_points(anb, anb->b[(anb->len_b - 1) - index], size);
		if (temp < points)
			points = temp;
		++index;
	}
	return (points);
}

t_ab	*ft_push_r(t_ab *anb, int r_points, int size)
{
	int	points;
	int	index;

	index = 0;
	points = 0;
	while (r_points != points)
	{
		points = index + ft_points(anb, anb->b[index], size);
		++index;
	}
	while (index-- > 1)
		anb = ft_rb(anb);
	return (anb);
}

t_ab	*ft_push_rr(t_ab *anb, int r_points, int size)
{
	int	points;
	int	index;

	index = 0;
	points = 0;
	while (r_points != points + 1)
	{
		points = index + ft_points(anb, anb->b[(anb->len_b - 1) - index], size);
		++index;
	}
	while (index-- > 0)
		anb = ft_rrb(anb);
	return (anb);
}
