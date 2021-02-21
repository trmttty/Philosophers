/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:22:07 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 00:39:22 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		init_state(int argc, char **argv, t_state *state)
{
	state->n_philo = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		state->meals = 1;
		state->eat_count = ft_atoi(argv[5]);
    }
}

int			init_philosopher(t_philo *philo, unsigned int n_philo)
{
	unsigned int	i;
	sem_t			*sem_forks;
	sem_t			*sem_display;

	i = 0;
	sem_unlink("fork");
	sem_unlink("display");
	sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, n_philo);
	sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	while (i < n_philo)
	{
		philo[i].sem_forks = sem_forks;
		philo[i].sem_display = sem_display;
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
	return (0);
}
