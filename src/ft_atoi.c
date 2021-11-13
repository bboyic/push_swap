/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:56:34 by aconchit          #+#    #+#             */
/*   Updated: 2021/11/13 02:52:06 by aconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f' \
	|| *str == '\r' || *str == '\n' || *str == '\f') && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	if (res > 2147483647 && sign > 0)
		return (0);
	if (res > 2147483648 && sign < 0)
		return (0);
	return (res * sign);
}
