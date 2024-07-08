/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:13:58 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:47:34 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void ft_mutex_init(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(table->main_lock), NULL);
	pthread_mutex_init(&(table->end_lock), NULL);
	while (i < table->philo_n)
	{
		pthread_mutex_init(&(table->fork_lock[i]), NULL);
		i++;
	}
}

static void ft_mutex_destroy(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(table->main_lock));
	pthread_mutex_destroy(&(table->end_lock));
	while (i < table->philo_n)
	{
		pthread_mutex_destroy(&(table->fork_lock[i]));
		i++;
	}
}


void	ft_run_thread(t_table *table)
{
	if (table->philo_n == 1)
		ft_dead_alone(table);
	else if (table->philo_diet == 0)
	{
		ft_mutex_init(table);
		ft_mutex_destroy(table);
	}
}