/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:25:28 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:19:37 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ab	*ft_rb(t_ab *anb)
{
	int	temp;
	int	index;

	index = 0;
	temp = anb->b[0];
	while (anb->len_b > index + 1)
	{
		anb->b[index] = anb->b[index + 1];
		index++;
	}
	anb->b[index] = temp;
	write(1, "rb\n", 3);
	return (anb);
}

t_ab	*ft_rra(t_ab *anb)
{
	int	temp;
	int	index;

	index = anb->len_a - 1;
	temp = anb->a[anb->len_a - 1];
	while (index > 0)
	{
		anb->a[index] = anb->a[index - 1];
		index--;
	}
	anb->a[0] = temp;
	write(1, "rra\n", 4);
	return (anb);
}

t_ab	*ft_rrb(t_ab *anb)
{
	int	temp;
	int	index;

	index = anb->len_b - 1;
	temp = anb->b[anb->len_b - 1];
	while (index > 0)
	{
		anb->b[index] = anb->b[index - 1];
		index--;
	}
	anb->b[0] = temp;
	write(1, "rrb\n", 4);
	return (anb);
}

t_ab	*ft_ss(t_ab *anb)
{
	anb = ft_sa(anb);
	anb = ft_sb(anb);
	write(1, "ss\n", 3);
	return (anb);
}

t_ab	*ft_rr(t_ab *anb)
{
	anb = ft_ra(anb);
	anb = ft_rb(anb);
	write(1, "rr\n", 3);
	return (anb);
}
