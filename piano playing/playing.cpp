include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void playSound(const std::string& filename) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename)) return; // Handle error
    sf::Sound sound(buffer);
    sound.play();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Digital Piano");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::A: playSound("noteA.wav"); break;
                    case sf::Keyboard::S: playSound("noteB.wav"); break;
                    // Add more cases for other keys
                }
            }
        }

        window.clear();
        // Draw your piano keys here
        window.display();
    }

    return 0;
}