//*****************************************************************************
// TITLE:			Tron
// 
// NAME:		    Andrew Lundholm, Jiayu Wang
// LAB SECTION:		303
// LAB DAY:			Tuesday Afternoon
//
// CLASS:			ECE 210
// DATE: 			Spring 2016
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


