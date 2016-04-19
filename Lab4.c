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
// DESCRIPTION:		Tron Light Cycle Game
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
RIT128x96x4Init(1000000);
RIT128x96x4Clear();

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

		int start = 0;

  	while(!start)
    {
						start = start || read_PBSwitchNum(1) || read_PBSwitchNum(2) || read_PBSwitchNum(3);
            RIT128x96x4StringDraw(“Tron”, 108, 40, 15);
						//char is 6 wide by 8 tall, Tron = 24w, 8h
						//res 240 by 96
    }

    //Display instructions

    while(button not pressed)
    {
         //read for button press
    }

    //Reset variables to initial state

		sysTickWait1mS(100);
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
