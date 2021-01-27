/*******************************************/
/*****                                 *****/
/*****      Compiler Project III       *****/
/*****                                 *****/
/*****                                 *****/
/***** Contributors:                   *****/
/***** p19239 APOSTOLOS SIDERIS        *****/
/***** p19122 SOPHIA-MARIA NIKOLIA     *****/
/***** p19111 IASONAS BARMPERIS        *****/
/***** p19174 ATHANASIOS TSIARAS       *****/
/*****                                 *****/
/*******************************************/


#include "func.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::stack;
using std::vector;
using std::queue;

using Matrix = vector<vector<char>>;

// Global variables used in the InitTree function
queue<string> PROD;
queue<char> MT; 

int GetMenuOption()
{
    int option;

    cout << "Input here: ";
    cin >> option;

    // Check if user entered an invalid option
    while (!cin>>option)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid input." << '\n';
        cout << "Please enter a number that is next to the menu." << '\n';
    }
    
    cout << '\n';
    return option;
}


void PromptAndWait()
{
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << '\n' <<"Press enter to exit the program." << '\n';
    std::cin.get();
      
}

void SplashScreen()
{
    	std::cout << "                           _ _" << '\n';
	std::cout << "  ___ ___  _ __ ___  _ __ (_| | ___ _ __" << '\n';
	std::cout << " / __/ _ \\| '_ ` _ \\| '_ \\| | |/ _ | '__|" << '\n';
    std::cout << "| (_| (_) | | | | | | |_) | | |  __| |" << '\n';
    std::cout << " \\___\\___/|_| |_| |_| .__/|_|_|\\___|_|" << '\n';
    std::cout << "                    |_|"<< '\n';
    
    std::cout << "		                 _           _" << '\n';
    std::cout << "		 _ __  _ __ ___ (_) ___  ___| |_" << '\t' << " ___" <<'\n';
    std::cout << "		| '_ \\| '__/ _ \\| |/ _ \\/ __| __|" << '\t'<<"|_ _|"<<'\n';
    std::cout << "		| |_) | | | (_) | |  __| (__| |_" << '\t'<< " | |" <<'\n';
    std::cout << "		| .__/|_|  \\____/ |\\___|\\___|\\__|" << '\t'<< " | |" << '\n';
    std::cout << "		|_|           |__/" << '\t' << '\t'  << '\t' <<"|___|" << '\n';
}

void DisplayMenu()
{
    cout << "Select and type the number next to the menu option that you wanna use." << '\n' << '\n';

    cout << "1. Test Sentence\n";
    cout << "0. Exit\n";
}

void ToStack(stack<char> &st, string &production)
{
    // if the string consists of one character just insert it into the string
    if (production.size() == 1)
    {
        char ch = production[0];
        st.push(ch);        
    }
    else
    {
        // first reverse the string
        std::reverse(production.begin(), production.end());

        // insert each character of the string into the stack
        for (int  i = 0; i < production.size(); ++i)
        {
            st.push(production[i]);
        }
        
    }
    // Clear string production. Needs to be empty for the next itteration.
    production.clear();
}


void RemoveElementFromQueue(queue<char> &q)
{
    q.pop();
}

void RemoveElementFromStack(stack<char> &st)
{
    st.pop();
}

void PrintQueue(string &str)
{
    str.erase(0,1);
    cout << "Input: " << str << '\n';  
}

void Analyzer(stack<char> &st, queue<char> &q, bool &valid, string &str)
{
    // check if top element of the stack is non terminal
    if(CheckTopElementOfStack(st) == false)
    {
        // ((b-a)*(a+b))
        // ((b+a)*b)

        // initialize a char vaiable to be equal to the top element of the stack
        char mt = GetTopStack(st);

        // initialize a char vaiable to be equal to the top element of the queue
        char t =  GetTopQueue(q);

        // remove the top element from the stack
        RemoveElementFromStack(st); 

        // initialize a string variable to be equal to the production
        // of the top element of the stack and the top element of the queue
        string production = M(mt, t); 

        // check if the production is equal to Invalid
        if (production == "Invalid")
        {
            valid = false;
        }
        else
        {
            
            MT.push(mt); // 0: S

            PROD.push(production);  // 0: (X)

            
            
            //cout <<  << '\n';

            PrintM(mt, t);
            cout << '\t';
            cout << '\t';
            cout << mt << " ~> " << production << '\t';
            cout << '\n';
            
            // insert the reversed production string into the stack
            ToStack(st, production);
            
        }
                
    }
    else
    {
        // if the top element of the stack is terminal
        // then remove the top element from the stack and the queue
        RemoveElementFromStack(st);
        RemoveElementFromQueue(q);
        PrintQueue(str);
    }
    
}


void ToQueue(queue<char> &q, string str)
{
    // Insert each character from  the string into the queue
    for (int i = 0; i < str.size(); ++i)
    {
        q.push(str[i]);
    } 
}

void PrintM(char mt, char t)
{
    cout << "M(" << mt << ", " << t << ")";
}

/*
void PrintTree(queue<char> &MT, queue<string> &PROD)
{
    int MT_size = MT.size();
    for (int i = 0; i < MT_size; ++i)
    {
        char ch = MT.front();
        string str = PROD.front();

        if (i == 0)
        {
            cout <<  ch << '\n'; // S
        }
        
        int size = str.size();

        switch (size)
        {
            case 1:
            {
                //cout << '\t' << "/" << '\n';
                cout << str;
                break;
            }
            case 2:
            {
                char first_ch = str[0];
                char second_ch = str[1];

                //cout << '\t' << "/" << '\t' << "\\" << '\n';
                cout << first_ch << " " << second_ch;
                break;
            }
            case 3:
            {
                char first_ch = str[0];
                char second_ch = str[1];
                char third_ch = str[2];

                //cout << '\t' << "/" << '\t' << "|" << '\t' <<"\\" << '\n';
                cout << first_ch << " "  << second_ch << " "  << third_ch;
                break;
            }    

        }
        MT.pop();
        PROD.pop();
        cout << '\n';
    }
    
}
*/
bool CheckTopElementOfStack(const stack<char> &st)
{
    // Create two arrays.
    // mt_array consists of all the non terminal characters
    char mt_array[] = {'S', 'X', 'Y', 'Z'};     

    // t_array consists of all the terminal characters
    char t_array[] = {'(', ')', '*', '-', '+', 'a', 'b'};

    if (st.empty())
    {
        return false;
    }

    // top element of stack
    char top_ch = st.top(); // (

    // check if top element of stack is terminal or non terminal
    
    for (int i = 0; i < 4; ++i)
    {
        // return false if its non terminal
        if (top_ch == mt_array[i])
        {
            //cout << "CheckTopElementOfStack ~> top_ch = " << top_ch << '\n';
            return false;
        }   
        
    }

    for (int i = 0; i < 7; ++i) 
    {
        // return true if its terminal
        if (top_ch == t_array[i])
        {
            return true;
        }   
    }
}

bool MenuOption()
{
    DisplayMenu();
    int option = GetMenuOption();

    switch (option)
    {
        case 1:
        {
            string str = GetInput(); 
            bool valid = true;

            
            stack<char> st;
            st.push('S');
            
            queue<char> q;

            ToQueue(q, str);
            
            //break;
            while (!(IsStackEmpty(st)) && valid)
            {
            
                Analyzer(st, q, valid, str);
            }            

            if(IsStackEmpty(st))
            {
                cout << "Finish!" << '\n';
                //PrintTree(MT, PROD);
            }

            break;
        }
        return false;
    }
    return true;
}

bool IsStackEmpty(const stack<char> &st)
{
    if (st.empty())
    {
        return true;
    }
    return false;
}


string M(char mt, char t)
{
    string output;
    string str;

    switch (mt)
    {
        case 'S':
        {
            switch (t)
            {
                case '(':
                {
                    output = "S -> (X)";
                    str = "(X)";
                    break;
                }
                default:
                {
                    str = "Invalid";
                    break;
                }
            }
            break;
        }
        case 'X':
        {
            switch (t)
            {
                case '(':
                {
                    output = "S -> YZ";
                    str = "YZ";
                    break;
                }
                case 'a':
                {
                    output = "X -> YZ";
                    str = "YZ";
                    break;
                }
                case 'b':
                {
                    output = "X -> YZ";
                    str = "YZ";                    
                    break;
                }
                default:
                {
                    str = "Invalid";
                    break;
                }
            }
            break;
        }
        case 'Y':
        {
            switch (t)
            {
                case '(':
                {
                    output = "Y -> S";
                    str = "S";
                    break;
                }
                case 'a':
                {
                    output = "Y -> a";
                    str = "a";
                    break;
                }
                case 'b':
                {
                    output = "Y -> b";
                    str = "b";
                    break;
                }
                default:
                {
                    str = "Invalid";
                    break;
                }
            }
            break;
        }
        case 'Z':
        {
            switch (t)
            {   
                case '*':
                {
                    output = "Z -> *X";
                    str = "*X";
                    break;
                }
                case '-':
                {
                    output = "Z -> -X";
                    str = "-X";
                    break;
                }
                case '+':
                {
                    output = "Z -> +X";
                    str = "+X";
                    break;
                }
                case ')':
                {
                    break;
                }
                default:
                {
                    str = "Invalid";
                    break;
                }
            }
            break;
        }
    }
    
    //cout << output << '\n';
    return str;
}

string GetInput()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    string str;

    // TODO: Change just so it cannot take numbers
    getline(cin, str);

    return str;
}


char GetTopStack(const stack<char> &st)
{
    char top_ch = st.top();
    return top_ch;
}

char GetTopQueue(const queue<char> &q)
{
    char top_ch = q.front();
    return top_ch;
}






