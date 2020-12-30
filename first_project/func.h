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

#pragma once

#include <iostream>
#include <limits>
#include <stack>
#include <string>


void SplashScreen();                            // Display projects name in figlet form
void DisplayMenu();                             // Display projects Menu
void PromptAndWait();                           // Wait for user input to exit the program

int GetMenuOption();                            // Get input from user for the menu option

std::string GetString();                        // Get string from user

bool MenuOption();
bool IsBalanced(std::string str);               // Return true if the syntax of the string is acceptable
bool CheckString(std::string str);              // Return true if the string is valid
