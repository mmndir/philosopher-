/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:04 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:04 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->info->fork);
	print(philo, philo->id, "has taken a fork");
	sem_wait(philo->info->fork);
	print(philo, philo->id, "has taken a fork");
	sem_wait(philo->info->eating);
	philo->last_ate = get_time();
	philo->ate++;
	if (philo->ate == philo->info->must_eat)
		sem_post(philo->info->stop);
	sem_post(philo->info->eating);
	print(philo, philo->id, "is eating");
	philo_pause(philo->info->time_eat);
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
}

void	routine(t_philo *phil)
{
	if (phil->id % 2)
		usleep(2000);
	while (1)
	{
		philo_eat(phil);
		print(phil, phil->id, "is sleeping");
		philo_pause(phil->info->time_sleep);
		print(phil, phil->id, "is thinking");
	}
}
