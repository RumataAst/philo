/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:51:44 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 20:33:36 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_thinking(t_table *table, t_phil *phil_th, long time)
{
	long	dif;

	pthread_mutex_lock(&table->main_lock);
	if (check_end(table))
	{
		pthread_mutex_unlock(&table->main_lock);
		return ;
	}
	dif = ft_get_current_time() - time;
	printf("%li %i is thinking\n", dif, phil_th->id + 1);
	pthread_mutex_unlock(&table->main_lock);
}

static void	ft_sleeping(t_table *table, t_phil *phil_th, long time)
{
	long	dif;

	pthread_mutex_lock(&table->main_lock);
	if (check_end(table))
	{
		pthread_mutex_unlock(&table->main_lock);
		return ;
	}
	dif = ft_get_current_time() - time;
	printf("%li %i is sleeping\n", dif, phil_th->id + 1);
	pthread_mutex_unlock(&table->main_lock);
	ft_usleep(table->time_s);
}

int	check_end(t_table *table)
{
	int	end;

	pthread_mutex_lock(&table->end_lock);
	end = table->end;
	pthread_mutex_unlock(&table->end_lock);
	return (end);
}

static void	ft_schedule(t_table *table, t_phil *phil_th, long long time)
{
	while (1)
	{
		if (check_end(table))
			return ;
		ft_thinking(table, phil_th, time);
		if (check_end(table))
			return ;
		ft_eating(table, phil_th, time);
		if (check_end(table))
			return ;
		ft_sleeping(table, phil_th, time);
	}
}

void	*routine(void *arg)
{
	t_phil	*phil_th;
	t_table	*table;
	long	time;

	phil_th = (t_phil *)arg;
	table = phil_th->table;
	pthread_mutex_lock(&table->end_lock);
	pthread_mutex_lock(&phil_th->time_lock);
	time = table->time_start;
	phil_th->time_next_meal = time + table->time_d;
	pthread_mutex_unlock(&phil_th->time_lock);
	pthread_mutex_unlock(&table->end_lock);
	ft_schedule(table, phil_th, time);
	return (NULL);
}
