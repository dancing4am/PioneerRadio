/*
*	PROJECT			:	OOP_A06_ChowonJung
*	FILE			:	PioneerAm.h
*	NAME			:	Chowon Jung
*	FIRST VERSION	:	2019-03-27
*	DESCRIPTION		:	This is the header file of PioneerAM class.
*					:	All of the bodies of class methods are in this file for convenience.
*					  This file contains :
*					  1. Load Once								: Line 16
*					  2. Libraries								: Line 22
*					  3. Constants								: Line 26
*					  4. PioneerAM Class Definition				: Line 30
*/


/* Load Once */
#ifndef _PIONEERAMRADIO_H
#define _PIONEERAMRADIO_H
#pragma once


/* Libraries */
#include "PioneerCarRadio.h"						// This class will inherit PioneerCarRadio


/* Constants */
#define MODEL_XS440_AM "XS440-AM"					// Model name of PioneerAM radio


/*	Class PioneerAMRadio
*	Name			:	PioneerAM
*	Purpose			:	This class is used to create PioneerAM radio that inherits from AmFmRadio.
*					:	This radio object allows using only AM band which cannot be toggledto FM band.
*					:	It allows to scan up the frequency of each band downward and upward by wrapping up at its edge.
*					:	The radio can store five presets for the band and able to display its current settings.
*	Class constants	:	None
*	Data members	:	None (except inhereted)
*	Methods			:
*		ToggleBand()	: This method prevents current band to be mutated from AM band.
*/
class PioneerAM : public PioneerCarRadio
{
public:
	/* ***************************** Constructor ***************************** */
	PioneerAM(void)
	{
		// indicate this is PioneerAM Radio
		AmFmRadio::SetTree(Tree_AM);
		// indicate the model of this radio is XS440-AM
		PioneerCarRadio::SetModel(MODEL_XS440_AM);
	}

	/* ***************************** Destructor ***************************** */
	virtual ~PioneerAM(void)
	{
		// If the lastly instantiated class is PioneerAM
		if (AmFmRadio::GetTree() == Tree_AM)
		{
			// This destructor prints destroying message
			printf("Destroying PioneerAM Radio\n");
		}
	}

	/* ****************************** Method ******************************* */
	/*
	*	Method		: ToggleBand()
	*	Purpose		: This method prevents to toggle current band to the FM band.
	*	Parameters	: void
	*	Return		: void
	*/
	virtual void ToggleBand(void)
	{
		AmFmRadio::SetBand(AM);
	}
};
#endif