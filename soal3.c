#include<stdio.h>
#include<pthread.h>

int statlohan=100
void * delohan (void * arg){
  sleep(10);
  statlohan-=10;
}


int main(){
  pthread_t t1,t2;
  pthread_create(&t1,NULL,delohan,NULL);
  pthread_create(&t2,NULL,dekepiting,NULL);	
  
  return 0;
}
