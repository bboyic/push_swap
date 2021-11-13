/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:57:20 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/12 13:18:23 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

t_ab	*ft_sa(t_ab *anb)
{
	int	temp;

	temp = anb->a[0];
	anb->a[0] = anb->a[1];
	anb->a[1] = temp;
	write(1, "sa\n", 3);
	return (anb);
}

t_ab	*ft_sb(t_ab *anb)
{
	int	temp;

	temp = anb->b[0];
	anb->b[0] = anb->b[1];
	anb->b[1] = temp;
	write(1, "sb\n", 3);
	return (anb);
}

t_ab	*ft_pb(t_ab *anb)
{
	t_ab	*temp;
	int		index;

	index = 0;
	temp = (t_ab *)malloc(sizeof(t_ab));
	temp->len_a = anb->len_a - 1;
	temp->len_b = anb->len_b + 1;
	temp = ft_new_anb(temp);
	temp->b[0] = anb->a[0];
	while (temp->len_a > index)
	{
		temp->a[index] = anb->a[index + 1];
		index++;
	}
	index = 1;
	while (temp->len_b > index)
	{
		temp->b[index] = anb->b[index - 1];
		index++;
	}
	ft_ab_clear(anb);
	write(1, "pb\n", 3);
	return (temp);
}

t_ab	*ft_pa(t_ab *anb)
{
	t_ab	*temp;
	int		index;

	index = 0;
	temp = (t_ab *)malloc(sizeof(t_ab));
	temp->len_a = anb->len_a + 1;
	temp->len_b = anb->len_b - 1;
	temp = ft_new_anb(temp);
	temp->a[0] = anb->b[0];
	while (temp->len_b > index)
	{
		temp->b[index] = anb->b[index + 1];
		index++;
	}
	index = 1;
	while (temp->len_a > index)
	{
		temp->a[index] = anb->a[index - 1];
		index++;
	}
	ft_ab_clear(anb);
	write(1, "pa\n", 3);
	return (temp);
}

t_ab	*ft_ra(t_ab *anb)
{
	int	temp;
	int	index;

	index = 0;
	temp = anb->a[0];
	while (anb->len_a > index + 1)
	{
		anb->a[index] = anb->a[index + 1];
		index++;
	}
	anb->a[index] = temp;
	write(1, "ra\n", 3);
	return (anb);
}
