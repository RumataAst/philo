/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:52:05 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:57:25 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_checker_thread(void *arg)
{
	t_phil	**phil_th;
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	phil_th = table->phil;
	i = 0;
}

void	ft_checker(t_table *table)
{
	
}