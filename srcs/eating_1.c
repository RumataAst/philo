/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:58:48 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 21:12:38 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	un_two(pthread_mutex_t *m1, pthread_mutex_t *m2)
{
	pthread_mutex_unlock(m1);
	pthread_mutex_unlock(m2);
}
