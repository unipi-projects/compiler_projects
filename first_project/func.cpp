/*******************************************/  
/*****                                 *****/
/*****      Compiler Project I         *****/
/*****                                 *****/
/*****                                 *****/
/***** Contributors:                   *****/
/***** p19239 APOSTOLOS SIDERIS        *****/
/***** p19122 Sophia-Maria Nikolia     *****/
/***** p19239 APOSTOLOS SIDERIS        *****/
/***** p19239 APOSTOLOS SIDERIS        *****/
/*****                                 *****/
/*******************************************/   

#include <iostream>
#include <limits>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::stack;


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

string GetString()
{
    string str;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Get user input for string
    getline(cin, str);

    return str;
}

bool CheckString(string str)
{
    // Check if the first character of the string is equal to x
    if(str[0] != 'x')
    {
        cout << "X was not the first character." << '\n';
        return false;
    }


    // Check if all the characters are either 'x' or 'y'
    for (int i = 0; i < str.size(); ++i)
    {
        if(str[i] != 'x' && str[i] != 'y')
        {
            cout << "Invalid character in string." << '\n';
            return false;
        }
    }
    
    int counter_x{};       // Keep track of how many 'x' characters the string has
    int counter_y{};       // Keep track of how many 'y' characters the string has
    
    // Count all the 'x' and 'y' characters
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == 'x')
        {
            ++counter_x;
        }
        else
        {
            ++counter_y;
        } 
    }

    
    if(counter_y != counter_x)
    {
        cout << "They are not equal." << '\n';
        return false;
    }

    return true;
}

bool IsBalanced(string str)
{
    // Creating a stack of characters
    stack<char> str_stack;

    for(int i = 0; i < str.size(); ++i)
    {
        // Check if the current character is 'x' and push it into the stack
        // Else remove an element from the stack
        if(str[i] == 'x')
        {
            str_stack.push(str[i]);
        }
        else
        {
            // Return false if the stack is empty and the current character is 'y'
            if(str_stack.empty())
            {
                cout << "The stack is empty." << '\n';
                return false;
            }
            
            // Remove an element from the stack
            str_stack.pop();           
        }
        
    }
    return str_stack.empty();
}

void PromptAndWait()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

    cout << "1. Test Sentence" << '\n';
    cout << "2. Exit" << '\n';
}

bool MenuOption()
{
    DisplayMenu();
    int option = GetMenuOption();

    switch (option)
    {
        case 1:
        {
            cout << '\n' <<"Type a string that consists only x or y." << '\n';

            string str = GetString();

            if(CheckString(str))
            {  
                if(IsBalanced(str))
                {
                    cout << "The string is acceptable." << '\n';
                }
                else
                {
                    cout << "The string is not acceptable." << '\n';
                }
            
            }
            break;
        }
        return false;
    }
}