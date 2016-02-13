/**
	Author: Dinglasan, Danika Mae S.
	Student Number: 2013-52048
	Section: CMSC 128 AB-2L
	Program Description: This program let the user cnovert a number to words, words to number, words to number with the specified currency and number with delimeters
	Date: February 14, 2016
**/

#include<stdio.h>
#include<string.h>
#include "Dinglasan_Danika.h"//contains the function menu and numToWords
#include "wordsToNum.h"
#include "wordsToCurrency.h"
#include "numberDelimited.h"


main(){
	
	int choice=5;
	
	/**
		asks the user his/her choice and perform the specific task
	**/
	
	while(choice!=0){
		menu();
		scanf("%d", &choice);
		switch(choice){
			case 0: printf("\t==========GOODBYE==========\n");
					break;
			case 1: printf("\t==========NUMBER TO WORDS==========\n");
					numToWords();//calls the function numToWords
					break;
			case 2: printf("\t==========WORDS TO NUMBER==========\n");
					wordsToNum();//calls the function wordsToNum()
					break;
			case 3: printf("\t==========WORDS TO CURRENCY==========\n");
					wordsToCurrency();//calls the fucntion wordsToCurrency
					break;
			case 4: printf("\t==========NUMBER DELIMITED==========\n");
					numberDelimited();//calls the function numberDelimeted
					break;
					
			default: printf("\tWRONG INPUT\n");
		}
	}
}
