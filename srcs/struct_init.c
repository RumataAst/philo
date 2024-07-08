/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:05:48 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:42:30 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_free_if_error(int i, t_table *table, int ex_num)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(table->phil[j]);
		j++;
	}
	if (table->fork_lock)
		free(table->fork_lock);
	free(table->phil);
	if (table)
		free(table);
	exit(ex_num);
}

static void	ft_ph_init(int i, t_phil *phil, t_table *main_table)
{
	phil->table = main_table;
	phil->time_next_meal = 0;
	phil->meals_eaten = 0;
	phil->id = i;
}

static void	ft_philo_th_create(t_table *table)
{
	int	i;

	i = 0;
	table->phil = (t_phil **)malloc(sizeof(t_phil *) * table->philo_n);
	if (!table->phil)
	{
		free(table);
		exit(3);
	}
	while (i < table->philo_n)
	{
		table->phil[i] = (t_phil *)malloc(sizeof(t_phil));
		if (!table->phil[i])
			ft_free_if_error(i, table, 5);
		ft_ph_init(i, table->phil[i], table);
		i++;
	}
}

void	ft_struct_init(int ac, char *av[], t_table *table)
{
	int	n;

	table->philo_n = ft_atol(av[1]);
	table->time_d = ft_atol(av[2]);
	table->time_s = ft_atol(av[3]);
	table->time_e = ft_atol(av[4]);
	table->end = 0;
	table->time_start = 0;
	if (ac == 6)
		table->philo_diet = ft_atol(av[5]);
	else
		table->philo_diet = 0;
	n = table->philo_n;
	table->fork_lock = (pthread_mutex_t *)malloc(n * sizeof(pthread_mutex_t));
	if (!table->fork_lock)
		fr_free_all(table, 6);
	ft_philo_th_create(table);
}
