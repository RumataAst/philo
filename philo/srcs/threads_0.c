/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:49:49 by akretov           #+#    #+#             */
/*   Updated: 2024/06/30 17:48:28 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*ft_death(void *arg)
{
	t_arg	*philo_arg;
	size_t	start_t;
	size_t	dif_t;

	start_t = ft_get_current_time();
	dif_t = ft_get_current_time() - start_t;
	printf("%zu 1 has taken a fork\n", dif_t);
	philo_arg = (t_arg *)arg;
	ft_usleep(philo_arg->time_d);
	dif_t += philo_arg->time_d;
	printf("%zu 1 died\n", dif_t);
	return (NULL);
}

static void	ft_dead_alone(t_arg *philo_arg)
{
	pthread_t	dead;

	if (pthread_create(&dead, NULL, ft_death, philo_arg) != 0)
		write(1, "Failed to create thread\n", 25);
	if (pthread_join(dead, NULL) != 0)
		write(1, "Failed to join thread\n", 23);
	ft_free_struct(philo_arg);
}



void	ft_start_thread(t_arg *philo_arg)
{
	if (philo_arg->philo_count == 1)
		ft_dead_alone(philo_arg);
	else if (philo_arg->philo_diet == 0)
		ft_no_diet(philo_arg);
	else
	{
		
	}
}