#include <stdio.h>
void TOH(int num, char source, char dest, char temp){
if (num == 1){
printf(" \nMove disk  from tower %c to tower %c ",source,dest);
return;
}
TOH(num - 1, source, temp, dest);
printf("\nMove disk  from tower %c to tower %c ",source,dest);
TOH(num - 1, temp, dest, source);
}
void main(){
int n;
printf("Tower Of Hanoi\n");
printf( "Number of discs : ");
scanf("%d",&n);
printf("The sequence of moves :\n");
TOH(n, 'A', 'B', 'C');

}