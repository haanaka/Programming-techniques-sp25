#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_RECT,		//Recangle item in menu
	ITM_SQR,
	ITM_TRI,
	ITM_HEXA,
	ITM_CIRC,
	ITM_COLOR,
	ITM_SELECT,
	ITM_SWAP,
	ITM_ROTATE,
	ITM_DELETE,
	ITM_CLEARALL,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_UNDO,
	ITM_REDO,
	ITM_SAVE,
	ITM_LOAD,
	ITM_SWITCH_TO_PLAY,
	ITM_EXIT,		//Exit item
	empty123,
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};
/*TM_BLACK,
ITM_RED,
ITM_GREEN,
ITM_BLUE,
ITM_YELLOW,
ITM_ORANGE,*/
enum PlayMenuItem //Thez items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names 
	PLAY_ITM_SAVE,
	PLAY_ITM_LOAD,
	PLAY_ITM_SWITCH_TO_DRAW,
	PLAY_ITM_SWITCH_GAME_MODE,
	PLAY_ITM_EXIT,
	PLAY_ITM_EMPTY1,
	PLAY_ITM_EMPTY2,
	PLAY_ITM_EMPTY3,
	PLAY_ITM_EMPTY4,
	PLAY_ITM_EMPTY5,
	PLAY_ITM_EMPTY6,
	PLAY_ITM_EMPTY7,
	PLAY_ITM_EMPTY8,
	PLAY_ITM_EMPTY9,
	PLAY_ITM_EMPTY10,
	PLAY_ITM_EMPTY11,
	PLAY_ITM_EMPTY12, 
	PLAY_ITM_EMPTY13,
	PLAY_ITM_EMPTY14,
	PLAY_ITM_EMPTY15,
	PLAY_ITM_COUNT,		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif