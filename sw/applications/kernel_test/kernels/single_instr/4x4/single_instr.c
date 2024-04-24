/*
                              *******************
******************************* C SOURCE FILE *******************************
**                            *******************                          **
**                                                                         **
** project  : CGRA-X-HEEP                                                  **
** filename : single_instr.c                                                 **
** version  : 1                                                            **
** date     : 2024-04-24                                                       **
**                                                                         **
*****************************************************************************
**                                                                         **
** Copyright (c) EPFL                                                      **
** All rights reserved.                                                    **
**                                                                         **
*****************************************************************************
*/

/***************************************************************************/
/***************************************************************************/

/**
* @file   single_instr.c
* @date   2024-04-24
* @brief  A description of the kernel...
*
*/

#define _SINGLE_INSTR_C

/****************************************************************************/
/**                                                                        **/
/*                             MODULES USED                                 */
/**                                                                        **/
/****************************************************************************/
#include <stdint.h>

#include "single_instr.h"
#include "../function.h"

/****************************************************************************/
/**                                                                        **/
/*                        DEFINITIONS AND MACROS                            */
/**                                                                        **/
/****************************************************************************/

#define CGRA_COLS       4
#define IN_VAR_DEPTH    1
#define OUT_VAR_DEPTH   1

/****************************************************************************/
/**                                                                        **/
/*                      PROTOTYPES OF LOCAL FUNCTIONS                       */
/**                                                                        **/
/****************************************************************************/

static void        config  (void);
static void        software(void);
static uint32_t    check   (void);

/****************************************************************************/
/**                                                                        **/
/*                            GLOBAL VARIABLES                              */
/**                                                                        **/
/****************************************************************************/

const uint32_t  cgra_imem_sing[CGRA_IMEM_SIZE] = {  0x6a09000c, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x8b90000, 0xc80000, 0xc80000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x6a09000c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xad0000, 0xad0000, 0xad0000, 0xad0000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static uint32_t cgra_kmem_sing[CGRA_KMEM_SIZE] = {  0x0, 0xf018, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
 };

static int32_t cgra_input[CGRA_COLS][IN_VAR_DEPTH]     __attribute__ ((aligned (4)));
static int32_t cgra_output[CGRA_COLS][OUT_VAR_DEPTH]   __attribute__ ((aligned (4)));

static uint32_t	i_in_ptr_soft;
static uint32_t	i_in_ptr_cgra;

static uint32_t	o_ret_soft;
static uint32_t	o_ret_cgra;


/****************************************************************************/
/**                                                                        **/
/*                           EXPORTED VARIABLES                             */
/**                                                                        **/
/****************************************************************************/

extern kcom_kernel_t sing_kernel = {
    .kmem   = cgra_kmem_sing,
    .imem   = cgra_imem_sing,
    .col_n  = CGRA_COLS,
    .in_n   = IN_VAR_DEPTH,
    .out_n  = OUT_VAR_DEPTH,
    .input  = cgra_input,
    .output = cgra_output,
    .config = config,
    .func   = software,
    .check  = check,
    .name   = "Single_instr",
};

/****************************************************************************/
/**                                                                        **/
/*                            LOCAL FUNCTIONS                               */
/**                                                                        **/
/****************************************************************************/

void config()
{
    static uint32_t	testVect[30];
    for (int i = 0; i < 30; i++) {
        testVect[i] = (uint32_t)i;
    }
	cgra_input[0][0] = (uint32_t)testVect;
    cgra_input[1][0] = (uint32_t)testVect;
    cgra_input[2][0] = (uint32_t)testVect;
    cgra_input[3][0] = (uint32_t)testVect;

    cgra_input[0][1] = (uint32_t)testVect;
    cgra_input[0][2] = (uint32_t)testVect;
    cgra_input[0][3] = (uint32_t)testVect;

}

void software(void) 
{
    o_ret_soft = single_instr( i_in_ptr_soft );
}

uint32_t check(void) 
{
    uint32_t errors = 0;
    
	o_ret_cgra = cgra_output[1][0];


#if PRINT_CGRA_RESULTS
    PRINTF("------------------------------\n");
    for( uint8_t c = 0; c < CGRA_COLS; c ++)
    {
        for( uint8_t r = 0; r < OUT_VAR_DEPTH; r++ )
        {
            PRINTF("[%d][%d]:%08x\t\t",c,r,cgra_output[c][r]);
        }
        PRINTF("\n");
    }
#endif //PRINT_CGRA_RESULTS


#if PRINT_RESULTS
        PRINTF("\nCGRA\t\tSoft\n");
#endif

    for( int i = 0; i < 1; i++ )
    {
#if PRINT_RESULTS
        PRINTF("%08x\t%08x\t%s\n",
        o_ret_cgra,
        o_ret_soft,
        (o_ret_cgra != o_ret_soft) ? "Wrong!" : ""
        );
#endif

        if (o_ret_cgra != o_ret_soft) {
            errors++;
        }
    }
    return errors;
}

/****************************************************************************/
/**                                                                        **/
/**                                EOF                                     **/
/**                                                                        **/
/****************************************************************************/