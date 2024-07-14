/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:52:05 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 21:26:54 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	setup_checker(t_table *table, t_phil ***phil_th, long *time)
{
	*phil_th = table->phil;
	pthread_mutex_lock(&table->end_lock);
	*time = table->time_start;
	pthread_mutex_unlock(&table->end_lock);
	ft_usleep(table->time_d);
}

static int	check_philosopher_state(t_phil *phil, t_table *table, long time)
{
	long	next_meal;

	pthread_mutex_lock(&phil->time_lock);
	next_meal = phil->time_next_meal;
	pthread_mutex_unlock(&phil->time_lock);
	if (ft_get_current_time() >= next_meal)
	{
		pthread_mutex_lock(&table->main_lock);
		pthread_mutex_lock(&table->end_lock);
		printf("%li %i died\n", ft_get_current_time() - time, phil->id + 1);
		table->end = 1;
		pthread_mutex_unlock(&table->end_lock);
		pthread_mutex_unlock(&table->main_lock);
		return (1);
	}
	return (0);
}

static int	check_diet_status(t_phil *phil, t_table *table, int *diet_status)
{
	pthread_mutex_lock(&phil->time_lock);
	if (phil->meals_eaten >= table->philo_diet)
		(*diet_status)++;
	pthread_mutex_unlock(&phil->time_lock);
	return (*diet_status);
}

static void	*loop_checker(t_table *table, t_phil **phil_th, long time)
{
	int	i;
	int	diet_status;

	diet_status = 0;
	while (1)
	{
		i = 0;
		while (i < table->philo_n)
		{
			if (check_philosopher_state(phil_th[i], table, time))
				return (NULL);
			check_diet_status(phil_th[i], table, &diet_status);
			i++;
		}
		if (table->philo_diet != 0 && diet_status == table->philo_n)
		{
			pthread_mutex_lock(&table->end_lock);
			table->end = 1;
			pthread_mutex_unlock(&table->end_lock);
			break ;
		}
		else
			diet_status = 0;
	}
	return (NULL);
}

void	*checker(void *arg)
{
	t_table	*table;
	t_phil	**phil_th;
	long	time;

	table = (t_table *)arg;
	setup_checker(table, &phil_th, &time);
	return (loop_checker(table, phil_th, time));
}
