#include<stdio.h>
#include"data.h"


  void set_age(struct data *p,int age)
{
	p->age = age;

}



 static void datashow(struct data *p)
{
	printf("age=%d\n",p->age);

}

void show (struct data *p)
{
	datashow(p);
}