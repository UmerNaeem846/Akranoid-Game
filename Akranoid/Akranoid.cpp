#include "Akranoid.h"
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <cstdlib>
#include <ctime>

using namespace sf;
using namespace std;

void Akranoid::initwindow()
{
	window.create(VideoMode(1280, 720), "Flappy Bird", Style::Titlebar | Style::Close | Style::Resize);
	window.setFramerateLimit(60);
}

void Akranoid::menuscreen()
{
	ofmenuscreen.loadFromFile("AGENCYB.TTF");
	formenuscreen.setFont(ofmenuscreen);
	formenuscreen.setFillColor(Color::White);
	formenuscreen.setCharacterSize(90);
	formenuscreen.setString("AKRANOID");
	formenuscreen.setPosition(470, 40);
	formenuscreen.setStyle(Text::Bold);
}

void Akranoid::selectionscreen()
{

	
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			if (i == 0 && j == 0)
			{
				SelectBar[i][j].setSize(Vector2f(100, 20));
				SelectBar[i][j].setPosition(400, 200);
				SelectBar[i][j].setFillColor(Color::White);
				boxes[i][j].setSize(Vector2f(20, 20));
				boxes[i][j].setOutlineColor(Color::White);
				boxes[i][j].setOutlineThickness(3);
				boxes[i][j].setPosition(440, 240);
				boxes[i][j].setFillColor(Color::Transparent);
			}
			if (i == 0 && j == 1)
			{
				SelectBar[i][j].setSize(Vector2f(100, 20));
				SelectBar[i][j].setPosition(700, 200);
				SelectBar[i][j].setFillColor(Color::Red);
				boxes[i][j].setSize(Vector2f(20, 20));
				boxes[i][j].setOutlineColor(Color::White);
				boxes[i][j].setOutlineThickness(3);
				boxes[i][j].setPosition(740, 240);
				boxes[i][j].setFillColor(Color::Transparent);

			}
			if (i == 1 && j == 0)
			{
				SelectBar[i][j].setSize(Vector2f(100, 20));
				SelectBar[i][j].setPosition(400, 400);
				SelectBar[i][j].setFillColor(Color::Cyan);
				boxes[i][j].setSize(Vector2f(20, 20));
				boxes[i][j].setOutlineColor(Color::White);
				boxes[i][j].setOutlineThickness(3);
				boxes[i][j].setPosition(440, 440);
				boxes[i][j].setFillColor(Color::Transparent);

			}
			if (i == 1 && j == 1)
			{
				SelectBar[i][j].setSize(Vector2f(100, 20));
				SelectBar[i][j].setPosition(700, 400);
				SelectBar[i][j].setFillColor(Color::Green);
				boxes[i][j].setSize(Vector2f(20, 20));
				boxes[i][j].setOutlineColor(Color::White);
				boxes[i][j].setOutlineThickness(3);
				boxes[i][j].setPosition(740, 440);
				boxes[i][j].setFillColor(Color::Transparent);

			}

		}
	}

	ofstratbutton2.loadFromFile("AGENCYB.TTF");
	forstartbutton2.setFont(ofstratbutton2);
	forstartbutton2.setFillColor(Color::White);
	forstartbutton2.setCharacterSize(40);
	forstartbutton2.setString("Start Game");
	forstartbutton2.setPosition(550, 600);
	forstartbutton2.setStyle(Text::Bold);
	gamestarted = false;
}

void Akranoid::startbutton()
{
	ofstratbutton.loadFromFile("AGENCYB.TTF");
	forstartbutton.setFont(ofstratbutton);
	forstartbutton.setFillColor(Color::White);
	forstartbutton.setCharacterSize(40);
	forstartbutton.setString("Start Game");
	forstartbutton.setPosition(40, 270);
	forstartbutton.setStyle(Text::Bold);
	selection = false;
}

void Akranoid::instructionbutton()
{
	ofinstructionbutton.loadFromFile("AGENCYB.TTF");
	forinstructionbutton.setFont(ofinstructionbutton);
	forinstructionbutton.setFillColor(Color::White);
	forinstructionbutton.setCharacterSize(40);
	forinstructionbutton.setString("Instructions");
	forinstructionbutton.setPosition(40, 320);
	forinstructionbutton.setStyle(Text::Bold);
	instruction = false;
}
void Akranoid::quitbutton()
{
	ofquitbutton.loadFromFile("AGENCYB.TTF");
	forquitbutton.setFont(ofquitbutton);
	forquitbutton.setFillColor(Color::White);
	forquitbutton.setCharacterSize(40);
	forquitbutton.setString("Quit Game");
	forquitbutton.setPosition(40, 370);
	forquitbutton.setStyle(Text::Bold);
}

void Akranoid::backbutton()
{
	ofbackbutton.loadFromFile("AGENCYB.TTF");
	forbackbutton.setFont(ofbackbutton);
	forbackbutton.setFillColor(Color::Black);
	forbackbutton.setCharacterSize(40);
	forbackbutton.setString("Back");
	forbackbutton.setPosition(70, 120);
	forbackbutton.setStyle(Text::Bold);
}

void Akranoid::mainmenubutton()
{
	ofmainmenubutton.loadFromFile("AGENCYB.TTF");
	formainmenubutton.setFont(ofmainmenubutton);
	formainmenubutton.setPosition(550, 300);
	formainmenubutton.setString("Main Menu");
	formainmenubutton.setFillColor(Color::White);
	formainmenubutton.setCharacterSize(40);
}

void Akranoid::instructionmenu()
{
	ofinstructionmenu.loadFromFile("AGENCYB.TTF");
	forinstructionmenu.setFont(ofinstructionmenu);
	forinstructionmenu.setFillColor(Color::White);
	forinstructionmenu.setCharacterSize(30);
	forinstructionmenu.setString("Game Instructions\n\n"
	"1.Use Arrow keys or A/D keys to move Bar.\n"
	"2.Use bar to move ball.\n"
	"3.Prevent the ball from falling below the bar.\n"
	"4.The ball will break bricks when it touches them.\n"
	"5.Different colors may represent different levels or points.\n");
	forinstructionmenu.setPosition(290, 170);
	forinstructionmenu.setStyle(Text::Bold);
	bar2.setPosition(1000, 240);
	bar2.setFillColor(Color::White);
	bar2.setSize(Vector2f(100, 20));
	ball2.setRadius(8);
	ball2.setPosition(1040, 222);
	ball2.setFillColor(Color::Blue);

}

void Akranoid::gameovermenu()
{
	ofgameover.loadFromFile("AGENCYB.TTF");
	forgameover.setFont(ofgameover);
	forgameover.setCharacterSize(40);
	forgameover.setString("You lose the Game! You are a noob player.");
	forgameover.setFillColor(Color::White);
	forgameover.setPosition(370, 170);




	gameover = false;

}
void Akranoid::gamewinmenu()
{
	ofgamewin.loadFromFile("AGENCYB.TTF");
	forgamewin.setFont(ofgamewin);
	forgamewin.setCharacterSize(40);
	forgamewin.setString("You Won the Game! You are a PRO player.");
	forgamewin.setFillColor(Color::White);
	forgamewin.setPosition(370, 170);




	gamewin = false;

}

void Akranoid::Boundary()
{
	boundary.setSize(Vector2f(1260, 650));
	boundary.setPosition(10, 10);
	boundary.setFillColor(Color::Transparent);
	boundary.setOutlineThickness(20);
	boundary.setOutlineColor(Color::White);
}

void Akranoid::makinghealth()
{
	float xspacing = 25;
	for (int i = 0;i < 3;i++)
	{
		life[i].setRadius(8);
		life[i].setPosition(20 + i * xspacing, 690);
		life[i].setFillColor(Color::Blue);
	}
}

void Akranoid::makingbar()
{
	bar.setSize(Vector2f(100, 20));
	bar.setPosition(590, 610);
	if (selectedCheckboxCol == 0 && selectedCheckboxRow == 0)
	{
		bar.setFillColor(Color::White);
	}
	if (selectedCheckboxCol == 1 && selectedCheckboxRow == 0)
	{
		bar.setFillColor(Color::Red);
	}
	if (selectedCheckboxCol == 0 && selectedCheckboxRow == 1)
	{
		bar.setFillColor(Color::Cyan);
	}
	if (selectedCheckboxCol == 1 && selectedCheckboxRow == 1)
	{
		bar.setFillColor(Color::Green);
	}

}

void Akranoid::makingball()
{
	ball.setRadius(8);
	ball.setPosition(630,592);
	ball.setFillColor(Color::Blue);

}

void Akranoid::makingbricksforlevel1()
{
	float xspacing = 62;
	float yspacing = 22;
	float startx = 20;
	float starty = 20;
	bricksrows = 6;
	for (int i = 0;i < bricksrows;i++)
	{
		brickscolunms = 20;
		for (int j = 0;j < brickscolunms;j++)
		{
			bricks[i][j].setSize(Vector2f(60, 20));
			if (i == 0)
				bricks[i][j].setFillColor(Color::Red);
			else if (i == 1)
				bricks[i][j].setFillColor(Color::Blue);
			else if (i == 2)
				bricks[i][j].setFillColor(Color::Cyan);
			else if (i == 3)
				bricks[i][j].setFillColor(Color::Yellow);
			else if (i == 4)
				bricks[i][j].setFillColor(Color(102, 0, 0));
			else if (i == 5)
				bricks[i][j].setFillColor(Color::Green);

			bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);
		}
	}
}

void Akranoid::makingbricksforlevel2()
{
	float xspacing = 62;
	float yspacing = 22;
	float startx = 300;
	float starty = 40;
	bricksrows = 10;
	for (int i = 0; i <bricksrows ; i++) 
	{
		brickscolunms = i + 1;

		for (int j = 0; j < brickscolunms; j++)
		{
			bricks[i][j].setSize(Vector2f(60, 20));
			if (j % bricksrows == 0) 
				bricks[i][j].setFillColor(Color::Red);
			else if (j % bricksrows == 1) 
				bricks[i][j].setFillColor(Color::Blue);
			else if (j % bricksrows == 2) 
				bricks[i][j].setFillColor(Color::Cyan);
			else if (j % bricksrows == 3) 
				bricks[i][j].setFillColor(Color::Yellow);
			else if (j % bricksrows == 4)
				bricks[i][j].setFillColor(Color(102, 0, 0));
			else if (j % bricksrows == 5)
				bricks[i][j].setFillColor(Color::Green);
			else if (j % bricksrows == 6) 
				bricks[i][j].setFillColor(Color::Blue);
			else if (j % bricksrows == 7)
				bricks[i][j].setFillColor(Color::Cyan);
			else if (j % bricksrows == 8)
				bricks[i][j].setFillColor(Color::Yellow);
			else if (j % bricksrows == 9)
				bricks[i][j].setFillColor(Color::Green);
			else if (j % bricksrows == 10)
				bricks[i][j].setFillColor(Color::Green);
			bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);
		}
	}
}

void Akranoid::makingbricksforlevel3()
{
	float xspacing = 62;
	float yspacing = 70;
	float startx = 20;
	float starty = 20;
	bricksrows = 6;
	for (int i = 0;i < bricksrows;i++)
	{
		brickscolunms = 20;
		for (int j = 0;j < brickscolunms;j++)
		{
			bricks[i][j].setSize(Vector2f(60, 20));
			if (i == 0)
				bricks[i][j].setFillColor(Color::Red);
			else if (i == 1)
				bricks[i][j].setFillColor(Color::Blue);
			else if (i == 2)
				bricks[i][j].setFillColor(Color::Cyan);
			else if (i == 3)
				bricks[i][j].setFillColor(Color::Yellow);
			else if (i == 4)
				bricks[i][j].setFillColor(Color(102, 0, 0));
			else if (i == 5)
				bricks[i][j].setFillColor(Color::Green);

			bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);
		}
	}
}

void Akranoid::makingbricksforlevel4()
{
	float xspacing = 62;
	float yspacing = 22;
	float startx = 110;
	float starty = 20;
	bricksrows = 14;
	for (int i = 0;i < bricksrows;i++)
	{
		brickscolunms = 16;
		for (int j = 0;j < brickscolunms;j++)
		{

			bricks[i][j].setSize(Vector2f(60, 20));
			if (i == 0||i==9)
				bricks[i][j].setFillColor(Color::Red);
			else if (i == 1||i==10)
				bricks[i][j].setFillColor(Color::Blue);
			else if (i == 2||i==11)
				bricks[i][j].setFillColor(Color::Cyan);
			else if (i == 3||i==12 || i == 6)
				bricks[i][j].setFillColor(Color::Yellow);
			else if (i == 4 || i==13 || i == 7)
				bricks[i][j].setFillColor(Color(102, 0, 0));
			else if (i == 5 || i==14 || i==8)
				bricks[i][j].setFillColor(Color::Green);
			if (j == 8)
			{
				xspacing = 124;
				bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);

			}
			else
			{
				xspacing = 62;
				bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);

			}
		}
	}
}

void Akranoid::makingbricksforlevel5()
{
	float xspacing = 62;  
	float yspacing = 22;  
	float startx = 300;   
	float starty = 50;    
	bricksrows = 11;
	brickscolunms = 13;
	int brickPattern[11][13] = {
		{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0},
		{0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0},
		{1, 1, 2, 2, 3, 3, 3, 3, 2, 2, 1, 1, 0},
		{0, 1, 1, 2, 3, 3, 3, 3, 2, 1, 1, 0, 0},
		{0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0}
	};

	for (int i = 0; i < bricksrows; i++) 
	{       
		for (int j = 0; j < brickscolunms; j++)
		{   
			if (brickPattern[i][j] != 0)
			{ 
				bricks[i][j].setSize(Vector2f(60, 20));

				if (brickPattern[i][j] == 1)
					bricks[i][j].setFillColor(Color::Red);
				else if (brickPattern[i][j] == 2)
					bricks[i][j].setFillColor(Color::Blue);
				else if (brickPattern[i][j] == 3)
					bricks[i][j].setFillColor(Color::Yellow);

				bricks[i][j].setPosition(startx + j * xspacing, starty + i * yspacing);
			}
		}
	}
}


Akranoid::Akranoid()
{
	initwindow();
	selectionscreen();
	makingbar();
	makingball();
	makingbricksforlevel1();
	makinghealth();
	menuscreen();
	startbutton();
	instructionbutton();
	quitbutton();
	backbutton();
	mainmenubutton();
	gameovermenu();
	gamewinmenu();
	instructionmenu();
	Boundary();
}

bool const Akranoid::windowisopen() const
{
	return window.isOpen();
}




void Akranoid::Updaitngball2andbar2position()
{
	if (ballandbarcolor.getElapsedTime().asSeconds() > ballandbarcolorchange)
	{
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		bar2.setFillColor(Color(r, g, b));
		ballandbarcolor.restart();

	}
	bar2.move(bar2speed, 0);
	ball2.move(ball2speedx, ball2speedy);
	if (bar2.getPosition().x <= 1000)
	{
		bar2speed = -bar2speed;
		bar2.setPosition(1000, 240);

	}
	if (bar2.getPosition().x + 20 >= 1040)
	{
		bar2speed = -bar2speed;
		bar2.setPosition(1020, 240);
	}
	if (ball2.getGlobalBounds().intersects(bar2.getGlobalBounds()))
	{
		ball2speedy = -ball2speedy;
	}
	if (ball2.getPosition().x <= 1000 || ball2.getPosition().x + 16 >= 1040)
	{
		ball2speedx = -ball2speedx;
	}

	if (ball2.getPosition().y <= 170)
	{
		ball2speedy = -ball2speedy;
	}
}

void Akranoid::Updatingboundarycolor()
{
	if (boundarycolor.getElapsedTime().asSeconds() > boundarycolorchange)
	{
		int r= rand() % 256;
		int g = rand() % 256;
		int b= rand() % 256;
		boundary.setOutlineColor(Color(r, g, b));
		boundarycolor.restart();

	}
}

void Akranoid::UpdatingBarposition()
{
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		bar.move(-6, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		bar.move(6, 0);
	}
	if (bar.getPosition().x > 1170)
	{
		bar.setPosition(1170, 610);
	}
	if (bar.getPosition().x < 10)
	{
		bar.setPosition(10, 610);
	}
}

void Akranoid::UpdatingBallposition()
{
	ball.move(ballspeedx, ballspeedy);
	if (ball.getPosition().x <= 10 || ball.getPosition().x + 16 >= 1270) 
	{
		ballspeedx = -ballspeedx;
	}

	if (ball.getPosition().y <= 10) 
	{
		ballspeedy = -ballspeedy;
	}
	if (ball.getPosition().y > 666)
	{
		health--;
		makingbar();
		makingball();
		resetgame();

	}

}




void Akranoid::ballandbar()
{
	if (ball.getGlobalBounds().intersects(bar.getGlobalBounds()))
	{
		ballspeedy = -ballspeedy;
	}
}

void Akranoid::ballandbricks()
{
	forscore.loadFromFile("AGENCYB.TTF");
	scoreUpdating.setFont(forscore);
	scoreUpdating.setCharacterSize(30);
	scoreUpdating.setFillColor(Color::White);
	scoreUpdating.setPosition(1100, 680);
	scoreUpdating.setString("Score: " + to_string(score));
	for (int i = 0;i < bricksrows;i++)
	{
		for (int j = 0;j < brickscolunms;j++)
		{
			if (ball.getGlobalBounds().intersects(bricks[i][j].getGlobalBounds()))
			{
				bricks[i][j].setPosition(-100, -100);
				ballspeedy = -ballspeedy;
				if (bricks[i][j].getFillColor() == Color::Green)
				{
					score += 50;

				}
				else if (bricks[i][j].getFillColor() == Color(102,0,0))
				{
					score +=60 ;
				}
				else if (bricks[i][j].getFillColor() == Color::Yellow)
				{
					score +=70 ;
				}
				else if (bricks[i][j].getFillColor() == Color::Cyan)
				{
					score += 90;
				}
				else if (bricks[i][j].getFillColor() == Color::Blue)
				{
					score += 90;
				}
				else if (bricks[i][j].getFillColor() == Color::Red)
				{
					score += 100;
				}
				scoreUpdating.setString("Score: " + to_string(score));
				gamecomplete();
			}

		}
	}
}
void Akranoid::gamecomplete()
{
	gamecompleted = true;
	for (int i = 0;i < bricksrows;i++)
	{
		for (int j = 0;j < brickscolunms;j++)
		{
			if (bricks[i][j].getPosition().x > -100 && bricks[i][j].getPosition().y > -100)
			{
				gamecompleted = false;
				break;
			}
		}

	}

	if (gamecompleted)
	{
		level++;
		if (level < 10)
		{
			if (level == 2)
			{
				makingbricksforlevel2();
				makingball();
				makingbar();
			}
			if (level == 3)
			{
				makingbricksforlevel3();
				makingball();
				makingbar();
			}
			if (level == 4)
			{
				makingbricksforlevel4();
				makingball();
				makingbar();
			}
			if (level == 5)
			{
				makingbricksforlevel5();
				makingball();
				makingbar();
			}
		}
		else
		{
			gamestarted = false;
			gamewin = true;
			mouseenabled = true;
			if (score > highscore)
			{
				highscore = score;
				ofstream file("highscore.txt");
				if (file.is_open())
				{
					file << highscore;
					file.close();
				}
			}
			forhighscore.loadFromFile("AGENCYB.TTF");
			ofhighscore.setFont(forhighscore);
			ofhighscore.setFillColor(Color::White);
			ofhighscore.setCharacterSize(30);
			ofhighscore.setString("High Score: " + std::to_string(highscore));
			ofhighscore.setPosition(550, 220);
			ofhighscore.setStyle(Text::Bold);
			score = 0;
			health = 3;
			makingbricksforlevel1();
			makingball();
			makingbar();
		}

	}
}
void Akranoid::resetgame()
{
	if (health == 0)
	{
		gamestarted = false;
		gameover = true;
		mouseenabled = true;
		if (score > highscore)
		{
			highscore = score;
			ofstream file("highscore.txt");
			if (file.is_open())
			{
				file << highscore;
				file.close();
			}
		}
		forhighscore.loadFromFile("AGENCYB.TTF");
		ofhighscore.setFont(forhighscore);
		ofhighscore.setFillColor(Color::White);
		ofhighscore.setCharacterSize(30);
		ofhighscore.setString("High Score: " + std::to_string(highscore));
		ofhighscore.setPosition(550, 220);
		ofhighscore.setStyle(Text::Bold);
		score = 0;
		health = 3;
		makingball();
		makingbar();
		makingbricksforlevel1();
	}
}

void Akranoid::eventpoll()
{
	while (window.pollEvent(key))
	{
		switch (key.type)
		{
		case Event::Closed:
			window.close();
		case Event::MouseMoved:
			if (mouseenabled)
			{
				if (forstartbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					forstartbutton.setFillColor(Color::Green);
				}
				else
				{
					forstartbutton.setFillColor(Color::White);

				}
				if (forinstructionbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					forinstructionbutton.setFillColor(Color::Green);
				}
				else
				{
					forinstructionbutton.setFillColor(Color::White);

				}
				if (forbackbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					forbackbutton.setFillColor(Color::Green);
				}
				else
				{
					forbackbutton.setFillColor(Color::White);
				}
				if (forquitbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					forquitbutton.setFillColor(Color::Green);
				}
				else
				{
					forquitbutton.setFillColor(Color::White);

				}
				if (formainmenubutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					formainmenubutton.setFillColor(Color::Green);

				}
				else
				{
					formainmenubutton.setFillColor(Color::White);
				}
				if (forstartbutton2.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					forstartbutton2.setFillColor(Color::Green);

				}
				else
				{
					forstartbutton2.setFillColor(Color::White);
				}
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						if (boxes[i][j].getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
						{
							if (selectedCheckboxRow != -1 && selectedCheckboxCol != -1)
							{
								boxes[selectedCheckboxRow][selectedCheckboxCol].setFillColor(Color::Transparent);
							}

							boxes[i][j].setFillColor(Color::Green);
							selectedCheckboxRow = i;
							selectedCheckboxCol = j;
							makingbar();

						}
					}
				}

			}
			
		case Event::MouseButtonPressed:

			if (mouseenabled && key.key.code == Mouse::Left)
			{
				if (forstartbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					selection = true;
				}
				else if (forstartbutton2.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					gamestarted = true;
					mouseenabled = false;
					selection = false;
				}
				else if (forinstructionbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					instruction = true;
				}

				else if (forquitbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					window.close();
				}
				else if (forbackbutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					instruction = false;
				}
				else if (formainmenubutton.getGlobalBounds().contains(Vector2f(Mouse::getPosition(window))))
				{
					gamewin = false;
					gameover = false;
				}

			}
		}
	}
}


void Akranoid::update()
{
	eventpoll();
	Updatingboundarycolor();
	if (instruction)
	{
		Updaitngball2andbar2position();

	}
	if (gamestarted)
	{
		UpdatingBarposition();
		UpdatingBallposition();
		ballandbar();
		ballandbricks();
	}

}

void Akranoid::render()
{
	window.clear();
	window.draw(boundary);
	if (gamestarted)
	{
		window.draw(bar);
		window.draw(ball);
		window.draw(scoreUpdating);
		for (int i = 0;i < bricksrows;i++)
		{
			for (int j = 0;j < brickscolunms;j++)
			{
				window.draw(bricks[i][j]);
			}
		}
		for (int i = 0;i < health;i++)
		{
			window.draw(life[i]);
		}
	}
	if (!gamewin)
	{
		if (!gameover)
		{
			if (!gamestarted)
			{
				if (!instruction && !selection)
				{
					window.draw(formenuscreen);
					window.draw(forstartbutton);
					window.draw(forinstructionbutton);
					window.draw(forquitbutton);
				}
				if (selection)
				{
					for (int i = 0;i < 2;i++)
					{
						for (int j = 0;j < 2;j++)
						{
							window.draw(SelectBar[i][j]);
							window.draw(boxes[i][j]);
						}
					}
					window.draw(forstartbutton2);
				}
				if (instruction)
				{
					window.draw(forbackbutton);
					window.draw(forinstructionmenu);
					window.draw(bar2);
					window.draw(ball2);
				}
			}
		}
	}
	if (gameover)
	{
		window.draw(forgameover);
		window.draw(formainmenubutton);
		window.draw(ofhighscore);
	}
	else if (gamewin)
	{
		window.draw(forgamewin);
		window.draw(formainmenubutton);
		window.draw(ofhighscore);


	}
	window.display();
}
