#include "list.h"

using namespace std;

list::list(string n,int t,string c):name(n),ticket(t), city(c), next(NULL), prev(NULL)
{}

ostream& operator<<(ostream& os, const list& l)
{
    return os << "Name: " << l.name << "\t\tTicket Number: " << l.ticket <<"\t\tDestination: " << l.city<< "\n";
}
