/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:47:54 by akretov           #+#    #+#             */
/*   Updated: 2024/06/30 19:49:56 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_check_death(void *arg)
{
	t_arg	*philo_arg;
	int		i;

	philo_arg = (t_arg *)arg;
	i = 0;
	while (philo_arg->philo_stat[i] != 4)
	{
		i++;
		if (i == philo_arg->philo_count)
			i = 0;
		printf("%i vs %i\n", i, philo_arg->philo_stat[i]);
		ft_usleep(500);
	}
	return ((void *)(intptr_t)i);
}

static void ft_thread_d(t_arg *philo_arg)
{
	pthread_t	dead;
	void		*thread_result;
	size_t		start_t;
	size_t		dif_t;

	start_t = ft_get_current_time();
	if (pthread_create(&dead, NULL, ft_check_death, philo_arg) != 0)
	{
		write(1, "Failed to create thread\n", 25);
		return;
	}
	ft_usleep(500);
	philo_arg->philo_stat[3] = 4;
	if (pthread_join(dead, &thread_result) != 0)
	{
		write(1, "Failed to join thread\n", 23);
		return;
	}
	dif_t = ft_get_current_time() - start_t;
	printf("%zu %d has died\n", dif_t, (int)(intptr_t)thread_result);
	// destroy_thread(dead);
	// ft_destroy_threads(philo_arg);
	// ft_free_struct(philo_arg);
}

void	ft_no_diet(t_arg *philo_arg)
{
	// int			i;

	ft_thread_d(philo_arg);
	ft_usleep(500);
	philo_arg->philo_stat[3] = 4;
}
