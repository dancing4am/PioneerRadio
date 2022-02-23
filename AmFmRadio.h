/*
*	FILE			: AmFmRadio.h
*	PROJECT			: OOP_A06_ChowonJung
*	NAME			: Chowon Jung
*	FIRST VERSION	: 2019-02-24
*	DESCRIPTION		: This file is the header file for the project AmFmRadio.
*					  This file contains :
*					  1. Load Once								: Line 16
*					  2. Constants								: Line 21
*					  3. Enum									: Line 57
*					  3. Struct									: Line 64
*					  4. AmFmRaio Class Definition				: Line 72
*/


/* Load Once */
#ifndef _AMFMRADIO_H
#define _AMFMRADIO_H


/* Constants */
#define MAX_PRESET 5			// maximum number of radio preset
#define AMFM 3					// maxinum length of string "AM" and "FM"
#define AM 0					// to indicate AM band by return
#define FM 1					// to indicate FM band by return
#define PRINT_AM "AM"			// string indicates AM band for print function
#define PRINT_FM "FM"			// string indicates FM band for print function
#define MAX_INPUT 20			// maxinum length of user input
#define MIN_VOL 0				// minimum settable volume
#define MAX_VOL 100				// maximum settable volume
#define MAX_AM_FREQ 17000		// maximum settable AM frequency
#define MIN_AM_FREQ 5300		// minimum settable AM frequency
#define TICK_AM 100				// amount of frequency moved at a time when scan AM band
#define TICK_FM 2				// amount of frequency moved at a time when scan FM band
#define MAX_FM_FREQ 1079		// maximum settable FM frequency
#define MIN_FM_FREQ 879			// minimum settable FM frequency
#define OK 0					// indicates no error when return/compare
#define ERROR -1				// indicates error when return/compare
#define UNDER 1					// indicates invalid value smaller than valid range
#define OVER 2					// indicates invalid value larger than valid range
#define BACK_TO_DOUBLE 10.0		// used to calculate AM frequency integer to print out
#define ON true					// indicates ON statement of radio/settings
#define OFF false				// indicates OFF statement of radio/settings
#define PRINT_ON "ON"			// string used to print ON statement of radio/settings
#define PRINT_OFF "OFF"			// string used to print OFF statement of radio/settings
#define VALID_INT 1				// to indicate singvle valid input within parsing user input
#define SHOW_ALL_SET 0			// used to indicate user requested to print out all current data member status
#define SHOW_ONOFF_SET 1		// used to indicate user requested to print out radio on/off status
#define SHOW_BAND_SET 2			// used to indicate user requested to print out radio AM/FM status
#define SHOW_VOL_SET 3			// used to indicate user requested to print out radio volume status
#define SHOW_CUR_FREQ_SET 4		// used to indicate user requested to print out current radio frequency
#define SHOW_PRESETS_SET 5		// used to indicate user requested to print out current radio presets
#define SHOW_DISPLAY_SET 6		// used to indicate user requested to print out extra messages on/off status
#define NUMBER_OF_SETTINGS 6	// maximum number of settings can be printed


/* Enum */
enum familyTree
{
	Tree_AmFm, Tree_Car, Tree_AM, Tree_WRLD				// Used to determine which destructor to print message
};


/* Struct */
struct Freqs
{
	int AMFreq;											// AM frequency
	int FMFreq;											// FM frequency
};


/*	Class AmFmRadio
*	Name			:	AmFmRadio
*	Purpose			:	This class is used to create a radio object that has AM and FM bands which can be toggled.
*					:	It allows to scan up the frequency of each band downward and upward by wrapping up at its edge.
*					:	The radio can store five presets for each band and able to display its current settings.
*	Class constants	:	None
*	Data members	:
*		int		tree			:	Used to determine the exact class instantiated as the object
*								:	0 - AmFmRadio, 1 - PioneerCarRadio, 2 - PioneerAM, 3 - PioneerWorld
*		Freqs	presets[]		:	List of radio presets 5 each for AM and FM
*		Freqs	prevFreq		:	Two last frequencies for AM and FM
*		int		currentFreq		:	Current frequency of the radio
*		int		band			:	Current band of the radio
*		int		prevVolume		:	Previous volume before turned off
*		int		currentVolume	:	Current volume of the radio
*		bool	onOff			:	Current on/off status of the radio
*		bool	displayOutput	:	Current setting about displaying setting-respond messages
*	Methods			:
*		PowerToggle()			: This method toggles current radio power to the opposite status.
*		SetVolumeByInput()		: This method sets current volume from user input prompted.
*		ToggleBand()			: This method toggles current band to the opposite status.
*		CurrentFreqToPreset()	: This method saves the current frequency as the preset requested.
*		SelectExistingPreset()	: This method sets current frequency as the existing preset requested.
*		ShowCurrentSettings()	: This method displays requested current settings.
*		ScanUp()				: This method scans the current frequency upward.
*		ScanDown()				: This method scans the current frequency downward.
*/
class AmFmRadio
{
private:
	/* Data members */
	int tree;											// Used to determine exact class instantiated
	Freqs	presets[MAX_PRESET];						// List of radio presets 5 each for AM and FM
	Freqs	prevFreq;									// Two last frequencies for AM and FM
	int		currentFreq;								// Current frequency of the radio
	int		band;										// Current band of the radio
	int		prevVolume;									// Previous volume before turned off
	int		currentVolume;								// Current volume of the radio
	bool	onOff;										// Current on/off status of the radio
	bool	displayOutput;								// Current setting about displaying setting-respond messages

public:
	/* Constructors */
	AmFmRadio(bool newOn);
	AmFmRadio(bool newOn, Freqs newPresets[MAX_PRESET]);

	/* Destructor */
	virtual ~AmFmRadio();

	/* Accessors */
	int		GetTree(void);								// Getter for lastly instantiated object indicator
	Freqs*	GetPresets(int presetIndex);				// Preset getter given by the index of preset
	Freqs*	GetPrevFreq(void);							// Previous frequency getter
	int		GetCurrentFreq(void);						// Current frequency getter
	int		GetBand(void);								// Current band getter
	int		GetVolume(void);							// Current volume getter
	int		GetPrevVolume(void);						// Previous volume getter
	bool	GetOnOff(void);								// Radio power status getter
	bool	GetDisplayOutput(void);						// Responding message setting status getter

	/* Mutators */
	void SetTree(int newTree);							// Setter for lastly instantiated object indicator
	int SetPreset(int preset_num, int band);			// Setter sets passed frequency as the requested preset
	int SetPrevFreq(int newPrevFreq);					// Setter saves given frequency for later use
	int SetCurrentFreq(int newCurrentFreq);				// Setter sets current frequency as newly given frequency
	int SetBand(int newBand);							// Setter sets current band as newly given band
	int SetVolume(int newVolume);						// Setter sets current volume as newly given volume
	int SetPrevVolume(int newPrevVolume);				// Setter saves given volume for later use
	bool SetOnOff(bool newOnOff);						// Setter sets current radio power as newly given status
	bool SetDisplayOutput(bool newDisplay);				// Setter sets message display setting as newly given status

	/* Methods */
	void PowerToggle(void);								// Body: AmFmRadio.cpp Line 306
	int SetVolumeByInput(void);							// Body: AmFmRadio.cpp Line 339
	virtual void ToggleBand(void);						// Body: AmFmRadio.cpp Line 387
	int CurrentFreqToPreset(void);						// Body: AmFmRadio.cpp Line 414
	int SelectExistingPreset(void);						// Body: AmFmRadio.cpp Line 442
	void ShowCurrentSettings(int whatToShow);			// Body: AmFmRadio.cpp Line 484
	virtual void ScanUp(void);							// Body: AmFmRadio.cpp Line 579
	virtual void ScanDown(void);						// Body: AmFmRadio.cpp Line 617
};
#endif
