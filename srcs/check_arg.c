/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:41:18 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 17:53:48 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_check_int(int ac, char **av)
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

static int	ft_check_arguments(int ac, char **av)
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

static void	ft_error_han(char *err_msg, int ex_num)
{
	printf("%s", err_msg);
	exit(ex_num);
}

void	ft_check_pars(int ac, char *av[])
{
	char	*str;

	str = NULL;
	if (ac == 5 || ac == 6)
	{
		if (ft_check_arguments(ac, av) != 0)
		{
			str = "Invalid argument\n";
			ft_error_han(str, 1);
		}
		if (ft_check_int(ac, av) != 0)
		{
			str = "Number should be int\n";
			ft_error_han(str, 2);
		}
	}
	else
	{
		str = "Incorrect number of arguments\n";
		ft_error_han(str, 3);
	}
}
