/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/25 21:13:22 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		init_state(int argc, char **argv, t_state *state)
{
	state->num_philo = ft_atou64(argv[1]);
	state->time_die = ft_atou64(argv[2]);
	state->time_eat = ft_atou64(argv[3]);
	state->time_sleep = ft_atou64(argv[4]);
	if (argc == 6)
		state->num_must_eat = ft_atou64(argv[5]);
	sem_unlink("fork");
	// if ((state->sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, state->num_philo / 2)) == SEM_FAILED)
	if ((state->sem_forks = sem_open("fork", O_CREAT, S_IRWXU, state->num_philo / 2)) == SEM_FAILED)
		exit_status(SEMOPEN);
	sem_unlink("display");
	if ((state->sem_display = sem_open("display", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		exit_status(SEMOPEN);
	sem_unlink("finish_meals");
	if ((state->sem_finish_meals = sem_open("finish_meals", O_CREAT, S_IRWXU, 1)) == SEM_FAILED)
		exit_status(SEMOPEN);
}

void		init_philosopher(t_philo *philo, t_state *state)
{
	uint64_t	i;

	i = 0;
	while (i < state->num_philo)
	{
		philo[i].id = i + 1;
		i++;
	}
}
