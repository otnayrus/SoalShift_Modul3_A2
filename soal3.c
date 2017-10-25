#include<stdio.h>
#include<pthread.h>

int alive=1,lock1=0,lock2=0;

int statlohan=100, statkepiting=100;
void * delohan (void * arg){
  while(alive!=0){
   sleep(10);
   while(lock1!=0);
   lock1=1;
   statlohan-=15;
   if(statlohan<=0) alive=0;
   lock1=0;
  }
}

void * dekepiting (void * arg){
  while(alive!=0){
   sleep(20);
   while(lock2!=0);
   lock2=1;
   statkepiting-=10;
   if(statkepiting<=0) alive=0;
   lock2=0;
  }
}

int main(){

  pthread_t t1,t2,t3;
  pthread_create(&t1,NULL,delohan,NULL);
  pthread_create(&t2,NULL,dekepiting,NULL);
  int n,makan;
	
  while(alive!=0){
   printf("Kasih makan siapa? 1. Lohan , 2. Kepiting : ");
   scanf("%d",&n);
   if(n==1){
	while(lock1!=0);
	lock1=1;
	if(alive!=0) statlohan+=10;
	if(statlohan>100) alive=0;
	lock1=0;
   }
   else if(n==2){
	while(lock2!=0);
	lock2=1;
	if(alive!=0) statkepiting+=10;
	if(statkepiting>100) alive=0;
	lock2=0;
   }
   else printf("Salah command!\n");
  }
  return 0;
}
