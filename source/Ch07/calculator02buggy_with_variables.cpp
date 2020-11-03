#include "std_lib_facilities.h"

constexpr char number = '8';
constexpr char quit = 'x';
constexpr char print = ';';
constexpr char result = '=';
constexpr char let = 'L';
constexpr char name = 'a';
constexpr char square_root = '@';
constexpr char power_to = ',';

const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";

double primary();

double expression();

class Variable{
public:
    string name;
    double value;
};

vector<Variable> var_table;

bool is_declared(string var){
    for(const auto& v : var_table)
        if(v.name == var) return true;
    return false;
}

double define_name(string var, double val){
    if(is_declared(var)) error("Variable is declared: ", var);
    var_table.push_back(Variable{var,val});
    return val;
}

double get_value(string s){
    for(const auto& v : var_table)
        if(v.name == s) return v.value;
    error("get: variable not defined");
    return 1;
}


void set_value(string s, double d){
    for(auto& v : var_table)
        if(v.name == s)
        {
            v.value = d;
            return;
        }
    error("set: variable not defined");
}

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;
    Token(): kind(0) {}
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case print:    // for "print"
        case quit:    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/': case '%': case '=':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val = 0; // try to initialize a value
            cin >> val;              // read a floating-point number
            return Token(number, val);   // let '8' represent "a number"
        }
        default:
        {
            if(isalpha(ch)){
                string s;
                s += ch;
                while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
                cin.putback(ch);
                if(s == declkey) return Token{let};
                else if(s == sqrtkey) return Token{square_root};
                else if(s == powkey) return Token{power_to};
                else if(is_declared(s))
                    return Token(number, get_value(s));
                return Token{name, s};
            }
            error("Bad token");
            return 1;
        }
    }
}

void Token_stream::ignore(char c)
{
    if(full && c == buffer.kind)
    {
        full = false;
        return;
    }

    full = false;

    char ch = 0;
    while(cin >> ch)
        if(ch == c) return;
}

Token_stream ts;        // provides get() and putback() 

double calc_sqrt(){

    char ch;
    if(cin.get(ch) && ch != '(') error("'(' expected");
    cin.putback(ch);
    double d = expression();
    if (d < 0) error("sqrt: negative value");
    return sqrt(d);
}

double pow_to(){

    char ch;
    if(cin.get(ch) && ch != '(') error("'(' expected");
    string first_value = "";
    string second_value = "";

    while(cin.get(ch) && ch != ','){
        first_value += ch;
    }

    while(cin.get(ch) && ch != ')'){
        second_value += ch;
    }

    double d = pow(stod(first_value), stod(second_value));

    return d;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case number:            // we use '8' to represent a number
        return t.value;  // return the number's value
	case '+':
		return primary();
	case '-':
		return - primary();
    case square_root: // sqrt(9); sqrt(9+6); sqrt(3*x);
        return calc_sqrt();
    case power_to:
        return pow_to();
    case quit:
        exit(0);
    default:
        error("primary expected");
        return 0;
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = primary();
                if(d == 0) error("%: zero divider");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);     // put t back into the token stream
                return left;
            }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void clean_up_mess(){
    ts.ignore(print);
}

void greet_user()
{
	cout << "Welcome to our simple calculator." << endl
		<<"Please enter expressions using floating-point numbers." << endl;
}

double declaration(){
    Token t = ts.get();
    if(t.kind != name) error("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=') error("= expected in declaration");

    double d = expression();
    define_name(var_name, d);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind){
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

void calculate()
{
    double val = statement();

    while (cin) {
        Token t = ts.get();

        if (t.kind == quit) return; // 'x' for quit
        if (t.kind == print)        // '=' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = statement();
    }   
}


int main()
try
{
    define_name("pi", 3.14159);
    define_name("e", 2.71828);

	greet_user();	
	calculate();

    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}