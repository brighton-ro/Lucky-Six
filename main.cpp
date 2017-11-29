#include<SFML/Graphics.hpp>
#include<Loptica.h>
#include<Izvlacenje.h>
#include<Timer.h>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Lucky Six!", sf::Style::Fullscreen, settings);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);

    sf::Texture tx;
    sf::Sprite bg;

    tx.loadFromFile("slike/bg.jpg");
    bg.setTexture(tx);

    Loptica l;
    Izvlacenje iz;
    Timer t;
    Tiketi ti;

    sf::Sprite exit;
    sf::Texture txExit;

    txExit.loadFromFile("slike/exit.png");
    exit.setTexture(txExit);
    exit.setPosition(1250.0f, -3.0f);
    exit.setScale(0.07f, 0.07f);

    int startFlag = 0;

    int i = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if(event.mouseButton.button == sf::Mouse::Left)
                    if(exit.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
                        window.close();

            t.clickedOn(event, startFlag);

            ti.unosImena(event);
            //ti.unosBrojeva(event);
            ti.unosUloga(event);
        }

        window.clear();
        window.draw(bg);
        window.draw(exit);

        t.timerDone(startFlag);

        if(startFlag == 1)
        {
            l.Draw(window);

            if(i > 0)
                Sleep(4000);

            iz.Draw(i, window);
            iz.DrawVeliki(i, window);

            for(int j = 0; j < i; j++)
            {
                iz.Draw(j, window);
                iz.DrawVeliki(i, window);
            }

            i++;
        }
        else if(startFlag == 2)
        {
            ti.Draw(window);
        }
        else
            t.Draw(window);

        window.display();
    }

    return 0;
}
