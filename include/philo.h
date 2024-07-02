/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:42 by akretov           #+#    #+#             */
/*   Updated: 2024/07/02 12:24:00 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_th
{
	struct s_table	*table;
	pthread_t		thread;
	size_t			time_next_meal;
	unsigned int	meals_eaten;
	unsigned int	id;
}	t_phil;

typedef struct s_table
{
	t_phil			**phil;
	pthread_mutex_t	*forks_lock;
	pthread_mutex_t	main_lock;
	size_t			time_d;
	size_t			time_s;
	size_t			time_e;
	unsigned int	*forks;
	unsigned int	*meals;
	unsigned int	philo_count;
	unsigned int	philo_diet;
}	t_table;

//check_arg.c
int			ft_check_int(int ac, char **av);
int			ft_check_arg(int ac, char **av);

//struct_init_0.c
void		ft_free_if_error(int i, t_table *table);
void		ft_struct_fill(int ac, char **av, t_table *table);

//struct_init_1.c
void		ft_init_meals(t_table *table);

//utils_0.c
size_t		ft_get_current_time(void);
int			ft_usleep(size_t milliseconds);
int			ft_isdigit(int c);
long long	ft_atol(const char *str);

//utils_1.c
void		ft_free_struct(t_table *table);

#endif
