/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:27 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:27 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_info{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	int					done_eat;
	sem_t				*fork;
	sem_t				*eating;
	sem_t				*stop;
	sem_t				*count;
	sem_t				*death;
	sem_t				*printing;
}				t_info;

typedef struct s_philo
{
	int			ate;
	long long	last_ate;
	long long	start_time;
	int			id;
	int			died;
	pid_t		pid;
	t_info		*info;
}				t_philo;

int			ft_isdigit(int num);
void		create_process(t_philo *philo);
void		destroy_process_sema(t_philo *philo);
void		*check_done_eat_and_die(void *philo);
int			ft_atoi(char *str);
long long	get_time(void);
void		philo_pause(int time_pause);
void		*check_die(void *philo);
int			ft_check_died(t_philo *philo);
void		routine(t_philo *philo);
void		print(t_philo *philo, int id, char *is_doing);
void		info_init(t_philo *philo, t_info *info, int ac, char **av);
int			monitor_death_done_eat(t_philo *philo);

#endif