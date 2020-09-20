#include <stdio.h>
#include "square.h"

int main() {
	int input, output;

	while(1) {
		printf("Enter integer to square: ");
		scanf("%d", &input);
		output = ISquare(input);
		printf("The output is: %d\n", output);
		if(output == 0) {
			return 0;
		}
	}
}