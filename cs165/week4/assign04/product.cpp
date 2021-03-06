/***************************************************************
 * File: product.cpp
 * Author: Jordan Jarvis
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/
 
#include <iomanip>
#include <iostream>
#include <string>
#include "product.h"
using namespace std;

/**********************************************************************
 * this function asks the user for information in an item
 ***********************************************************************/
void Product :: prompt()
{
   cout << "Enter name: ";
   getline(cin, this->productName);
   cout << "Enter description: ";
   getline(cin, this->description);
   cout << "Enter weight: ";
   cin >> this->weight;

   while (this->basePrice <= 0)
   {
      cout << "Enter price: ";
      cin >> this->basePrice;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         this->basePrice = 0;
      }
   }
   return;
}

/**********************************************************************
 * this function gets sales tax based on item price
 ***********************************************************************/
float Product :: getSalesTax()
{
   float tax = 0;
   tax = this->basePrice * .06;
   return tax;
}

/**********************************************************************
 * this function gets shipping cost based on the weight
 ***********************************************************************/
float Product :: getShippingCost()
{
   float shippingCost = 0;
   int temp = this->weight;
   if (this->weight > 5)
   {
      shippingCost = 2 + (this->weight - 5) *.1;
   }
   else
   {
      shippingCost = 2;
   }
   return shippingCost;
}

/**********************************************************************
 * this function computes the total price of the product
 ***********************************************************************/
float Product :: getTotalPrice()
{
   float totalPrice = 0;
   float tax = 0;
   float shippingCost = 0;
   tax = getSalesTax();
   shippingCost = getShippingCost();
   totalPrice = (tax + shippingCost + this->basePrice);
   return totalPrice;
}

/**********************************************************************
 * This function shows name price and description of a product
 ***********************************************************************/
void Product :: advertisingProfile()
{
   cout << this->productName << " - $";
   cout << this->basePrice << "\n(";
   cout << this->description << ")" << endl;
   return;
}
  
/**********************************************************************
 * This function displays information based on name and weight
 ***********************************************************************/
void Product :: inventoryLineItem()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "$" << this->basePrice << " - ";
   cout << this->productName << " - ";
   cout.precision(1); 
   cout << this->weight << " lbs" << endl;
   return;
}

/**********************************************************************
 * This function displays information based on a reciept
 ***********************************************************************/
void Product :: reciept()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float totalPrice = 0;
   float salesTax = 0;
   float shippingCost;
   salesTax = getSalesTax();
   shippingCost = getShippingCost();
   totalPrice = getTotalPrice();
   cout << this->productName << endl;
   cout << "  Price:" << setw(10) << "$" << setw(8) << this->basePrice << endl;
   cout << "  Sales tax: " << setw(5) << "$" << setw(8) << salesTax << endl;
   cout << "  Shipping cost: $" << setw(8) << shippingCost << endl;
   cout << "  Total:" << setw(10) << "$" << setw(8) << totalPrice << endl;
}
   

