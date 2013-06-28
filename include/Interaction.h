#ifndef INTERACTION_H_INCLUDED
#define INTERACTION_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <random>

#include "BallEntity.h"
#include "PaddleEntity.h"
#include "BumperEntity.h"

class Interaction
{
public:
    void ballMovement(sf::Clock&, BallEntity&, PaddleEntity&);
    void compMovement(sf::Clock&, BallEntity&, PaddleEntity&);
    void hitBumper(BallEntity&, BumperEntity&);
    void gameCondition(sf::Clock&, BallEntity&);

    bool movingLeft = true;

private:
    static std::uniform_int_distribution<unsigned> m_moveDistribution;
    static std::default_random_engine m_engine;
    float m_Ymovement = 0.0;
    bool m_collide = false;
};

#endif // INTERACTION_H_INCLUDED
