/*
*	FILE			:	PioneerCarRadio.h
*	PROJECT			:	OOP_A06_ChowonJung
*	NAME			:	Chowon Jung
*	FIRST VERSION	:	2019-03-20
*	DESCRIPTION		:	This is the header file for class PioneerCarRadio that inherits AmFmRadio class.
*					  This file contains :
*					  1. Load Once								: Line 16
*					  2. Libraries								: Line 21
*					  3. Constants								: Line 28
*					  4. Enum									: Line 38
*					  5. PioneerCarRadio Class Definition		: Line 67
*/


/* Load Once */
#ifndef _CARRADIO_H
#define _CARRADIO_H


/* Libraries */
#include "AmFmRadio.h"			// This class wil inherit AmFmRadio
#include <conio.h>
#include <iostream>
#include <string>


/* Constants */
#define MODEL_XS440 "XS440"		// name of pioneer car radio model XS440
#define VALID_KEY	0			// to indicate vaild key from input validation
#define EXIT_KEY	-1			// to indicate exit request from input validation
#define INVALID_KEY	1			// to indicate invalid key from input validation
#define MAX_MODEL	16			// maxinum length of name of pioneer car radio model
#define ASCII_TO_LOAD_INDEX 49	// used to interpret user input to corresponding preset index when load
#define ASCII_TO_SET_INDEX 33	// used to interpret user input to corresponding preset index when save


/* Enum */
const enum keypress				// valid input for basic functions
{
	ON_OFF = 'o',				// used to toggle power
	VOL_UP = '+',				// used to turn up current volume
	VOL_DN = '_',				// used to turn down current volume
	SC_UP = '=',				// used to scan up current frequency
	SC_DN = '-',				// used to scan down current frequency
	SW_BAND = 'b',				// used to toggle band
	EXIT = 'x'					// used to exit program
};
const enum load_preset			// valid input for loading presets
{
	LOAD_1 = '1',				// used to load preset 1 and set as current frequency
	LOAD_2 = '2',				// used to load preset 2 and set as current frequency
	LOAD_3 = '3',				// used to load preset 3 and set as current frequency
	LOAD_4 = '4',				// used to load preset 4 and set as current frequency
	LOAD_5 = '5'				// used to load preset 5 and set as current frequency
};
const enum set_preset			// valid input for setting presets
{
	SET_1 = '!',				// used to save current frequency as preset 1
	SET_2 = '@',				// used to save current frequency as preset 2
	SET_3 = '#',				// used to save current frequency as preset 3
	SET_4 = '$',				// used to save current frequency as preset 4
	SET_5 = '%'					// used to save current frequency as preset 5
};


/*	Class AmFmRadio
*	Name			:	AmFmRadio
*	Purpose			:	This class inherits AmFmRadio class which is used to create a radio object
*					:	that has AM and FM bands which can be toggled. It allows to scan up the frequency of each band
*					:	downward and upward by wrapping up at its edge. The radio can store five presets for each band
*					:	and able to display its current settings. Unlike AmFmRadio, this class is completely encapsulated
*					:	as an functional object that allows user input and responds for each valid input.
*	Class constants	:	None
*	Data members	:
*		char	model[]			:	Name of the Pioneer radio model
*	Methods			:
*		GetKeypress()			: This method reads and reacts instantly as control unit of the radio for corresponding user input.
*		DisplayStatus()			: This method displays current data status of the radio.
*/
class PioneerCarRadio : public AmFmRadio
{
private:
	/* Data member */
	char model[MAX_MODEL];					// holds model ID of the radio

public:
	/* Constructor */
	PioneerCarRadio(void);					// default constructor of PioneerCarRadio
	virtual ~PioneerCarRadio(void);			// destructor of PioneerCarRadio

	/* Accessor */
	char* GetModel(void);					// getter returns current name of PioneerCarRadio model

	/* Mutator */
	void SetModel(char* newModel);			// setter sets model name

	/* Method */
	void GetKeypress(void);					// Body: PioneerCarRadio.cpp Line 64
	void DisplayStatus(void);				// Body: PioneerCarRadio.cpp Line 154
};
#endif
