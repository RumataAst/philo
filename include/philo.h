/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:42 by akretov           #+#    #+#             */
/*   Updated: 2024/07/14 21:09:57 by akretov          ###   ########.fr       */
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
	struct s_table	*table;			//main struct
	pthread_t		thread;			//thread
	pthread_mutex_t	time_lock;		//lock for time_next_meal
	long			time_next_meal;	//when to eat
	int				meals_eaten;	//how many meals
	int				id;				//which philo
}	t_phil;

typedef struct s_table
{
	t_phil			**phil;		//create n structs
	pthread_t		waiter;		//thread for checker
	pthread_mutex_t	*fork_lock;//lock for forks [0,0,0,0,0,..,n]
	pthread_mutex_t	main_lock;	//lock for writing to terminal
	pthread_mutex_t	end_lock;	//lock to check if somebody died
	long			time_start;	//time when every thread is created
	int				time_d;		//time to die
	int				time_e;		//time to eat
	int				time_s;		//time to sleep
	int				end;		//flag for death
	int				philo_n;	//how many philo
	int				philo_diet;	//how many meals they need to eat
}	t_table;

//check_arg.c
void		ft_check_pars(int ac, char *av[]);

//utils.c Time + atol
long		ft_get_current_time(void);
int			ft_usleep(long milliseconds);
int			ft_isdigit(int c);
long long	ft_atol(const char *str);

//struct_init.c
void		ft_struct_init(int ac, char *av[], t_table *table);

//free.c
int			fr_free_all(t_table *table, int ex_num);

//one_pthread.c
void		ft_dead_alone(t_table *table);

//checker_thread.c
void		*checker(void *arg);

//philo_thread.c
int			check_end(t_table *table);
void		*routine(void *arg);

//thread_0.c
void		ft_run_thread(t_table *t);

//thread_1.c
void		ft_norm(t_table *t);

//eating.c
void		ft_eating(t_table *table, t_phil *phil_th, long time);

//eating_1.c
void		un_two(pthread_mutex_t *m1, pthread_mutex_t *m2);

#endif
