#include <stdio.h>

//function prototypes
int left_bitshifting(int number, int numberOfShifts);
int right_bitshifting(int number, int numberOfShifts);

int main(){

// printf("%d\n", left_bitshifting(2,7) );//Left shifting
printf("%d\n", right_bitshifting(4,1) );//right shifting

}

//Function Definitions
int left_bitshifting(int number, int numberOfShifts){
	int x ;
		x = number << numberOfShifts; 
	return x;
}
int right_bitshifting(int number, int numberOfShifts){
	int x;
	x= number >> numberOfShifts;
	return x;
}