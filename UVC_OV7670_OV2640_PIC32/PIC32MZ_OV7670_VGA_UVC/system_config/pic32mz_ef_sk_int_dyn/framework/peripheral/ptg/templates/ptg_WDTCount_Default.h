/*******************************************************************************
  PTG Peripheral Library Template Implementation

  File Name:
    ptg_WDTCount_Default.h

  Summary:
    PTG PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : WDTCount
    and its Variant : Default
    For following APIs :
        PLIB_PTG_WDTCountValueSet
        PLIB_PTG_DisableWDT
        PLIB_PTG_WDTCountValueGet
        PLIB_PTG_ExistsWDTCount

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

#ifndef _PTG_WDTCOUNT_DEFAULT_H
#define _PTG_WDTCOUNT_DEFAULT_H

//******************************************************************************
/* Function :  PTG_WDTCountValueSet_Default

  Summary:
    Implements Default variant of PLIB_PTG_WDTCountValueSet 

  Description:
    This template implements the Default variant of the PLIB_PTG_WDTCountValueSet function.
*/

PLIB_TEMPLATE void PTG_WDTCountValueSet_Default( PTG_MODULE_ID index , PTG_WDT_TIMEOUT_SEL wdtTimeOutSel )
{
	PTGCONbits.PTGWDT = wdtTimeOutSel;
}


//******************************************************************************
/* Function :  PTG_DisableWDT_Default

  Summary:
    Implements Default variant of PLIB_PTG_DisableWDT 

  Description:
    This template implements the Default variant of the PLIB_PTG_DisableWDT function.
*/

PLIB_TEMPLATE void PTG_DisableWDT_Default( PTG_MODULE_ID index )
{
	PTG_WDT_TIMEOUT_SEL wdtTimeOutSel = PTG_WDT_DISABLE;
	PTGCONbits.PTGWDT = wdtTimeOutSel;
}


//******************************************************************************
/* Function :  PTG_WDTCountValueGet_Default

  Summary:
    Implements Default variant of PLIB_PTG_WDTCountValueGet 

  Description:
    This template implements the Default variant of the PLIB_PTG_WDTCountValueGet function.
*/

PLIB_TEMPLATE PTG_WDT_TIMEOUT_SEL PTG_WDTCountValueGet_Default( PTG_MODULE_ID index )
{
	return (PTG_WDT_TIMEOUT_SEL) PTGCONbits.PTGWDT;
}


//******************************************************************************
/* Function :  PTG_ExistsWDTCount_Default

  Summary:
    Implements Default variant of PLIB_PTG_ExistsWDTCount

  Description:
    This template implements the Default variant of the PLIB_PTG_ExistsWDTCount function.
*/

#define PLIB_PTG_ExistsWDTCount PLIB_PTG_ExistsWDTCount
PLIB_TEMPLATE bool PTG_ExistsWDTCount_Default( PTG_MODULE_ID index )
{
    return true;
}


#endif /*_PTG_WDTCOUNT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

