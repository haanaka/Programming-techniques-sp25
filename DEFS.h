#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQR,		//Draw Square
	DRAW_CIRCLE,	//Draw Circle
	DRAW_HEXA,		//Draw Hexagon
	DRAW_TRI,		//Draw Triangle
	COLOUR,		    //COLOR OF SHAPE
	SELECT,			//Select a figure
	SWAP,			//Swap two figures
	ROTATE,			//Rotate a figure
	dELETE,			//Delete a figure
	CLEAR_ALL,		//Clear the drawing area
	COPY,			//Copy a figure
	CUT,			//Cut a figure
	REDO,
	UNDO,
	PASTE,			//Paste a figure
	SAVE,			//Save the drawing
	LOAD,			//Load a drawing
	SWITCH_TO_DRAW,	//Switch interface to Draw mode
	SWITCH_TO_PLAY,	//Switch interface to Play mode
	SWITCH_GAMEMODE,//Switch interface to Game mode
	EXIT,			//Exit
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	PLAYING_AREA,	//A click on the playing area

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif