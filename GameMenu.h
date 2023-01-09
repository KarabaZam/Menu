#pragma once
#include <SFML/Graphics.hpp>

namespace game {

	class GameMenu
	{
		int max_menu;                // ������������ ���������� ������� ����
		int size_font;               // ������ ������
		int mainMenuSelected;        // ����� �������� ������ ���� 
		sf::Font font;               // ����� ���� 
		sf::Text* mainMenu;          // ������������ ������ �������� ����
		sf::Color menu_text_color;   // ���� ����
		sf::Color chose_text_color;  // ���� ������ ����
		sf::Color border_color;      // ���� ������� ������

		// ��������� ������ ����
		void setInitText(sf::Text& text, std::string str, float xpos, float ypos);

		sf::RenderWindow& mywindow;
	public:

		GameMenu(sf::RenderWindow& window, float menux, float menuy, int sizeFont = 60, int step = 80, int len_menu = 4);

		void draw();                                     // ������ ����

		void MoveUp();                                   // ����������� ���� �����

		void MoveDown();                                 // ����������� ���� ����

		void setStringMenu(sf::String name[]);  // ����� ����

		void setColotTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);  // ���� ����

		void setPositionX(int posx);                    // ������������ ��������� ����

		int getMainMenuPressed()                        // ��������� ����� ��������� ��������
		{
			return mainMenuSelected;
		}
		~GameMenu()
		{
			delete[] mainMenu;
		}

	};

}