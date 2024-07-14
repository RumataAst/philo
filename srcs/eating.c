/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:59:18 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 21:31:46 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_pick_right(t_table *table, t_phil *phil_th, long time)
{
	long	dif;
	int		r_fork_id;
	int		l_fork_id;

	ft_usleep(50);
	l_fork_id = phil_th->id;
	r_fork_id = (phil_th->id + 1) % table->philo_n;
	pthread_mutex_lock(&table->fork_lock[r_fork_id]);
	pthread_mutex_lock(&table->main_lock);
	if (check_end(table))
	{
		un_two(&table->main_lock, &table->fork_lock[r_fork_id]);
		return (1);
	}
	dif = ft_get_current_time() - time;
	printf("%li %i has taken a fork\n", dif, phil_th->id + 1);
	pthread_mutex_unlock(&table->main_lock);
	pthread_mutex_lock(&table->fork_lock[l_fork_id]);
	if (check_end(table))
	{
		un_two(&table->fork_lock[l_fork_id], &table->fork_lock[r_fork_id]);
		return (1);
	}
	return (0);
}

static int	ft_pick_left(t_table *table, t_phil *phil_th, long time)
{
	long	dif;
	int		r_fork_id;
	int		l_fork_id;

	l_fork_id = phil_th->id;
	r_fork_id = (phil_th->id + 1) % table->philo_n;
	pthread_mutex_lock(&table->fork_lock[l_fork_id]);
	pthread_mutex_lock(&table->main_lock);
	if (check_end(table))
	{
		un_two(&table->main_lock, &table->fork_lock[l_fork_id]);
		return (1);
	}
	dif = ft_get_current_time() - time;
	printf("%li %i has taken a fork\n", dif, phil_th->id + 1);
	pthread_mutex_unlock(&table->main_lock);
	pthread_mutex_lock(&table->fork_lock[r_fork_id]);
	if (check_end(table))
	{
		un_two(&table->fork_lock[r_fork_id], &table->fork_lock[l_fork_id]);
		return (1);
	}
	return (0);
}

static void	ft_update(t_table *table, t_phil *phil_th, long time)
{
	long	dif;

	pthread_mutex_lock(&table->main_lock);
	dif = ft_get_current_time() - time;
	printf("%li %i is eating\n", dif, phil_th->id + 1);
	pthread_mutex_lock(&phil_th->time_lock);
	phil_th->time_next_meal = ft_get_current_time() + table->time_d;
	pthread_mutex_unlock(&phil_th->time_lock);
	pthread_mutex_unlock(&table->main_lock);
	ft_usleep(table->time_e);
}

static void	ft_lock(t_table *table, int i, int r_f, int l_f)
{
	if (i == 0)
	{
		pthread_mutex_unlock(&table->fork_lock[r_f]);
		pthread_mutex_unlock(&table->fork_lock[l_f]);
	}
	else
	{
		pthread_mutex_unlock(&table->fork_lock[l_f]);
		pthread_mutex_unlock(&table->fork_lock[r_f]);
	}
}

void	ft_eating(t_table *table, t_phil *phil_th, long time)
{
	int		i;
	int		r_fork_id;
	int		l_fork_id;

	l_fork_id = phil_th->id;
	r_fork_id = (phil_th->id + 1) % table->philo_n;
	if (phil_th->id % 2 == 0)
	{
		if (ft_pick_right(table, phil_th, time) != 0)
			return ;
		i = 0;
	}
	else
	{
		if (ft_pick_left(table, phil_th, time) != 0)
			return ;
		i = 1;
	}
	ft_update(table, phil_th, time);
	ft_lock(table, i, r_fork_id, l_fork_id);
	pthread_mutex_lock(&phil_th->time_lock);
	phil_th->meals_eaten ++;
	pthread_mutex_unlock(&phil_th->time_lock);
}
