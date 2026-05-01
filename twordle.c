//Author: Layla McArthur
//Purpose: Project 10
//Date: 4-24-26

#include <stdio.h>
#include <stdbool.h>

#define WordLength 5
#define MaxGuess 6

void loadWord(char word[]);
void userGuess(char guess[]);
bool validGuess(char guess[]);
void lowercase(char str[]);
void compare(char guess[], char word[], char result[]);
void showResult(char guess[], char result[]);
bool win(char result[]);

void loadWord(char word[]){
	FILE *file = fopen("word.txt", "r");
	if (file == NULL){
		printf("Error\n");
		return;
		}
	fscanf(file, "%s", word);
	fclose(file);
	}
	
void lowercase(char str[]){
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
		str[i] += 32;
		}
	}
}

void userGuess(char guess[]){
	printf("Enter guess: ");
	scanf("%s", guess);
	lowercase(guess);
	}
	
bool validGuess(char guess[]){
	int length = 0;
	
	while(guess[length] != '\0'){
		if(guess[length] < 'a' || guess[length] > 'z'){
		return false;
		}
		length++;
	}
	return length == WordLength;
}
void compare(char guess[], char word[], char result[]){
	for(int i = 0; i < WordLength; i++){
		if(guess[i] == word[i]){
		result[i] = 'C';
		}
	else{
		bool found = false;
		for(int j = 0; j < WordLength; j++){
			if(guess[i] == word[j]){
			found = true;
			break;
			}
		}
		result[i] = found ? 'P':'_'; 
		}
	}
}

void showResult(char guess[], char result[]){
	for(int i = 0; i < WordLength; i++){
		if(result[i] == 'C'){
		printf("%c", guess[i] -32);
		}
		else{
			printf("%c", guess[i]);
			}
		}
		printf("\n");
	}
	
bool win(char result[]){
	for(int i = 0; i < WordLength; i++){
		if(result[i] != 'C'){
		return false;
		}
	}
	return true;
}

int main(){
char word[WordLength + 1];
char guess[WordLength + 1];
char result[WordLength];

loadWord(word);
int attempts = 0;

while(attempts < MaxGuess){
	userGuess(guess);
	if(!validGuess(guess)){
		printf("Invalid guess. Try again\n");
		continue;
		}
	compare(guess, word, result);
	showResult(guess, result);
	
	attempts++;
	
	if(win(result)){
		printf("You win!\n");
		return 0;
		}
	}
	printf("Out of guesses, Word was: %s\n", word);
	return 0;
	}

	
	
