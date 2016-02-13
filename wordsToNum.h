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

void wordsToNum();

/**
	function for converting words to numbers
	Accepts a number in word form (from zero to 1 million) and returns it in numerical form
**/
void wordsToNum(){
	char number[100];//for the input
	long num=0;
	int temp=0, i=0, size=0, a=0, flag=0, len=0;
	
	printf("\n\tEnter the word/s from zero to one million(Eg. nine hundred thousand nine): ");
	getchar();
	fgets(number, 100, stdin);//get the input from the user
	len = strlen(number);
	number[len-1] = '\0';//removing newline
	printf("\n\tWords:%s\n", number);
}
