/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:26:44 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:31:59 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_status_write(t_phil *phil_th, t_table *table, char *arg)
{
	pthread_mutex_lock(&table->main_lock);
	printf("%zu ", ft_get_current_time() - phil_th->time_start);
	printf("%i ", phil_th->id + 1);
	printf("%s\n", arg);
	pthread_mutex_unlock(&table->main_lock);
}

int ft_check_death(t_table *table)
{
	if (table->death == 1)
		return (1);
	return (0);
}

void	ft_mutex_init(t_table *table)
{
	t_phil			**phil_th;
	unsigned int	i;

	phil_th = table->phil;
	i = 0;
	pthread_mutex_init(&table->main_lock, NULL);
	while (i < table->philo_count)
	{
		pthread_mutex_init(&table->forks_lock[i], NULL);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_init(&phil_th[i]->time_lock, NULL);
		i++;
	}
}

void	ft_mutex_destroy(t_table *table)
{
	t_phil			**phil_th;
	unsigned int	i;

	phil_th = table->phil;
	i = 0;
	pthread_mutex_destroy(&table->main_lock);
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&table->forks_lock[i]);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&phil_th[i]->time_lock);
		i++;
	}
}
