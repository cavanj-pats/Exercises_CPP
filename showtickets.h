//showticket.h
//it works if i include prototype and defintion in one file
//by that i mean VS Code compiles it.

#include <string>


using namespace std;

class ShowTickets {
    private:
        string rows[10];  
        string seats[10];
        int items;

    public:
        bool is_sold(string row, string seat);
        
        int show_items();

        ShowTickets();
        
        void sell_seat(string row, string seat);

        string print_ticket(string row, string seat);

};

//pasted before upload to grader

      bool ShowTickets::is_sold(string row, string seat){         
            if (items == 0)
                return false;
            else{
                for (int i=0;i<items;i++){
                    if (rows[i] == row && seats[i] == seat)
                        return true;
                }
            }
            return false;
        }

        int ShowTickets::show_items(){
            return items;
        }
        
        void ShowTickets::sell_seat(string row, string seat){ 
            if (items<10){
                rows[items]= row;
                seats[items]=seat;
                items++;
            }
        }

        string ShowTickets::print_ticket(string row, string seat){
            if (this->is_sold(row, seat))
                return row + " "+ seat + " sold";
            else
                return row + " "+ seat + " is available";
        }



ShowTickets::ShowTickets(){
    items=0;  //create an empty batch of tickets

}


