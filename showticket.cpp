//showticket.h


#include <string>
#include <showticket.h>

using namespace std;

class ShowTicket {
    private:
        string row;
        string seatNumber;
        bool sold;
    public:
        bool is_sold(){         
            return sold;
        }

        ShowTicket(string s, string r);
        
        void sell_seat(){ 
            sold = true;
            }

        string print_ticket(){
            if (sold)
                return row + " "+ seatNumber + " sold";
            else
                return row + " "+ seatNumber + " is available";
        }

};

ShowTicket::ShowTicket(string r, string s){
    row = r;
    seatNumber = s;
    sold = false;

}