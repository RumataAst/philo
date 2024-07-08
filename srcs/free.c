/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:07:22 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:42:46 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	fr_free_all(t_table *table, int ex_num)
{
	int	i;

	i = 0;
	if (table->phil)
	{
		while (i < table->philo_n)
			free(table->phil[i++]);
		free(table->phil);
	}
	if (table->fork_lock)
		free(table->fork_lock);
	if (table)
		free(table);
	if (ex_num != 0)
		exit(ex_num);
	return (0);
}
