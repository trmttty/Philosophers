/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 14:13:27 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		*check_alive(void *data)
{
	t_state			*state;
	t_philo			*philo;
	unsigned int	current_time;

	philo = ((t_data*)data)->philo;
	state = ((t_data*)data)->state;
	usleep(state->t_die * 1000);
	current_time = get_duration_time(state);
	if (philo->live && current_time - philo->last_meal >= state->t_die)
	{
		sem_wait(philo->sem_display);
		state->philo_dead = TRUE;
		display_manager(philo, state, EVENT_DEAD);
	}
	return (NULL);
}

void		*launch_philosophers(void *data)
{
	t_philo			*philo;
	t_state			*state;
	pthread_t		thread;
	unsigned int	i;

	i = 0;
	philo = ((t_data*)data)->philo;
	state = ((t_data*)data)->state;
	philo->live = TRUE;
	while (!state->philo_dead && (!state->n_must_eat || i < state->n_must_eat))
	{
		pthread_create(&thread, NULL, &check_alive, data);
		pthread_detach(thread);
		philo_take_forks(philo, state);
		philo_eat(philo, state);
		philo_sleep(philo, state);
		philo_think(philo, state);
		i++;
	}
	philo->live = FALSE;
	if (state->n_must_eat && i == state->n_must_eat)
		state->finish_meal_count++;
	return (NULL);
}

int			launch(t_philo *philo, t_state *state, t_data *data)
{
	pthread_t		thread;
	unsigned int	i;

	set_start_time(state);
	i = 0;
	while (i < state->n_philo)
	{
		data[i].philo = &philo[i];
		data[i].state = state;
		if (pthread_create(&thread, NULL, &launch_philosophers, &data[i]))
			return (error_status(PCREATE));
		if (pthread_detach(thread))
			return (error_status(PDETACH));
		i++;
	}
	return (0);
}
