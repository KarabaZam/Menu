#include "GameMenu.h"

void game::GameMenu::setInitFont(sf::Text& text, std::string str, float xpos,float ypos)
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(str);
	text.setCharacterSize(60);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(sf::Color::Black);
}

void game::GameMenu::setStringMenu(int index, sf::String name) 
{
	mainMenu[index].setString(name);
}

void game::GameMenu::setPositionX(int index, float x1)
{
	mainMenu[index].setPosition(mainMenu[index].getPosition().x+x1, mainMenu[index].getPosition().y);
}

game::GameMenu::GameMenu(float menux, float menuy, int step, int len_menu)
{
	if (len_menu < 2) len_menu = 2;

	if (!font.loadFromFile("font/troika.otf"))
	{
		std::cout << "No font is here";
	}
	max_menu = len_menu;
	mainMenu = new sf::Text[max_menu];
	for (int i = 0, ypos = menuy; i < max_menu; i++, ypos += step) 
		setInitFont(mainMenu[i], std::to_string(i)+" name", menux, ypos);
	
	mainMenuSelected = 0;
	mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);

}

void game::GameMenu::MoveUp()
{
    mainMenuSelected--;

	if (mainMenuSelected >= 0) {
		mainMenu[mainMenuSelected + 1].setFillColor(sf::Color::White);
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	else
	{
		mainMenu[0].setFillColor(sf::Color::White);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
}

void game::GameMenu::MoveDown()
{
	mainMenuSelected++;

	if (mainMenuSelected < max_menu) {
		mainMenu[mainMenuSelected - 1].setFillColor(sf::Color::White);
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	else
	{
		mainMenu[max_menu-1].setFillColor(sf::Color::White);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
	
}


void game::GameMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < max_menu; i++) window.draw(mainMenu[i]);
}