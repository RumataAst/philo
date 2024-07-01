/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:05:04 by akretov           #+#    #+#             */
/*   Updated: 2024/06/30 18:34:10 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_init_forks_stat(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
}

static void	ft_init_philo_meal(t_arg *philo_arg)
{
	int	i;

	i = 0;
	while (i < philo_arg->philo_count)
	{
		philo_arg->philo_meal[i] = philo_arg->philo_diet;
		i++;
	}
}

static void	ft_init_philo_time_l(t_arg *philo_arg)
{
	int	i;

	i = 0;
	while (i < philo_arg->philo_count)
	{
		philo_arg->time_l[i] = philo_arg->time_d;
		i++;
	}
}

static void	ft_struct_fill_1(t_arg *philo_arg)
{
	int	i;

	i = philo_arg->philo_count;
	philo_arg->time_l = (size_t *)malloc(sizeof(size_t) * i);
	if (!philo_arg->time_l)
	{
		free(philo_arg->forks);
		free(philo_arg->philo_stat);
		exit(3);
	}
	philo_arg->philo_meal = (int *)malloc(sizeof(int) * i);
	if (!philo_arg->philo_meal)
	{
		free(philo_arg->time_l);
		free(philo_arg->forks);
		free(philo_arg->philo_stat);
		exit(3);
	}
	ft_init_philo_meal(philo_arg);
	ft_init_philo_time_l(philo_arg);
}

void	ft_struct_fill(int ac, char **av, t_arg *philo_arg)
{
	philo_arg->philo_count = ft_atol(av[1]);
	philo_arg->time_d = ft_atol(av[2]);
	philo_arg->time_s = ft_atol(av[3]);
	philo_arg->time_e = ft_atol(av[4]);
	if (ac == 6)
		philo_arg->philo_diet = ft_atol(av[5]);
	else
		philo_arg->philo_diet = 0;
	philo_arg->philo_stat = (int *)malloc(sizeof(int) * philo_arg->philo_count);
	if (!philo_arg->philo_stat)
		exit (1);
	philo_arg->forks = (int *)malloc(sizeof(int) * philo_arg->philo_count);
	if (!philo_arg->forks)
	{
		free(philo_arg->philo_stat);
		exit(2);
	}
	ft_init_forks_stat(philo_arg->forks, philo_arg->philo_count);
	ft_init_forks_stat(philo_arg->philo_stat, philo_arg->philo_count);
	ft_struct_fill_1(philo_arg);
}
