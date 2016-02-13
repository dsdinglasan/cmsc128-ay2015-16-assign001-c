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
	char each_word[20];//for each word in the input
	char *array_of_words[20];//store the array of words of the input
	/**needed variables**/
	char *ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *tens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *twentys[10] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *place[3] = {"hundred", "thousand", "million"};
	long num=0;
	int temp=0, i=0, size=0, a=0, flag=0, len=0;
	
	printf("\n\tEnter the word/s from zero to one million(Eg. nine hundred thousand nine): ");
	getchar();
	fgets(number, 100, stdin);//get the input from the user
	len = strlen(number);
	number[len-1] = '\0';//removing newline
	printf("\n\tWords:%s\n", number);
	array_of_words[i] = strtok(number," ");//splits the collection of words by spaces
	
	/**splits the collection of words through strtok and storing each word to the array of words**/
	while(array_of_words[i]!=NULL)
	{
	   array_of_words[++i] = strtok(NULL," ");
	   size++;//getting the number of words
	}
	for(i=0;i<size;i++){//while there is still word
		if(flag==1){//if thousand word is encountered
			flag=0;
			temp=num;//storing the number to temp
			num=0;
		}
		strcpy(each_word, array_of_words[i]);//copies the word from the array of words to each_word
		//printf("%s\n", each_word);
		for(a=0;a<10;a++){//comparing the current word to the words one, two ... nine
			if(strcmp(each_word, ones[a])==0){
				num+=a;//adds the equivalent number to num
				break;
			}
		}
		for(a=0;a<10;a++){//comparing the current word to the words ten, eleven, ... nineteen
			if(strcmp(each_word, tens[a])==0){
				num = num + 10 + a;//adds the equivalent number to num
				break;
			}
		}
		for(a=0;a<10;a++){//comparing the current word to the word twenty, thirty, ... ninety
			if(strcmp(each_word, twentys[a])==0){
				num = num + (a*10);//adds the equivalent number to num
				break;
			}
		}
		for(a=0;a<3;a++){//comparing the current to the words of number places
			if(strcmp(each_word, place[a])==0){
				switch(a){
					case 0: num = num * 100;//adding/multiplying the equivalent number to num to get the right number
							break;
					case 1: num = num * 1000;
							flag=1;//to check if 3 digits are already converted
							break;
					case 2: num = num * 1000000;
							break;
				}
				break;
			}
		}
		//printf("%s: %ld\n", each_word, num);
	}
	num = temp + num;//adds temp to num to get the total num
	printf("\tNumber: %ld\n", num);
}
