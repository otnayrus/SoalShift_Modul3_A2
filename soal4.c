#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void * faktorial(void * arg)
{
	int i;
	int num = (int) arg ;
	long long jumlah = 1 ;
	for(i=1;i<= num;i++) 
	{
		jumlah *=(long long) i;
	}
	printf("Hasil %d! = %lld\n",num,jumlah); 
}

int main(int argv,char *argc[])
{
	int i,l;	
	pthread_t t1[argv];
	for( i=1; i<argv;i++)
	{
		
		int num = atoi(argc[i]);
		pthread_create(&t1[i],NULL,faktorial,(void *)num);
		
	}
	for(l=1;l<argv;l++)
	{
		pthread_join(t1[l],NULL);
	}
      return 0;
}
