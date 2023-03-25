/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:45 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:45 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_process(t_philo *philo)
{
	pthread_t	check;

	pthread_create(&check, NULL, check_die, philo);
	routine(philo);
	pthread_detach(check);
}

void	destroy_process_sema(t_philo *philo)
{
	int	i;

	sem_close(philo[0].info->eating);
	sem_close(philo[0].info->printing);
	sem_close(philo[0].info->fork);
	sem_close(philo[0].info->stop);
	i = 0;
	while (i < philo->info->num_philo)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
}

void	create_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
		{
			printf("Can't create a new process\n");
			destroy_process_sema(philo);
			exit(1);
		}	
		else if (philo[i].pid == 0)
		{
			philo_process(&philo[i]);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i++ < philo->info->num_philo)
		sem_wait(philo->info->stop);
	destroy_process_sema(philo);
}
