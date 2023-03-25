/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:15 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:15 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_sema(t_philo *philo)
{
	sem_unlink("/printing");
	sem_unlink("/eating");
	sem_unlink("/fork");
	sem_unlink("/stop");
	philo->info->stop = sem_open("/stop", O_CREAT, 0777, 0);
	philo->info->printing = sem_open("/printing", O_CREAT, 0777, 1);
	philo->info->eating = sem_open("/eating", O_CREAT, 0777, 1);
	philo->info->fork = sem_open("/fork", O_CREAT, 0777,
			philo->info->num_philo);
}

void	philo_init(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philo)
	{
		philo[i].info = info;
		philo[i].ate = 0;
		philo[i].id = i;
		philo[i].last_ate = get_time();
		philo[i].start_time = get_time();
	}
}

void	info_init(t_philo *philo, t_info *info, int ac, char **av)
{
	int	i;

	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	info = malloc(sizeof(t_info));
	info->num_philo = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	info->done_eat = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = 0;
	philo_init(info, philo);
	create_sema(philo);
	create_process(philo);
	philo->info = info;
	i = 0;
	while (i < philo->info->num_philo)
		waitpid(philo[i++].pid, NULL, 0);
	free(philo);
	free(info);
}
