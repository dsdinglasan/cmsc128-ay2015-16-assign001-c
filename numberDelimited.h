/**
	Author: Dinglasan, Danika Mae S.
	Student Number: 2013-52048
	Section: CMSC 128 AB-2L
	Program Description: This program let the user cnovert a number to words, words to number, words to number with the specified currency and number with delimeters
	Date: February 14, 2016
**/

/**libraries**/
#include<stdio.h>
#include<string.h>

void numberDelimited();

/**
	Accepts three arguments: the first is the number from zero to 1 miliion, the second is the delimiter to be used (single character only) and third, the number of jumps when the delimiter will appear (from right most going to left most digit)
**/
void numberDelimited(){
	char number[7];//needed variables
	int jump, i=0, len=0, position;
	char delimeter;
	
	printf("\n\tEnter a number from 0 to 1000000(Eg. 900009): ");//get the input from the user
	scanf("%s", number);
	len = strlen(number);//get the string length
	printf("\n\tEnter the delimeter (one character only): ");//get the delimeter to be used
	getchar();
	scanf("%c", &delimeter);
	//printf("%c", delimeter);
	printf("\n\tEnter the number of jumps when the delimiter will appear from 0 to %d: ", len);//get the number of jumps when the delimiter will appear
	scanf("%d", &jump);
	position = len-jump;//get the position of the jump in the number
	position--;//deduct 1 because character index starts with 0
	printf("\n\tNumber with the delimeter: ");
	if(jump==len){//if the number of jumps indicated by the user is equal to the length of the number
		printf("%c", delimeter);//print the delimeter first
	}
	for(i=0;i<len;i++){//prints the number per digit from the highest place down to the lowest place
		printf("%c", number[i]);
		if(i==position){//if the index or place of the number is equal to the position resulted from the number of jumps indicated by the user
			printf("%c", delimeter);//print the delimeter
		}
	}
	printf("\n");
}
