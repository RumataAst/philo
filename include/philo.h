/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:42 by akretov           #+#    #+#             */
/*   Updated: 2024/07/07 18:34:22 by akretov          ###   ########.fr       */
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

# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DEAD "died"

typedef struct s_philo_th
{
	struct s_table	*table;
	pthread_t		thread;
	pthread_mutex_t	time_lock; // lock for changing and reading time_next_meal
	size_t			time_next_meal;
	size_t			time_start;
	unsigned int	meals_eaten;
	unsigned int	id;
}	t_phil;

typedef struct s_table
{
	t_phil			**phil;
	pthread_mutex_t	*forks_lock; //lock for forks [0,0,0,0,0,..,n]
	pthread_mutex_t	main_lock; // lock for writing to terminal
	pthread_mutex_t	death_lock;
	size_t			time_d;
	size_t			time_s;
	size_t			time_e;
	int				*forks;
	int				*meals;
	int				death;
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

//threads_0.c
void		ft_start_thread(t_table *table);

//threads_1.c
void		ft_no_diet(t_table	*table);

//threads_2.c
void		*ft_checker(void *arg);

//threads_3.c
void		*ft_pthread(void *arg);

//threads_utils.c
void		ft_status_write(t_phil *phil_th, t_table *table, char *arg);
int			ft_check_death(t_table *table);
void		ft_mutex_init(t_table *table);
void		ft_mutex_destroy(t_table *table);

//DELETE TEST.c
void	ft_print_philo(t_table *table);

#endif
