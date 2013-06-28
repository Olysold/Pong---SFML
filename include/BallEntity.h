#ifndef BALLENTITY_H_INCLUDED
#define BALLENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class BallEntity: public sf::Drawable, public sf::Transformable
{
public:
    BallEntity();
    sf::FloatRect getOverallBounds();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};

#endif // BALLENTITY_H_INCLUDED
