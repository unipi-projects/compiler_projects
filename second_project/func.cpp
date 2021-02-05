/*******************************************/
/*****                                 *****/
/*****      Compiler Project II        *****/
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
#include <iostream>
#include <limits>
#include <random>
#include <string>


using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;



int GetMenuOption()
{
    int option;

    cout << "Input here: ";

    // Check if user entered an invalid option
    while (!(cin>>option))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid input." << '\n';
        cout << "Please enter a number that is next to the menu." << '\n';
    }
    
    cout << '\n';
    return option;
}

int Rand(int rnum)
{
    // Create seed
    random_device rand_seed;

    // Create a number generator with our seed
    mt19937 mt(rand_seed());

    // Create a uniform distribution that generates a number from 0 to rnum
    uniform_int_distribution<int> dist(0, rnum);

    int random_number = dist(mt);

    return random_number;
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
    std::cout << "		 _ __  _ __ ___ (_) ___  ___| |_" << '\t' << " ___" << "  ___" << '\n';
    std::cout << "		| '_ \\| '__/ _ \\| |/ _ \\/ __| __|" << '\t'<<"|_ _|" << "|_ _|" << '\n';
    std::cout << "		| |_) | | | (_) | |  __| (__| |_" << '\t'<< " | |" << "  | |" << '\n';
    std::cout << "		| .__/|_|  \\____/ |\\___|\\___|\\__|" << '\t'<< " | |" << "  | |" << '\n';
    std::cout << "		|_|           |__/" << '\t' << '\t'  << '\t' <<"|___|" << "|___|" << '\n';
}

void DisplayMenu()
{
    cout << "Select and type the number next to the menu option that you wanna use." << '\n' << '\n';

    cout << "1. Generate String" << '\n';
    cout << "0. Exit" << '\n';
}

bool MenuOption()
{
    DisplayMenu();
    int option = GetMenuOption();

    switch (option)
    {
        case 1:
        {
            string A[2] = {"v", "E"};
            string B[3] = {"-Y", "+Y", "e"};

            constexpr short max_iterations = 30; 
            short counter{};

            bool fl = true;

            string str = "E";

            cout << "Starting string: " << str << '\n' << '\n';
            // E -> (Y)
            // Y -> AB 

            // A -> v || E
            // B -> -Y || +Y || e

            int num_string_display {};
            int index {};

            while (fl)
            {
                

                if (counter == max_iterations)
                {
                    cout << '\n' << "Achieved max iterations..." << '\n';
                    cout << "The string in its current state is not acceptable." << '\n';
                    fl = false;
                }

                switch (str[index])
                {
                    case 'A':
                    {
                        int array_index = Rand(1);

                        string temp_str = A[array_index];

                        str.replace(index, 1, temp_str);
                        ++counter;
                        cout << "MID: " << str << '\n';
                        cout << "Counter: " << counter << '\n';
                        index = 0;
                        break;
                    }
                    case 'B':
                    {
                        int array_index = Rand(2);

                        string temp_str = B[array_index];

                        if (array_index == 2)
                        {
                            str.replace(index, 1, " ");
                        }
                        else
                        {  
                            str.replace(index, 1, temp_str);
                        }
                        ++counter;
                        cout << "MID: " << str << '\n';
                        cout << "Counter: " << counter << '\n';
                        index = 0;

                        break;                       
                    }
                    case 'E':
                    {
                        str.replace(index, 1, "(Y)");

                        cout << "MID: " << str << '\n';
                        cout << "Counter: " << counter << '\n';
                        index = 0;

                        break;
                    }
                    case 'Y':
                    {
                        str.replace(index, 1, "AB");
                        ++counter;
                        cout << "MID: " << str << '\n';
                        cout << "Counter: " << counter << '\n';
                        index = 0;

                        break;
                    }
                    case 'v':
                    {
                        if (index == str.size() - 1)
                        {
                            fl = false;
                            cout << '\n' << "The string is acceptable!" << '\n';
                        }
                        break;
                    }
                    case '(':
                    {
                        if(index == str.size() - 1)
                        {
                            fl = false;
                            cout << '\n' << "The string is acceptable!" << '\n';
                        }
                        break;
                    }
                    case ')':
                    {
                        if (index == str.size() - 1)
                        {
                            fl = false;
                            cout << '\n' << "The string is acceptable!" << '\n';
                        }
                        break;
                    }

                }

                ++index;
                
            } // End of while
            
            
            cout << '\n' << "Final string: " << str << '\n';
            cout << "Counter: " << counter << '\n';
            PromptAndWait();
            break;
        }
        return false;
    }
    return true;
}
