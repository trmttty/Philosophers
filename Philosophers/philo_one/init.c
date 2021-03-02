/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/03/02 09:42:30 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			init_state(int argc, char **argv, t_state *state)
{
	uint64_t	i;

	state->num_philo = ft_atou64(argv[1]);
	state->time_die = ft_atou64(argv[2]);
	state->time_eat = ft_atou64(argv[3]);
	state->time_sleep = ft_atou64(argv[4]);
	if (argc == 6)
		state->num_must_eat = ft_atou64(argv[5]);
	if ((state->m_display = ft_calloc(1, sizeof(pthread_mutex_t))) == NULL)
		return (error_status(NOMEM));
	pthread_mutex_init(state->m_display, NULL);
	if ((state->m_forks = ft_calloc(state->num_philo, sizeof(pthread_mutex_t))) == NULL)
		return (error_status(NOMEM));
	i = 0;
	while (i++ < state->num_philo)
		pthread_mutex_init(&state->m_forks[i], NULL);
	return (0);
}

int			init_philosopher(t_philo *philo, t_state *state)
{
	uint64_t	i;

	i = 0;
	while (i < state->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].m_rfork = &state->m_forks[i];
		philo[i].m_lfork = &state->m_forks[(i + 1) % state->num_philo];
		i++;
	}
	return (0);
}
