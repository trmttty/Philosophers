/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/24 22:10:05 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			main(int argc, char **argv)
{
	t_philo		*philo;
	t_state		*state;
	t_data		*data;

	if (check_args(argc, argv))
		exit_status(INVAL);
	if (!(state = ft_calloc(1, sizeof(t_state))))
		exit_status(NOMEM);
	init_state(argc, argv, state);
	if (!(philo = ft_calloc(state->num_philo, sizeof(t_philo))))
		exit_status(NOMEM);
	init_philosopher(philo, state);
	if (!(data = ft_calloc(state->num_philo, sizeof(t_data))))
		exit_status(NOMEM);
	launch(philo, state, data);
	monitor(philo, state);
	free(philo);
	free(state);
	free(data);
	return (0);
}
