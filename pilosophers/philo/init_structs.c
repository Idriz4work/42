/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:35:35 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/19 13:47:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Destroy mutexes && also make sure that everyhting is freed
// Destroy only the actually initialized mutexes
void	mutex_cleanup(t_philo *philo, size_t n_philo)
{
	size_t		i;
	static int	cleaned_up = 0;

	// Prevent multiple cleanup calls
	// Destroy all chopstick mutexes
	if (cleaned_up)
		return ;
	cleaned_up = 1;
	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_destroy(&philo->chop_sticks[i]);
		// Destroy global mutexes
		i++;
	}
	pthread_mutex_destroy(&philo->print_lock);
	pthread_mutex_destroy(&philo->dead_lock);
	pthread_mutex_destroy(&philo->meal_lock);
}

//
// First allocate philosopher array
// Then initialize global mutexes
int	init_mutexer(t_philo *philos)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 250)
	{
		if (pthread_mutex_init(&philos->chop_sticks[i], NULL) == -1)
		{
			while (j < i)
			{
				pthread_mutex_destroy(&philos->chop_sticks[j]);
				j++;
			}
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&philos->meal_lock, NULL) == -1
		|| pthread_mutex_init(&philos->print_lock, NULL) == -1
		|| pthread_mutex_init(&philos->dead_lock, NULL) == -1
		|| pthread_mutex_init(&philos->exit_lock, NULL) == -1)
	{
		printf("Error initializing global mutexes\n");
		free(philos->phil);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//
// Set mutex pointers
// Allocate thread
// init thread
int	init_philo(t_philo *philos, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		philos->phil[i].dead = 0;
		if (philos->dinner_count != -1)
			philos->phil[i].dinner_count = philos->dinner_count;
		philos->phil[i].number_p = i;
		philos->phil[i].state = IS_THINKING;
		philos->phil[i].time_sleep = philos->time_sleep;
		philos->phil[i].time_die = philos->time_die;
		philos->phil[i].time_eat = philos->time_eat;
		philos->phil[i].parent = philos;
		philos->phil[i].last_meal_time = 0;
		philos->phil[i].left_chop = i;
		philos->phil[i].right_chop = (i + 1) % n_philos;
		if (i % 2)
		{
			philos->phil[i].right_chop = i;
			philos->phil[i].left_chop = (i + 1) % n_philos;
		}
		if (pthread_create(philos->phil[i].threads, NULL, &philosopher_algo,
				(void *)&philos->phil[i]) == -1)
		{
			printf("Error init threads for philosopher %d\n", i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

// Allocate memory for the array of t_attr (one for each philosopher)
int	init_mem_philo(t_philo *philos, int n_philos)
{
	int	i;
	int	j;

	philos->phil = (t_attr *)malloc(sizeof(t_attr) * n_philos);
	if (!philos->phil)
	{
		printf("Memory allocation failed for philosophers\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (i < n_philos)
	{
		philos->phil[i].threads = malloc(sizeof(pthread_t));
		if (!philos->phil[i].threads)
		{
			j = 0;
			while (j < i)
			{
				free(philos->phil[j].threads);
				j++;
			}
			free(philos->phil);
			printf("Memory allocation failed for thread pointers\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_join_threads(t_philo *philos, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		if (pthread_join(*philos->phil[i].threads, NULL) == -1)
		{
			printf("Error JOINING threads for philosopher %d\n", i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

// Initialize threads and values
// join threads
int	init_threads(t_philo *philos, int n_philos)
{
	int	i;

	i = 0;
	philos->n_philo = n_philos;
	philos->time_passed = 0;
	philos->start_time = get_time_in_ms();
	if (init_mem_philo(philos, n_philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mutexer(philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_philo(philos, n_philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_join_threads(philos, n_philos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
