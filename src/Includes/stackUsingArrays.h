#ifndef __STACK_USING_ARRAYS__
#define __STACK_USING_ARRAYS__

#include "../Infrastructure/types.h"

#define STACK_SIZE 50                       // max stack size
#define OVERFLOW_MSG "Stack Overflow\n"     // stackoverflow msg text
#define EMPTY_MSG "Stack Is Empty\n"        // stack empty text

/**
 * pushes an element to the stack
 * @param data => data to be pushed
 */
void pushUsingArray(uint8_t u8_data);

/**
 * gets an element from the top of the stack
 * @return uint8_t => data from the top of the stack
 */
uint8_t pullUsingArray();

/**
 * print stack elements from the last pushed to the first pushed
 */
void printStackUsingArray();

/**
 * gets the used size of the stack
 * @return uint8_t => used size of the stack
 */
uint8_t stackSizeUsingArray();

#endif /* __STACK_USING_ARRAYS__ */
