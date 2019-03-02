#include "stdio.h"
void pln(){
    printf("\nthis is the second func\n");
}
int sum(int a,int b){
	int c;
	c=a+b;
	return c;
}
int main(){
	int x;
    printf("this is the first seasion\n");
    //pln();
    //printf("this is the 3 seasion\n");
    x=sum(1,4);
    printf("%d",x);
    return 0;
}
