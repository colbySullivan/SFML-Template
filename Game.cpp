#include "Game.h"
#include <string> 

void Game::initVariables(){
    this->gameWidth = 800;
    this->gameHeight = 600;
}

void Game::initWindow(){
	this->window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(gameWidth), static_cast<unsigned int>(gameHeight), 32), "Template",
                            sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
}

const bool Game::running() const{
	return this->window->isOpen();
}

void Game::pollEvents(){
    while (this->window->pollEvent(this->event)){
            // Window closed or escape key pressed: exit
            if ((this->event.type == sf::Event::Closed) ||
               ((this->event.type == sf::Event::KeyPressed) && (this->event.key.code == sf::Keyboard::Escape))){
                this->window->close();
                break;
            }
        }
}

void Game::rungame(){
    while (this->window->isOpen()){
        // Handle events
        this->pollEvents();

        // Clear the window
        this->window->clear(sf::Color(0, 0, 0));

        // Display things on screen
        this->window->display();
    }
}

Game::Game(){
	this->initVariables();
    this->initWindow();
}