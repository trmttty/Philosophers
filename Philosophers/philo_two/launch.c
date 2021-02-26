/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/26 16:11:07 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	*check_alive(void *data)
{
	t_state			*state;
	t_philo			*philo;
	unsigned int	current_time;

	philo = ((t_data*)data)->philo;
	state = ((t_data*)data)->state;
	while (1)
	{
		current_time = get_duration_time(state);
		if (current_time - philo->last_meal_start >= state->time_die * 1000)
		{
			philo->dead = TRUE;
			state->philo_dead = TRUE;
			sem_wait(state->sem_display);
			print_timestamp(data, current_time, ACTION_DEAD);
			break ;
		}
		else
			usleep(state->time_die * 1000 - (current_time - philo->last_meal_start));
	}
	return (NULL);
}

static void	*launch_philosophers(void *data)
{
	t_philo			*philo;
	t_state			*state;
	pthread_t		thread;
	unsigned int	i;

	philo = ((t_data*)data)->philo;
	state = ((t_data*)data)->state;
	if (pthread_create(&thread, NULL, &check_alive, data))
		return (error_exit(state, PCREATE));
	if (pthread_detach(thread))
		return (error_exit(state, PDETACH));
	i = 0;
	while (!state->philo_dead && (!state->num_must_eat || i < state->num_must_eat))
	{
		philo_take_forks(data);
		philo_eat(data);
		philo_sleep(data);
		philo_think(data);
		i++;
	}
	if (state->num_must_eat && i == state->num_must_eat)
		state->num_finish_meal++;
	return (NULL);
}

int			launch(t_philo *philo, t_state *state, t_data *data)
{
	pthread_t		thread;
	unsigned int	i;

	set_start_time(state);
	i = 0;
	while (i < state->num_philo)
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
