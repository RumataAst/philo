/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_pthread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:18:11 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:28:45 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*ft_death(void *arg)
{
	t_table	*table;
	size_t	start_t;
	size_t	dif_t;

	start_t = ft_get_current_time();
	dif_t = ft_get_current_time() - start_t;
	printf("0 1 is thinking\n");
	printf("%zu 1 has taken a fork\n", dif_t);
	table = (t_table *)arg;
	ft_usleep(table->time_d);
	dif_t += table->time_d;
	printf("%zu 1 died\n", dif_t);
	return (NULL);
}

void	ft_dead_alone(t_table *table)
{
	pthread_t	dead;

	if (pthread_create(&dead, NULL, ft_death, table) != 0)
		write(1, "Failed to create thread\n", 25);
	if (pthread_join(dead, NULL) != 0)
		write(1, "Failed to join thread\n", 23);
}
