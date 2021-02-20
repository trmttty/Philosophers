/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 12:40:54 by ttarumot         ###   ########.fr       */
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
	if (philo->life && current_time - philo->last_meal >= data->t_die)
	{
		sem_wait(philo->sem_display);
		data->one_die = TRUE;
		display_manager(s, philo, EVENT_DEAD);
	}
	return (NULL);
}

void		*life_philosophers(void *stock)
{
	unsigned int	i;
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;
	pthread_t		death;

	i = 0;
	s = stock;
	data = s->data;
	philo = s->philo;
	philo->life = TRUE;
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
	philo->life = FALSE;
	pthread_detach(death);
	if (data->meals && i == data->nb_meals)
		data->meals_finish++;
	return (NULL);
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
		if (pthread_create(&philo[i].thread, NULL, &life_philosophers, &stock[i]))
			return (1);
		usleep(35);
		i++;
	}
	return (0);
}
