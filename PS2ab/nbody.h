#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class CelestialBody: public sf::Drawable {
public:
	CelestialBody();
	CelestialBody(double, double, double, double, double, std::string);
	
	void setUniRadius(double radius);
	double getUniRadius(void)const;
	void setDisplayXY(int x, int y);
	int getXvel(void)const;
	int getYvel(void)const;
	void setXvel(double);
	void setYvel(double);
	void setXYpos(double, double);
	double getXpos(void)const;
	double getYpos(void)const;
	double getMass(void)const;

       	//		int getDisplayX(void)const;
	//		int getDisplayY(void)const;
       	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	friend std::istream& operator>>(std::istream& in, CelestialBody& body);
private:
	double xpos;
	double ypos;
	double xvel;
	double yvel;
	double mass;
	std::string fileName;
	double universeRadius;
	int dispX;
	int dispY;
	int dxpos;
	int dypos;
	sf::Sprite sprite;
	sf::Texture texture;
};


class Universe: public sf::Drawable {
public:
  Universe();
  Universe(double rad, int bodies, int, int, std::istream&);  
  void step(double seconds);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  
private:
  std::vector<std::unique_ptr<CelestialBody>> CB_Vector;
  double radius;
  int numBodies;
  int display_x;
  int display_y;
};
