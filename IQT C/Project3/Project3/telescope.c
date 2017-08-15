//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// MQT (I.5.A) PERFORMANCE LAB 2 ///////////////////////////////////////////
/////////////////////////////////////////////////////// ARRAYS ///////////////////////////////////////////////////////
//////////////////////////////////////////// "Telescope Array Project" ///////////////////////////////////////////////
///////////////////////////////////////////////////// Stub Code //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The following stub code defines four non-null-terminated character arrays
// Each array stores the map coordinates, in Degrees Mintues Seconds (DMS) format, of a 
//     "Telescope Array Project" station (https://en.wikipedia.org/wiki/Telescope_Array_Project)
// The coordinates are not listed complete with degrees (o), minutes ('), and seconds ("")
// The student must modify each char array to change the underscores (_) to the appropriate symbol
// For each array:
//     Index 3 and index 17 must be changed to 0xF8, the degree symbol (or 0xB0, depending on the implementation)
//     Index 7 and index 21 must be changed to 0x27, the apostrophe
//     Index 11 and index 25 must be changed to 0x22, the double apostrophe
// The students may only modify the char arrays using dereferenced pointers
//     (the exact reasoning will become clear later in this objective)
//     (SPOILER:  "pass by reference")
// After the modifications have been made, print all four char arrays in a human-readable format
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 28 // Standard dimension for the four char arrays

int main(void)
{
	/* The four "Telescope Array Project" station char arrays are defined with DMS coordinates */
	// IMPORTANT NOTE:  These char arrays are (purposely) *NOT* null-terminated so take care!
	char blackRockMesaDMS[BUFF_SIZE] = { "039_011_018_N 112_042_042_W" };
	char longRidgeDMS[BUFF_SIZE] = { "039_012_028_N 113_007_017_W" };
	char middleDrumDMS[BUFF_SIZE] = { "039_028_022_N 112_059_037_W" };
	char centralLaserFacilityDMS[BUFF_SIZE] = { "039_017_049_N 112_054_031_W" };


	///////////////////////
	// MODIFY THE ARRAYS //
	///////////////////////

	char * memoryLocations[] = { blackRockMesaDMS, longRidgeDMS, middleDrumDMS, centralLaserFacilityDMS };
	
	for (int i = 0; i < sizeof(memoryLocations) / sizeof(memoryLocations[0]); i++)
	{
		//sets equal to ascii degrees (°)
		memoryLocations[i][3] = 0xF8;
		memoryLocations[i][17] = 0xF8;

		//sets equal to ascii apostrophe (') for minutes
		memoryLocations[i][7] = 0x27;
		memoryLocations[i][21] = 0x27;

		//sets equal to ascii double apostrophe/quotes (") for seconds
		memoryLocations[i][11] = 0x22;
		memoryLocations[i][25] = 0x22;
	}


	//////////////////////
	// PRINT THE ARRAYS //
	//////////////////////

	for (int o = 0; o < sizeof(memoryLocations)/sizeof(memoryLocations[0]); o++)
	{
		for (int i = 0; i < BUFF_SIZE; i++)
		{
			putchar(memoryLocations[o][i]);
		}
		printf("\n");
	}

	getchar();
	return 0;
}
