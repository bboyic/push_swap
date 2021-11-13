/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:31:20 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/13 02:24:12 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_pars(int ac, char **av)
{
	int	index;

	index = 0;
	if (ft_pars_repeat(ac, av))
		return (1);
	while (index < ac)
	{
		if (ft_strIsNum(av[index]))
			return (1);
		++index;
	}
	return (0);
}

int	ft_strIsNum(char *av)
{
	while (*av)
	{
		if (*av == '-')
			++av;
		if (*av < '0' || *av > '9')
			return (1);
		++av;
	}
	return (0);
}

int	ft_pars_repeat(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (!ft_strcmp(av[i], av[j]))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
