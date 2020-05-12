#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include "nodeList.h"
#include "list.h"

/*
Victoria C
Double Linked List Reservation Program
5/13/13
*/

using namespace std;

int randTicket();
int randCity();
void clear();
string cities[] = {"Seoul", "Paris", "NewYork", "Tokyo","LA","Liverpool","Rome","Toronto","Alaska","Madrid"};
int main()
{
    srand((unsigned)time(NULL));
    nodeList* nl = new nodeList();

    while (true)
    {
        int choice;

        cout << "::AIRLINE RESERVATION SYSTEM::\n\n"
             << "1. Reserve a ticket\n"
             << "2. Cancel a ticket\n"
             << "3. Check a ticket\n"
             << "4. Display Passengers\n"
             << "5. EXIT\n"
             << "6. Change Destination\n"
             << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << "Reserving a ticket\n\n";
                cout << "Enter Name: ";
                string name;
                cin >> name;
                int tix = randTicket();
                int cit = randCity();
                string C = cities[cit];
                list* newTicket = new list(name,tix, C);
                nl->addToHead(newTicket);
                cout << "Ticket reservation sucessful!\n";
                cout << "Your ticket information is the latest one\n";
                cout << "Please keep a copy for your records\n";
                nl->printList();
                cout << "\n";
                break;
            }
            case 2:
            {
                cout << "Canceling a ticket\n\n";
                cout << "Enter ticket number: ";
                int ticketToFind;
                cin >> ticketToFind;
              list* ticketToDelete = nl->FindNodeByTicket(ticketToFind);
              if (ticketToDelete != NULL)
              {
              nl->deleteNode(ticketToDelete);
              cout << "Ticket deletion sucessful";
              }
              else
              cout << "unable to locate ticket";
                break;
            }

            case 3:
            {
                cout << "Checking a ticket\n\n";
                int ticketToFind;
                cout << "Enter ticket number: ";
                cin >> ticketToFind;
                list* foundTicket = nl->FindNodeByTicket(ticketToFind);
                if (foundTicket != NULL)
                {
                    cout << *foundTicket;
                }
                else
                {
                    cout << "no ticket found";
                }
                break;
            }

            case 4:
            {
                cout << "Displaying Passengers\n\n";
                nl->printList();
                break;
            }

            case 5:
            {
                cout << "Now exiting program\n\n";
                clear();
                return 0;
                break;
            }

            case 6:
            {
                string newCity;
                int ticketNum;
                cout << "\nChanging Destination\n\n";
                cout << "Enter Ticket Number: ";
                cin >> ticketNum;
                list* foundTicket = nl->FindNodeByTicket(ticketNum);
                if (foundTicket == NULL){cout << "no ticket found"; break;}
                cout << endl;
        
                cout << ":::Selection Provided Below...:::\n";
                for(int i = 1; i < 10; i = i+2) cout << cities[i-1] << "\t\t" << cities[i] << endl;
                cout << "Enter a new Destination: ";
                cin >> newCity;

                foundTicket->city = newCity;

                break;
            }

            default:
            {
                cout << "Invalid Input\n\n";
                return 0;
            }

        }
    }

    return 0;
}

int randTicket()
{//randomizes ticket
    int num = rand();
    return num % 100000;
}

int randCity()
{//random City
    int num = rand();
    return num % 10;
}
void clear()
{ //free up clutter
    int a = 1;
    int b = 100;
    do
    {
        printf("\n");
        a++;
    }
    while( a < b );

                            cout << "\t\t\tThe sky is the limit\n\n";


                        cout << "\t\t     \\__________( )__________/\n";
                        cout << "\t\t             o'     `o           ";

}
