/**
  EXT_INT Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    ext_int.c

  @Summary
    This is the generated driver implementation file for the EXT_INT 
    driver using MPLAB(c) Code Configurator

  @Description:
    This source file provides implementations for driver APIs for EXT_INT. 
    Generation Information : 
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F1709
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/**
   Section: Includes
 */
#include <xc.h>
#include "extInt.h"
#include "../timer0Int.h"
//***User Area Begin->code: Add External Interrupt handler specific headers 

//***User Area End->code: Add External Interrupt handler specific headers

/**
   Section: External Interrupt Handlers
 */
// INTn Dynamic Interrupt Handlers 
void (*INT_InterruptHandler)(void);

/**
  Interrupt Handler for EXT_INT - INT
*/
void INT_ISR(void)
{
    //***User Area Begin->code***

    //***User Area End->code***
    
    EXT_INT_InterruptFlagClear();

    // Callback function gets called everytime this ISR executes
    INT_CallBack();    
}

/**
  Callback function for EXT_INT - INT
*/
void INT_CallBack(void)
{
    // Add your custom callback code here
    if(INT_InterruptHandler)
    {
        INT_InterruptHandler();
    }
}

/**
  Allows selecting an interrupt handler for EXT_INT - INT at application runtime
*/
void INT_SetInterruptHandler(void* InterruptHandler){
    INT_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for EXT_INT - INT 
*/
void INT_DefaultInterruptHandler(void){
    // add your INT interrupt custom code
    // or set custom function using INT_SetInterruptHandler()
}
/**
    Section: External Interrupt Initializers
 */
/**
    void EXT_INT_Initialize(void)

    Initializer for the following external interrupts
    INT
*/
void EXT_INT_Initialize(void)
{
    
    /*******
     * INT
     * Clear the interrupt flag
     * Set the external interrupt edge detect
     * Enable the interrupt, if enabled in the UI. 
     ********/
    EXT_INT_InterruptFlagClear();   
    EXT_INT_fallingEdgeSet();    
    // Set Default Interrupt Handler
    INT_SetInterruptHandler(INT_DefaultInterruptHandler);
    EXT_INT_InterruptEnable();      



 
      
}



