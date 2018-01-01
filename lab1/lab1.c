#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>



void calculate(double eps, double x, int task_2){

	double Uk_1 = 1.0;
	double series = 1.0;
	int count = 1;
	int fact = 1;
	double R, abs_delta;

	x = fabs(x);
	while (x >= 2 * M_PI)
		x = x - 2 * M_PI;

	while (fabs(Uk_1) > eps){
		Uk_1 = -(x*x*Uk_1) / (2 * count*(2 * count - 1));
		series += Uk_1;
		count++;
	}
	
	R = x;
	for (int i = 1; i < 2 * count; i++){
		fact = fact*i;
		R = (R*x) / fact;
	}

	series += R;
	abs_delta = fabs(series - cos(x));

	if (task_2==0)
		printf("|%15E |%5d |%20E |%20E |\n", eps, count, abs_delta, R);
	if (task_2==1)
		printf("|%10f |%20E |%20E |\n", x, abs_delta, R);
}


int main(){
	double a = -30.3;
	double b = 7.4;
	double x =(a + b) / 2;
	double h = fabs((b - a) / 10);
	double eps;
	int i;
	printf("---------------------------------------------------------------------\n");
	printf("|%15s |%5s |%20s |%20s |\n", "eps", "n", "abs_delta", "R");
	printf("---------------------------------------------------------------------\n");

	eps = 1e-2;
	while (eps>1e-14){
		calculate(eps, x, 0);
		eps /= 100;
	}
	printf("---------------------------------------------------------\n");
	printf("|%10s |%20s |%20s |\n", "X", "abs_delta", "R");
	printf("---------------------------------------------------------\n");

	x = a;
	for (i = 1; i <= 11; i++){
		calculate(1e-8, x, 1);
		x = a + h*i;
	}

	return 0;
}