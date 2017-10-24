#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int main(int argv,int *argc[]){
	int i;	
	pthread_t t1[argv];
	for( i=1; i<=argv;i++){
		int num = atoi(argc[i]);
		pthread_create(&(t1[i]),NULL,faktorial,&num);
	}
      return 0;
}
