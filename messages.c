#include "philo.h"

void print_message(t_table *table, long long time_difference, int philosopher_id, char *str)
{
    pthread_mutex_lock(&table->die_check_mutex);
    if (!table->die_check_flag) {
        pthread_mutex_lock(&table->write_text);
        printf("%lld %d %s\n", time_difference, philosopher_id + 1, str);
        pthread_mutex_unlock(&table->write_text);
    }
    pthread_mutex_unlock(&table->die_check_mutex);
}

void print_message2(t_table *table, long long time_difference, int philosopher_id, char *str)
{
    pthread_mutex_lock(&(table->write_text));
    printf("%lld %d %s\n", time_difference, philosopher_id + 1,str);
    pthread_mutex_unlock(&(table->write_text));
}