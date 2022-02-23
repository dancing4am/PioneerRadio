/*
*	PROJECT			:	OOP_A06_ChowonJung
*	FILE			:	PioneerWorld.h
*	NAME			:	Chowon Jung
*	FIRST VERSION	:	2019-03-27
*	DESCRIPTION		:	This is the header file for PioneerWorld class.
*					:	All of the bodies of class methods are in this file for convenience.
*					  This file contains :
*					  1. Load Once								: Line 16
*					  2. Libraries								: Line 21
*					  3. Constants								: Line 26
*					  4. PioneerWorld Class Definition			: Line 33
*/


/* Load Once */
#ifndef _WORLDRADIO_H
#define _WORLDRADIO_H


/* Libraries */
#include "PioneerAM.h"					// This class will inherit PioneerAM
#pragma once


/* Constants */
#define MODEL_XS440_WRLD "XS440-WRLD "	// model name of PioneerWorld radio
#define MAX_FREQ_WRLD 16020				// maximum settable AM frequency
#define MIN_FREQ_WRLD 5310				// minimum settable AM frequency
#define TICK_WRLD 90					// amount of frequency moved at a time when scan AM band


/*	Class PioneerWorld
*	Name			:	PioneerWorld
*	Purpose			:	This class is used to create PioneerWorld radio that inherits from PioneerAM class.
*					:	This radio object allows using only AM band which cannot be toggledto FM band.
*					:	It allows to scan up the frequency of each band downward and upward by wrapping up at its edge.
*					:	The frequency range is limited to 531 kHz to 1602 kHz which is different from PioneerAM class.
*					:	The radio can store five presets for the band and able to display its current settings.
*	Class constants	:	None
*	Data members	:	None (except inhereted)
*	Methods			:
*		ScanUp()	: This method scans the current frequency upward by 9kHz per tick.
*		ScanDown()	: This method scans the current frequency downward by 9kHz per tick.
*/
class PioneerWorld : public PioneerAM
{
public:
	/* ***************************** Constructor ***************************** */
	PioneerWorld(void)
	{
		// indicate this is PioneerWorld Radio
		AmFmRadio::SetTree(Tree_WRLD);
		// indicate the model of this radio is XS440-WRLD
		PioneerCarRadio::SetModel(MODEL_XS440_WRLD);

		//AM band range starts from 531 kHz
		this->SetCurrentFreq(MIN_FREQ_WRLD);
		//set all the presets as 531 kHz
		for (int i = 0; i < MAX_PRESET; ++i)
		{
			this->AmFmRadio::SetPreset(i, AM);
		}
	}

	/* ***************************** Destructor ***************************** */
	virtual ~PioneerWorld(void)
	{
		// If the lastly instantiated class is PioneerWorld
		if (AmFmRadio::GetTree() == Tree_WRLD)
		{
			// This destructor prints destroying message
			printf("Destroying PioneerWorld Radio\n");
		}
	}

	/* ****************************** Methods ****************************** */
	/*
	*	Method		: ScanUp()
	*	Purpose		: This method scans the current frequency upward by 9kHz per tick.
	*	Parameters	: void
	*	Return		: void
	*/
	virtual void ScanUp(void)
	{
		//if current_station is 1602, the current_station becomes 531
		if (GetCurrentFreq() >= MAX_FREQ_WRLD)
		{
			this->SetCurrentFreq(MIN_FREQ_WRLD);
		}
		else
		{
			//scan the current frequency upward by 9kHz per tick
			this->SetCurrentFreq(GetCurrentFreq() + TICK_WRLD);
		}
	}

	/* Methods */
	/*
	*	Method		: ScanDown()
	*	Purpose		: This method scans the current frequency downward by 9kHz per tick.
	*	Parameters	: void
	*	Return		: void
	*/
	virtual void ScanDown(void)
	{
		//if current_station is 531, the current_station becomes 1602
		if (GetCurrentFreq() <= MIN_FREQ_WRLD)
		{
			this->SetCurrentFreq(MAX_FREQ_WRLD);
		}
		else
		{
			//scan the current frequency downward by 9kHz per tick
			this->SetCurrentFreq(GetCurrentFreq() - TICK_WRLD);
		}
	}
};
#endif