
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	***JGC  I renamed this file simply calculator02

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

	
Expression:
	Term
	Expression "+" Term // addition
	Expression "-" Term // subtraction

Term:
	Primary
	Term "*" Primary // multiplication
	Term "/" Primary // division
	Term "%" Primary // remainder (modulo)

Primary:
	Number
    Factorial   Exercise 3 P. 218   
	"(" Expression ")"
    "{" Expression "}"   Exercise 2 p. 218

Number:
	floating-point-literal

*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to false to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
        {    
		// ********************************  JGC Fixed missing "case '8' "

            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
        return buffer;  //added 3/21/2021  //on 3/31/2021 JGC thinks this might be incorrect.
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

int factorial (int num){
    int factRes = 1;
    for (int i=2; i<=num;i++)
        factRes *= i;
    return factRes;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double expression();    // declaration so that primary() can call expression()

//-----------------------------------------------------------------------------
bool isFactorial(){
    Token t=ts.get();
    if (t.kind == '!')
        return true;
    else
        ts.putback(t); return false;
}

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '{':  //handle '{' expression '}'
        {
            double d = expression();
            t=ts.get();
            if (t.kind != '}') error("'}' expected");
            return d;
        }
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        {
            double d = t.value;
            t=ts.get();
            if (t.kind == '!'){
                //is factorial
                return (double) factorial((int) d);
            } 
            else {
                ts.putback(t);  //not a factorial 
                return d;
            }
            
        }         
    default:
        error("primary expected");
        return 0.0;   //added 3/21/2021
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream
    
    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
			break;             // *************  fixed missing break   JGC+
        case '/':
              {  
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
              }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}


//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract    ****fixed this logic error***
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Type an Expression. Terminate with semicolon ';'. Then hit Enter.\n";
	cout << "> ";  //print intial prompt
	double val = 0;
    while (cin) 
    {
		
		Token t = ts.get();
		//double val = expression();
        if (t.kind == 'q') break; // 'q' for quit
		if (t.kind == ';')        // ';' for "print now"
		{
			cout << "=" << val << '\n';
			cout << "> ";   //print prompt to retrieve next expression
            val = 0;  //3/21/2021
		}
        else
        {
            ts.putback(t);
            val = expression();
            
        }

    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	//keep_window_open();  //see p. 226 for an explaination as to why we comment this line.

	//the code below can replace the Bjarne provided keep_window_open().
	//but there is another version of keep window open to replace the below.   
	//see p. 227.   
	/*
	cout << "Please enter the character ~ to close the window.\n";
	for (char ch; cin >> ch;)
		if (ch == '~') return 1;
	*/
	keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
