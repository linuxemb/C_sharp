// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


double tbl_rpm_to_duty[11][2] =
{
	{ 8600, 15 },
	{ 6600, 10 },
	{ 6000, 9.0 },
	{ 5000, 8.0 },
	{ 4500, 20.0 },
	{ 4000, 8.0 },
	{ 3500, 7 },
	{ 3000, 7 },
	{ 2000, 6.9 },
	{ 1000, 6.5 },
	{ 800, 7.5 }
};


/**
* My interpolation function
* should return linear interpolated second dimension value
* if the col_a value is greater it will return the highest value (capped results)
* results off the lower end of the chart will interpolate to zero
*/
double interp_table(double dbl_table[][2], int col_a)
{
	short i;
	double col_b_diff;

	for (i = 0; dbl_table[i][0]; i++) {
		if ((dbl_table[i][0] >= col_a) && (dbl_table[i + 1][0] <= col_a)) {
			col_b_diff = dbl_table[i][1] - dbl_table[i + 1][1];
			return dbl_table[i + 1][1] + col_b_diff *(col_a - dbl_table[i + 1][0]) / (dbl_table[i][0] - dbl_table[i + 1][0]);
		}
	}

	if (col_a > dbl_table[0][0]) {
		return dbl_table[0][1];
	}

	return 0;
}

int main(void)
{
	printf("%f\n", interp_table(tbl_rpm_to_duty, 9422));
	printf("%f\n", interp_table(tbl_rpm_to_duty, 500));
	printf("%f\n", interp_table(tbl_rpm_to_duty, 5400));
	int i;
	scanf_s("%c", &i);
	return 0;
}
