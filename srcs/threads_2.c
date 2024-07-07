/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:06:39 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:49:33 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_checker(void *arg)
{
	t_phil			**phil_th;
	t_table			*table;
	unsigned int	i;
	size_t			time_start;
	size_t			time_now;
	size_t			time_next_m;

	table = (t_table *)arg;
	phil_th = table->phil;
	time_now = 0;
	time_start = ft_get_current_time();
	time_next_m = 0;
	i = 0;
	// condition to start only once all threads were created
	// while (
	ft_usleep(10000);
	printf("Checker %zu\n", ft_get_current_time());
	while (1)
	{
		i = 0;
		while (i < table->philo_count)
		{
			time_now = ft_get_current_time();
			pthread_mutex_lock(&phil_th[i]->time_lock);
			time_next_m = phil_th[i]->time_next_meal;
			pthread_mutex_unlock(&phil_th[i]->time_lock);
			if (time_next_m - time_now >= 0)
			{
				pthread_mutex_lock(&table->main_lock);
				printf("%zu %i died\n", time_now - time_start, phil_th[i]->id);
				pthread_mutex_lock(&table->death_lock);
				table->death = 1;
				pthread_mutex_unlock(&table->death_lock);
				pthread_mutex_unlock(&table->main_lock);
				return (NULL);
			}
			i++;
		}
		ft_usleep(500);
	}
	return (NULL);
	// )
}
