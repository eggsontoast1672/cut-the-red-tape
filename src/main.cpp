#include <iostream>

#include <SFML/Graphics.hpp>

int main(void) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Cut The Red Tape",
    sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.display();
  }

  std::cout << "Hello, world!" << std::endl;
}
