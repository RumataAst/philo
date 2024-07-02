/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:05:04 by akretov           #+#    #+#             */
/*   Updated: 2024/07/02 12:27:30 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_if_error(int i, t_table *table)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(table->phil[j]);
		j++;
	}
	free(table->forks);
	free(table->phil);
	free(table);
	exit(4);
}

static void	ft_struct_init(int i, t_phil *phil, t_table *main_table)
{
	phil->table = main_table;
	phil->time_next_meal = 0;
	phil->meals_eaten = 0;
	phil->id = i;
}

static void	ft_philo_th_create(t_table *table)
{
	unsigned int	i;

	i = 0;
	table->phil = (t_phil **)malloc(sizeof(t_phil *) * table->philo_count);
	if (!table->phil)
	{
		free(table->forks);
		free(table);
		exit(3);
	}
	while (i < table->philo_count)
	{
		table->phil[i] = (t_phil *)malloc(sizeof(t_phil));
		if (!table->phil[i])
			ft_free_if_error(i, table);
		ft_struct_init(i, table->phil[i], table);
		i++;
	}
}

static void	ft_init_forks(unsigned int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = 1;
		i++;
	}
}

void	ft_struct_fill(int ac, char **av, t_table *table)
{
	table->philo_count = ft_atol(av[1]);
	table->time_d = ft_atol(av[2]);
	table->time_s = ft_atol(av[3]);
	table->time_e = ft_atol(av[4]);
	if (ac == 6)
		table->philo_diet = ft_atol(av[5]);
	else
		table->philo_diet = 0;
	table->forks = (unsigned int *)malloc(sizeof(int) * table->philo_count);
	if (!table->forks)
	{
		free(table);
		exit(2);
	}
	ft_init_forks(table->forks, table->philo_count);
	ft_init_meals(table);
	ft_philo_th_create(table);
}