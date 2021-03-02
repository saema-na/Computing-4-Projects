/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: saema nazar


Hours to complete assignment: 6

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
created a program to implement a circular buffer. I did this by using a double
ended queue data structure stored within a class. The class has methods for
enqueue, dequeue, peek etc




/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
-using classes is essential to object oriented design because it enables
abstraction and encapsulation.
- i am using a double ended queue because it better enables the program
to function the way it is intended, as a circular buffer. Items can be added
to front or end.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
-the class handles all functions for a double ended queue like adding/deleting
elements, checking if full or empty. It also throws errors when needed.

**implemented lambda expression/function within boost test case
for dequeue.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, passes all boost test cases as well as my own tests within main.cpp.



/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes it passes all tests. No errors are given.




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
dequeues most often have O(1) time compplexity.




/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
cpp reference websites, class lectures, notes


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
- implemented lambda expression in test.cpp file for extra credit.
For testing dequeue functionality.
