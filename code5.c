#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int chunk=100;
int array[1000];
void * sumfunction(void* s){
	int start=(int)s;
	int sum=0;
	for(int i=start;i<start+chunk;i++)sum+=array[i];
	return (void *)sum;
}
int main(){
	int sum=0;
	void *v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10;
	for(int i=0;i<1000;i++)array[i]=i;
	pthread_t p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	pthread_create(&p1,NULL,sumfunction,(void *)0);
	pthread_create(&p2,NULL,sumfunction,(void *)100);
	pthread_create(&p3,NULL,sumfunction,(void *)200);
	pthread_create(&p4,NULL,sumfunction,(void *)300);
	pthread_create(&p5,NULL,sumfunction,(void *)400);
	pthread_create(&p6,NULL,sumfunction,(void *)500);
	pthread_create(&p7,NULL,sumfunction,(void *)600);
	pthread_create(&p8,NULL,sumfunction,(void *)700);
	pthread_create(&p9,NULL,sumfunction,(void *)800);
	pthread_create(&p10,NULL,sumfunction,(void *)900);
	pthread_join(p1,(void **)&v1);
	pthread_join(p2,(void **)&v2);
	pthread_join(p3,(void **)&v3);
	pthread_join(p4,(void **)&v4);
	pthread_join(p5,(void **)&v5);
	pthread_join(p6,(void **)&v6);
	pthread_join(p7,(void **)&v7);
	pthread_join(p8,(void **)&v8);
	pthread_join(p9,(void **)&v9);
	pthread_join(p10,(void **)&v10);
	sum+= (int)v1+(int)v2+(int)v3+(int)v4+(int)v5+(int)v6+(int)v7+(int)v8+(int)v9+(int)v10;
	printf("Sum is : %d",sum);
	printf("\n");
	return 0;
}
