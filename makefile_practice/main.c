#include <stdio.h>
#include "math.h"


int main() {
	int num1 = 10;
	int num2 = 5;

	int r_add = add(num1, num2);
	int r_sub = subtract(num1, num2);
	int r_mul = multiply(num1, num2);
	int r_divide = divide(num1, num2);

	printf("덧셈 결과 : %d\n", r_add);
	printf("뺄셈 결과 : %d\n", r_sub);
	printf("곱셈 결과 : %d\n", r_mul);
	printf("나눗셈 결과 : %d\n", r_divide);

	return 0;
}

