#include <stdio.h>

//function prototypes
int left_bitshifting(int number, int shifts);


int main(){




printf("%d\n", left_bitshifting(2,7) );

}

//Function Definitions
int left_bitshifting(int number, int shifts){
	int x ;
		x = number << shifts; 
	return x;
}