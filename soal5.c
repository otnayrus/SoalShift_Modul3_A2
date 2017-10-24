#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void* cariifah (void * arg){
	char kata[100];
	int jumlah = 0;	
	FILE * novel;
	novel = fopen("novel.txt","r");
	while(fscanf(novel,"%s",kata)!=EOF) {
		if(strcmp(kata,"ifah")==0) jumlah++; 
	}
printf("ifah : %d\n",jumlah);	
fclose(novel);
}

int main(){
	pthread_t t1;
	pthread_create(&(t1), NULL , &cariifah , NULL);
	pthread_join(t1,NULL);
return 0;
}
