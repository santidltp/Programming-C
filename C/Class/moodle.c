#include <stdio.h>

//function prototypes
int left_bitshifting(int number, int numberOfShifts);
int right_bitshifting(int number, int numberOfShifts);
int twos_complement(int number);

int main(){

// printf("%d\n", left_bitshifting(2,7) );//Left shifting
// printf("%d\n", right_bitshifting(4,1) );//right shifting
   printf("%d\n", twos_complement(-247) );
}

//Function Definitions
int left_bitshifting(int number, int numberOfShifts){
	return  number << numberOfShifts; 
}
int right_bitshifting(int number, int numberOfShifts){
	return number >> numberOfShifts;
}
int twos_complement(int number){
	return ~number | 1;
}