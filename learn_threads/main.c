#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int share_varaible = 0;

void *run_thread(void *pid)
{
	int i = 0;
	while (i < 5)
	{
		share_varaible++;
		printf("printf %ld: varaible shared_memory is: %d\n", (long)pid, share_varaible);
		sleep(1);
		i++;
	}
	return (NULL);
}
//                                      <|-----------|>
int main(int argc, char **argv)
{
	pthread_t pth1;
	pthread_t pth2;

	pthread_create(&pth1,  NULL, run_thread, (void*)&pth1);
	pthread_create(&pth2,  NULL, run_thread, (void*)&pth2);
	
	pthread_join(pth1, NULL);
	pthread_join(pth2, NULL);
	
	printf("Final value is share_varaible is %d\n", share_varaible);

	return 0;	
}
