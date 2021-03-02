#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>

#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100
using namespace std;

vector<sf::Int16> makeSamples(StringSound& gs) {
	std::vector<sf::Int16> samples;

	gs.pluck();
	int duration = 8;  // seconds
	int i;
	for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
		gs.tic();
		samples.push_back(gs.sample());
	}

	return samples;
}

int main() {

	cout << "Testing Exception handling by passing invalid argument into constructor: \n";
	// Testing Exceptions
	try {
		StringSound errorObject(0);
	}
	catch (std::invalid_argument) {
		cout << "Invalid Argument Error: Frequency cannot be less than or equal to zero.\n";
	}


	vector<sf::Keyboard::Key> keyVector = { sf::Keyboard::Key::Q,
											sf::Keyboard::Key::Num2,
											sf::Keyboard::Key::W,
											sf::Keyboard::Key::E,
											sf::Keyboard::Key::Num4,
											sf::Keyboard::Key::R,
											sf::Keyboard::Key::Num5,
											sf::Keyboard::Key::T,
											sf::Keyboard::Key::Y,
											sf::Keyboard::Key::Num7,
											sf::Keyboard::Key::U,
											sf::Keyboard::Key::Num8,
											sf::Keyboard::Key::I,
											sf::Keyboard::Key::Num9,
											sf::Keyboard::Key::O,
											sf::Keyboard::Key::P,
											sf::Keyboard::Key::Hyphen,
											sf::Keyboard::Key::LBracket,
											sf::Keyboard::Key::Equal,
											sf::Keyboard::Key::Z,
											sf::Keyboard::Key::X,
											sf::Keyboard::Key::D,
											sf::Keyboard::Key::C,
											sf::Keyboard::Key::F,
											sf::Keyboard::Key::V,
											sf::Keyboard::Key::G,
											sf::Keyboard::Key::B,
											sf::Keyboard::Key::N,
											sf::Keyboard::Key::J,
											sf::Keyboard::Key::M,
											sf::Keyboard::Key::K,
											sf::Keyboard::Key::Comma,
											sf::Keyboard::Key::Period,
											sf::Keyboard::Key::SemiColon,
											sf::Keyboard::Key::Slash,
											sf::Keyboard::Key::Quote,
											sf::Keyboard::Key::Space };



	sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
	sf::Event event;
	double freq;
	vector<sf::Int16> samples;

	vector<sf::Sound*> soundVector;
	vector<sf::SoundBuffer*> soundBuffVector;

	for (int i = 0; i < 37; i++) {
		freq = 440 * pow(2, (((double)i - 24) / 12));
		StringSound gs1 = StringSound(freq);

		sf::Sound *sound = new sf::Sound();
		sf::SoundBuffer *buf = new sf::SoundBuffer();
		samples = makeSamples(gs1);
		buf->loadFromSamples(&samples[0], samples.size(), 2, 44100);
		sound->setBuffer(*buf);
		soundVector.push_back(sound);
		soundBuffVector.push_back(buf);

	}


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			auto p = keyVector.end();

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
				
			case sf::Event::KeyPressed:

				p = find(keyVector.begin(), keyVector.end(), event.key.code);
				
				if (p != keyVector.end()) {
					int soundIndex = distance(keyVector.begin(), p);
					soundVector.at(soundIndex)->play();
					
				}		

			default:
				break;
			}

			window.clear();
			window.display();
		}
	}
	return 0;
}
