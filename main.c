#include<stdio.h>
#include<stdlib.h>
#include"data.h"


int main()
{

	struct data dt1;
	dt1.setage=set_age;
	dt1.show=show;
	dt1.setage(&dt1,10);
	dt1.show(&dt1);

}


