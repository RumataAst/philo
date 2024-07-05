/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:06:39 by akretov           #+#    #+#             */
/*   Updated: 2024/07/05 18:07:39 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_checker(void *arg)
{
	t_phil	**phil_th;
	int		i;
	size_t	time_start;
	size_t	time_now;
	t_table	*table;

	table = (t_table *)arg;
	phil_th = table->phil;
	time_now = 0;
	i = 0;
	// condition to start only once all threads were created
	// while (
	while (1)
	{
		i = 0;
		while (i < table->philo_count)
		{
			pthread_mutex_lock(&phil_th[i]->time_lock);
			time_now = ft_get_current_time();
			if (time_now - phil_th[i]->time_next_meal >= 0)
			{
				pthread_mutex_lock(&table->main_lock);
				printf("%zu %i had died\n", time_now - time_start, phil_th[i]->id);
				table->death = 1;
				pthread_mutex_unlock(&table->main_lock);
				pthread_mutex_unlock(&phil_th[i]->time_lock);
				return ;
			}
			pthread_mutex_unlock(&phil_th[i]->time_lock);
			i++;
		}
		ft_usleep(500);
	}
	// )
}

void	*ft_phread(void *arg)
{
	t_phil	*phil_th;
	int		i;
	t_table	*table;
	size_t	dif;

	phil_th = (t_phil *)arg;
	table = phil_th->table;
	i = 0;
	phil_th->time_next_meal = ft_get_current_time();
	phil_th->time_start = ft_get_current_time();
	dif = 0;
	while (table->death == 0)
	{
		//thinking
		//has taken a fork
		//eating
		//sleeping
		//repeat
	}
}
