/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 03:00:13 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		init_state(int argc, char **argv, t_state *state)
{
	state->n_philo = ft_atou64(argv[1]);
	state->t_die = ft_atou64(argv[2]);
	state->t_eat = ft_atou64(argv[3]);
	state->t_sleep = ft_atou64(argv[4]);
	if (argc == 6)
		state->n_must_eat = ft_atou64(argv[5]);
}

int			init_philosopher(t_philo *philo, t_state *state)
{
	unsigned int	i;
	sem_t			*sem_forks;
	sem_t			*sem_display;

	sem_unlink("fork");
	sem_unlink("display");
	if ((sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, state->n_philo)) == SEM_FAILED)
		return (error_status(SEMOPEN));
	if ((sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1)) == SEM_FAILED)
		return (error_status(SEMOPEN));
	i = 0;
	while (i < state->n_philo)
	{
		philo[i].sem_forks = sem_forks;
		philo[i].sem_display = sem_display;
		philo[i].id = i + 1;
		i++;
	}
	return (0);
}
