#include <stdio.h>
#include <stdlib.h>

#define MAX_BRACES 500

typedef int bool;
#define true 1
#define false 0

int main() {
    bool correct = true;
    char brace;
    char braces[MAX_BRACES];
    braces[0] = '*';
    int number = 0;
    brace = getchar();
    while ( (brace != '\n')&&(correct) ) {
        switch (brace) {
        case '(' :
            ++number;
            braces[number] = '(';
            break;
        case '{' :
            ++number;
            braces[number] = '{';
            break;
        case '[' :
            ++number;
            braces[number] = '[';
            break;
        case ')' :
           if ( braces[number] = '(' ) {
                --number;
                } else {
                    correct = false;
                }
            break;
        case '}' :
           if ( braces[number] = '{' ) {
                --number;
                } else {
                    correct = false;
                }
            break;
        case ']' :
           if ( braces[number] = '[' ) {
                --number;
                } else {
                    correct = false;
                }
            break;
        default :
            correct = false;
            break;
        }
        brace = getchar();
    }
    if ( (correct)&&(number == 0) ) {
        printf("CORRECT");
    } else {
        printf("INCORRECT");
    }
    return 0;
}
