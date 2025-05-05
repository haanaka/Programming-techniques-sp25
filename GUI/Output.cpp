#include "Output.h"
#define r3 1.7320508075689

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1290 ;
	UI.height = 720;
	UI.wx = 10;
	UI.wy = 10;


	UI.StatusBarHeight = 64;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 64;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("A+ BEL SATR TEAM 9");

	CreateDrawToolBar();
	CreateStatusBar();
}

//======================================================================================//
Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reorder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_sqr.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_triangle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_hexagon.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_circle.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Menu_COLOR.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_select.jpg";
	MenuItemImages[ITM_SWAP] = "images\\MenuItems\\Menu_swap.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\Menu_rotate.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_clear.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_paste.jpg";
	MenuItemImages[ITM_REDO]= "images\\MenuItems\\Menu_redo.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_undo.jpg";
	MenuItemImages[ITM_SAVE] =	"images\\MenuItems\\Menu_save.jpg";
	MenuItemImages[ITM_LOAD] =	       "images\\MenuItems\\Menu_load.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY] = "images\\MenuItems\\Menu_switchToDraw.jpg";
	MenuItemImages[ITM_EXIT] =			"images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[empty123] =				"images\\MenuItems\\Menu_Empty.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{

	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu


	string PLAYItemImages[PLAY_ITM_COUNT];
	PLAYItemImages[PLAY_ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	PLAYItemImages[PLAY_ITM_LOAD] = "images\\MenuItems\\Menu_load.jpg";
	PLAYItemImages[PLAY_ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\Menu_switchToPlay.jpg";
	PLAYItemImages[PLAY_ITM_SWITCH_GAME_MODE] = "images\\MenuItems\\Menu_switchmode.jpg";
	PLAYItemImages[PLAY_ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY1] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY2] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY3] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY4] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY5] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY6] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY7] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY8] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY9] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY10] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY11] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY12] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY13] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY14] = "images\\MenuItems\\Menu_Empty.jpg";
	PLAYItemImages[PLAY_ITM_EMPTY15] = "images\\MenuItems\\Menu_Empty.jpg";
	//////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PLAYItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int radius = sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));
	pWind->DrawCircle(P1.x, P1.y, radius, style);
	CreateDrawToolBar(); ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	CreateDrawToolBar(); ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	CreateDrawToolBar(); ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::Drawsquare(Point P1, GfxInfo SqrGfxInfo, bool selected) const 
{
	int* PX = new int[4];
	int* PY = new int[4];
	
	PX[0] = P1.x + 75;
	PY[0] = P1.y + 75;

	PX[1] = P1.x - 75;
	PY[1] = P1.y + 75;

	PX[2]= P1.x - 75;
	PY[2] = P1.y - 75;

	PX[3] = P1.x + 75;
	PY[3] = P1.y - 75;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SqrGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(PX, PY, 4, style);
	delete[] PX, PY;
	CreateDrawToolBar(); ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawHexagon(Point P, GfxInfo HexGfxInfo, bool selected) const
{
	int *PX, *PY;
	PX = new int[6];
	PY = new int[6];

	PX[0] = P.x+100;    PY[0] = P.y;

	PX[1] = P.x + 50;	PY[1] = P.y + 50 * r3;

	PX[2] = P.x-50;     PY[2] = P.y + 50 * r3;
	 
	PX[3] = P.x-100;    PY[3] = P.y;

	PX[4] = P.x-50;     PY[4] = P.y - 50 * r3;

	PX[5] = P.x+50;     PY[5] = P.y - 50 * r3;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawPolygon(PX,PY, 6, style);
	delete[] PX, PY;
	CreateDrawToolBar(); ClearStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearALl() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::changecolor(color c) const
{
	UI.DrawColor = c;
	pWind->SetPen(UI.DrawColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output() {}


