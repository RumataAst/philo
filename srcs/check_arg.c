/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:02:57 by akretov           #+#    #+#             */
/*   Updated: 2024/07/02 12:04:59 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_int(int ac, char **av)
{
	int			j;
	long long	value;

	j = 1;
	while (j < ac)
	{
		value = ft_atol(av[j]);
		if (value > INT_MAX || value < INT_MIN)
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '0' && i != 5)
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
