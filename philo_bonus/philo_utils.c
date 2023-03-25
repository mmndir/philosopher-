/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:33 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:33 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
		if ((res > 2147483647 && sign == 1))
			return (0);
	}
	return (res * sign);
}

void	print(t_philo *philo, int id, char *is_doing)
{
	sem_wait(philo->info->printing);
	printf("%lli %i %s\n", get_time() - philo->start_time,
		id + 1, is_doing);
	sem_post(philo->info->printing);
}

void	philo_pause(int time_pause)
{
	long long	time;

	time = get_time();
	while (1)
	{
		if (get_time() - time >= time_pause)
			break ;
		usleep(500);
	}
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
