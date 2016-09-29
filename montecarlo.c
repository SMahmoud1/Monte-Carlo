//========================================
//Author: Salma Mahmoud
//File Name: montecarlo.c
//=========================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//declare functions to be used
void print_val(int points);
double approximate(int points);

int main ()
{
	/* initialize random numbers */
	srand(time(0));
	//calls function print with 4 different inputs
	print_val(10);
	print_val(100);
	print_val(1000);
	print_val(10000);
}

double approximate(int points)
{
	//declare the variable types to be used in function
	double  inside,  outside, num_points, x, y, r;
	int count;
	
	//set count equal to the number of points to be generated
	count = points;
	//set inside and outside equal to zero to so keep track of the  
	//number of points within the unit circle
	inside=0;
	outside=0;
	//set a while loop to keep going while count is more that 0
	while(count > 0)
		{
		
		//set the x and y coordinate values to 0
		x=0;
		y=0;
		
	
		//generate a random point for both x and y coordinate 
		//between 0 and 1 with random generator
		x =((double)rand()/(double)RAND_MAX);
		y =((double)rand()/(double)RAND_MAX);
		
		//calculate r to determine if point is within unit circle
		r = (x*x) + (y*y);
			
		//if is less than or equal to 1
		if (r<= 1)
			{
			//add 1 to the variable inside
			inside = inside+1;
			}
		else
			{
			//add 1 to variable outside
			outside = outside+1;
			}
		//subtract 1 from count each time it iterates
		//through the while loop until it reaches zero
		count = count - 1;
		}
		
	//function returns the number of points inside the unit circle
	return (inside);
}

void print_val(int points)
{
	//declare the variable types for each variable
	int point;
	double  inside, error, approx, error_per;
	
	//set point equal to points so to call approximate with it
	//and printing purposes
	point = points;
	
	//calls function approximate in order to get the approximation of pi
	inside = approximate(point);
	
	//calculate the approximated value of pi based on 
	//number of points landing within the unit circle
	approx = (4* inside)/point;
	
	//calculate the error of the approximation
	error = (approx - M_PI )/(M_PI);
	
	//find the percent error and make it an absolute value
	error_per = fabs(error*100);
	
	//print the final outcome of number of points, approximated
	//value and the percentage error
	printf("points: %d, value: %lf, error: %lf%%\n", point, approx, error_per);
	
}
