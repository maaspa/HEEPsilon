/*
                              *******************
******************************* H SOURCE FILE *******************************
**                            *******************                          **
**                                                                         **
** project  : x-heep                                                       **
** filename : soc_ctrl_structs.h                                 **
** date     : 21/03/2024                                                      **
**                                                                         **
*****************************************************************************
**                                                                         **
**                                                                         **
*****************************************************************************

*/

/**
* @file   soc_ctrl_structs.h
* @date   21/03/2024
* @brief  Contains structs for every register
*
* This file contains the structs of the registes of the peripheral.
* Each structure has the various bit fields that can be accessed
* independently.
* 
*/

#ifndef _SOC_CTRL_STRUCTS_H
#define SOC_CTRL_STRUCTS

/****************************************************************************/
/**                                                                        **/
/**                            MODULES USED                                **/
/**                                                                        **/
/****************************************************************************/

#include <inttypes.h>
#include "core_v_mini_mcu.h"

/****************************************************************************/
/**                                                                        **/
/**                       DEFINITIONS AND MACROS                           **/
/**                                                                        **/
/****************************************************************************/

#define soc_ctrl_peri ((volatile soc_ctrl *) SOC_CTRL_START_ADDRESS)

/****************************************************************************/
/**                                                                        **/
/**                       TYPEDEFS AND STRUCTURES                          **/
/**                                                                        **/
/****************************************************************************/



typedef struct {

  uint32_t EXIT_VALID;                            /*!< Exit Valid - Used to write exit valid bit*/

  uint32_t EXIT_VALUE;                            /*!< Exit Value - Used to write exit value register*/

  uint32_t BOOT_SELECT;                           /*!< Boot Select Value - Used to decide whether to boot from JTAG or FLASH*/

  uint32_t BOOT_EXIT_LOOP;                        /*!< Boot Exit Loop Value - Set externally (e.g. JTAG, TESTBENCH, or another MASTER) to make the CPU jump to the main function entry*/

  uint32_t BOOT_ADDRESS;                          /*!< Boot Address Value - Used in the boot rom or power-on-reset functions*/

  uint32_t USE_SPIMEMIO;                          /*!< Spi Module Select Value - Used to decide whether to use the SPI from Yosys or OpenTitan*/

  uint32_t ENABLE_SPI_SEL;                        /*!< Enable Spi module selection from software*/

  uint32_t SYSTEM_FREQUENCY_HZ;                   /*!< System Frequency Value - Used to know and set at which frequency the system is running (in Hz)*/

} soc_ctrl;

/****************************************************************************/
/**                                                                        **/
/**                          EXPORTED VARIABLES                            **/
/**                                                                        **/
/****************************************************************************/

#ifndef _SOC_CTRL_STRUCTS_C_SRC



#endif  /* _SOC_CTRL_STRUCTS_C_SRC */

/****************************************************************************/
/**                                                                        **/
/**                          EXPORTED FUNCTIONS                            **/
/**                                                                        **/
/****************************************************************************/


/****************************************************************************/
/**                                                                        **/
/**                          INLINE FUNCTIONS                              **/
/**                                                                        **/
/****************************************************************************/



#endif /* _SOC_CTRL_STRUCTS_H */
/****************************************************************************/
/**                                                                        **/
/**                                EOF                                     **/
/**                                                                        **/
/****************************************************************************/
