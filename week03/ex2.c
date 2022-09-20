#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct Point {
    double x, y;
};

float distance(struct Point A, struct Point B) {
	float result;
    float x1 = A.x, y1 = A.y;
    float x2 = B.x, y2 = B.y; 
	
    result = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
	return result;
}

float area(struct Point A, struct Point B, struct Point C){
	float result;
    float x1 = A.x, y1 = A.y;
    float x2 = B.x, y2 = B.y;
    float x3 = C.x, y3 = C.y;

    result = 0.5 * fabs(x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3);

	return result;
}

int main(void) {

	struct Point A = {2.5, 6};
	struct Point B = {1, 2.2};
	struct Point C = {10, 6};

	float f = distance(A, B);
	printf("A -- B distance is %f\n", f);

	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);

	return EXIT_SUCCESS;
}