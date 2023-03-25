/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mndir <mndir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:40:40 by mndir             #+#    #+#             */
/*   Updated: 2023/03/25 15:40:40 by mndir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check(int ac, char **av)
{
	int			i;
	int			j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	double_check(int ac, char **av)
{
	if (ft_atoi(av[1]) > 200
		|| ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60 || ft_atoi(av[1]) < 1)
		return (0);
	else if (ft_atoi(av[ac - 1]) < 1 && ac == 6)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_philo		philo;
	t_info		info;

	if (ac > 6 || ac < 5)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	if (check(ac, av) == 0)
	{
		printf("Error found letter in arguments\n");
		return (0);
	}
	if (double_check(ac, av) == 0)
	{
		printf("Invalid arguments\n");
		return (0);
	}
	info_init(&philo, &info, ac, av);
	return (0);
}
