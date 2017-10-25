#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int guncomparator(char * arr){
	if(strcmp(arr,"MP4A1")==0) return 0;
	else if(strcmp(arr,"PM2-V1")==0) return 1;
	else if(strcmp(arr,"SPR-3")==0) return 2;
	else if(strcmp(arr,"SS2-V5")==0) return 3;
	else if(strcmp(arr,"SPG1-V3")==0) return 4;
	else if(strcmp(arr,"MINE")==0) return 5;
	else return -1;
}

void main()
{
        key_t key = 1234;
	char plus[8];
	int i , n , shmid,val, *gun;
        shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
        gun = (int*)shmat(shmid, NULL, 0);
//inisialisasi
	for(i=0;i<6;i++) gun[i]=0;

	while(1){
	  printf("1. Lihat stok , 2. Tambah Senjata : ");
	  scanf("%d",&n);
	  if(n==1){
	    for(i=0;i<6;i++) if(gun[i]!=0) printf("%d=%d\n",i,gun[i]);
	  }
	  else if(n==2){
	    printf("Tambah : ");
	    scanf("%s%d",plus,&val);
	    i=guncomparator(plus);
	    if(i!=-1) gun[i]+=val;
	    else printf("Gak jual itu\n");
	  }
	  else if(n==0) break;
	  else printf("Input salah\n");
	}

        shmdt(gun);
        shmctl(shmid, IPC_RMID, NULL);
}
