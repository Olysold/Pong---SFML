#include "Interaction.h"

std::uniform_int_distribution<unsigned> Interaction::m_moveDistribution(1, 2);
std::default_random_engine Interaction::m_engine;

void Interaction::ballMovement(sf::Clock& clock, BallEntity& ball, PaddleEntity& paddle)
{
    sf::FloatRect upBounds = paddle.upperBounds();
    sf::FloatRect midBounds = paddle.middleBounds();
    sf::FloatRect lowBounds = paddle.lowerBounds();

    //Elapsed time measurement unnecessary. Unit movement with "stock speed" is just fine
    if(clock.getElapsedTime().asSeconds() >= 0.01 && !movingLeft)
    {
        ball.move(10, m_Ymovement);
        clock.restart();
    }
    if(clock.getElapsedTime().asSeconds() >= 0.01 && movingLeft)
    {
        ball.move(-10, m_Ymovement);
        clock.restart();
    }


    if(upBounds.intersects(ball.getOverallBounds()) && !m_collide)
    {
        if(m_Ymovement > 0)
        {
            m_Ymovement -= (m_Ymovement * 2);
        }
        m_Ymovement -= (4 + (m_moveDistribution(m_engine)));
    }
    if(midBounds.intersects(ball.getOverallBounds()) && !m_collide)
    {
        m_Ymovement = m_moveDistribution(m_engine);
    }
    if(lowBounds.intersects(ball.getOverallBounds()) && !m_collide)
    {
        if(m_Ymovement < 0)
        {
            m_Ymovement -= (m_Ymovement * 2);
        }
        m_Ymovement += (4 + (m_moveDistribution(m_engine)));
    }
}

void Interaction::compMovement(sf::Clock& clock, BallEntity& ball, PaddleEntity& compPaddle)
{
    sf::FloatRect midPoint = compPaddle.middleBounds();
    sf::Vector2f ballPos = ball.getPosition();

    //Paddle moving upwards
    if(clock.getElapsedTime().asSeconds() >= 0.01 &&            //Unnecessary, see above
       compPaddle.getPosition().y != 30 &&                      //Top movement limit
       ballPos.y < (midPoint.top + (midPoint.height/2)) &&      //Position of ball is above the midpoint (y is < to be "above")
       !(ballPos.y > midPoint.top && ballPos.y < (midPoint.top + midPoint.height))) //Position of ball NOT within middle bounds
    {
        compPaddle.move(0, -10);
        clock.restart();
    }

    //Paddle moving downwards
    if(clock.getElapsedTime().asSeconds() >= 0.01 &&            //Unnecessary, see above
        (compPaddle.getPosition().y + 90) != 570 &&             //Bottom movement limit
       ballPos.y > (midPoint.top + (midPoint.height/2)) &&      //Position of ball is below the midpoint (y is > to be "below")
       !(ballPos.y > midPoint.top && ballPos.y < (midPoint.top + midPoint.height)) ) //Position of ball NOT within middle bounds
    {
        compPaddle.move(0, 10);
        clock.restart();
    }
}

void Interaction::hitBumper(BallEntity& ball, BumperEntity& bumper)
{
    if(bumper.getOverallBounds().intersects(ball.getOverallBounds()))
    {
        if(m_Ymovement > 0 || m_Ymovement < 0)
        {
            m_Ymovement -= (m_Ymovement * 2);
        }
    }
}

void Interaction::gameCondition(sf::Clock& clock, BallEntity &ball)
{
    if(clock.getElapsedTime().asSeconds() >= 1.5)
    {
        //Repeating collision event preventive measure (Unnecessary for this prog)
        m_collide = false;
        clock.restart();

        if(ball.getPosition().x < 0 || ball.getPosition().x > 800)
        {
            ball.setPosition(450, 300);
            m_Ymovement = 0;
        }
    }
}
