 #include <SFML/Graphics.hpp>

int main()
{
   
  sf::RenderWindow window(sf::VideoMode(900, 900), "SFML Works!");

    //Load a sprite to display
    sf::Texture texture;
    if(!texture.loadFromFile("sprite.png"))
      return EXIT_FAILURE;

    float pos1 = 1;
    float pos2 = 10;
    float rotate = 0;
    
    sf::Sprite sprite(texture);
    sprite.setRotation(0.f);
    
    while(window.isOpen()){
      sf::Event event;
      while(window.pollEvent(event))
      {
	if(event.type== sf::Event::Closed)
	  window.close();
      }
      sprite.setPosition(pos1, pos2);
      
      //keystrokes
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	pos2= pos2 - 5.0;
      
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	pos2 = pos2 + 5.0;


      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	pos1 = pos1 - 5.0;


      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	pos1 = pos1 + 5.0;


      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
	sprite.rotate(10.f);
        rotate= rotate+10;
    }
      

      //clear screen
      window.clear();

      //draw sprite
      window.draw(sprite);
      
      //update window
      window.display();
    }


    return 0;
}
