#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<memory.h>
int main()
{	int retval,shmid;
	void *memory=NULL;
	char *p;
	shmid=shmget((key_t)123456789,6,IPC_CREAT|0666);
	if(shmid<0)
		printf("Failure in creation ");
	
	printf("\n We are getting the shared memory created %d \n",shmid);
	memory=shmat(shmid,NULL,0);
	if(memory==NULL)
	{	printf("\n Attachment failure");
		return 0;
	}
	p=(char *)memory;
	printf("\n MESSAGE is %s \n",p);
	retval=shmdt(p);
	if(retval<0)
	{
		printf("detachment failure");
		return 0;
	}
	retval=shmctl(shmid,IPC_RMID,NULL);
return 0;
}

