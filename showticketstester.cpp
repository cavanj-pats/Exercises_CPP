//showticketstester.cpp
//selection sort execise  Week 24 sorting labs
#include <iostream>
#include <string>
#include "showtickets.h"  //- wont compile without edit of tasks.json
//which i did not do.  so i just pasted class code into this file.

using namespace std;



int main () {
    
    ShowTickets myticket;
    if(!myticket.is_sold("AA", "101"))
            myticket.sell_seat ("AA", "101");
    cout << myticket.print_ticket("AA", "101") << endl;
    cout << myticket.print_ticket("AA","102") << endl;
    myticket.sell_seat("AA","102");
myticket.sell_seat("AA","103");
myticket.sell_seat("AA","104");
myticket.sell_seat("AA","105");
myticket.sell_seat("AA","106");
myticket.sell_seat("AA","107");
myticket.sell_seat("AA","108");
myticket.sell_seat("AA","109");
myticket.sell_seat("AA","110");
cout<< myticket.show_items() << endl;
myticket.sell_seat("AA","111");
cout << myticket.show_items() << endl;
cout << myticket.print_ticket("AA", "110")<< endl;




    return 0;
}


