////////////////////////////////////////////////////////////
///
/// SFML BUTTON LIBRARY
/// Copyright (c) 2023 Pyromagne
///
////////////////////////////////////////////////////////////

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include <SFML/Graphics.hpp>

const sf::Color defaultHovered = sf::Color(191, 191, 191);
const sf::Color defaultPressed = sf::Color(153, 153, 153);

////////////////////////////////////////////////////////////
///
/// @brief Base class for button
///
////////////////////////////////////////////////////////////

class Button
{
    public:
    virtual void getButtonStatus(sf::RenderWindow&, sf::Event&) = 0;
    virtual void draw(sf::RenderWindow&) = 0;
    //virtual void setButtonLable(std::string, float) = 0;
    //virtual void setButtonFont(sf::Font&) = 0;

    bool isHover = false;
    bool isPressed = false;
    bool autoSize = false;
    bool enabled = true; //not implemented yet, for the button state if the button can be pressed by the user

    protected:
    sf::Text buttonLabel;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2f buttonPos;
    sf::FloatRect labelRect;
    std::string label;
};

////////////////////////////////////////////////////////////
///
/// @brief make a rectangle button
///
////////////////////////////////////////////////////////////

class RectButton: public Button
{
    public:

    RectButton(const sf::Vector2f);
    RectButton(const sf::Vector2f, const sf::Vector2f);
    RectButton(bool autoSize, const sf::Vector2f);

    ~RectButton();

    void getButtonStatus(sf::RenderWindow&, sf::Event&);
    void draw(sf::RenderWindow&);
    void setButtonLable(std::string, const sf::Color&, float);
    void setButtonFont(sf::Font&);

    sf::RectangleShape button;

    private:

    sf::FloatRect buttonRect;
};

////////////////////////////////////////////////////////////
///
/// @brief Make a circle button
///
////////////////////////////////////////////////////////////

class EllipseButton: public Button
{
    public:

    EllipseButton(float radius);
    EllipseButton(float radius, const sf::Vector2f);

    ~EllipseButton();

    void getButtonStatus(sf::RenderWindow&, sf::Event&);
    void draw(sf::RenderWindow&);

    sf::CircleShape button;

    private:
};




#endif // BUTTON_HPP_INCLUDED
