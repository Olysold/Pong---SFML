#ifndef MYENTITY_H_INCLUDED
#define MYENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

class PaddleEntity : public sf::Drawable, public sf::Transformable
{
public:
    PaddleEntity();
    sf::FloatRect getOverallBounds();
    sf::FloatRect upperBounds();
    sf::FloatRect middleBounds();
    sf::FloatRect lowerBounds();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};


#endif // MYENTITY_H_INCLUDED
