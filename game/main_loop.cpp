#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace std;

void saveGame() {
    ofstream saveFile("save.txt");
    if (saveFile.is_open()) {
        saveFile << "SavedGameState=1\n";
        saveFile.close();
        cout << "Game saved!\n";
    } else {
        cout << "Unable to save game.\n";
    }
}

void loadGame() {
    ifstream loadFile("save.txt");
    string line;
    if (loadFile.is_open()) {
        while (getline(loadFile, line)) {
            if (line == "SavedGameState=1") {
                cout << "Game loaded successfully!\n";
            }
        }
        loadFile.close();
    } else {
        cout << "No save file found.\n";
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quarantine Breach - Main Menu");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load font.\n";
        return 1;
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpg")) {
        cout << "Missing background.jpg\n";
        return 1;
    }
    sf::Sprite background(backgroundTexture);

    // Load zombie ambient music
    sf::Music zombieSound;
    if (!zombieSound.openFromFile("zombie_ambience.ogg")) {
        cout << "Missing zombie_ambience.ogg\n";
        return 1;
    }
    zombieSound.setLoop(true);
    zombieSound.setVolume(40);
    zombieSound.play();

    // Title
    sf::Text title("QUARANTINE BREACH", font, 50);
    title.setFillColor(sf::Color::Red);
    title.setPosition(120, 50);

    // Menu Items
    sf::Text menu[4];
    string labels[] = { "Start Game", "Load Game", "Settings", "Exit" };

    for (int i = 0; i < 4; i++) {
        menu[i].
