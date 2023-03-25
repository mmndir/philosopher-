/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:10 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:10 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_die(void *philo)
{
	t_philo	*phil;
	int		i;

	phil = (t_philo *)philo;
	i = 0;
	while (1)
	{
		sem_wait(phil->info->eating);
		if (get_time() - phil->last_ate >= phil->info->time_die)
		{
			print(phil, phil->id, "died");
			while (i++ < phil->info->num_philo)
				sem_post(phil->info->stop);
			break ;
		}
		else
			sem_post(phil->info->eating);
	}
	return (NULL);
}
