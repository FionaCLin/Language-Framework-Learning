#include <stdio.h>
#include <math.h>
int main(){
	float a,b,c;
	printf("Enter the sidelengths a,b,c of the triangle:\n");
	scanf("%f %f %f",&a,&b,&c);
	float s=(a+b+c)/2;
	float area = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("Enter the sidelengths a,b,c of the triangle:%f,%f,%f\n",a,b,c);
	printf("The area of triangle is %f\n",area);
}