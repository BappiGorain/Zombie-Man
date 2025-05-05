#include<SFML/Graphics.hpp>
using namespace sf;


int main()
{
    VideoMode vm(1920,1080);
    RenderWindow window(vm,"Zombie-Man",Style::Fullscreen);

    Texture background;
    background.loadFromFile("graphics/background_sheet.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(background);
    spriteBackground.setPosition(0,0);

    while(window.isOpen())
    {
        Event event;
		while (window.pollEvent(event)){}
        if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        window.clear();
        window.draw(spriteBackground);

        window.display();

    }


    return 0;

}