/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:32:23 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:19:53 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_ab_clear(t_ab *anb)
{
	if (anb->a)
		free(anb->a);
	if (anb->b)
		free(anb->b);
	free(anb);
}

t_ab	*ft_new_anb(t_ab *anb)
{
	anb->a = (int *)malloc(sizeof(int) * anb->len_a);
	if (!anb->a)
		return (NULL);
	anb->b = (int *)malloc(sizeof(int) * anb->len_b);
	if (!anb->b)
		return (NULL);
	return (anb);
}

t_ab	*ft_rrr(t_ab *anb)
{
	anb = ft_rra(anb);
	anb = ft_rrb(anb);
	write(1, "rrr\n", 4);
	return (anb);
}
