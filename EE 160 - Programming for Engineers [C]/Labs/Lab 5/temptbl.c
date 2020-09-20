#include<stdio.h>

float tocelsius(float f) {
	return (5.0 * (f - 32) / 9.0);
}

int temptable(float start, float stop, float step){
    int i, number_of_lines = 0;
    float c;
	
	if(step < 0)
		step = step * -1;
	if(step < 0.001) {
		printf("No table--step of %f smaller than 0.001!\n", step);
		return 0;
	}

    printf("===F===|===C===\n");
    if(start < stop) {
        for(float i = start; i <= stop; i += step) {
            c = tocelsius(i);

            printf("%.2f  | %.2f  \n", i, c);
            number_of_lines++;
        }
    } else {
        for(float i = start; i >= stop; i -= step) {
            c = tocelsius(i);

            printf("%.2f  | %.2f  \n", i, c);
            number_of_lines++;
        }
    }

    printf("Computed %d temperatures\n\n", number_of_lines);
	
	return number_of_lines;
}   

int main (void) {
    float start, stop, step;

    printf("Enter start,stop and step: ");
    int flag = scanf("%f %f %f",&start,&stop,&step);
    
    while(flag != EOF) {
        //printf("%f %f %f",start,stop,step);
        temptable(start,stop,step);
        
        printf("Enter start,stop and step: ");
        flag = scanf("%f %f %f",&start,&stop,&step);
    }
	
}
