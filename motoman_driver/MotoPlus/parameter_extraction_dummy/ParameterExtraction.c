/* ParameterExtraction.h - Parameter Extraction definitions header file */

/*
* Software License Agreement (BSD License) 
*
* Copyright (c) 2011, Yaskawa America, Inc.
* All rights reserved.
*
* Redistribution and use in binary form, with or without modification,
* is permitted provided that the following conditions are met:
*
*       * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*       * Neither the name of the Yaskawa America, Inc., nor the names 
*       of its contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/ 

#include "ParameterExtraction.h"
#include "MotoPlus.h"

/******************************************************************************/
/* << 2 >>                                                              	  */
/* Function name : int  GP_getNumberOfGroups()								  */
/* Functionality : Retrieves the Number of Defined Groups					  */
/* Parameter	 : NONE														  */
/* Return value	 : Success = Number of Groups								  */
/*				 : Failure = -1												  */	
/******************************************************************************/
extern int  	GP_getNumberOfGroups()
{
    return 3;
}

/******************************************************************************/
/* << 3 >>                                                              	  */
/* Function name : int  GP_getNumberOfAxes()								  */
/* Functionality : Retrieves the Number of Axes								  */
/* Parameter	 : int ctrlGrp - Robot control to fetch data	[IN]		  */
/* Return value	 : Success = Number of Axes									  */
/*				 : Failure = -1												  */	
/******************************************************************************/
extern int  	GP_getNumberOfAxes(int ctrlGrp)
{
    switch (ctrlGrp) {
        case 0:
            return 6;
            break;
        case 1:
            return 6;
            break;
        case 2:
            return 1;
            break;
        default:
            return -1;
            break;
    }
}

/******************************************************************************/
/* << 4 >>                                                              	  */
/* Function name : STATUS GP_getPulseToRad()								  */
/* Functionality : Gets the Pulse to radians conversion factors				  */
/* Parameter	 : int ctrlGrp - Robot control to fetch data	[IN]		  */
/*				   GB_PULSE_TO_RAD *PulseToRad -array of conversion data [OUT]*/
/* Return value	 : Success = OK 											  */
/*				 : Failure = NG												  */	
/******************************************************************************/
extern STATUS 	GP_getPulseToRad(int ctrlGrp, GB_PULSE_TO_RAD *PulseToRad)
{
    STATUS ret = OK;

    switch (ctrlGrp) {
        case 0:
        case 1:
            PulseToRad->PtoR[0] = 82239.5216094786;
            PulseToRad->PtoR[1] = 74502.7025033604;
            PulseToRad->PtoR[2] = 78879.7362754328;
            PulseToRad->PtoR[3] = 57041.1316041353;
            PulseToRad->PtoR[4] = 47206.4537413533;
            PulseToRad->PtoR[5] = -20078.4783246556;
            PulseToRad->PtoR[6] = 0.00;
            PulseToRad->PtoR[7] = 0.00;
            break;
        case 2:
            PulseToRad->PtoR[0] = -96155.0504183995;
            PulseToRad->PtoR[1] = 0;
            PulseToRad->PtoR[2] = 0;
            PulseToRad->PtoR[3] = 0;
            PulseToRad->PtoR[4] = 0;
            PulseToRad->PtoR[5] = 0;
            PulseToRad->PtoR[6] = 0;
            PulseToRad->PtoR[7] = 0;
            break;
        default:
            ret = NG;
            break;
    }

    return ret;
}

/******************************************************************************/
/* << 11 >>                                                             	  */
/* Function name : STATUS GetFBPulseCorrection()							  */
/* Functionality : Get all the pulse correction data for required axes		  */
/* Parameter	 : int ctrlGrp - Robot control to fetch data [IN]			  */
/*				   FB_PULSE_CORRECTION_DATA * correctionData[OUT]			  */
/* Return value	 : Success = OK 											  */
/*				 : Failure = NG												  */
/******************************************************************************/
extern STATUS GP_getFBPulseCorrection(int ctrlGrp, FB_PULSE_CORRECTION_DATA *correctionData)
{
    STATUS ret = OK;

    switch (ctrlGrp) {
        case 0:
        case 1:
            correctionData->correction[0].bValid = TRUE;
            correctionData->correction[0].ulSourceAxis = 5;
            correctionData->correction[0].ulCorrectionAxis = 6;
            correctionData->correction[0].fCorrectionRatio = -14483;
            correctionData->correction[1].bValid = FALSE;
            correctionData->correction[1].ulSourceAxis = 0;
            correctionData->correction[1].ulCorrectionAxis = 0;
            correctionData->correction[1].fCorrectionRatio = 0;
            correctionData->correction[2].bValid = FALSE;
            correctionData->correction[2].ulSourceAxis = 0;
            correctionData->correction[2].ulCorrectionAxis = 0;
            correctionData->correction[2].fCorrectionRatio = 0;
            correctionData->correction[3].bValid = FALSE;
            correctionData->correction[3].ulSourceAxis = 0;
            correctionData->correction[3].ulCorrectionAxis = 0;
            correctionData->correction[3].fCorrectionRatio = 0;
            correctionData->correction[4].bValid = FALSE;
            correctionData->correction[4].ulSourceAxis = 0;
            correctionData->correction[4].ulCorrectionAxis = 0;
            correctionData->correction[4].fCorrectionRatio = 0;
            correctionData->correction[5].bValid = FALSE;
            correctionData->correction[5].ulSourceAxis = 0;
            correctionData->correction[5].ulCorrectionAxis = 0;
            correctionData->correction[5].fCorrectionRatio = 0;
            correctionData->correction[6].bValid = FALSE;
            correctionData->correction[6].ulSourceAxis = 0;
            correctionData->correction[6].ulCorrectionAxis = 0;
            correctionData->correction[6].fCorrectionRatio = 0;
            correctionData->correction[7].bValid = FALSE;
            correctionData->correction[7].ulSourceAxis = 0;
            correctionData->correction[7].ulCorrectionAxis = 0;
            correctionData->correction[7].fCorrectionRatio = 0;
            break;
        case 2:
            correctionData->correction[0].bValid = FALSE;
            correctionData->correction[0].ulSourceAxis = 0;
            correctionData->correction[0].ulCorrectionAxis = 0;
            correctionData->correction[0].fCorrectionRatio = 0;
            correctionData->correction[1].bValid = FALSE;
            correctionData->correction[1].ulSourceAxis = 0;
            correctionData->correction[1].ulCorrectionAxis = 0;
            correctionData->correction[1].fCorrectionRatio = 0;
            correctionData->correction[2].bValid = FALSE;
            correctionData->correction[2].ulSourceAxis = 0;
            correctionData->correction[2].ulCorrectionAxis = 0;
            correctionData->correction[2].fCorrectionRatio = 0;
            correctionData->correction[3].bValid = FALSE;
            correctionData->correction[3].ulSourceAxis = 0;
            correctionData->correction[3].ulCorrectionAxis = 0;
            correctionData->correction[3].fCorrectionRatio = 0;
            correctionData->correction[4].bValid = FALSE;
            correctionData->correction[4].ulSourceAxis = 0;
            correctionData->correction[4].ulCorrectionAxis = 0;
            correctionData->correction[4].fCorrectionRatio = 0;
            correctionData->correction[5].bValid = FALSE;
            correctionData->correction[5].ulSourceAxis = 0;
            correctionData->correction[5].ulCorrectionAxis = 0;
            correctionData->correction[5].fCorrectionRatio = 0;
            correctionData->correction[6].bValid = FALSE;
            correctionData->correction[6].ulSourceAxis = 0;
            correctionData->correction[6].ulCorrectionAxis = 0;
            correctionData->correction[6].fCorrectionRatio = 0;
            correctionData->correction[7].bValid = FALSE;
            correctionData->correction[7].ulSourceAxis = 0;
            correctionData->correction[7].ulCorrectionAxis = 0;
            correctionData->correction[7].fCorrectionRatio = 0;
            break;
        default:
            ret = NG;
            break;
    }
    return ret;
}

/******************************************************************************/
/* << 12 >>                                                             	  */
/* Function name : STATUS GP_getQtyOfAllowedTasks()							  */
/* Functionality : No.of MotoPlus tasks that can be started concurrently  	  */
/* Parameter	 : TASK_QTY_INFO *taskInfo [OUT]				  			  */
/* Return value	 : Success = OK 											  */
/*				 : Failure = NG												  */
/******************************************************************************/
extern STATUS GP_getQtyOfAllowedTasks(TASK_QTY_INFO *taskInfo)
{
    STATUS ret = OK;
    taskInfo->qtyOfOutFiles = 0;
    taskInfo->qtyOfHighPriorityTasks = 0;
    taskInfo->qtyOfNormalPriorityTasks = 0;
    return ret;
}

/******************************************************************************/
/* << 13 >>                                                             	  */
/* Function name : STATUS GP_getInterpolationPeriod()						  */
/* Functionality : No.of millisecs b/w each tick of the interpolation-clock	  */
/* Parameter	 : UINT16 *periodInMilliseconds [OUT]						  */
/* Return value	 : Success = OK 											  */
/*				 : Failure = NG												  */	
/******************************************************************************/
extern STATUS GP_getInterpolationPeriod(UINT16* periodInMilliseconds)
{
    STATUS ret = OK;
    *periodInMilliseconds = 8;
    return ret;
}

/******************************************************************************/
/* << 14 >>                                                             	  */
/* Function name : STATUS GP_getMaxIncPerIpCycle()							  */
/* Functionality : Max increment the arm is capable of(limited by governor)	  */
/* Parameter	 : int ctrlGrp - Robot control to fetch data [IN]			  */
/*				   int interpolationPeriodInMilliseconds - obtained from GP_getInterpolationPeriod [IN] */
/*				   MAX_INCREMENT_INFO *mip [OUT]	   		 				  */
/* Return value	 : Success = OK 											  */
/*				 : Failure = NG												  */	
/******************************************************************************/
extern STATUS GP_getMaxIncPerIpCycle(int ctrlGrp, int interpolationPeriodInMilliseconds, MAX_INCREMENT_INFO *mip)
{
    STATUS ret = OK;

    switch (ctrlGrp) {
        case 0:
        case 1:
            mip->maxIncrement[0] = 2526;
            mip->maxIncrement[1] = 2080;
            mip->maxIncrement[2] = 2423;
            mip->maxIncrement[3] = 3265;
            mip->maxIncrement[4] = 2702;
            mip->maxIncrement[5] = 1710;
            mip->maxIncrement[6] = 0;
            mip->maxIncrement[7] = 0;
            break;
        case 2:
            mip->maxIncrement[0] = 2184;
            mip->maxIncrement[1] = 0;
            mip->maxIncrement[2] = 0;
            mip->maxIncrement[3] = 0;
            mip->maxIncrement[4] = 0;
            mip->maxIncrement[5] = 0;
            mip->maxIncrement[6] = 0;
            mip->maxIncrement[7] = 0;
            break;
        default:
            ret = NG;
            break;
    }
    return ret;
}

/******************************************************************************/
/* << 15 >>                                                             	  */
/* Function name : GP_getGovForIncMotion()									  */
/* Functionality : Percentage Limit of the max-increment					  */
/* Parameter	 : int ctrlGrp 				[IN]			  				  */
/* Return value	 : Success = percentage limit Of MaxSpeed					  */
/*				 : Failure = -1												  */	
/******************************************************************************/
extern float GP_getGovForIncMotion(int ctrlGrp)
{
    return 0.4;
}

