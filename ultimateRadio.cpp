/*
*	PROJECT			:	OOP_A06_ChowonJung
*	FILE			:	ultimateRadio.cpp
*	NAME			:	Chowon Jung
*	FIRST VERSION	:	2019-03-27
*	DESCRIPTION		:	This is the testharness for AmFmRadio, PioneerCarRadio, PioneerAM,
*					:	and PioneerWorld classes simulating inheritance. 
*					:	The functions in this file are used to generate the radio that is
*					:	requested through argument. Once the radio object is destroyed by
*					:	exit request, the program generates another radio by a key stroke.
*	CONTENTS		:	1. Libraries			: Line 21
*					:	2. Constants			: Line 27
*					:	3. Enum					: Line 36
*					:	4. Prototypes			: Line 44
*					:	5. Main					: Line 49
*					:	6. createRadio()		: Line 94
*					:	7. createByKeyStroke()	: Line 171
*/


/* Libraries */
#include "PioneerWorld.h"
#include <iostream>
using namespace std;


/* Constants */
#define GEN_CAR			"-car"									//command line argument for PioneerCarRadio
#define GEN_AM			"-am"									//command line argument for PioneerAM
#define GEN_WRLD		"-world"								//command line argument for PioneerWorld
#define UNKNOWN			"ERROR: unknown exception thrown"		//indicate unknown exception
#define OUT_OF_MEM		"ERROR: out of memory"					//indicate out-of-memory exception
#define WRONG_ARG		"ERROR: wrong argument"					//indicate wrong argument


/* Enum */
enum createThis
{
	// for keystroke reaction indicates which model of radio to create
	CREATE_CAR = 'c',  CREATE_AM = 'a', CREATE_WRLD = 'w', CREATE_EXIT = 'x'
};


/* Prototype */
PioneerCarRadio* createRadio(string radioName);					//parse argument and instantiate radio
PioneerCarRadio* createByKeyStroke(void);						//get key stroke and instantiate radio


void main(int argc, char *argv[])
{
	//read, convert and store radio type(first argument) into string object
	string radioType = string(argv[1]);

	//create radio holder for actual radio
	PioneerCarRadio* pRadio = NULL;

	try
	{
		//Create radio as passed argument from command line
		pRadio = createRadio(radioType);
		//Simulate the radio if succeeded to instantiate
		if (pRadio != NULL)
		{
			pRadio->GetKeypress();
			delete pRadio;
		}
		else
		{
			//inform wrong argument if failed due to wrong argument
			cout << WRONG_ARG << endl;
		}
		//Create radio as received user key stroke
		pRadio = createByKeyStroke();
		//Simulate the radio if succeeded to instantiate
		if (pRadio != NULL)
		{
			pRadio->GetKeypress();
			delete pRadio;
		}
	}
	//Display the message if a known exception is thrown
	catch (const char msg[])
	{
		cout << msg << endl;
	}
	//Display message if unknown exception is thrown
	catch (...)
	{
		cout << UNKNOWN << endl;
	}
}


/*
*	Function		:	createRadio()
*	Description		:	This function parse the argument and create corresponding radio.
*	Parameter		:	string radioName	:	indicates which model to be created
*	Return			:	PioneerCarRadio*	:	pointer to the instantiated radio wearing PioneerCarRadio glass
*/
PioneerCarRadio* createRadio(string radioName)
{
	//Take in and parse command-line arguments
	//If requested to create PioneerCarRadio
	if (radioName == GEN_CAR)
	{
		try
		{
			//Instantiate PioneerCarRadio and return the pointer
			PioneerCarRadio* newRadio = new PioneerCarRadio();
			return newRadio;
		}
		catch (bad_alloc& newRadio)
		{
			//throw exception when out-of-memory
			throw OUT_OF_MEM;
		}
		catch (...)
		{
			//throw exception for any other exception
			throw UNKNOWN;
		}
	}
	//If requested to create PioneerAM radio
	else if (radioName == GEN_AM)
	{
		try
		{
			//Instantiate PioneerAM radio and return the pointer
			PioneerAM* newRadio = new PioneerAM();
			return (PioneerCarRadio*)newRadio;
		}
		catch (bad_alloc& newRadio)
		{
			//throw exception when out-of-memory
			throw OUT_OF_MEM;
		}
		catch (...)
		{
			//throw exception for any other exception
			throw UNKNOWN;
		}
	}
	//If requested to create PioneerWorld
	else if (radioName == GEN_WRLD)
	{
		try
		{
			//Instantiate PioneerWorld radio and return the pointer
			PioneerWorld* newRadio = new PioneerWorld();
			return (PioneerCarRadio*)newRadio;
		}
		catch (bad_alloc& newRadio)
		{
			//throw exception when out-of-memory
			throw OUT_OF_MEM;
		}
		catch (...)
		{
			//throw exception for any other exception
			throw UNKNOWN;
		}
	}
	else
	{
		//return NULL if wrong input
		return NULL;
	}
}


/*
*	Function		:	createByKeyStroke()
*	Description		:	This function creates corresponding radio model by key stroke.
*	Parameter		:	void
*	Return			:	PioneerCarRdadio*	:	pointer to the instantiated radio wearing PioneerCarRadio glass
*/
PioneerCarRadio* createByKeyStroke(void)
{
	int keypress = 0;
	int valid = false;

	//repeat until get any valid input
	while (valid == false)
	{
		//get user input
		keypress = _getch();
		switch (keypress)
		{
		//create PioneerCarRadio if 'c'
		case CREATE_CAR:
			return createRadio(GEN_CAR);
		//create PioneerAM radio if 'a'
		case CREATE_AM:
			return createRadio(GEN_AM);
		//create PioneerWorld radio if 'w'
		case CREATE_WRLD:
			return createRadio(GEN_WRLD);
		//exit if 'x'
		case CREATE_EXIT:
			return NULL;
		//keep repeat until vaild input
		default:
			continue;
		}
	}
}