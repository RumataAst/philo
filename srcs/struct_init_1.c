/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:16:17 by akretov           #+#    #+#             */
/*   Updated: 2024/07/02 12:26:04 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init_meals(t_table *table)
{
	table->meals = (unsigned int *)malloc(sizeof(int) * table->philo_count);
	if (!table->meals)
	{
		ft_free_if_error(table->philo_count, table);
		exit(5);
	}
}