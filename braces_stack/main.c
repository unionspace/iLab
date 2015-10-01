#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

#define STACK_MAX_SIZE 20
typedef char T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void push(Stack_t *stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}

int main()
{
    Stack_t stack;
    stack.size = 0;

    bool correct = true;
    char brace;
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
    if ( (correct)&&(stack.size == 0) ) {
        printf("CORRECT");
    } else {
        printf("INCORRECT");
    }

    return 0;
}
