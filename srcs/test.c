/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:05:21 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:05:45 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_philo(t_table *table)
{
	printf("Philo count is %i\nTime to die %zu\nTime to sleep %zu\nTime to Eat %zu\nPhilo_diet %i",
		table->philo_count, table->time_d, table->time_s, table->time_e, table->philo_diet);
	printf("\n");
	printf("forks : ");
	for (unsigned int i = 0; i < table->philo_count; i++)
	{
		printf("%i ", table->forks[i]);
	}
	printf("\n");
	// printf("Max meals : ");
	// for (unsigned int i = 0; i < table->philo_count; i++)
	// {
	// 	printf("%i ", table->phil[i]->meals_eaten);
	// }
}