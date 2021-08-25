#ifndef __STACK_USING_LINKED_LISTS__
#define __STACK_USING_LINKED_LISTS__

#include "../Infrastructure/types.h"

#define EMPTY_MSG "Stack Is Empty\n"        // stack empty text

/**
 * pushes an element to the stack
 * @param data => data to be pushed
 */
void push(uint8_t u8_data);

/**
 * gets an element from the top of the stack
 * @return uint8_t => data from the top of the stack
 */
uint8_t pull();

/**
 * print stack elements from the last pushed to the first pushed
 */
void printStack();

/**
 * gets the used size of the stack
 * @return uint8_t => used size of the stack
 */
uint8_t stackSize();

#endif /* __STACK_USING_LINKED_LISTS__ */
