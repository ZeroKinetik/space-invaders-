#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "space-invaders");
    window.setFramerateLimit(144);
    // define a 120x50 rectangle
    sf::RectangleShape player(sf::Vector2f(25.f, 25.f));    
    player.setFillColor(sf::Color(255, 255, 255));
    float x = (window.getSize().x - player.getSize().x) / 2;
    float y = (window.getSize().y - player.getSize().y) / 2;
    player.setPosition({x,y});

    sf::Vector2f velocity(0.0f, 0.0f);
    sf::Clock clock;
    float speed = 200.0f;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                velocity.x = -speed;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                velocity.x = speed;
            else
                velocity.x = 0;
        }
        float deltaTime = clock.restart().asSeconds();  

        window.clear();
        player.move({velocity.x * deltaTime, velocity.y * deltaTime});
        window.draw(player);
        window.display();
    }
}
