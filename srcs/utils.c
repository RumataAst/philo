/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:43:50 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 17:53:34 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long milliseconds)
{
	long	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long long	ft_atol(const char *str)
{
	int			minus;
	long long	number;

	minus = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (!(minus % 2))
		return (number);
	return (-number);
}
