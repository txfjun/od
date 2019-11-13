#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int com(const void *a,const void *b)
{
    char *const *sa1= a;
    char *const *sb1= b;
    return strcmp(*sa1,*sb1);
}
// int com( const void *p1,const void *p2)
// {
//   return strcmp(( const char*)p1,(const char*)p2);
// }

// int com( const void *p1,const void *p2)
// {
//     return strcmp(*( char*const *)p1,*( char*const *)p2);
// }

// int cmpString ( const void *s1, const void *s2){
//      return strcmp(*(char * const *) s1, *(char * const *) s2);
//  }

int main()
{
     char *str[5]={"hello","word","find","123","pig"};
     qsort(str,5,sizeof(str[0]),com);
     for(int i=0;i<5;i++)
     {
         printf("%s\n",str[i]);
     }
    // char *p1="hello";
    // char *p2="aello";
    // printf("%d",com(p1,p2));
}