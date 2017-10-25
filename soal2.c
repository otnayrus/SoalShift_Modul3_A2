#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int poin1=0,poin2=0;
int board1[4][4],board2[4][4];
int jatahbermain;

void* pemain1(void * arg){
int x,i,j,trial=16,turn=4;
memset(board1,0,sizeof(board1[0][0])*16);
 while(poin1<10&&poin2<10&&trial!=0&&turn--){
	printf("Jumlah mine P1 : "); scanf("%d",&x); trial-=x;
	if(trial<0) x+=trial;
	while(x--){
	printf("Insert mine loc : ");
	scanf("%d %d",&i,&j);
	  if(board1[i][j]==0)board1[i][j]=1;
	  else {printf("Lubang sudah diproses\n"); x++;} 
	}
	jatahbermain=2;

	while(jatahbermain!=1);
	if(poin1>=10||poin2>=10) break;
	printf("Player 1 menebak! ");
	for(x=0;x<4;x++){
	  scanf("%d%d",&i,&j);
	  if(board2[i][j]==0) poin1++;
	  else if(board2[i][j]==1) poin2++;
	  else {printf("Sudah pernah terpilih\n"); x;}
	  board2[i][j]=2;
	}
	printf("p1%d p2%d\n",poin1,poin2);
 }
jatahbermain=2;
}


int main(){
	
	pthread_t t1,t2;
	pthread_create(&t1,NULL,pemain1,NULL);
	
	pthread_join(t1,NULL);
	return 0;
}
