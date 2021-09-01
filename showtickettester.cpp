//showtickettester.cpp
//selection sort execise  Week 24 sorting labs
#include <iostream>
#include <string>
#include "showticket.h"  //- wont compile without edit of tasks.json
//which i did not do.  so i just pasted class code into this file.

using namespace std;



int main () {
    
    ShowTicket myticket1("AA","101");
    ShowTicket myticket2("AA","102");
    if(!myticket1.is_sold())
            myticket1.sell_seat ();
    cout << myticket1.print_ticket() << endl;
    cout << myticket2.print_ticket() << endl;
    return 0;
}


