/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Saema Nazar
Hours to complete assignment: ~10

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
-created a universe and celestial body class to read input from planet.txt
and create sprite image of planets using SFML library

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
-the creation of classes and objects was important to this assignment because it
allows the use of OOP. Inheritance and abstraction are both central to the
creation of universe and celestialbody objects.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
 - ***all class headers in nbody.h, class definitions in nbody.cpp
-the universe class creates a vector of pointers to celestialbody objects.
The celestialbody objects are initialized within universe constructor.
-inherited sf::Drawable into celestialbody class to allow use of draw() function
-read in row from planets.txt in Universe class constructor using istream operator overload
-window/display size is arbitrary and can be changed in main
-universe size is aritrary, reads directly from planets.txt file
-universe class inherits from sf::Drawable which allows the use of window.draw(universeObject) in main.cpp

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
SFML library website

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
