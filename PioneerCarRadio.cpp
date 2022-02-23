/*
*	FILE			: PioneerCarRadio.cpp
*	PROJECT			: OOP_A06_ChowonJung
*	NAME			: Chowon Jung
*	FIRST VERSION	: 2019-02-24
*	DESCRIPTION		: This file contains all the method bodies of the PioneerCarRadio class.
*					  1. Libraries								: Line 17
*					  2. Constructors							: Line 22
*					  3. Destructor								: Line 30
*					  4. Accessors								: Line 37
*					  5. Methods								: Line 47
*						 - GetKeypress()						: Line 48
*						 - DisplayStatus()						: Line 127
*/


/* Libraries */
using namespace std;
#include "PioneerCarRadio.h"


/* ***************************** Constructor ***************************** */
PioneerCarRadio::PioneerCarRadio(void) :AmFmRadio(OFF)
{
	// indicate this is PioneerAM Radio
	AmFmRadio::SetTree(Tree_Car);
	//model name is XS440 by default
	strncpy_s(model, MODEL_XS440, MAX_MODEL);
}


/* ***************************** Destructor ***************************** */
PioneerCarRadio::~PioneerCarRadio(void)
{
	// If the lastly instantiated class is PioneerCarRadio
	if (AmFmRadio::GetTree() == Tree_Car)
	{
		// This destructor prints destroying message
		cout << "Destroying PioneerCarRadio" << endl;
	}
}


/* ***************************** Accessor ***************************** */
char* PioneerCarRadio::GetModel(void)
{
	char tmp[10];
	//pass copied variable to protect private data member
	strncpy_s(tmp, model, MAX_MODEL);
	return tmp;
}


/* ***************************** Mutator ***************************** */
void PioneerCarRadio::SetModel(char* newModel)
{
	strncpy_s(model, newModel, MAX_MODEL);
}


/* ***************************** Methods ***************************** */


/*
*	Method		: GetKeypress()
*	Purpose		: This method instantly responds to valid user input from keyboard for each corresponding function.
*	Parameters	: void
*	Return		: void
*/
void PioneerCarRadio::GetKeypress(void)
{
	int keypress = 0;
	bool exit = false;

	while (exit == false)
	{
		//clear screen and replace with new display
		system("cls");							
		this->DisplayStatus();

		//get user input
		keypress = _getch();

		//if asked to load preset
		if ((keypress >= LOAD_1) &&
			(keypress <= LOAD_5))
		{
			//Load requested preset matches current band
			keypress = keypress - ASCII_TO_LOAD_INDEX;
			if (this->GetBand() == AM)
			{
				//load from AM preset when now AM
				this->SetCurrentFreq(this->GetPresets(keypress)->AMFreq);
			}
			else
			{
				//load from FM preset when now FM
				this->SetCurrentFreq(this->GetPresets(keypress)->FMFreq);
			}
		}
		//if asked to set preset
		else if (((keypress == SET_1) ||
			(keypress == SET_2)) ||
			((keypress == SET_3) ||
			(keypress == SET_4)) ||
				(keypress == SET_5))
		{
			switch (keypress)
			{
				//convert keypress ascii to corresponding index number
			case SET_2:
				keypress = 1; //SET_2 is the irregular one, therefore case separated: 1 is the second index of the preset array
				break;
			default:
				keypress = keypress - ASCII_TO_SET_INDEX;
			}
			//save current frequency as requested preset
			this->SetPreset(keypress, this->GetBand());
		}
		else
		{
			//other basic radio functions
			switch (keypress)
			{
			case ON_OFF:
				this->PowerToggle();				//toggle radio power
				break;
			case VOL_UP:
				this->SetVolume(GetVolume() + 1);	//turn up current volume for +1
				break;
			case VOL_DN:
				this->SetVolume(GetVolume() - 1);	//turn down current volume for -1
				break;
			case SC_UP:
				this->ScanUp();						//scan up current frequency
				break;
			case SC_DN:
				this->ScanDown();					//scan down current frequency
				break;
			case SW_BAND:
				this->ToggleBand();					//toggle current band
				break;
			case EXIT:
				exit = true;						//exit
				break;
			default:
				continue;
			}
		}
	}
}


/*
*	Method		: DisplayStatus()
*	Purpose		: This method displays all current setting status of the PioneerCarRadio object.
*	Parameters	: void
*	Return		: void
*/
void PioneerCarRadio::DisplayStatus(void)
{
	//Print model name
	printf("Pioneer %s\n", (char*)model);
	//when radio is on
	if (this->GetOnOff() == ON)
	{
		//print on status and volume
		printf("Radio is on\n");
		printf("Volume: %d\n", this->GetVolume());
		//print current station
		if (this->GetBand() == AM)
		{
			printf("Current Station: %4d", ((this->GetCurrentFreq() / (int)BACK_TO_DOUBLE)));
			printf(" %s\n", PRINT_AM);
		}
		else
		{
			printf("Current Station: %4.1f", ((double)this->GetCurrentFreq() / BACK_TO_DOUBLE));
			printf(" %s\n", PRINT_FM);
		}
		//print all AM presets
		printf("AM Buttons:\n");
		for (int i = 0; i < MAX_PRESET; ++i)
		{
			printf("%d: %5d", i + 1, ((this->GetPresets(i)->AMFreq) / (int)BACK_TO_DOUBLE));
			if (i < MAX_PRESET - 1)
			{
				printf(", ");
			}
		}
		//if the object contains FM band functionality
		if ((AmFmRadio::GetTree() != Tree_AM) &&
			(AmFmRadio::GetTree() != Tree_WRLD))
		{
			//print all FM presets
			printf("\nFM Buttons:\n");
			for (int j = 0; j < MAX_PRESET; ++j)
			{
				printf("%d: %5.1f", j + 1, (this->GetPresets(j)->FMFreq) / BACK_TO_DOUBLE);
				if (j < MAX_PRESET - 1)
				{
					printf(", ");
				}
			}
		}
		printf("\n");
	}
	else
	{
		//print when radio is off
		printf("Radio is off\n");
	}
}