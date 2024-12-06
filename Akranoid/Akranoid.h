#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;



struct Akranoid
{

private:

	RenderWindow window; //Making Window For Game with buttons of resize close titlebar etc.
	Event key; //Capturing Event if we press any key in window

	RectangleShape boundary;
	RectangleShape bar;
	CircleShape ball;
	CircleShape ball2;
	RectangleShape bar2;
	RectangleShape bricks[20][20];
	RectangleShape boxes[2][2];
	RectangleShape SelectBar[2][2];
	CircleShape life[3];




	Clock boundarycolor;
	Clock ballandbarcolor;


	bool gamestarted;
	bool gamecompleted;
	bool instruction;
	bool gameover;
	bool gamewin;
	bool mouseenabled=true;
	int selectedCheckboxRow = -1; // -1 indicates no checkbox is selected
	int selectedCheckboxCol = -1;
	int bricksrows;
	int brickscolunms;
	int level = 1;
	bool selection;
	int score = 0;
	int highscore = 0;
	int health = 3;
	float bar2speed=-1;
	float boundarycolorchange = 0.2;
	float ballandbarcolorchange = 0.2;
	float ballspeedx = -3;
	float ballspeedy = -4;
	float ball2speedx = -2;
	float ball2speedy = -3;

	Font ofgamewin;
	Text forgamewin;

	Font ofgameover;
	Text forgameover;

	Font forscore;
	Text scoreUpdating;

	Font forhighscore;
	Text ofhighscore;

	Font ofmenuscreen;
	Text formenuscreen;

	Font ofstratbutton;
	Text forstartbutton;

	Font ofstratbutton2;
	Text forstartbutton2;

	Font ofselect;
	Text forselect;

	Font ofinstructionbutton;
	Text forinstructionbutton;

	Font ofquitbutton;
	Text forquitbutton;

	Font ofbackbutton;
	Text forbackbutton;

	Font ofinstructionmenu;
	Text forinstructionmenu;

	Font ofmainmenubutton;
	Text formainmenubutton;



	void initwindow();
	void menuscreen();
	void selectionscreen();
	void startbutton();
	void instructionbutton();
	void quitbutton();
	void backbutton();
	void mainmenubutton();
	void instructionmenu();
	void gameovermenu();
	void gamewinmenu();
	void Boundary();
	void makinghealth();
	void makingbar();
	void makingball();
	void makingbricksforlevel1();
	void makingbricksforlevel2();
	void makingbricksforlevel3();
	void makingbricksforlevel4();
	void makingbricksforlevel5();

public:
	Akranoid();

	bool const windowisopen() const;
	void eventpoll();

	void resetgame();
	void Updaitngball2andbar2position();
	void Updatingboundarycolor();
	void UpdatingBarposition();
	void UpdatingBallposition();
	void gamecomplete();
	void ballandbar();
	void ballandbricks();
	void update();
	void render();

}; 

