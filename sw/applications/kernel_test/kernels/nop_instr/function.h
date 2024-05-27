#ifndef _CGRA_FUNCTION_H_
#define _CGRA_FUNCTION_H_

#include <stdio.h>

int nop_instr(){
      uint32_t test = 0;
      uint32_t reg = 7;
    for (int i = 0; i < 32 - 1; ++i)
      {
            test = test + reg;
      }
      return test;
}


#endif // _CGRA_FUNCTION_H_