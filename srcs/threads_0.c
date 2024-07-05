/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:30:08 by akretov           #+#    #+#             */
/*   Updated: 2024/07/05 16:01:17 by akretov          ###   ########.fr       */
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

static void	ft_dead_alone(t_table *table)
{
	pthread_t	dead;

	if (pthread_create(&dead, NULL, ft_death, table) != 0)
		write(1, "Failed to create thread\n", 25);
	if (pthread_join(dead, NULL) != 0)
		write(1, "Failed to join thread\n", 23);
	ft_free_ft_no_dietstruct(table);
}

void	ft_start_thread(t_table *table)
{
	if (table->philo_count == 1)
		ft_dead_alone(table);
	else if (table->philo_diet == 0)
		ft_no_diet(table);
	// else
	// {

	// }
}
