//sporttickettester.cpp
//selection sort execise  Week 24 sorting labs
#include <iostream>
#include <string>
#include "sportticket.h"  //- wont compile without edit of tasks.json
//which i did not do.  so i just pasted class code into this file.

using namespace std;



int main () {
    
    SportTicket myticket1("AA","101");
  SportTicket myticket2("AA","102");
  myticket1.sell_seat();
  myticket2.sell_seat();
  myticket2.sell_beer();
  cout << myticket1.print_ticket() << endl;
  cout << myticket2.print_ticket() << endl;
  return 0;
}


