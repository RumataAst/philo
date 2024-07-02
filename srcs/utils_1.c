/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:40:27 by akretov           #+#    #+#             */
/*   Updated: 2024/07/02 12:26:02 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_struct(t_table *table)
{
	unsigned int	i;
	
	i = 0;
	if (table == NULL)
		return;

	// Free each philosopher's memory
	if (table->phil != NULL)
	{
		while (i < table->philo_count)
		{
			free(table->phil[i]);
			i++;
		}
		free(table->phil);
	}

	// if (table->forks_lock != NULL)
	// {
	// 	for (unsigned int i = 0; i < table->philo_count; ++i) {
	// 		pthread_mutex_destroy(&table->forks_lock[i]);
	// 	}
	// 	free(table->forks_lock);
	// }
	// // Destroy the main lock
	// pthread_mutex_destroy(&table->main_lock);
	free(table->forks);
	free(table->meals);
	free(table);
}