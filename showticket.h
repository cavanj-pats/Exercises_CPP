//showticket.h
//it works if i include prototype and defintion in one file
//by that i mean VS Code compiles it.

#include <string>

using namespace std;

class ShowTicket {
    private:
        bool sold;
    
    protected:    
        string row;
        string seat;
        
    public:
        bool is_sold();

        ShowTicket(std::string s, std::string r);
        
        void sell_seat();

        string print_ticket();

};

//pasted before upload to grader

      bool ShowTicket::is_sold(){         
            return sold;
        }

        
        
        void ShowTicket::sell_seat(){ 
            sold = true;
            }

        string ShowTicket::print_ticket(){
            if (sold)
                return row + " "+ seat + " sold";
            else
                return row + " "+ seat + " is available";
        }



ShowTicket::ShowTicket(string r, string s){
    row = r;
    seat = s;
    sold = false;

}


