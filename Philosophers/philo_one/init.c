/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/19 11:25:24 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

int			init_fork(t_philo *philo, unsigned int n_philo)
{
	unsigned int i;

	i = 0;
	while (i < n_philo)
	{
		if (!(philo[i].m_fork1 = malloc(sizeof(pthread_mutex_t))))
			return (1);
		pthread_mutex_init(philo[i].m_fork1, NULL);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		philo[i].m_fork2 = philo[(i + 1) % n_philo].m_fork1;
		i++;
	}
	return (0);
}

int			init_display(t_philo *philo, unsigned int n_philo)
{
	unsigned int	i;
	pthread_mutex_t	*display;

	if (!(display = malloc(sizeof(pthread_mutex_t))))
		return (1);
	pthread_mutex_init(display, NULL);
	i = 0;
	while (i < n_philo)
	{
		philo[i].m_display = display;
		i++;
	}
	return (0);
}

int			init_philosopher(t_philo *philo, unsigned int n_philo)
{
	unsigned int i;

	if (init_fork(philo, n_philo))
		return (1);
	if (init_display(philo, n_philo))
		return (1);
	i = 0;
	while (i < n_philo)
	{
		philo[i].id = i + 1;
		i++;
	}
	return (0);
}
