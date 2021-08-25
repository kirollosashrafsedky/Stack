/*
 ============================================================================
 Name         : Check Balanced Parenthese
 Author       : Kirollos Ashraf Sedky
 Team		  : Conquerors Team
 Organization : Sprints Internship
 Version      : 1.0
 Description  : parses the text and checks if each parenthesis is proberly closed or not
                by storing openings in the stack and pull them when reaching closings

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "checkBalancedParentheses.h"
#include "../Infrastructure/types.h"
#include "../Includes/StackUsingArrays.h"           // stack using Arrays (not used in this project)
#include "../Includes/StackUsingLinkedLists.h"      // stack using linked lists

// arrays for openings and closings of parentheses
const uint8_t gau8_openingParentheses[] = {'(', '{', '[', '<'};
const uint8_t gau8_closingParentheses[] = {')', '}', ']', '>'};

int main(void) {
   setvbuf(stdout, NULL, _IONBF, 0);	// solve eclipse issue in printf and scanf

   // testing cases
   printf("%s\t\t%s\n","((((((((((()))))))))))", balancedParentheses((uint8_t*)"((((((((((()))))))))))"));
   printf("%s\t%s\n","<html> <body) </body> </html>", balancedParentheses((uint8_t*)"<html> <body) </body> </html>"));
   printf("%s\t%s\n","<html> <body> </body> </html>", balancedParentheses((uint8_t*)"<html> <body> </body> </html>"));
   printf("%s\t\t%s\n","(2 * 3 + (5/2+(4*3)))", balancedParentheses((uint8_t*)"(2 * 3 + (5/2+(4*3)))"));
   printf("%s\t\t\t%s\n","{((2+10)}*11}", balancedParentheses((uint8_t*)"{((2+10)}*11}"));
   printf("%s\t\t\t\t%s\n","{}", balancedParentheses((uint8_t*)"{}"));

   return 0;
}

/**
 * parses the text and checks if each parenthesis is proberly closed or not
 * by storing openings in the stack and pull them when reaching closings
 * @param expression => string containing parentheses to be parsed
 * @return uint8_t* => "Balanced" or "Not Balanced"
 */
uint8_t* balancedParentheses(uint8_t* expression){
   uint8_t* pu8_result = (uint8_t*)NOT_BALANCED_STR;   // result to store Balanced or Not Balanced text
   uint8_t u8_initialStackSize = stackSize();           // initial stack size before excuting the function
   // loop over all characters
   while(*expression != '\0')
   {
      // loop over the items of the openings and closings of the parentheses
      for(uint8_t counter = 0; counter < PARENTHESES_SIZE; counter ++)
      {
         // case 1: an opening parenthesis is found
         if(*expression == gau8_openingParentheses[counter])
         {
            // push to the stack
            push(counter);
            break;
         }
         // case 2: a closing parenthesis is found
         else if(*expression == gau8_closingParentheses[counter])
         {
            // if closing is found before opening then the result is not balanced
            if(stackSize() == u8_initialStackSize)
            {
               return pu8_result;
            }
            // pull closing from stack and check if it has the same index as the last pushed opening parenthesis
            uint8_t u8_lastParentheseIndex = pull();
            if (u8_lastParentheseIndex != counter)
            {
               return pu8_result;
            }
            break;
         }
         // case 3: neither opening nor closing
      }
      expression ++;    // increment the pointer to the next char
   }
   // balanced only if stack is equal to the initial stack value i.e. stack is balanced
   if(stackSize() == u8_initialStackSize)
   {
      pu8_result = (uint8_t*)BALANCED_STR;
   }
   return pu8_result;
}
