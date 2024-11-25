/*
* Name: Nate O'Brien
* Project: 
* Date: 11/25/24
* Extra: Error checks user input, and kicks them out if an improper variable is entered
*/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
//method declarations
double calcPrice(double price, double toppings);
void displayBill(double price);

//vars
double price;
double tax;
double curItemPrice;

int main() {
    char again;
    int choice;
    //do while for program
    do {  
        //gets what they want, goes through a switch
        printf("Welcome to Little Dominos Pizza! Our prices are as follows:\n1. Small Anshy Pizza: 10.99\n2. Large Pranny Pizza: 12.99\nAll Toppings are 1.99\n\nPlease enter your choice.");
        scanf("%d", &choice);

        //gets user input and compares what they get.
        switch(choice) {
            case 1:
                printf("You ordered a Small Anshy Pizza.");
                curItemPrice = 10.99;
                break;
            case 2:
                printf("You ordered a Large Pranny Pizza.");
                curItemPrice = 12.99;
                break;
            //extra - if a wrong value is entered, they get kicked out.
            default:
                printf("Not a thing. Get out of my store.");
                exit(0);
                break;
        }

        //topping vars
        char anotherTopping;
        double toppingMultiplier = 0;
        string notNeededVar;
        do {
            //gets input for topping
            printf("\nEnter a topping. We will put anything on the pizza! ");
            scanf("\n");
            getline(cin, notNeededVar);
            //since all toppings get 1.99, just need a multiplier
            toppingMultiplier++;
            //exits when they are done with toppings
            printf("Want to order another topping? (y/n)");
            scanf(" %c", &anotherTopping);
        } while (anotherTopping != 'n');
        
        //adds the items current price to the total price
        price += calcPrice(curItemPrice, toppingMultiplier);

        //exits loop if they do not want any more.
        printf("Want to order something else? (y/n)");
        scanf(" %c", &again);
    } while (again != 'n');
    
    //prints bill
    displayBill(price);

    return 0;
}

//calcs current price and returns it
double calcPrice(double price, double toppings){
    return price + 1.99 * toppings;
}

void displayBill(double price){
    //gets tax and total, before printing out
    double tax = price * 0.06625;
    double total = price + tax;
    printf("\n\n*********************************\nSubtotal: $%f\nTax: $%f\nTotal: $%f\n\nThank you for visiting!\n*********************************", price, tax, total);
}