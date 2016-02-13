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

void menu();
void numToWords();
/**
	function for printing the menu
**/
void menu(){
	printf("\t ===================================== \n");
	printf("\t|        CHOOSE AN OPERATION          |\n");
	printf("\t|       [1] - Number to Words         |\n");
	printf("\t|       [2] - Words to Number         |\n");
	printf("\t|       [3] - Words to Currency       |\n");
	printf("\t|       [4] - Number Delimited        |\n");
	printf("\t|       [0] - Exit                    |\n");
	printf("\t ===================================== \n\n");
	
	printf("\tYour Choice: ");
}
/**
	function for converting number to words
	Accepts a whole number from zero (0) to 1 million (1000000; without commas for example: 1,000,000) and prints on screen the number in word form
**/
void numToWords(){
	long num;
	printf("\n\tEnter a number from 0 to 1000000(Eg. 900009): ");
	scanf("%ld", &num);
	
	//needed variables
	int no_of_digits = 0, curr_position, current_no, dividend = 1, quotient, remainder;
	char *number_ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *number_tens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *number_tys[10] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	
	if(num>1000000||num<0){//more than millions place
		printf("INVALID INPUT!\n");
	}
	else{
		if(num==0){//just print zero if the given number is 0
			printf("%s\n", number_ones[0]);
		}
		else{//else perform the parsing of each digit and converting it to its equivalent word
			printf("\n\tANSWER: ");
			current_no = num;
			while(current_no>=10){//counts the number of digits and initializes dividend to be used in the latter part of the program
				no_of_digits++;
				current_no= current_no/10;
				dividend*=10;
			}
			current_no = num;
			no_of_digits++;
			curr_position = no_of_digits-1;//assigns the position of the largest place in curr_position
			while(curr_position>=0){//while curr_posiition is not yet in the end of the number
				quotient = current_no / dividend;//get the digit in the position of curr_position
				remainder = current_no%dividend;//get the remainder
				if(quotient!=0){//don't print anything if the quotient is 0
					switch(curr_position){
						case 0: if(dividend==1){//print the ones place if the dividend is 1
									printf("%s ", number_ones[quotient]);
									curr_position--;
								}
								else{
									curr_position--;
								}
								break;
						case 1: if(current_no/10==1&&current_no%10!=0||current_no==10){//for the cases of ten, eleven... nineteen
									printf("%s ", number_tens[remainder]);//print the word
									curr_position-=2;//skip two positions
									}
									else{
										printf("%s ", number_tys[quotient]);//for the cases of twenty, ... ninety
										current_no = remainder;//assigns remainder to current_no for further computations 
										curr_position--;
										dividend = dividend/10;//updates the dividend
									}
								break;
						case 2: printf("%s ", number_ones[quotient]);//print the word
								printf("hundred ");
								//updates current_no, dividend and curr_position
								current_no = remainder;
								dividend = dividend/10;
								curr_position--;
								break;
						case 3: printf("%s ", number_ones[quotient]);//print the word
								printf("thousand ");
								//updates current_no, dividend and curr_position
								current_no = remainder;
								dividend = dividend/10;
								curr_position--;
								break;
						case 4: if(current_no/10000==1&&current_no%10000!=0||current_no==10000){//for the cases of ten, eleven .. nineteen
									printf("%s ", number_tens[remainder/1000]);//print the word
									curr_position-=2;//skip 2 positions
									current_no= current_no%1000;//update
									dividend = dividend /100;
									printf("thousand ");
								}
								else{
									printf("%s ", number_tys[quotient]);//for the cases of twenty, .. ninety
									current_no = remainder;//update
									dividend = dividend/10;
									curr_position--;
									if(current_no==0||remainder<1000){
										printf("thousand ");
									}
								}
								break;
						case 5: printf("%s ", number_ones[quotient]);//print the word
								printf("hundred ");
								current_no = remainder;//update
								dividend = dividend/10;
								curr_position--;
								break;
						case 6: printf("%s ", number_ones[quotient]);//print the word
								printf("million ");
								current_no = remainder;//update
								dividend = dividend/10;
								curr_position--;
								break;
					}
				}
				else{//if the quotient is 0, update the necessary variables
					current_no = remainder;
					dividend = dividend/10;
					curr_position--;
				}
			}
			printf("\n\n");
		}
	}
}
