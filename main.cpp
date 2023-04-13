#include <SFML/Graphics.hpp>
#include <iostream>
#include "sfml_button.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(960, 600), "IDLE: Fishing");

    sf::Font jackInput;
    jackInput.loadFromFile("assets/JackInput.TTF");

    sf::Texture buttonTexture;
    buttonTexture.loadFromFile("assets/button.png");

    RectButton button1(sf::Vector2f(100, 50), sf::Vector2f(50, 50));
    //button1.button.setTexture(&buttonTexture);
    button1.setButtonFont(jackInput);
    button1.setButtonLable("Exit",sf::Color::Black, 30);

    RectButton button2(sf::Vector2f(100, 50), sf::Vector2f(50, 150));
    //button2.button.setTexture(&buttonTexture);
    button2.setButtonFont(jackInput);
    button2.setButtonLable("Play",sf::Color::Black, 30);

    EllipseButton button3(30,sf::Vector2f(50, 250));
    button3.enabled = false;

    RectButton button4(true,sf::Vector2f(50, 350));
    //button4.button.setTexture(&buttonTexture);
    button4.setButtonFont(jackInput);
    button4.setButtonLable("Continue",sf::Color::Black, 30);


    while (app.isOpen())
    {
        // Process events
        sf::Event eventMain;
        while (app.pollEvent(eventMain))
        {
            // Close window : exit
            if (eventMain.type == sf::Event::Closed)
            {
                app.close();
            }

            if (button1.isPressed)
            {
                std::cout<<"Button 1 is pressed"<<std::endl;
            }
            if (button2.isPressed)
            {
                std::cout<<"Button 2 is pressed"<<std::endl;
            }
            if (button3.isPressed)
            {
                std::cout<<"Button 3 is pressed"<<std::endl;
            }
            if (button4.isPressed)
            {
                std::cout<<"Button 4 is pressed"<<std::endl;
            }

            button1.getButtonStatus(app, eventMain);
            button2.getButtonStatus(app, eventMain);
            button3.getButtonStatus(app, eventMain);
            button4.getButtonStatus(app, eventMain);
        }

        app.clear(sf::Color( 16, 8, 59, 255) );
        button1.draw(app);
        button2.draw(app);
        button3.draw(app);
        button4.draw(app);

        // Update the window
        app.display();
    }



    return EXIT_SUCCESS;
}
