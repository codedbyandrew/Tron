//*****************************************************************************
// TITLE:            Tron
//
// NAME:            Andrew Lundholm, Jiayu Wang
// LAB SECTION:        303
// LAB DAY:            Tuesday Afternoon
//
// CLASS:            ECE 210
// DATE:             Spring 2016
// DUE:       May 3rd
// DESCRIPTION:        Tron Light Cycle Game
//*****************************************************************************
/* Initialization Functions */
void    LEDBARInit(void);
void     DIPSWInit(void);
void    PBSwInit(void);
void     RGB_LEDInit(void);
void     sysTickInit(void);
/* Inputs, outputs, and wait timers */
int     read_PBSwitchNum(int SwitchNumber);
int        read_Switches(void);
void  LEDBAROutput(int value);
void     turnOn(char color);
void     turnOff(char color);
void  potentiometersInit(void);
int   readPotentiometer0(void);
int   readPotentiometer1(void);
int   readPotentiometer2(void);
void  sysTickWait1mS(int waitTime);
void    RIT128x96x4Init(int freq);
void  RIT128x96x4Clear(void);
void  RIT128x96x4StringDraw(const char* letter, int xx, int yy, int intensity);
void RIT128x96x4ImageDraw(const char* image, int x, int y, int width, int len);
char* convert(int baudotCode);
void waitForButtonPress(void);
int updatePlayerDir(int currDir);


const char DOT[96] = {255,255};


//*****************************************************************************
//
// Main Application:
//
//*****************************************************************************

//Define variables
//2D array 128 by 96
int grid[48][96];
//x,y coords of CPU and Player
int cpuX;
int cpuY;
int playerX;
int playerY;
//Current direction for both cpu and user (0-left, 1 -up, 2-right, 3 - down)
int cpuDir;
int playerDir;
int oldPalyerDir;
long x;
int i;
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
    //    potentiometersInit();
    RIT128x96x4Init(1000000);
    
    RGB_LEDInit();
    potentiometersInit();
    RIT128x96x4Clear();
    
    RIT128x96x4StringDraw("Tron", 52, 44, 15);
    RIT128x96x4StringDraw("press button to start", 1, 52, 15);
    //char is 6 wide by 8 tall, Tron = 24w, 8h
    //res 128 by 96
    waitForButtonPress();
    
    RIT128x96x4Clear();
    //Display instructions
    //40 chars will fill the screen
    RIT128x96x4StringDraw("Navigate your", 0, 0, 15);
    RIT128x96x4StringDraw("lightcycle and avoid", 0, 8, 15);
    RIT128x96x4StringDraw("touching the paths", 0, 16, 15);
    RIT128x96x4StringDraw("First player to be", 0, 24, 15);
    RIT128x96x4StringDraw("trapped by a trail", 0, 32, 15);
    RIT128x96x4StringDraw("will be derezzed-lose", 0, 40, 15);
    sysTickWait1mS(500);
    waitForButtonPress();
    RIT128x96x4Clear();
    
    //Reset variables to initial state
    cpuX = 20;
    cpuY = 48;
    playerX = 106;
    playerY = 48;
    cpuDir = 2;
    playerDir = 0;
    
    
    
    RIT128x96x4StringDraw("CPU", 0, 40, 15);
    RIT128x96x4ImageDraw(DOT, cpuX, cpuY, 2, 1);
    
    RIT128x96x4StringDraw("YOU", 108,  40, 15);
    RIT128x96x4ImageDraw(DOT, playerX, playerY, 2, 1);
    
    RIT128x96x4StringDraw("3", 61, 44, 15);
    sysTickWait1mS(1000);
    RIT128x96x4StringDraw("2", 61, 44, 15);
    sysTickWait1mS(1000);
    RIT128x96x4StringDraw("1", 61, 44, 15);
    sysTickWait1mS(1000);
    RIT128x96x4StringDraw(" ", 61, 44, 15);
    RIT128x96x4StringDraw("   ", 108,  40, 15);
    RIT128x96x4StringDraw("   ", 0, 40, 15);
    
    progress = 0;
    while(progress == 0){
        RIT128x96x4ImageDraw(DOT, cpuX, cpuY, 2, 2);
        RIT128x96x4ImageDraw(DOT, playerX, playerY, 2, 2);
        cpuX+=2;
        
        
        oldPalyerDir = playerDir;
        
        for(i=0; i < 100000; i++){
            playerDir = updatePlayerDir(oldPalyerDir);
        }
        
        if(playerDir == 0){
            playerX-=2;
            }else if(playerDir == 1){
            playerY-=2;
            }else if(playerDir == 2){
            playerX+=2;
            }else{
            playerY+=2;
        }
        
        if(playerX < 0 || playerX > 128 || playerY > 96 || playerY < 0){
            progress = 1;
            
        }
	}


	if(progress == 1){  
    RIT128x96x4StringDraw("YOU LOSE", 40,  44, 15);
	}else{
    RIT128x96x4StringDraw("YOU WIN", 43,  44, 15);
	}
}

void waitForButtonPress(){
    int progress1 = read_PBSwitchNum(1);
    int progress2 = read_PBSwitchNum(2);
    int progress3 = read_PBSwitchNum(3);
    
    while((progress1 != 0x0) && (progress2 != 0x0) && (progress3 != 0x0))
    {
        //start on any button press
        progress1 = read_PBSwitchNum(1);
        progress2 = read_PBSwitchNum(2);
        progress3 = read_PBSwitchNum(3);
    }
    
    
}

int updatePlayerDir(int currDir){
    int progress1 = read_PBSwitchNum(1);
    int progress3 = read_PBSwitchNum(3);
    
    if((progress1 == 0x0) && (progress3 == 0x0)){
        //don't do anything
        }else if((progress1 == 0x0)){
        currDir = currDir -1;
        currDir = currDir%4;
        }else if((progress3 == 0x0)){
        currDir = currDir +1;
        currDir = currDir%4;
    }
    return currDir;
}