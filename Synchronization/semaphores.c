#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
int count = 0;

void *fun(void *arg)
{
	int loop = 3;
	int result = (int)arg;

	while(loop > 0)
	{
		if(count % 3 == result)
		{
			
			switch(result)	
			{
				case 0:
					printf("--- a \n");
					break;
				case 1:
					printf("--- b \n");
					break;
				case 2:
					printf("--- c \n");
					break;
				default:
					return NULL;
			}
			pthread_mutex_lock(&lock);
			count++;
			loop--;
			pthread_mutex_unlock(&lock);
		}
	}
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t t1, t2, t3;

	pthread_create(&t1, NULL, fun, (void *)0);
	pthread_create(&t2, NULL, fun, (void *)1);
	pthread_create(&t3, NULL, fun, (void *)2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	return 0;
	
}
