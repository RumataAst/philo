/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:59:33 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:45:25 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_no_diet(t_table *table)
{
	pthread_t		waiter;
	unsigned int	i;
	t_phil			**phil_th;
	
	i = 0;
	phil_th = table->phil;
	ft_mutex_init(table);
	if (pthread_create(&waiter, NULL, ft_checker, table) != 0)
	{
		printf("Failed to create checker thread\n");
		ft_free_struct(table);
		exit(6);
	}
	while (i < table->philo_count)
	{
		if (pthread_create(&table->phil[i]->thread, NULL, ft_pthread, table) != 0)
		{
			printf("Failed to create thread\n");
			ft_free_struct(table);
			exit(6);
		}
		i++;
	}
	if (pthread_join(waiter, NULL) != 0 )
	{
		printf("Failed to join checker thread\n");
		ft_free_struct(table);
		exit(6);
	}
	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_join(table->phil[i]->thread, NULL) != 0)
		{
			printf("Failed to join thread\n");
			ft_free_struct(table);
			exit(6);
		}
		i++;
	}
	ft_mutex_destroy(table);
}
