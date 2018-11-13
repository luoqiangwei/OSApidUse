#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t g_mutex;
int g_cnt = 0;

void *func(void *arg)
{
    int loop = 3;
    int result = (int)arg;

    while(loop > 0)
    {
        if(g_cnt % 3 == result)
        {
            
            switch (result)
            {
                case 0:
                    printf("--- a\n");
                    break;
                case 1:
                    printf("--- b\n");
                    break;
                case 2:
                    printf("--- c\n");
                    break;
            }
            pthread_mutex_lock(&g_mutex);
            g_cnt++;
            loop--;
            pthread_mutex_unlock(&g_mutex);
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2, t3;
    pthread_mutex_init(&g_mutex, NULL);
    pthread_create(&t1, NULL, func, (void*)0);
    pthread_create(&t2, NULL, func, (void*)1);
    pthread_create(&t3, NULL, func, (void*)2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}