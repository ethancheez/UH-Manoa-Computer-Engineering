#include <stdio.h>

int ISquare(int x);

int ISquare(int x) {
	return x*x;
}

int main() {
	int input, output;

	while(1) {
		printf("Enter integer to square: ");
		scanf("%d" , &input);
		output = ISquare(input);
		printf("The output is: %d\n", output);
		if(output == 0) {
			return 0;
		}
	}
}
