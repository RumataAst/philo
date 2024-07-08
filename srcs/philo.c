/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:48:30 by akretov           #+#    #+#             */
/*   Updated: 2024/07/08 18:47:56 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	t_table	*table;

	table = NULL;
	ft_check_pars(ac, av);
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		printf("Memory allocation failed\n");
		exit (4);
	}
	ft_struct_init(ac, av, table);
	ft_run_thread(table);
	print_all(table);
	fr_free_all(table, 0);
	return (0);
}
