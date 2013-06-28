#include <SFML/Graphics.hpp>

#include "PaddleEntity.h"

PaddleEntity::PaddleEntity(): m_vertices(sf::Quads, 4) {  m_vertices[0].position = sf::Vector2f(0, 0);
                                                          m_vertices[1].position = sf::Vector2f(20, 0);
                                                          m_vertices[2].position = sf::Vector2f(20, 90);
                                                          m_vertices[3].position = sf::Vector2f(0, 90); }

sf::FloatRect PaddleEntity::getOverallBounds()
{
    auto vec_pos = getPosition();
    sf::FloatRect overall = m_vertices.getBounds();

    overall.top += vec_pos.y;
    overall.left += vec_pos.x;

    return overall;
}

sf::FloatRect PaddleEntity::upperBounds()
{
    auto vec_pos = getPosition();
    sf::FloatRect upper = m_vertices.getBounds();

    upper.top += vec_pos.y;
    upper.left += vec_pos.x;
    upper.height /= 3;

    return upper;
}

sf::FloatRect PaddleEntity::middleBounds()
{
    auto vec_pos = getPosition();
    sf::FloatRect mid = m_vertices.getBounds();

    mid.top += vec_pos.y;
    mid.left += vec_pos.x;

    mid.height /= 3;
    mid.top += mid.height;

    return mid;
}

sf::FloatRect PaddleEntity::lowerBounds()
{
    auto vec_pos = getPosition();
    sf::FloatRect low = m_vertices.getBounds();

    low.top += vec_pos.y;
    low.left += vec_pos.x;

    low.height /= 3;
    low.top += (low.height*2);

    return low;

}

void PaddleEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_vertices, states);
}


