#ifndef BUMPERENTITY_H_INCLUDED
#define BUMPERENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class BumperEntity: public sf::Drawable, public sf::Transformable
{
public:
    BumperEntity();
    sf::FloatRect getOverallBounds();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};

#endif // BUMPERENTITY_H_INCLUDED
