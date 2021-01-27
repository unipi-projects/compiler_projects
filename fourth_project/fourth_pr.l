VARIABLES_U     [A-Z]
DIGITS          [0-9]
OPERATORS       "+"|"-"|"*"|"/"|"%"
VARIABLES_L     [a-z]

%%
.                                                                                           {printf("\nWrong input!\n"); return 1;}
{VARIABLES_U}"="({VARIABLES_L}|{DIGITS})({OPERATORS}({VARIABLES_L}|{DIGITS}))+";"$          {printf("\nThe string is acceptable!\n");}      
%%

int main()
{
    yylex();
    return 0;
}