/*******************************************/  
/*****                                 *****/
/*****      Compiler Project III       *****/
/*****                                 *****/
/*****                                 *****/
/***** Contributors:                   *****/
/***** p19239 APOSTOLOS SIDERIS        *****/
/***** p19122 SOPHIA-MARIA NIKOLIA     *****/
/***** p19111 IASONAS MPARMPERIS       *****/
/***** p19174 ATHANASIOS TSIARAS       *****/
/*****                                 *****/
/*******************************************/ 

#pragma once

#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

int GetMenuOption();                                                        // Get input from user for the menu option

void SplashScreen();                                                        // Display projects name in figlet form
void DisplayMenu();                                                         // Display projects Menu
void PromptAndWait();                                                       // Wait for user input to exit the program
void ToStack(std::stack<char> &st, const std::string &production);          // Insert elements to stack, reverse it if need 
void Analyzer(std::stack<char> &st, std::queue<char> &q, bool &valid, std::string &str);                                                            //  
void ToQueue(std::queue<char> &q, std::string str);                         // Insert each character of the string into the queue
void RemoveElementFromQueue(std::queue<char> &q);                           // Removes the top element from the queue
void RemoveElementFromStack(std::stack<char> &st);                          // Removes the top element from the stack
void PrintQueue(std::string &str);
void PrintStack();
void PrintM(char mt, char t);                                               // Display M in its current state


bool CheckTopElementOfStack(const std::stack<char> &st);

bool IsStackEmpty(const std::stack<char> &st);                              // Return true if the stack is empty else return false

bool MenuOption();

std::string M(char mt, char t);                                             // Display and return the production

std::string GetInput();                                                     // Get input for   

char GetTopStack(const std::stack<char> &st);                               // Get top element from stack

char GetTopQueue(const std::queue<char> &q);                                // Get top element from queue

