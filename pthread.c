#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void* run1()
{
    while (1)
    {
        printf("i am run1\n");  /* code */
        sleep(1);
    }
    
    
}

void*  run2()
{
    while(1)
    {
    printf("i am run2\n");
    sleep(1.5);

    }
    
}

int main()
{
    pthread_t thread1,thread2;
     pthread_create(&thread1,NULL,run1,NULL);
     pthread_create(&thread2,NULL,run2,NULL);


     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
     return 0;


}