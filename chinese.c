
#include<stdio.h>
#include<stdlib.h>
#include <wchar.h>
#include <locale.h>
int main()
{


//    char str[6]="我是谁";
    wchar_t str[4]= L"我是谁";
    setlocale(LC_ALL, "zh_CN.UTF-8"); 
    wprintf(L"%ls\n",str);
    printf("%d",sizeof(str));
    
    return 0;
}