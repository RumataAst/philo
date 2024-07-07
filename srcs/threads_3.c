/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:25:24 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:43:36 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_pick_left(t_phil *phil_th, t_table *table, int fork_l)
{
	table->forks[fork_l] = 0;
	ft_status_write(phil_th, table, FORK);
}

static void	ft_pick_right(t_table *table, int fork_r)
{
	table->forks[fork_r] = 0;
}

static void ft_put_forks(t_table *table, int fork_l,int fork_r)
{
	table->forks[fork_l] = 1;
	table->forks[fork_r] = 1;
	pthread_mutex_unlock(&table->forks_lock[fork_l]);
	pthread_mutex_unlock(&table->forks_lock[fork_r]);
	pthread_mutex_lock(&table->phil[fork_l]->time_lock);
	table->phil[fork_l]->time_next_meal += table->time_d;
	pthread_mutex_lock(&table->phil[fork_l]->time_lock);
}

static void	ft_pick_eat(t_phil *phil_th, t_table *table)
{
	int	fork_l;
	int	fork_r;

	fork_l = phil_th->id;
	fork_r = (phil_th->id + 1) % table->philo_count;

	while (1)
	{
		printf("WTF\n");
		pthread_mutex_lock(&table->forks_lock[fork_l]);
		if (table->forks[fork_l] == 1)
		{
			ft_pick_left(phil_th, table, fork_l);
			pthread_mutex_lock(&table->forks_lock[fork_r]);
			if (table->forks[fork_r] == 1)
			{
				ft_pick_right(table, fork_r);
				ft_status_write(phil_th, table, EAT);
				ft_usleep(table->time_e);
				ft_put_forks(table, fork_l, fork_r);
				break;
			}
		}
	ft_usleep(100);
	}
}

static void	ft_sleep(t_phil *phil_th, t_table *table)
{
	ft_status_write(phil_th, table, SLEEP);
	ft_usleep(table->time_s);
}

void	*ft_pthread(void *arg)
{
	t_phil	*phil_th;
	t_table	*table;
	size_t	dif;
	int		i;

	phil_th = (t_phil *)arg;
	table = phil_th->table;
	i = 0;
	phil_th->time_next_meal = ft_get_current_time();
	phil_th->time_start = ft_get_current_time();
	dif = 0;

	printf("%zu\n", ft_get_current_time());
	if (phil_th->id % 2)
		ft_usleep(100);
	while (1)
	{
		ft_status_write(phil_th, table, THINK);
		ft_pick_eat(phil_th, table);
		ft_sleep(phil_th, table);
		pthread_mutex_lock(&table->death_lock);
		if (table->death == 1)
		{
			pthread_mutex_unlock(&table->death_lock);
			break;
		}
		pthread_mutex_unlock(&table->death_lock);
		ft_usleep(100);
	}
	return (NULL);
}