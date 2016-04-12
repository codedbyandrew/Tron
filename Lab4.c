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
void	PBSwInit(void);	
void 	sysTickInit(void);
void 	RGB_LEDInit(void);
void	LEDBARInit(void);

int 	read_PBSwitchNum(int SwitchNumber);
void    sysTickWait1mS(int waitTime);

int
main(void)
{

/* Initialization Functions */
	//Section to initialize switches and displays
	    //Initialize display
	  //used for system clock
	    //Initialize Buttons
	int PB1, PB2;
	PBSwInit();
	
	//Define variables
	    //2D array 128 by 96
	int grid[128][96];
	    //x,y coords of CPU and Player
	    int cpuX;
	    int cpuY;
	    int playerX;
	    int playerY;
	    //Current direction for both cpu and user (0-left, 1 -up, 2-right, 3 - down)
	    int cpuDir;
	    int playerDir;


    //Display title screen

  	while(button not pressed)
    {
            //read for button press
    }

    //Display instructions

    while(button not pressed)
    {
         //read for button press
    }

    //Reset variables to initial state

    while(time is not .1sec){
        //read buttons to update player direction
        //generate random direction for CPU
    }

    //Update Coordinates in array and variables
    //Check for collisions
        //No collisions: display the array to the screen
        //Collision: Determine who collided and display win/lose screen
                //Go back to instruction screen






}   


