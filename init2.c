#include "philo.h"

int init_mutexes2(t_table *table)
{
	int i;
	int counter;

	i = -1;
	counter = 0;
	while (++i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			print_error4("Mutex init error",table,counter,0);
			return (0);
		}
		counter++;
	}
	if (pthread_mutex_init(&table->write_text, NULL))
	{
		print_error4("Mutex init error",table,counter,1);
		return (0);
	}
	if (pthread_mutex_init(&table->die_check_mutex,NULL))
	{
		print_error4("Mutex init error",table,counter,2);
		return (0);
	}
	return (1);
}

void init_philos2(t_table *table, int i)
{
    table->philo[i].id = i;
    table->philo[i].right_hand_id = i;
	table->philo[i].left_hand_id = (i - 1 + table->number_of_philosophers) % table->number_of_philosophers;
	table->philo[i].table = table;
	table->philo[i].meal_count = 0;
	table->philo[i].is_full_flag = 0;
	table->philo[i].last_eat_time = current_time();
}
