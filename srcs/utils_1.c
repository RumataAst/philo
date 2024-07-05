/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:40:27 by akretov           #+#    #+#             */
/*   Updated: 2024/07/05 16:00:41 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_struct(t_table *table)
{
	unsigned int	i;

	i = 0;
	if (table == NULL)
		return ;
	if (table->phil != NULL)
	{
		while (i < table->philo_count)
		{
			free(table->phil[i]);
			i++;
		}
		free(table->phil);
	}
	free(table->forks);
	free(table->meals);
	free(table);
	exit(1);
}
