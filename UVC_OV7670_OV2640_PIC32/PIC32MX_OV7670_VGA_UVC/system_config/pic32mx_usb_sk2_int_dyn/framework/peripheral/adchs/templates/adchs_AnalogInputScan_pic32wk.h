/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputScan_pic32wk.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputScan
    and its Variant : pic32wk
    For following APIs :
        PLIB_ADCHS_AnalogInputScanIsComplete
        PLIB_ADCHS_AnalogInputScanSelect
        PLIB_ADCHS_AnalogInputScanRemove
        PLIB_ADCHS_AnalogInputScanIsSelected
        PLIB_ADCHS_AnalogInputScanSetup
        PLIB_ADCHS_ScanCompleteInterruptEnable
        PLIB_ADCHS_ScanCompleteInterruptDisable
        PLIB_ADCHS_ExistsAnalogInputScan

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _ADCHS_ANALOGINPUTSCAN_PIC32WK_H
#define _ADCHS_ANALOGINPUTSCAN_PIC32WK_H



//******************************************************************************
/* Function :  ADCHS_AnalogInputScanIsComplete_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputScanIsComplete 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputScanIsComplete function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsComplete_pic32wk( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)regs->ADCCON2.EOSRDY;
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSelect_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputScanSelect 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputScanSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSelect_pic32wk( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCSSx[analogInput / 32] |= BIT(analogInput % 32);
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanRemove_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputScanRemove 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputScanRemove function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanRemove_pic32wk( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCSSx[analogInput / 32] &= ~BIT(analogInput % 32);
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanIsSelected_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputScanIsSelected 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputScanIsSelected function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsSelected_pic32wk( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    return (bool)(regs->ADCCSSx[analogInput / 32] & BIT(analogInput % 32));
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSetup_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_AnalogInputScanSetup 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_AnalogInputScanSetup function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSetup_pic32wk( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput , ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive , ADCHS_SCAN_TRIGGER_SOURCE triggerSource )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCSSx[analogInput / 32] |= BIT(analogInput % 32);
    regs->ADCCON1.STRGLVL = trgSensitive;
    regs->ADCCON1.STRGSRC = triggerSource;
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptEnable_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ScanCompleteInterruptEnable 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ScanCompleteInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptEnable_pic32wk( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON2.EOSIEN = 1;
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptDisable_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ScanCompleteInterruptDisable 

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ScanCompleteInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptDisable_pic32wk( ADCHS_MODULE_ID index )
{
    volatile adchs_register_t *regs = (adchs_register_t *)index;

    regs->ADCCON2.EOSIEN = 0;
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputScan_pic32wk

  Summary:
    Implements pic32wk variant of PLIB_ADCHS_ExistsAnalogInputScan

  Description:
    This template implements the pic32wk variant of the PLIB_ADCHS_ExistsAnalogInputScan function.
*/

#define PLIB_ADCHS_ExistsAnalogInputScan PLIB_ADCHS_ExistsAnalogInputScan
PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputScan_pic32wk( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ANALOGINPUTSCAN_PIC32WK_H*/

/******************************************************************************
 End of File
*/

