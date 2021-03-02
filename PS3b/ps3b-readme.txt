/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: saema nazar

Hours to complete assignment : 6-8

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes. All parts of program works as intended and produces sounds when the appropriate 
keys are pressed. Keys produce the right sounds. 

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/
Yes. I implemented a second version of the program that simulates drum sounds.
This is located in a directory called "ps3b-drum" inside the ps3b directory.
I did this by modifying the decay factor and changing the sign of the average value
being added to the buffer (in function tic() ) to negative 50% of the time.


/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, the contructors in StringSound throw errors when invalid inputs are read.
I put throw() statements and error handling in these functions.

I placed try-catch blocks in main.cpp and initialized a StringSound object with an invalid
argument. This throws an error, outputting an error msg,which shows that exception handling is successful.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
class notes, cpp references websites


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
