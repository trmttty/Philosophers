/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/27 15:09:44 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		delete_philosophers(t_philo *philo, t_state *state)
{
	uint64_t	i;

	i = 0;
	while (i < state->num_philo)
		kill(philo[i++].pid, SIGKILL);
}

static int	check_status(t_state *state)
{
	int		status;

	(void)state;
	status = 0;
	waitpid(-1, &status, 0);
	if ((status >> 8) == EXIT_PHILO_DEAD)
		return (EXIT_PHILO_DEAD);
	else if ((status >> 8) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}

static void	*monitor_finish_meals(void *data)
{
	t_state			*state;
	t_philo			*philo;
	uint64_t		i;

	philo = ((t_data*)data)->philo;
	state = ((t_data*)data)->state;
	i = 0;
	while (i < state->num_philo)
	{
		sem_wait(state->sem_finish_meals);
		i++;
	}
	sem_wait(state->sem_display);
	display_finish_all_meals(state);
	delete_philosophers(philo, state);
	return (NULL);
}

static void	monitor_meals(t_philo *philo, t_state *state, t_data *data)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &monitor_finish_meals, data))
	{
		delete_philosophers(philo, state);
		error_exit(state, PCREATE);
	}
	if (pthread_detach(thread))
	{
		delete_philosophers(philo, state);
		error_exit(state, PDETACH);
	}
}

void		monitor(t_philo *philo, t_state *state, t_data *data)
{
	uint64_t	i;
	int			status;

	if (state->num_must_eat)
		monitor_meals(philo, state, data);
	i = 0;
	while (i < state->num_philo)
	{
		status = check_status(state);
		if (status == EXIT_PHILO_DEAD || status == EXIT_FAILURE)
			break ;
		i++;
	}
	delete_philosophers(philo, state);
	if (status == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
