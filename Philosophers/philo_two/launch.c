/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 03:03:35 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		*reaper(void *data)
{
	t_data			*s;
	t_state			*state;
	t_philo			*philo;
	unsigned int	current_time;

	s = data;
	state = s->state;
	philo = s->philo;
	usleep(state->t_die * ONE_MILLISEC);
	current_time = get_time(state->t_start_usec, state->t_start_sec);
	if (philo->life && current_time - philo->last_meal >= state->t_die)
	{
		sem_wait(philo->sem_display);
		state->philo_dead = TRUE;
		display_manager(s, philo, EVENT_DEAD);
	}
	return (NULL);
}

void		*life_philosophers(void *data)
{
	unsigned int	i;
	t_data			*s;
	t_state			*state;
	t_philo			*philo;
	pthread_t		death;

	i = 0;
	s = data;
	state = s->state;
	philo = s->philo;
	philo->life = TRUE;
	while (!state->philo_dead && (!state->n_must_eat || i < state->n_must_eat))
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
	if (state->n_must_eat && i == state->n_must_eat)
		state->eat_count++;
	return (NULL);
}

int			launch(t_philo *philo, t_state *state, t_data *data)
{
	unsigned int	i;

	if (get_start_time(state))
		return (error_status(GETTIME));
	i = 0;
	while (i < state->n_philo)
	{
		data[i].philo = &philo[i];
		data[i].state = state;
		if (pthread_create(&philo[i].thread, NULL, &life_philosophers, &data[i]))
			return (error_status(PCREATE));
		i++;
	}
	return (0);
}
