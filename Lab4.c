//*****************************************************************************
// TITLE:			LAB 4
// 
// NAME:		    <Your Name Here>
// LAB SECTION:		<301, 302, 303, or 304>
// LAB DAY:			<Lab Day>
//
// CLASS:			ECE 210
// DATE: 			FALL 2012
// 
// DESCRIPTION:		<Insert a short description of what you are working on in 
//                   in this lab>
//*****************************************************************************

//*****************************************************************************
//
// Main Program:
//
//*****************************************************************************
int
main(void)
{	
	//This is a "container" for the value of the switches
	int switchValues;

	// We must get the devices on the BB12 ready to use.
	// The two lines below get our DIP Switches and LED Bar ready to go.
	DIPSWInit();
	LEDBARInit();


  	while(1)
    {
		//Get the values from the switches
		switchValues = read_Switches();
		//Put them out on the LEDBAR
		LEDBAROutput(switchValues);
		
			

    }
}   


