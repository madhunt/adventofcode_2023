#include <stdio.h>
#include <ctype.h>

// this is equivalent to #define MAX_STRING_SIZE 1000
const int MAX_STRING_SIZE = 1000;


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
                    first_digit = character - '0';
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