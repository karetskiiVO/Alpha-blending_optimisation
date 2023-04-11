#include "testtools.h"

#include <SFML/Graphics.hpp>
#include <math.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

int main () {
    sf::Vector2u resolution(800, 600);
    sf::Vector2f MsetPosition(0.f, 0.f);
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Render");
    startFPScnt(&window);

    sf::Sprite  MondSet;
    sf::Texture texture;

    float scale = 3.f / 1000.f;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resolution = window.getSize();
                    break;
                case sf::Event::KeyReleased:
                    


                   break;
                default:
                    break;
            }
        }

        MondSet.setTexture(texture);

        window.clear();

        window.draw(MondSet);
        updateFPS();
        drawFPS();

        window.display();
    }
    
    return 0;
}

void blendPhoto (sf::Image& frontimg, sf::Image& background, sf::Vector2u pos, sf::Image& summary) {
    sf::Vector2u edge = {min(background.getSize().x - pos.x, frontimg.getSize().x), 
                         min(background.getSize().y - pos.y, frontimg.getSize().y)};

    for (sf::Uint32 xi = 0; xi < edge.x; xi++) {
        for (sf::Uint32 yi = 0; yi < edge.y; yi++) {
            sf::Color front = frontimg.getPixel(xi, yi);
            sf::Color back  = background.getPixel(pos.x + xi, pos.y + yi);
        }
    }


}
