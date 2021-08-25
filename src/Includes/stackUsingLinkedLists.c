/*
 ============================================================================
 Name         : Stack using Linked List
 Author       : Kirollos Ashraf Sedky
 Team         : Conquerors Team
 Organization : Sprints Internship
 Version      : 1.0
 Description  : Stack data structure made using linked list, allows push, pull, print
                and get stack size

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Infrastructure/types.h"
#include "StackUsingLinkedLists.h"

// node structure
typedef struct gstrNode_t{
   uint8_t data;
   struct gstrNode_t* next;
} gstrNode_t;

gstrNode_t* gptr_head = NULL;                    // linked list head
uint8_t gu8_stackSize = 0;                       // linked list size

/**
 * pushes an element to the stack
 * @param data => data to be pushed
 */
void push(uint8_t u8_data){
   // dynamically allocate space for a node
   gstrNode_t* str_temp = (gstrNode_t*)malloc(sizeof(gstrNode_t));

   // set node data to input data
   str_temp -> data = u8_data;

   // point the next pointer of the node to the head
   str_temp -> next = gptr_head;

   // point the head to the first node (the recent created one)
   gptr_head = str_temp;

   // increment size on delete
   gu8_stackSize ++;
}

/**
 * gets an element from the top of the stack
 * @return uint8_t => data from the top of the stack
 */
uint8_t pull(){
   // make temp pointer to node equal head
   gstrNode_t* str_temp = gptr_head;

   // check if empty
   if(gptr_head == NULL)
   {
      printf(EMPTY_MSG);
      return 0;
   }

   // save data before deleting to return
   uint8_t u8_data = str_temp -> data;

   // point head to the next node
   gptr_head = str_temp -> next;

   // delete first node
   free(str_temp);

   // decrement size on delete
   gu8_stackSize --;

   return u8_data;
}

/**
 * print stack elements from the last pushed to the first pushed
 */
void printStack(){
   // make temp pointer to node equal head
   gstrNode_t* str_temp = gptr_head;

   // check if empty
   if(gptr_head == NULL)
   {
      printf(EMPTY_MSG);
      return;
   }

   while(str_temp)
   {
      // print data
      printf("%d\t", str_temp -> data);

      // increment pointer to next node
      str_temp = str_temp -> next;
   }

   printf("\n");
}

/**
 * gets the used size of the stack
 * @return uint8_t => used size of the stack
 */
uint8_t stackSize(){
   return gu8_stackSize;
}
