#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

void playSound(const std::string& filename) {
    static std::vector<sf::Sound> sounds; // Keep sounds alive
    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile("/home/ambilikisye/Desktop/paino-palying/piano playing/sounds/" + filename)) {
        std::cerr << "Error loading sound file: " << filename << std::endl;
        return; // Exit if file cannot be loaded
    }
    
    std::cerr << "Successfully loading sound file: " << filename << std::endl;
    
    sf::Sound sound(buffer);
    sound.play();
    
    // Store sound in vector to keep it alive
    sounds.push_back(sound);
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
                    case sf::Keyboard::A: playSound("wavA.wav"); break;
                    case sf::Keyboard::S: playSound("wavB.wav"); break;
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