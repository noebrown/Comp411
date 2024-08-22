#include <stdio.h>

int main( int argc, char** argv ) {

	int choice;
	float result1;
	float clockcylce1;
	float result2;
	float clockcyle2;
	float clockcyle;
	float programinstruct2;
	float ccperinstruct2;

	printf("Please select the computation you want to make: (1 = clock rate, 2 = CPU time): ");
	scanf("%d", &choice);

	if(choice == 1) {

		printf("You selected clock rate, please enter the duration of one clock cycle in seconds: ");
		scanf("%f", &clockcylce1);
		result1 = 1/clockcylce1;
		printf("The clock rate corresponding to this duration is: %.1f Hertz.", result1);

	} else if (choice == 2) {

		printf("You selected CPU time, please enter the duration of one clock cycle in seconds: ");
		scanf("%f", &clockcyle2);
		printf("You selected CPU time, please enter the number of instructions in the program: ");
		scanf("%f", &programinstruct2);
		printf("You selected CPU time, please enter the number of clock cycles per instruction: ");
		scanf("%f", &ccperinstruct2);
		clockcyle = 1/clockcyle2;
		result2 = (programinstruct2)*(ccperinstruct2)*(clockcyle2);
		printf("The CPU execution time corresponding to these parameters: %.1f seconds.", result2 );
	}
	return(0);
}

