#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

struct passer{
  char arr[100]; 
};

void* carikata (void * arg){
	char kata[100],dicari[100];
	struct passer * cari = (struct passer *) arg;
	strcpy(dicari,cari->arr);
	int jumlah = 0;	
	FILE * novel;
	novel = fopen("novel.txt","r");
	while(fscanf(novel,"%s",kata)!=EOF) {
		if(strcmp(kata,dicari)==0) jumlah++; 
	}
printf("%s : %d\n",dicari,jumlah);	
fclose(novel);
}

int main(int argv, char * argc[]){
	pthread_t t1[argv];
	int i;
	struct passer listkata;
	for(i=1;i<argv;i++){
	strcpy(listkata.arr,argc[i]);		
	pthread_create(&(t1[i]), NULL , carikata ,(void *) &listkata);
}
for(i=1;i<argv;i++) pthread_join(t1[i],NULL);
	
 return 0;
}
