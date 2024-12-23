#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>

class SoundPlayer {
public:
    void playSound(const std::string& filename) {
        auto buffer = std::make_shared<sf::SoundBuffer>();
        if (!buffer->loadFromFile("/home/ambilikisye/Desktop/paino-palying/piano playing/sounds/" + filename)) {
            std::cerr << "Error loading sound file: " << filename << std::endl;
            return; // Exit if file cannot be loaded
        }
        
        std::cerr << "Successfully loading sound file: " << filename << std::endl;

        auto sound = std::make_shared<sf::Sound>(*buffer);
        sound->play();
        
        // Store buffer and sound in vectors to keep them alive
        buffers.push_back(buffer);
        sounds.push_back(sound);
    }

private:
    std::vector<std::shared_ptr<sf::SoundBuffer>> buffers;
    std::vector<std::shared_ptr<sf::Sound>> sounds;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Digital Piano");
    SoundPlayer player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::A: player.playSound("wavA.wav"); break;
                    case sf::Keyboard::S: player.playSound("wavB.wav"); break;
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