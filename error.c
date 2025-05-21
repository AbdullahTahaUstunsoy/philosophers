#include "philo.h"
void	print_error1(char *str, t_table *table)
{
	printf("%s",str);
    free(table);
}

void print_error2(char *str,t_table *table, int counter)
{
    printf("%s",str);
    int i;

    i = 0;
    while (i < counter)
    {
        pthread_mutex_destroy(&table->philo[i].philo_eating_mutex);
        i++;
    }
    free(table->philo);
    free(table);
}

void	print_error3(char *str, t_table *table)
{ 
    printf("%s",str);
    int i;

    i = 0;
    while (i < table->number_of_philosophers)
    {
        pthread_mutex_destroy(&table->philo[i].philo_eating_mutex);
        i++;
    }
    free(table->philo);
    free(table);
}

void print_error4(char *str,t_table *table, int last_mutex, int flag)
{
    int i;

    i = -1;
    printf("%s",str);
    if (flag == 1)
        pthread_mutex_destroy(&(table->write_text));
    if (flag == 2)
    {
        pthread_mutex_destroy(&(table->write_text));
        pthread_mutex_destroy(&(table->die_check_mutex));
    }
    while (++i < last_mutex)
        pthread_mutex_destroy(table->forks+i);
    free(table->philo);
    free(table->forks);
    free(table);
}
void print_error5(char *str, t_table *table, int counter)
{
    int i;

    i = -1;
    printf("%s",str);
    while(++i < counter)
        pthread_join(table->philo[i].philosopher,NULL);    
    i = -1;
    while(++i < table->number_of_philosophers)
        pthread_mutex_destroy(table->forks+i);
    pthread_mutex_destroy(&(table->write_text));
    pthread_mutex_destroy(&(table->die_check_mutex));
    free(table->philo);
    free(table->forks);
    free(table);
}
