/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:03:53 by akretov           #+#    #+#             */
/*   Updated: 2024/06/29 20:29:28 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// DELETE
void	ft_print_philo(t_arg *philo_arg)
{
	printf("Philo count is %i\nTime to die %zu\nTime to sleep %zu\nTime to Eat %zu\nPhilo_diet %i",
		philo_arg->philo_count, philo_arg->time_d, philo_arg->time_s, philo_arg->time_e, philo_arg->philo_diet);
	printf("\n");
	printf("forks : ");
	for (int i = 0; i < philo_arg->philo_count; i++)
	{
		printf("%i ", philo_arg->forks[i]);
	}
	printf("\n");
	printf("status : ");
	for (int i = 0; i < philo_arg->philo_count; i++)
	{
		printf("%i ", philo_arg->philo_stat[i]);
	}
	printf("\n");
	printf("Max meals : ");
	for (int i = 0; i < philo_arg->philo_count; i++)
	{
		printf("%i ", philo_arg->philo_meal[i]);
	}
	printf("\n");
	printf("Time left : ");
	for (int i = 0; i < philo_arg->philo_count; i++)
	{
		printf("%zu ", philo_arg->time_l[i]);
	}
}

int	ft_philo_run(int ac, char **av, t_arg *philo_arg)
{
	if (ft_check_arg(ac, av) != 0)
	{
		write(1, "Invalid argument\n", 18);
		return (ft_check_arg(ac, av));
	}
	if (ft_check_int(ac, av) != 0)
	{
		write(1, "Number should be int\n", 22);
		return (ft_check_int(ac, av));
	}
	philo_arg = (t_arg *)malloc(sizeof(t_arg));
	if (!philo_arg)
	{
		write(1, "Memory allocation failed\n", 26);
		return (2);
	}
	ft_struct_fill(ac, av, philo_arg);
	ft_start_thread(philo_arg);
	ft_print_philo(philo_arg);
	ft_free_struct(philo_arg);
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	*philo_arg;
	int		i;

	philo_arg = NULL;
	if (ac == 5 || ac == 6)
	{
		i = ft_philo_run(ac, av, philo_arg);
		if (i != 0)
			return (i);
	}
	else
	{
		write(1, "Incorrect number of arguments\n", 31);
		return (2);
	}
	return (0);
}
