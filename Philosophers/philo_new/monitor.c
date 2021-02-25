/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/25 09:24:47 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		delete_philosophers(t_philo *philo, t_state *state)
{
	unsigned int	i;

	i = 0;
	while (i < state->num_philo)
		kill(philo[i++].pid, SIGKILL);
}

int			check_status(t_state *state)
{
	int		status;

	status = 0;
	waitpid(-1, &status, 0);
	if ((status >> 8) == EXIT_PHILO_DEAD)
		return (EXIT_PHILO_DEAD);
	else if ((status >> 8) == EXIT_FINISH_MEALS)
	{
		state->num_finish_meal++;
		if (state->num_finish_meal == state->num_philo)
			return (EXIT_FINISH_MEALS);
	}
	else if ((status >> 8) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}

void		monitor(t_philo *philo, t_state *state)
{
	unsigned int		i;
	int					status;

	i = 0;
	while (i < state->num_philo)
	{
		status = check_status(state);
		if (status == EXIT_PHILO_DEAD || status == EXIT_FINISH_MEALS || status == EXIT_FAILURE)
			break ;
		i++;
	}
	kill_philosophers(state, philo);
	if (status == EXIT_FINISH_MEALS)
	{
		sem_wait(state->sem_display);
		display_finish_all_meals(state);
	}
	if (status == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
