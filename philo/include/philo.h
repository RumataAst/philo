/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:42 by akretov           #+#    #+#             */
/*   Updated: 2024/06/30 20:47:35 by akretov          ###   ########.fr       */
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

typedef struct s_thr
{
	pthread_t		p_th;
	pthread_mutex_t	*lock_forks;
	pthread_mutex_t	lock_write;
	size_t			*time_start;
	t_shared		shared	
}	t_th;

typedef struct s_arg
{
	pthread_mutex_t	*lock_fork;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	*lock_read;
	pthread_t		*p_th;
	size_t			*time_l;
	size_t			*next_meal;
	int				*philo_stat;
	int				*philo_meal;
	int				*forks;
	size_t			time_d;
	size_t			time_s;
	size_t			time_e;
	int				philo_count;
	int				philo_diet;
	int 			dinner_over;	
	t_th			phil[];
}	t_arg;

//check_arg.c
int			ft_check_int(int ac, char **av);
int			ft_check_arg(int ac, char **av);

//struct.c
void		ft_struct_fill(int ac, char **av, t_arg *philo_arg);

//utils_0.c
void		ft_free_struct(t_arg *philo_arg);
size_t		ft_get_current_time(void);
int			ft_usleep(size_t milliseconds);
long long	ft_atol(const char *str);
int			ft_isdigit(int c);

//utils_1.c
void		ft_free_struct(t_arg *philo_arg);

//threads_0.c
void		ft_start_thread(t_arg *philo_arg);

//threads_1.c
void		ft_no_diet(t_arg *philo_arg);

#endif
