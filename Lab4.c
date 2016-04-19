//*****************************************************************************
// TITLE:			Tron
//
// NAME:		    Andrew Lundholm, Jiayu Wang
// LAB SECTION:		303
// LAB DAY:			Tuesday Afternoon
//
// CLASS:			ECE 210
// DATE: 			Spring 2016
// DUE:       May 3rd
// DESCRIPTION:		Tron Light Cycle Game
//*****************************************************************************

//*****************************************************************************
//
// Main Program:
//
//*****************************************************************************
void	LEDBARInit(void);
void 	DIPSWInit(void);
void	PBSwInit(void);
void 	RGB_LEDInit(void);
void 	sysTickInit(void);
int rand(void);
/* Inputs, outputs, and wait timers */
int 	read_PBSwitchNum(int SwitchNumber);
int		read_Switches(void);
void    LEDBAROutput(int value);
void 	turnOn(char color);
void 	turnOff(char color);
void  potentiometersInit(void);
int   readPotentiometer0(void);
int   readPotentiometer1(void);
int   readPotentiometer2(void);
void    LEDBAROutput(int number);
void    LEDBAR_TurnOn(int number);
void    LEDBAR_TurnOff(int number);
int   read_SwitchNum(int SwitchNum);
int   read_Switches(void);
void    sysTickWait1mS(int waitTime);
void	RIT128x96x4Init(int freq);
void    RIT128x96x4Clear(void);
void    RIT128x96x4StringDraw(const char* letter, int xx, int yy, int intensity);
char* 	convert(int baudotCode);
void	LEDBARInit(void);
time_t time(time_t *);


	//Define variables
	//2D array 240 by 96
int grid[240][96];
	//x,y coords of CPU and Player
int cpuX;
int cpuY;
int playerX;
int playerY;
	//Current direction for both cpu and user (0-left, 1 -up, 2-right, 3 - down)
int cpuDir;
int playerDir;
long x;
  //Display title screen
int progress = 0;

int
main(void)
{

/* Initialization Functions */
	//Section to initialize switches and displays
	    //Initialize display
	  //used for system clock
	    //Initialize Buttons
	LEDBARInit();
	DIPSWInit();
	PBSwInit();
	RGB_LEDInit();
	sysTickInit();
	potentiometersInit();
	RIT128x96x4Init(1000000);

RGB_LEDInit();
potentiometersInit();
RIT128x96x4Clear();



  	while(!progress)
    {
						//start on any button press
						progress = progress || read_PBSwitchNum(1) || read_PBSwitchNum(2) || read_PBSwitchNum(3);
            RIT128x96x4StringDraw("Tron", 108, 40, 15);
						//char is 6 wide by 8 tall, Tron = 24w, 8h
						//res 240 by 96
    }
		progress = 0;

    //Display instructions
    while(!progress)
    {
			//40 chars will fill the screen
			progress = progress || read_PBSwitchNum(1) || read_PBSwitchNum(2) || read_PBSwitchNum(3);
			RIT128x96x4StringDraw("Navigate your lightcycle and avoid", 0, 0, 15);
			RIT128x96x4StringDraw("touching the paths. First player to be", 0, 8, 15);
			RIT128x96x4StringDraw("trapped by a trail will be derezzed (lose).", 0, 16, 15);
    }
		progress = 0;


    //Reset variables to initial state
		cpuX = 0;
		cpuY = 48;
		playerX = 239;
		playerY = 48;
		cpuDir = 2;
		playerDir = 0;




    while(!progress){
				sysTickWait1mS(100);
        //read buttons to update player direction
				//rotate counter-clockwise
				playerDir = (playerDir - read_PBSwitchNum(1))%4;
				//rotate clockwise
				playerDir = (playerDir + read_PBSwitchNum(3))%4;

        //generate random direction for CPU
				//x = random();

    //}

    //Update Coordinates in array and variables
    //Check for collisions
        //No collisions: display the array to the screen
        //Collision: Determine who collided and display win/lose screen
                //Go back to instruction screen
	 }
}
