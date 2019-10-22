#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
int main()
{	int retval,shmid;
	void *memory=NULL;
	char *p;
	shmid=shmget((key_t)123456789,6,IPC_CREAT|0666);
	if(shmid<0)
	{
		printf("Failure in creation ");
		shmid=shmget((key_t)123456789,6,0666);
	}
	printf("\n We are getting the shared memory created %d \n",shmid);
	memory=shmat(shmid,NULL,0);
	if(memory==NULL)
	{
		printf("\n Attachment failure");
		return 0;
	}
	p=(char *)memory;
	memset(p,'\0',6);
	memcpy(p,"hello",6);
	
	retval=shmdt(p);
	if(retval<0)
	{
		printf("detachment failure");
		return 0;
	}
}


/*[Aditya@localhost os]$ gcc sha1.c -o b
[Aditya@localhost os]$ gcc sha1.c -o a
[Aditya@localhost os]$ gcc sha2.c -o b
[Aditya@localhost os]$ ./a

 We are getting the shared memory created 229378 
[Aditya@localhost os]$ ./b

 We are getting the shared memory created 229378 

 MESSAGE is hello 
[Aditya@localhost os]$ ./a

 We are getting the shared memory created 262146 
[Aditya@localhost os]$ ./b

 We are getting the shared memory created 262146 

*/
