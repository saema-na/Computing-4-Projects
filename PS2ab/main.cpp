#include <iostream>
#include <cstdio>
#include <string>

#include "nbody.h"
using namespace std;


int main(int argc, char* argv[]){
  int displayX = 600;
  int displayY = 600; 
  int N;
  double R; //radius

  double uni_T=0; // universe time, start at 0
  double T;
  double deltaT; // seconds

  
  T = strtod(argv[1], NULL);
  deltaT = strtod(argv[2], NULL);

  
  cin>>N;
  cin>>R;
  Universe system(R, N, displayX, displayY, cin);
  
  sf::RenderWindow window(sf::VideoMode(displayX, displayY), "The Solar System!");  
  

while(window.isOpen()){
      sf::Event event;
      while(window.pollEvent(event))
      {
	if(event.type== sf::Event::Closed)
	  window.close();
      }
      
      
      //clear screen
      window.clear();


      //stop calling step when time is up
       if(uni_T < T){
       	system.step(deltaT);
		uni_T += deltaT;

       }
      
      
      //draw sprite
      window.draw(system);
      
      //update window
      window.display();
      }
}
