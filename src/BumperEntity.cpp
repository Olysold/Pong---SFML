#include "BumperEntity.h"

BumperEntity::BumperEntity(): m_vertices(sf::Quads, 4) { m_vertices[0].position = sf::Vector2f(0, 0),
                                                         m_vertices[1].position = sf::Vector2f(800, 0),
                                                         m_vertices[2].position = sf::Vector2f(800, 10),
                                                         m_vertices[3].position = sf::Vector2f(0, 10); }

sf::FloatRect BumperEntity::getOverallBounds()
{
    auto vec_pos = getPosition();
    sf::FloatRect overall = m_vertices.getBounds();

    overall.top  += vec_pos.y;
    overall.left += vec_pos.x;

    return overall;
}

void BumperEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_vertices, states);
}
