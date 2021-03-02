#include <iostream>
#include <cstdio>
#include "CircularBuffer.h"

using namespace std;

int main(int argc, char* argv[]){
  int16_t x =1;
  int16_t y =2;
  int16_t z =3;
  int16_t a =4;
  int16_t b =5;
  int16_t c = 6;
  
  cout<<"main\n";
  CircularBuffer test(3);
  
  //pushing 6 elements onto deque
  test.enqueue(x);
  test.enqueue(y);
  test.enqueue(z);
  test.enqueue(a);
  test.enqueue(b);
  test.enqueue(c);
  
  cout<<"First element: " << test.peek()<<endl;
  cout<<"Size before dequeue: "<<test.size()<<endl;
  cout<<"Popped element: "<<test.dequeue()<<endl;
  cout<<"Size after dequeue: "<<test.size();

  cout<<"\n\nEmpty? "<<test.isEmpty()<<endl;
  cout<<"Full? "<<test.isFull()<<endl;

}
