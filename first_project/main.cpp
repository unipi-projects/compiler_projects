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


#include "func.h"                               // Header that contains all the custom functions that were used for this program
#include <iostream>
#include <limits>
#include <stack>
#include <string>

constexpr int MAX = 100;                        // Max number of acceptable characters in a string

int main()
{
    SplashScreen();

	MenuOption();
    
    PromptAndWait();

    return 0;
}
