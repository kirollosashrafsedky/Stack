#ifndef __CHECK_BALANCED_PARENTHESES__
#define __CHECK_BALANCED_PARENTHESES__

#include "../Infrastructure/types.h"

#define PARENTHESES_SIZE 4                  // available parenthese array size (,{,<,[
#define BALANCED_STR "Balanced"             // Balanced print text
#define NOT_BALANCED_STR "Not Balanced"     // Not Balanced print text

/**
 * parses the text and checks if each parenthesis is proberly closed or not
 * by storing openings in the stack and pull them when reaching closings
 * @param expression => string containing parentheses to be parsed
 * @return uint8_t* => "Balanced" or "Not Balanced"
 */
uint8_t* balancedParentheses(uint8_t* expression);

#endif /* __CHECK_BALANCED_PARENTHESES__ */
