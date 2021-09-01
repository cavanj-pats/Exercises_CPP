//sportticket

#include <string>
#include "showticket.h"

using namespace std;

class SportTicket: public ShowTicket{
    private:
        bool haveBeer;
    
    public:
        bool beer_sold();
        void sell_beer();
        string print_ticket();
        SportTicket(string r, string s);
};

string SportTicket::print_ticket(){
        if (is_sold())
            if (haveBeer)
                return row + " "+ seat + " sold beer" ;
            else
                return row + " "+ seat + " sold nobeer";
        else
            return row + " " + seat + " is available";
}

void SportTicket::sell_beer(){
    haveBeer = true;
}

bool SportTicket::beer_sold(){
    return haveBeer;
}

SportTicket::SportTicket(string r, string s):ShowTicket(r,s){
    //row = r;
    //seat = s;
    haveBeer=false;
}