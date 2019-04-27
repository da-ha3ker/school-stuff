/***********************************************************************
* Program:
*    Checkpoint 00, test4          (e.g. Assignment 01, Hello World)  
*    Brother Cook, CS165
* Author:
*    Jordan Jarvis
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

struct Phone
{
   string phoneNumber;
   bool isRinging;
};

void answerCall(Phone & phone)
{
   phone.isRinging = 0;
}

void displayStatus(Phone phone)
{
   cout << "The phone number is ";
   cout << phone.phoneNumber;
   if (phone.isRinging == 1)
      cout << "\nThe phone is ringing";
   else
      cout << "\nThe phone is not ringing\n";
}
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   Phone phone;
   phone.phoneNumber = "8014224636";
   phone.isRinging = 1;
   if (phone.isRinging == 1)
      answerCall(phone);
   displayStatus(phone);
   cout << phone.isRinging;
   
   return 0;
}
