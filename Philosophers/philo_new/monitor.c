/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/24 21:36:53 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		kill_philosophers(t_philo *philo, t_state *state)
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
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 42)
			return (42);
		else if (WEXITSTATUS(status) == 2)
		{
			state->num_finish_meal++;
			if (state->num_finish_meal == state->num_must_eat)
				return (2);
		}
	}
	return (0);
}

void		monitor(t_philo *philo, t_state *state)
{
	unsigned int		i;
	unsigned int		n_philo;
	int					status;

	i = 0;
	n_philo = 0;
	while (i < state->num_philo)
	{
		status = check_status(state);
		if (status == 42 || status == 2)
			break ;
		i++;
	}
	kill_philosophers(philo, state);
	if (status == 2)
		display_finish_all_meals(state);
}
