#include <SFML/Graphics.hpp>
#include "PaddleEntity.h"
#include "BallEntity.h"
#include "BumperEntity.h"
#include "Interaction.h"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    //Declaring entities
    PaddleEntity l_paddle;
    PaddleEntity r_paddle;
    BumperEntity t_bumper;
    BumperEntity b_bumper;
    BallEntity ball;

    //Repositioning
    l_paddle.setPosition(30, 320);
    r_paddle.setPosition(750, 280);
    t_bumper.setPosition(0, 20);
    b_bumper.setPosition(0, 570);
    ball.setPosition(450, 300);

    //Time
    sf::Clock gameClock;
    sf::Clock ballClock;
    sf::Clock compPaddleClock;

    //Declaring interaction
    Interaction interact;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        //Keyboard
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && l_paddle.getPosition().y != 30)
        {
            l_paddle.move(0, -10);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (l_paddle.getPosition().y + 90) != 570)
        {
            l_paddle.move(0, 10);
        }

        //Bounds
        sf::FloatRect lp_oBounds = l_paddle.getOverallBounds();
        sf::FloatRect rp_oBounds = r_paddle.getOverallBounds();
        sf::FloatRect ball_bounds = ball.getOverallBounds();

        //Upon collision, alter ball direction
        if(lp_oBounds.intersects(ball_bounds))
        {
            interact.movingLeft = false;
        }
        if(rp_oBounds.intersects(ball_bounds))
        {
            interact.movingLeft = true;
        }

        //Interactions
        interact.gameCondition(gameClock, ball);
        interact.ballMovement(compPaddleClock, ball, l_paddle);
        interact.compMovement(ballClock, ball, r_paddle);
        interact.hitBumper(ball, t_bumper);
        interact.hitBumper(ball, b_bumper);

        window.clear(sf::Color::Black);

        window.draw(l_paddle);
        window.draw(r_paddle);
        window.draw(t_bumper);
        window.draw(b_bumper);
        window.draw(ball);

        window.display();
    }

    return 0;
}
