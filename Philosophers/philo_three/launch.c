/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 20:48:53 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*reaper(void *stock)
{
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;
	unsigned int	current_time;

	s = stock;
	data = s->data;
	philo = s->philo;
	usleep(data->t_die * ONE_MILLISEC);
	current_time = get_time(data->t_start_usec, data->t_start_sec);
	if (current_time - philo->last_meal >= data->t_die)
	{
		sem_wait(philo->sem_display);
		data->one_die = TRUE;
		display_manager(s, philo, EVENT_DEAD);
		exit(42);
	}
	return (NULL);
}

void		life_philosophers(t_stock *s, t_philo *philo)
{
	unsigned int	i;
	t_data			*data;
	pthread_t		death;

	i = 0;
	data = s->data;
	while (!data->one_die && (!data->meals || i < data->nb_meals))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &reaper, s);
		philo_take_fork(s, philo);
		philo_eat(s, philo);
		philo_sleep(s, philo);
		philo_think(s, philo);
		i++;
	}
	pthread_detach(death);
	if (data->one_die)
		exit(42);
	if (data->meals && i == data->nb_meals)
		data->meals_finish++;
	exit(2);
}

int			launch(t_stock *stock, t_data *data, t_philo *philo)
{
	unsigned int	i;

	get_time_start(data);
	i = 0;
	while (i < data->n_philo)
	{
		stock[i].philo = &philo[i];
		stock[i].data = data;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			life_philosophers(stock, &philo[i]);
		usleep(35);
		i++;
	}
	return (0);
}
