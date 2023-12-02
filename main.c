#include <stdio.h>
#include <ctype.h>
#include <string.h>

// this is equivalent to #define MAX_STRING_SIZE 1000
const int MAX_STRING_SIZE = 1000;

int word_to_digit(char *character) {
    if (strncmp(character, "one", 3) == 0) {
        return 1; }
    if (strncmp(character, "two", 3) == 0) {
        return 2; }
    if (strncmp(character, "three", 5) == 0) {
        return 3; }
    if (strncmp(character, "four", 4) == 0) {
        return 4; }
    if (strncmp(character, "five", 4) == 0) {
        return 5; }
    if (strncmp(character, "six", 3) == 0) {
        return 6; }
    if (strncmp(character, "seven", 5) == 0) {
        return 7; }
    if (strncmp(character, "eight", 5) == 0) {
        return 8; }
    if (strncmp(character, "nine", 4) == 0) {
        return 9; }
    
    return 0;
}


int main() {
    // get a pointer to the data file
    FILE *input_file = fopen("./data/input1.txt", "r");
    char string[MAX_STRING_SIZE];
    // fgets() returns NULL when it reaches end-of-file
    // pull out one line from the file
    int answer = 0;
    while (fgets(string, MAX_STRING_SIZE, input_file) != NULL) {
        int index = 0;
        int first_digit = -1;
        int last_digit = -1;
        // loop through all the characters in the string
        while(string[index]){ // string[index] returns 0 at end
            char character = string[index];
            if(isdigit(character)){
                last_digit = character - '0';
                // if this is the first time through this string
                if(first_digit == -1){
                    first_digit = last_digit;
                }
            }

            // not a digit. is it a word?
            if(word_to_digit(&string[index])){
                last_digit = word_to_digit(&string[index]);
                if(first_digit == -1){
                    first_digit = last_digit;
                }
            }
            index ++;
        }
        //printf("%d %d\n", first_digit, last_digit);
        int sum = first_digit*10 + last_digit;
        answer += sum;
        printf("%d\n",answer);
    }


}