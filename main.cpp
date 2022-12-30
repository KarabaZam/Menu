#include <SFML/Graphics.hpp>
#include"GameMenu.h"
#include<SFML/Audio.hpp>
#include "Animator.h"

using namespace sf;
// ������� ��������� ������
void InitText(Text & mtext,float xpos, float ypos,String str, int size_font=60, Color menu_text_color=Color::White,int bord=0, Color border_color = Color::Black)
{
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);

}
// ����
void Gam�Start()
{
    RenderWindow Play(VideoMode::getDesktopMode(), L"������� 1", Style::Fullscreen);
      
    
    RectangleShape background_play(Vector2f(1920, 1080));

    Texture texture_play;
    if (!texture_play.loadFromFile("image/menu4.jpg")) exit(1);
    background_play.setTexture(&texture_play);

    while (Play.isOpen())
    {
        Event event_play;
        while (Play.pollEvent(event_play))
        {
            if (event_play.type == Event::KeyPressed)
            {
                if (event_play.key.code == Keyboard::Escape) { Play.close();}
            }
        }
        Play.clear();
        Play.draw(background_play);
        Play.display();
    }
}
// ��������� ����
void Options() 
{
    RenderWindow Options(VideoMode::getDesktopMode(), L"���������", Style::Fullscreen);

    RectangleShape background_opt(Vector2f(1920, 1080));
    Texture texture_opt;
    if (!texture_opt.loadFromFile("image/menu1.jpg")) exit(2);
    
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
// �������� ����
void About_Game() 
{
    RenderWindow About(VideoMode::getDesktopMode(), L"� ����", Style::Fullscreen);

    RectangleShape background_ab(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
    Texture texture_ab;
    if (!texture_ab.loadFromFile("image/menu2.jpg")) exit(3);
    background_ab.setTexture(&texture_ab);

    // ����� ��� �������� ������
    Font font;
    if (!font.loadFromFile("font/troika.otf")) exit(6);
    // ����� � ��������� ������
    Text Titul;
    Titul.setFont(font);
    InitText(Titul, 500, 50, L"�������� ����", 120, Color(237, 147, 0), 3);

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
        About.draw(Titul);
        About.display();
    }
}

int main()
{
   
    RenderWindow window(VideoMode::getDesktopMode(), L"��� ����", Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setMouseCursorVisible(false); //��������� ��������� �������

    SoundBuffer buffer,buf_return;
    
    if (!buffer.loadFromFile("audio/audiomenu2.wav")) return 22;
    if (!buf_return.loadFromFile("audio/audiomenu5.wav")) return 22;
    Sound sound,sound_return;
    sound.setBuffer(buffer);
    sound_return.setBuffer(buf_return);

    Music music;
    if (!music.openFromFile("audio/horror.ogg")) return 25; 
    music.setLoop(true);
    music.setVolume(50);
    music.play();

    Music musicF;
    if (!musicF.openFromFile("audio/faer.ogg")) return 28;
    musicF.setLoop(true);
    musicF.setVolume(50);
    musicF.play();
   

    // ���������� ������������ ������
    float center[4]{ 0,-120,-20,-30 };
    // �������� ������� ����
    String name_menu[4]{ L"�����",L"���������", L"� ����",L"�����" };
    // ������ ����
    game::GameMenu mymenu(800,350,100,120);
    // ��������� ����� ����������� ����
    mymenu.setColotTextMenu(Color(237, 147, 0), Color::Red, Color::Black);
    // ��������������� ������ ����
    for (int i = 0; i < 4; i++) { 
        mymenu.setPositionX(i, center[i]);
        mymenu.setStringMenu(i, name_menu[i]); 
    }


    // ������������� ��� ������ ����
    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

    RectangleShape background(Vector2f(1920, 1080));
    Texture texture_window;
    if (!texture_window.loadFromFile("image/menu9.jpg")) return 4;
    background.setTexture(&texture_window);

    // ����� ��� �������� ������
    Font font;
    if (!font.loadFromFile("font/troika.otf")) return 5;
    // ����� � ��������� ������
    Text Titul;
    Titul.setFont(font);
    InitText(Titul,480,50,L"�����������",150, Color(237,147,0),3);

    Vector2i spriteSize(300, 313);

    Sprite sprite;
    sprite.setPosition(440, 730);
    Animator animator(sprite);

    auto& idleAnimation = animator.CreateAnimation("Idle", "image/f.png", seconds(1), true);

    idleAnimation.AddFrames(Vector2i(0, 0), spriteSize, 5, 4);

    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            
              if(event.type==Event::Closed) window.close();
                
              if (event.type==Event::KeyReleased) 
              {
                // ������� ����� ������� ����
                  if (event.key.code == Keyboard::Up) { sound.play(); mymenu.MoveUp(); }       // �����
                  if (event.key.code == Keyboard::Down) { sound.play(); mymenu.MoveDown(); }  // ����
                if (event.key.code == Keyboard::Return)                    // ����
                {   
                    music.pause(); musicF.pause();
                    sound_return.play();
                    // ��������� �� ��������� ����� ����
                    switch (mymenu.getMainMenuPressed())
                    {
                    case 0:Gam�Start(); break;
                    case 1:Options(); break;
                    case 2:About_Game();  break;
                    case 3:window.close(); break;           
                    }  
                    music.play(); musicF.play();
                } 
              }
        }
        
        Time deltaTime = clock.restart();
        animator.Update(deltaTime);
       
        window.clear();
        window.draw(background);
        window.draw(Titul);
        mymenu.draw(window); 
        window.draw(sprite);
        window.display();
    }
    return 0;
}