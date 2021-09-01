//ticketsales.h

#include <string>
#include "sportticket.h"

using namespace std;

class TicketSales{
    public: 
    string print_ticket(ShowTicket *myTicket){
        return myTicket->print_ticket();
    }

    string  print_ticket(SportTicket *myTicket){
        return myTicket->print_ticket();
    }

    TicketSales(){
    }
};