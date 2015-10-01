#include <stdio.h>
#include <stdlib.h>

/*FYI:
	Note about my comments.
	TODO is a thing, I need you to correct in your code.
	SUGGESTION is a thing, I would correct in code. But if you clarify, why you want to keep that variant, I will agree.
	QUESTION is a thing, you should answer in comments or at classes(after lecture).
*/

/*
	TODO: Place declaration and description of stack outside of file of solving.
		  Remind me to explain it after lecture. 	
*/

typedef int bool;
#define true 1
#define false 0
/*TODO: Why do you need this? C has own bool.
*/


#define STACK_MAX_SIZE 20 // better use "const"s. Ilya Ded should explain you later

typedef char T;// FYO: good.

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

// QUESTION: Not clear, why do you use here this constant.
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void push(Stack_t *stack, const T value) {//check for pointer stack != null.
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);// TODO:Here should be your logs, not system ones.
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);// TODO:Here should be your logs, not system. 
    }
    stack->size--;
    return stack->data[stack->size];
}

/*TODO: Initialize the variables.
		everything you declare must be initialized.
		That's the rule Ilya Ded will tell you later.
		There are some exceptions in this rules. But not in this case.
*/


int main()
{
    Stack_t stack;//initialize. Whether static( = {...}), or dinamic (calloc, malloc)
    stack.size = 0;

    bool correct = true;
    char brace;

/* TODO: Place reading and processing into another function.
*/
    brace = getchar();
    while ( (brace != '\n')&&(correct) ) {
        switch (brace) {
        case '(' :
            push(&stack, brace);
            break;
        case '{' :
            push(&stack, brace);
            break;
        case '[' :
            push(&stack, brace);
            break;
        case ')' :
           if ( pop(&stack) != '(' ) {
                correct = false;
                }
            break;
        case '}' :
           if ( pop(&stack) != '{' ) {
                correct = false;
                }
            break;
        case ']' :
           if ( pop(&stack) != '[' ) {
                correct = false;
                }
            break;
        default :
            correct = false;
            break;
        }
        brace = getchar();
    }
    if ( (correct)&&(stack.size == 0) ) {// SUGGESTION: Some note about codestyle. (sth) && (sth) looks better, than (sth)&&(sth)  
        printf("CORRECT");
    } else {
        printf("INCORRECT");
    }

    return 0;
}
