// Copyright Saema Nazar 2020
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LFSR.h"

using namespace std;  // NOLINT
using namespace sf;  // NOLINT

void transform(sf::Image& image, FibLFSR bits) {  // NOLINT
  // p is a pixel
        sf::Color p;
        sf::Vector2u size = image.getSize();
        // encrypting
       for (int x = 0; (unsigned)x < size.x; x++) {
          for (int y = 0; (unsigned)y < size.y; y++) {
              p = image.getPixel(x, y);
              p.r = p.r ^ bits.generate(8);
              p.g = p.g ^ bits.generate(8);
              p.b = p.b ^ bits.generate(8);
              image.setPixel(x, y, p);
          }
       }
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    cout << "Wrong number of args. Exiting now..." << endl;
    exit(1);
  }

  Image inputImg;
  Image outputImg;
  FibLFSR bitsObj(argv[3]);

  if (!inputImg.loadFromFile(argv[1])) {
    cout << "Error loading input image. Exiting now..." << endl;
    exit(1);
  }
  if (!outputImg.loadFromFile(argv[1])) {
    cout << "Error loading output image. Exiting now..." << endl;
    exit(1);
  }
    transform(outputImg, bitsObj);

  Vector2u sizeImg = inputImg.getSize();
  sf::RenderWindow window(sf::VideoMode(sizeImg.x *2, sizeImg.y), "Normal & Transformed Images");  // NOLINT

  sf::Texture input;
  input.loadFromImage(inputImg);
  Sprite inputSprite(input);
  Texture output;
  output.loadFromImage(outputImg);
  Sprite outputSprite(output);

  inputSprite.setPosition(0, 0);
  outputSprite.setPosition(sizeImg.x, 0);

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) { window.close(); }
    }
    window.clear();
    window.draw(inputSprite);
    window.draw(outputSprite);
    window.display();
  }
  if (!outputImg.saveToFile(argv[2])) {
      cout << "Error saving output image to file. Exiting now ..." << endl;
      exit(1);
    }
      return 0;
}
