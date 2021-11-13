/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:52:10 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/13 03:41:13 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ab	*ft_push_swap(t_ab *anb, int *sort_a, int md)
{
	md = anb->len_a / 2;
	if (!ft_check_sort(anb->a, anb->len_a))
	{
		anb = ft_push_b(anb, sort_a, md);
		anb = ft_push_a(anb);
	}
	return (anb);
}

t_ab	*ft_freeAnb(t_ab *anb)
{
	free(anb->a);
	free(anb->b);
	free(anb);
	return (NULL);
}

t_ab	*ft_anb_create(int ac, char **av)
{
	t_ab	*anb;
	int		index;

	index = 0;
	anb = (t_ab *)malloc(sizeof(t_ab));
	if (!anb || ft_pars(ac, av))
	{
		if (anb)
			free(anb);
		return (NULL);
	}
	anb->len_a = ac;
	anb->len_b = 0;
	anb = ft_new_anb(anb);
	while (anb && anb->len_a > index)
	{
		anb->a[index] = ft_atoi(av[index]);
		if ((anb->a[index] == 0 && ft_strcmp("0", av[index])) \
		|| ft_strlen(av[index]) > 10)
			anb = ft_freeAnb(anb);
		++index;
	}
	if (!anb)
		return (NULL);
	return (anb);
}

int	main(int argc, char **argv)
{
	t_ab	*anb;
	int		*a;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_size_split(argv);
	}
	else
	{
		++argv;
		--argc;
	}
	anb = ft_anb_create(argc, argv);
	if (!anb)
	{
		write (2, "Error\n", 6);
		if (argc == 1)
			ft_freeAv(argv);
		return (0);
	}
	a = ft_sortACreate(anb, argc);
	anb = ft_push_swap(anb, a, anb->len_a / 2);
	ft_free(anb, a, argc, argv);
	return (0);
}
