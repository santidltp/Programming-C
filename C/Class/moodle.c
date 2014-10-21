#include <stdio.h>

//function prototypes
int left_bitshifting(int number, int numberOfShifts);
int right_bitshifting(int number, int numberOfShifts);
int twos_complement(int number);
void printBinary(int number);


int main(){

// printf("%d\n", left_bitshifting(2,7) );//Left shifting
// printf("%d\n", right_bitshifting(4,1) );//right shifting
// printf("%d\n", twos_complement(17) );
// printBinary(-3);
}

//Function Definitions
//computes a given number of left bitshifting
//to a given integer
int left_bitshifting(int number, int numberOfShifts){
	return  number << numberOfShifts; 
}
//computes a given number of right bitshifting
//to a given integer
int right_bitshifting(int number, int numberOfShifts){
	return number >> numberOfShifts;
}
//returns the Two's complement of a givne number
int twos_complement(int number){
	return ~number + 1;
}
//prints binary number of a given decimal.
void printBinary(int number){
int i=0;
	for(i=sizeof(double)-1; i>=0; --i){
	if(number & (1<< i))
		printf("1");
	else
		printf("0");
	}
	printf("\n");
}
