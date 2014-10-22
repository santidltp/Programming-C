#include <stdio.h>
#include <string.h>

//function prototypes
int left_bitshifting(int number, int numberOfShifts);
int right_bitshifting(int number, int numberOfShifts);
int twos_complement(int number);
void printBinary(int number);

// void gryffindor(char* harry) {

//   char* potter = harry;

//   while (*potter != ‘\0’) {

//     char LOL = *potter;

//     if (LOL >= 0x61 && LOL <= 0x7A)
//       *potter = *potter – 0x20;

//     potter++;

//   }
// printf("%s\n",potter );
// // return potter;
// }

// int main(){

// // printf("%d\n", left_bitshifting(2,7) );//Left shifting
// // printf("%d\n", right_bitshifting(4,1) );//right shifting
// // printf("%d\n", twos_complement(17) );
// // printBinary(-3);
// 	//char a[6] = {'h','e','l','l','o','\0'};
// 	// char *s="santiago";
// 	// gryffindor(s) ;


// double ans = 10.0+2.0/4.0-2.0*3.0;

// printf("%f\n", ans);

// }
// void my_print(int *a, int n) {
//   printf("%d\n", *a);
//   if (n == 1)
//     return;
//   my_print( (a+1), n-1);
// }

// int main() {
//   int a[20];
//   int i=0;
//   for ( i = 0; i < 20;i++) {
//     a[i] = i;
//   }
//   my_print(a, 20);
// }

// int main(){
// 	union {

//   unsigned int word;

//   char bytes[4];

// } U;

// U.word = 0xDEADBEEF;
// int i=0;
// for(i=0; i<4; i++){
// 	// if(U.bytes[i]== 0xAD)
// 	printf("%x\n", 0xAD);
// }
// // printf("%d\n",U.bytes[2] );
// }

int main(){
	union {
  int q[10]; 
  struct {
    union {
      int n;
      char o[5];
    } C;
    char p[6];
  } B;
  unsigned int r[7];
  char s;
} A;

printf("%d\n",sizeof(A) );

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
