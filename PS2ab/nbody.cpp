#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include "nbody.h"
using namespace std;


CelestialBody::CelestialBody() {
  xpos = 0;
  ypos = 0;
  xvel = 0;
  yvel = 0;
  mass = 0;
  fileName = "";
  universeRadius = 0;
  dispX = 0;
  dispY = 0;
}

CelestialBody::CelestialBody(double xpos_init, double ypos_init, double xvel_init, double yvel_init, double mass_init, string filename_init) {
  xpos = xpos_init;
  ypos = ypos_init;
  xvel = xvel_init;
  yvel = yvel_init;
  mass = mass_init;
  fileName = filename_init;

  
  /////////
  sf::Image image;
  if(!(image.loadFromFile(fileName))){
    std::cout<<"Error: Cannot load image."<<endl;
  }
  
  texture.loadFromImage(image);
  sprite.setTexture(texture);

  //////
  dxpos = ((xpos/universeRadius)* (dispX/2)) + (dispX/2);
  dypos = ((ypos/universeRadius)*(dispY/2)) + (dispY/2);

  sprite.setPosition(dxpos,dypos);
  
}

void CelestialBody::setUniRadius(double Uradius) {
  universeRadius = Uradius;
}

double CelestialBody::getUniRadius(void)const {
  return universeRadius;
}
int CelestialBody::getXvel(void)const{
  return xvel;
}
int CelestialBody::getYvel(void)const{
  return yvel;
}

void CelestialBody::setXYpos(double xpos_init, double ypos_init){
  xpos = xpos_init;
  ypos = ypos_init;
  
  dxpos = ((xpos/universeRadius)* (dispX/2)) + (dispX/2);
  dypos = ((-ypos/universeRadius)*(dispY/2)) + (dispY/2);

  sprite.setPosition(dxpos,dypos);
  
}

//void CelestialBody::setYpos(double ypos_init){
//  ypos = ypos_init;
//}

double CelestialBody::getXpos(void)const{
  return xpos;
}
double CelestialBody::getYpos(void)const{
  return ypos;
}

double CelestialBody::getMass(void)const{
  return mass; 
}
std::istream& operator>>(std::istream& in, CelestialBody& body){
  cin>> body.xpos >> body.ypos >> body.xvel >> body.yvel >> body.mass >> body.fileName;

  
  sf::Image image;
  if(!(image.loadFromFile(body.fileName))){
    std::cout<<"Error: Cannot load image."<<endl;
  }

  body.texture.loadFromImage(image);
  body.sprite.setTexture(body.texture);

  body.dxpos = ((body.xpos/body.universeRadius)* (body.dispX/2)) + (body.dispX/2);
  body.dypos = ((body.ypos/body.universeRadius)*(body.dispY/2)) + (body.dispY/2);
  body.sprite.setPosition(body.dxpos, body.dypos);
  return in;
}

void CelestialBody::setXvel(double xvel_init){
  xvel= xvel_init;
}
void CelestialBody::setYvel(double yvel_init){
  yvel = yvel_init;
}

void CelestialBody::setDisplayXY(int x, int y) {
  dispX = x;
  dispY = y;}

//int CelestialBody::getDisplayX(void)const {
//  return dispX;}

//int CelestialBody::getDisplayY(void)const {
//  return dispY;}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(sprite, states);
}

Universe::Universe() {
  radius = 0;
  numBodies =0;
}

Universe::Universe(double rad, int bodies, int xDisp, int yDisp, std::istream& in){
  radius = rad;
  numBodies = bodies;
  display_x = xDisp;
  display_y= yDisp;
  
  for (int i = 0; i < numBodies; i++) {
    std::unique_ptr<CelestialBody> CB_ptr(new CelestialBody());
    CB_Vector.push_back(move(CB_ptr));
    CB_Vector.at(i)->setUniRadius(radius);
    CB_Vector.at(i)->setDisplayXY(xDisp, yDisp);
    in>>(*CB_Vector.at(i));
 } 
}

void Universe::step(double seconds){
  int j=0;
  int i=0;
  for (i = 0; i < numBodies; i++) {
    double fX_net=0;
    double fY_net=0;
    
    for(j=0; j < numBodies; j++){
      //calculating force of each body on body in the outer loop
      //what effect each body has on i
      if(j!=i){
	double dX = CB_Vector[j]->getXpos() - CB_Vector[i]->getXpos();
        double dY = CB_Vector[j]->getYpos() - CB_Vector[i]->getYpos();
	double r = sqrt(pow(dX,2)+pow(dY,2));
	double f = (6.67e-11 * CB_Vector[j]->getMass() * CB_Vector[i]->getMass())/pow(r,2);
	double fX = f * (dX / r);
	double fY = f * (dY / r);

	fY_net += fY;
	fX_net+= fX;
      }	
    }    
    double aX= fX_net/ CB_Vector[i]->getMass();
    double aY = fY_net/ CB_Vector[i]->getMass();
    double vX = CB_Vector[i]->getXvel() + seconds * aX;
    double vY = CB_Vector[i]->getYvel() + seconds * aY;
    CB_Vector[i]->setXvel(vX);
    CB_Vector[i]->setYvel(vY);
    double nX = (CB_Vector[i]->getXpos()) + vX * seconds;
    double nY = (CB_Vector[i]->getYpos()) + vY * seconds;
    CB_Vector[i]->setXYpos(nX, nY);    
  }

  
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  for(int i=0; i<numBodies; i++){
    target.draw(*(CB_Vector.at(i)), states); 
  }
}
