#include <SFML/Graphics.hpp>
#include"GameMenu.h"
// #include<SFML/Audio.hpp>
#include "Animator.h"
// #include<Windows.h>
// Прототипы функций
void InitText(sf::Text& mtext, float xpos, float ypos, sf::String str, int size_font, sf::Color menu_text_color, int bord, sf::Color border_color);

void GameStart();

void Options();

void About_Game();


 using namespace sf;




int main()
{
    
    RenderWindow window;
    //window.create(VideoMode::getDesktopMode(), L"Моя игра", Style::Fullscreen);
    window.create(VideoMode(1920,1080), L"Моя игра", Style::Default);


    window.setMouseCursorVisible(false); //��������� ��������� �������


    //  float width = (VideoMode::getDesktopMode().width);
    //  float height = (VideoMode::getDesktopMode().height);
    float width = 1920;  // ваше предпочтительное значение для ширины
    float height = 1080;
    
 


    RectangleShape background(Vector2f(width, height));

    Texture texture_window;
    if (!texture_window.loadFromFile("../image/menu9.jpg")) return 4;
    background.setTexture(&texture_window);

    // ����� ��� �������� ������
    Font font;
    if (!font.loadFromFile("../font/troika.otf")) return 5;

    Text Titul;
    Titul.setFont(font);

    InitText(Titul, 420, 50, L"THE LAST Dragon", 150, Color(237, 147, 0), 3, Color(237, 147, 0));

    String name_menu[]{L"Start",L"Options", L"About",L"Exit"};

    game::GameMenu mymenu(window, 950, 350, 4 , name_menu,100,120);
    
    // �������� ������
    // Vector2i spriteSize(300, 313);
    mymenu.setColorTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    mymenu.AlignMenu(2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::KeyReleased)
            {
                
                if (event.key.code == Keyboard::Up) { mymenu.MoveUp(); }       // �����
                if (event.key.code == Keyboard::Down) {  mymenu.MoveDown(); }  // ����
                if (event.key.code == Keyboard::Return)                                     // ����
                {

                    switch (mymenu.getSelectedMenuNumber())
                    {
                    case 0:GameStart();  break;
                    case 1:Options();     break;
                    case 2:About_Game();  break;
                    case 3:window.close(); break;
                    }

                }
            }
            
        }

        //mymenu.AlignMenu(2);
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw();
        window.display();
     }
     
    return 0;
    }



void InitText(Text& mtext, float xpos, float ypos, String str, int size_font, 
    Color menu_text_color, int bord, Color border_color)
{
mtext.setCharacterSize(size_font);
mtext.setPosition(xpos, ypos);
mtext.setString(str); 
mtext.setFillColor(menu_text_color); 
mtext.setOutlineThickness(bord); 
mtext.setOutlineColor(border_color);



}


void GameStart()
{
    //RenderWindow Play(VideoMode::getDesktopMode(), L"Уровень 1", Style::Fullscreen);
    RenderWindow Play(VideoMode(1920,1080), L"Уровень 1", Style::Default);


    RectangleShape background_play(Vector2f(1920, 1080));

    Texture texture_play;
    if (!texture_play.loadFromFile("../image/menu4.jpg")) exit(1);
    background_play.setTexture(&texture_play);

    while (Play.isOpen())
    {
        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) { Play.close(); }
            }
        }
        Play.clear();
        Play.draw(background_play);
        Play.display();
    }
}


void Options()
{
    //RenderWindow Options(VideoMode:getDesktopMode() ,L"Настройки", Style::Fullscreen);
    RenderWindow Options(VideoMode(1920, 1080) ,L"Настройки", Style::Default);

    RectangleShape background_opt(Vector2f(1920, 1080));
    Texture texture_opt;
    if (!texture_opt.loadFromFile("../image/menu1.jpg")) exit(2);

    background_opt.setTexture(&texture_opt);
    while (Options.isOpen())
    {
        Event event_opt;
        while (Options.pollEvent(event_opt))
        {
            if (event_opt.type == Event::Closed) Options.close();
            if (event_opt.type == Event::KeyPressed)
            {
                if (event_opt.key.code == Keyboard::Escape) Options.close();
            }
        }
        Options.clear();
        Options.draw(background_opt);
        Options.display();
    }

}

// // �������� ����
void About_Game()
{
    RenderWindow About(VideoMode::getDesktopMode(), L"О игре", Style::Default);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("../image/menu2.jpg")) exit(3);
    background_ab.setTexture(&texture_ab);



    while (About.isOpen())
    {
        Event event_play;
        while (About.pollEvent(event_play))
        {
            if (event_play.type == Event::Closed) About.close();
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) About.close();
            }
        }
        About.clear();
        About.draw(background_ab);
        //About.draw(Titul);
        About.display();
    }  
}
