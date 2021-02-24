/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/24 14:46:36 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			init_state(int argc, char **argv, t_state *state)
{
	state->num_philo = ft_atou64(argv[1]);
	state->time_die = ft_atou64(argv[2]);
	state->time_eat = ft_atou64(argv[3]);
	state->time_sleep = ft_atou64(argv[4]);
	if (argc == 6)
		state->num_must_eat = ft_atou64(argv[5]);
	sem_unlink("fork");
	sem_unlink("display");
	if ((state->sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, state->num_philo / 2)) == SEM_FAILED)
		return (error_status(SEMOPEN));
	if ((state->sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1)) == SEM_FAILED)
		return (error_status(SEMOPEN));
	return (0);
}

int			init_philosopher(t_philo *philo, t_state *state)
{
	unsigned int	i;

	i = 0;
	while (i < state->num_philo)
	{
		philo[i].id = i + 1;
		i++;
	}
	return (0);
}
