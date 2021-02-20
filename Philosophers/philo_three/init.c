/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 12:03:38 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->meals = 1;
		data->nb_meals = ft_atoi(argv[5]);
    }
}

int			init_philosopher(t_philo *philo, unsigned int n_philo)
{
	unsigned int	i;
	sem_t			*sem_forks;
	sem_t			*sem_display;

	i = 0;
	sem_unlink("fork");
	sem_unlink("display");
	sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, n_philo);
	sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	while (i < n_philo)
	{
		philo[i].sem_forks = sem_forks;
		philo[i].sem_display = sem_display;
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
	return (0);
}
