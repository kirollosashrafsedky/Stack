/*
 ============================================================================
 Name         : Stack using Arrays
 Author       : Kirollos Ashraf Sedky
 Team         : Conquerors Team
 Organization : Sprints Internship
 Version      : 1.0
 Description  : Stack data structure made using arrays, allows push, pull, print
                and get stack size

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Infrastructure/types.h"
#include "StackUsingArrays.h"

uint8_t gau8_stack[STACK_SIZE];                  // stack array
int8_t gs8_stackTop = -1;                        // stack top (stack pointer)

/**
 * pushes an element to the stack
 * @param data => data to be pushed
 */
void pushUsingArray(uint8_t u8_data){
   if(gs8_stackTop < (STACK_SIZE - 1))
   {
      gs8_stackTop ++;                           // increment stack top
      gau8_stack[gs8_stackTop] = u8_data;        // save data to array
   }
   else
   {
      printf(OVERFLOW_MSG);                      // overflow happens
   }
}

/**
 * gets an element from the top of the stack
 * @return uint8_t => data from the top of the stack
 */
uint8_t pullUsingArray(){
   uint8_t u8_data = 0;
   if(gs8_stackTop >= 0)
   {
      u8_data = gau8_stack[gs8_stackTop];           // get data from top of the stack
      gs8_stackTop --;                           // decrement stack top
   }
   else
   {
      printf(EMPTY_MSG);                         // in case stack is empty
   }
   return u8_data;
}

/**
 * print stack elements from the last pushed to the first pushed
 */
void printStackUsingArray(){
   if(gs8_stackTop == -1)
   {
      printf(EMPTY_MSG);                        // in case stack is empty
      return;
   }
   for(int8_t s8_counter = gs8_stackTop; s8_counter >= 0; s8_counter --)
   {
      printf("%d\t", gau8_stack[s8_counter]);   // loop over stack items and print them
   }
   printf("\n");
}

/**
 * gets the used size of the stack
 * @return uint8_t => used size of the stack
 */
uint8_t stackSizeUsingArray(){
   return gs8_stackTop + 1;
}
