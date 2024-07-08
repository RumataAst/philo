/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTING.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:41:38 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:06:57 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_all(t_table *table)
{
	printf("Main struct:\n");
	printf("Time to die %i\n", table->time_d);
	printf("Time to eat %i\n", table->time_e);
	printf("Time to sleep %i\n", table->time_s);
	printf("Party time %lli\n", table->time_start);
	printf("End flag %i\n", table->end);
	printf("Philo count %i\n", table->philo_n);
	printf("Diet %i\n", table->philo_diet);

	printf("Philo:\n");
	for (int i = 0; i < table->philo_n; i++)
	{
		printf("ID %i\n", table->phil[i]->id);
		printf("Time till next meal %lli\n", table->phil[i]->time_next_meal);
		printf("How many meals eaten %i\n", table->phil[i]->meals_eaten);
	}
}