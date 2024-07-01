/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:40:27 by akretov           #+#    #+#             */
/*   Updated: 2024/06/29 20:29:47 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_struct(t_arg *philo_arg)
{
	free(philo_arg->philo_stat);
	free(philo_arg->philo_meal);
	free(philo_arg->time_l);
	free(philo_arg->forks);
	free(philo_arg);
	exit(1);
}
