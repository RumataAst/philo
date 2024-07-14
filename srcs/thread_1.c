/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:13:58 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 17:58:34 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_thread_error(t_table *table, int c_j)
{
	if (c_j == 0)
	{
		printf("Failed to create thread\n");
		fr_free_all(table, 8);
	}
	if (c_j == 1)
	{
		printf("Failed to join thread\n");
		fr_free_all(table, 9);
	}
}

static void	ft_mutex_init(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_init(&table->main_lock, NULL);
	pthread_mutex_init(&table->end_lock, NULL);
	while (i < table->philo_n)
	{
		pthread_mutex_init(&(table->fork_lock[i]), NULL);
		pthread_mutex_init(&(table->phil[i]->time_lock), NULL);
		i++;
	}
}

static void	ft_mutex_destroy(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->main_lock);
	pthread_mutex_destroy(&table->end_lock);
	while (i < table->philo_n)
	{
		pthread_mutex_destroy(&(table->fork_lock[i]));
		pthread_mutex_destroy(&(table->phil[i]->time_lock));
		i++;
	}
}

static void	ft_create_threads(t_table *t)
{
	t_phil	*phil;
	int		i;

	phil = NULL;
	i = 0;
	while (i < t->philo_n)
	{
		phil = t->phil[i];
		if (pthread_create(&phil->thread, NULL, routine, phil) != 0)
			ft_thread_error(t, 0);
		i++;
	}
	if (pthread_create(&t->waiter, NULL, checker, t) != 0)
		ft_thread_error(t, 0);
}

void	ft_norm(t_table *t)
{
	int				i;

	i = 0;
	ft_mutex_init(t);
	pthread_mutex_lock(&t->end_lock);
	ft_create_threads(t);
	t->time_start = ft_get_current_time();
	pthread_mutex_unlock(&t->end_lock);
	while (i < t->philo_n)
		if (pthread_join(t->phil[i++]->thread, NULL) != 0)
			ft_thread_error(t, 1);
	if (pthread_join(t->waiter, NULL) != 0)
		ft_thread_error(t, 1);
	ft_mutex_destroy(t);
}
