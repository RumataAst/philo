/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:48:30 by akretov           #+#    #+#             */
/*   Updated: 2024/07/05 17:56:44 by akretov          ###   ########.fr       */
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

int	ft_philo_run(int ac, char *av[], t_table *table)
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
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		write(1, "Memory allocation failed\n", 26);
		return (2);
	}
	ft_struct_fill(ac, av, table);
	ft_start_thread(table);
	ft_print_philo(table);
	// ft_free_struct(table);
	return (0);
}

int	main(int ac, char *av[])
{
	t_table	*table;
	int		i;

	table = NULL;
	if (ac == 5 || ac == 6)
	{
		i = ft_philo_run(ac, av, table);
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
