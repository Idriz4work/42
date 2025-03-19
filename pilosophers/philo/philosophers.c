/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 14:01:53 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// this f
void	sleep_own(size_t i, t_philo *philo, char action)
{
	if (action == 's')
		usleep(philo->phil[i].time_sleep * 1000);
	if (action == 'e')
		usleep(philo->phil[i].time_eat * 1000);
	if (action == 's')
		action = 's';
}

int	philosopher_one(t_philo *philo, size_t i)
{
	while (1)
	{
		think(i, philo);
		if (is_alive(philo, i) == EXIT_FAILURE)
		{
			endtimes(i, philo);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

// calls routine tepending on number of args
// Optional: Small delay for odd-numbered philosophers to avoid initial contention
// Think first
// Then try to eat (all philosophers should attempt to eat)
// Then sleep
void	*philosopher_algo(void *arg)
{
	t_attr	*philosopher;
	int		i;

	philosopher = (t_attr *)arg;
	i = philosopher->number_p;
	if (i % 2 == 1)
		usleep(1000);
	if (philosopher->parent->n_philo == 0)
		if (philosopher_one(philosopher->parent, i) == EXIT_SUCCESS)
			return (NULL);
	while (is_alive(philosopher->parent, i) != EXIT_FAILURE)
	{
		think(i, philosopher->parent);
		philosopher->last_meal_time = time_since_last_meal(philosopher->parent,
				i);
		if (philosopher->last_meal_time > philosopher->time_die)
		{
			// endtimes(i, philosopher->parent);
			// return (NULL);
			;
		}
		attend_to_eat(philosopher->parent, i);
		send_to_sleep(i, philosopher->parent);
		philosopher->parent->dinner_count++;
	}
	return (NULL);
}

//
int	main(int argc, char **argv)
{
	t_philo		phil_array;
	static int	simulation = IS_ALIVE;

	if (input_parser(argc, argv, &phil_array) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	phil_array.time_passed = 0;
	if (init_threads(&phil_array, phil_array.n_philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
