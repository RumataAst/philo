/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:59:33 by akretov           #+#    #+#             */
/*   Updated: 2024/07/05 17:25:47 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void ft_mutex_init(t_table *table)
{
	t_phil		**phil_th;
	int			i;

	phil_th = table->phil;
	i = 0;
	pthread_mutex_init(&table->main_lock, NULL);
	while (i < table->philo_count)
	{
		pthread_mutex_init(&table->forks_lock[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_init(&phil_th[i]->time_lock, NULL);
		i++;
	}
}

static void	ft_mutex_destroy(t_table *table)
{
	t_phil		**phil_th;
	int			i;

	phil_th = table->phil;
	i = 0;
	pthread_mutex_destroy(&table->main_lock);
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&table->forks_lock[i]);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&phil_th[i]->time_lock);
		i++;
	}
}

void	ft_no_diet(t_table *table)
{
	pthread_t	waiter;
	int			i;
	t_phil		**phil_th;
	
	i = 0;
	phil_th = table->phil;
	ft_mutex_init(table);
	while (i < table->philo_count)
	{
		if (pthread_create(&table->phil[i]->thread, NULL, ft_checker, table) != 0)
		{
			printf("Failed to create thread\n");
			ft_free_struct(table);
			exit(6);
		}
		i++;
	}
	if (pthread_create(&waiter, NULL, ft_phread, table) != 0)
	{
		printf("Failed to create checker thread\n");
		ft_free_struct(table);
		exit(6);
	}
	if (pthread_join(waiter, NULL) != 0 )
	{
		printf("Failed to join checker thread\n");
		ft_free_struct(table);
		exit(6);
	}
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_join(table->phil[i]->thread, NULL) != 0)
		{
			printf("Failed to join thread\n");
			ft_free_struct(table);
			exit(6);
		}
		i++;
	}
	ft_mutex_destroy(table);
}
