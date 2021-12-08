#include "std_lib_facilities.h"

constexpr char number = '8';
constexpr char print = ';';
constexpr char quit = 'q';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char root ='r';
constexpr char power = 'p';
const string declkeywrd = "let";
const string sqrtwrd = "sqrt";
const string powwrd = "pow";
double expression();

class Variable
{
public:
    string name;
    double value;

};

vector<Variable> var_table;

bool is_declared(string var)
{
    for(auto v : var_table)
     {
        if(v.name == var)
            return true;
    }
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var))
        error("Variable is already declared.");

    var_table.push_back(Variable{var,val});
    return val;

}

double get_value(string var)
{
    for(auto v : var_table)
        {
        if(v.name == var )
            return v.value;
        }
    error("get: Variable not defined");
    return 0;

}

void set_value(string var, double val)
{

        for(auto& v: var_table)
        {
            if(v.name == var)
            {
                v.value = val;
                return;
            }
        }

    error("set: Variable not defined.");

}



class Token
{
public:
    char kind;
    double value;
    string name;

    Token(): kind(0){};
    Token(char ch): kind(ch), value(0) {};
    Token(char ch, double val): kind(ch), value(val) {};
    Token(char ch, string n): kind (ch), name(n) {};

};

class Token_stream
{
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream(): full (false), buffer{0} {};

void Token_stream::putback(Token t)
{
    if (full)
        simple_error("Token_stream buffer is full\n");
    full =true;
    buffer = t;

}


Token Token_stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch(ch)
        {
            case quit:
            case print:
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '=':
            case ',':
                    return Token(ch);

            case '.':
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);
                double  val = 0;
                cin >> val;
                return Token(number,val);
            }
            default:
                {
                    if(isalpha(ch))
                    {
                        string s;
                        s += ch;
                        while(cin.get(ch) && ( isalpha(ch) || isdigit(ch) ) )
                            s+=ch;

                        cin.putback(ch);
                        if ( s == sqrtwrd) return Token{root};
                        if ( s == powwrd) return Token{power};
                        if( s == declkeywrd) return Token(let);
                        else if( is_declared(s) )
                            return Token(number, get_value(s));
                        return Token(name, s);
                    }
                    error("Bad token");
                    return 0;
                }
        }

}

Token_stream ts;

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }

    full = false;
    char ch = 0;
    while(cin >> ch )
       {    if(ch == c )
                return;
        }
}




double primary()
{
    Token t = ts.get();

    switch (t.kind)
    {
        case '(':
                {
                    double d = expression();
                    t = ts.get();
                    if(t.kind != ')') error("')'expected");
                    return d;
                }
        case number:
            return t.value;

        case '-':
                return -primary();
        case '+':
                return primary();

        case 'r':
            {

             //   t = ts.get();
                double d = expression();
                if (d < 0 )
                    error("Negative sqare root not defined on real number plane");

                return sqrt(d);
            }

        case 'p':
                {
                    t = ts.get();
                    if (t.kind != '(')
                          error("'(' expected");


                    double alap = expression();
                    t = ts.get();
                    if (t.kind != ',')
                            error("',' expected");
                    double kitevo = expression();
                    t = ts.get();

                    if (t.kind != ')')
                            error("')' expected");
                    return pow(alap,kitevo);

                }
        default:
            ts.putback(t);
            error("primary expected\n");
            return 0;
    }
return 0;
}

double term ()
{
    double left = primary();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
            {
                case '*' :
                        left *= primary();
                        t = ts.get();
                        break;
                case '/' :
                    {
                        double d = primary();
                        if (d==0) error("Zero value in /");
                        left /= d;
                        t = ts.get();
                        break;
                    }
                case '%' :
                        {/*
                            double d = primary();
                            if(d==0)    error("Zero value in %");
                            left =fmod(left, d);
                            t= ts.get();
                            break;
                            */
                            int i1 = narrow_cast<int>(left);
                            int i2 = narrow_cast<int>(primary());
                            if(i2 == 0) error("Zero value in %");
                            left = i1 % i2;
                            t = ts.get();
                            break;

                        }
                    //    left %= primary();
                    //    t = ts.get();

                default:
                    ts.putback(t);
                    return left;
            }
    }
}


double expression ()
{
    double left = term();
    Token t = ts.get();
    while(true)
    {
        switch(t.kind)
            {
                case '+' :
                        left += term();
                        t = ts.get();
                        break;
                case '-' :
                        left -= term();
                        t = ts.get();
                        break;
                default:
                        ts.putback(t);
                        return left;
            }
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        error("Name expected in declaration!");
    string var_name = t.name;

    t = ts.get();
    if (t.kind != '=')
        error ("'=' expected in declaration");

    double d = expression();

    define_name(var_name, d);

    return d;
}




double statement()
{
    Token t = ts.get();

    switch(t.kind)
    {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();

    }


}





void calculate()
{

    while (cin)
    try{
            Token t = ts.get();
            while(t.kind == print)
                t = ts.get();
            if(t.kind == quit)
                return;
            ts.putback(t);
            cout << '=' << statement() <<'\n';

    }catch(exception& e)
    {
        cerr << e.what() << '\n';
        clean_up_mess();
    }

}


int main()
try {
    cout << "Welcome to our simple calculator." << endl;
    cout << "Please enter expressions using floating-point numbers." << endl;
    cout << "Available operators: +, -, /, *, ()" << endl;
    cout << "Sqare root is available, use 'sqrt()'" << endl;
    cout << "Power function is available, use 'pow(number,power)' expression"<< endl;
    cout << "To print the result use command ';'" << endl;
    cout << "To exit the calculator program use 'quit'" << endl;
    cout << "To define variables use 'let x=' phrase, already declared: pi, k " << endl;

    define_name("k",1000);
    define_name("pi",3.1415926535);

    calculate();

    return 0;
    }
catch (exception& e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;

    }
