/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/22 00:01:17 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			main(int argc, char **argv)
{
	t_state		*state;
	t_philo		*philo;
	t_data		*data;

	if (check_args(argc, argv))
		return (error_status("Error: Invalid argument"));
	if (!(state = ft_calloc(1, sizeof(t_state))))
		return (1);
	init_state(argc, argv, state);
	if (!(philo = ft_calloc(state->n_philo, sizeof(t_philo))))
		return (1);
	if (init_philosopher(philo, state->n_philo))
		return (1);
	if (!(data = ft_calloc(state->n_philo + 1, sizeof(t_data))))
		return (0);
	launch(data, state, philo);
	monitor(state, philo);
	free(philo);
	free(state);
	free(data);
	return (0);
}
