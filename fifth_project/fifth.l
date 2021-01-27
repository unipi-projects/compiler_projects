%%
.                       {printf("\nWrong input!\n");return 1;}
^"point "[A-H]{1}$      {printf("\nThe shape is indeed a point.");}
^"line "[A-H]{2}$       {
                            if(yytext[5] == yytext[6])
                            {
                                printf("\nWrong input!\n");
                            }
                            else
                            {
                                printf("\nThe shape is indeed a line.\n");
                            }
                        }
^"triangle "[A-H]{3}$   {
                            if((yytext[9] == yytext[10]) && (yytext[9] == yytext[11]) && (yytext[10] == yytext[11]))
                            {
                                printf("\nWrong input!\n");
                            }
                            else
                            {
                                printf("\nThe shape is indeed a triangle.\n");
                            }
                        }
                        
                            
^"square "[A-H]{4}$     {
                            for(int j = 7; j < 11; ++j)
                            {
                                for(int i = j + 1; i < 11; ++i)
                                {
                                    if(yytext[i] == yytext[j])
                                    {
                                        printf("\nWrong input!\n");
                                        return 1;
                                    }
                                    
                                }
                            }
                            printf("The shape is indeed a square.\n");
                        }
^"pentagon "[A-H]{5}$   {
                            for(int j = 9; j < 14; ++j)
                            {
                                for(int i = j + 1; i < 14; ++i)
                                {
                                    if(yytext[i] == yytext[j])
                                    {
                                        printf("\nWrong input!\n");
                                        return 1;
                                    }
                                    
                                }
                            }
                            printf("The shape is indeed a pentagon.\n");
                        }
^"hexagon "[A-H]{6}$    {
                            for(int j = 8; j < 14; ++j)
                            {
                                for(int i = j + 1; i < 14; ++i)
                                {
                                    if(yytext[i] == yytext[j])
                                    {
                                        printf("\nWrong input!\n");
                                        return 1;
                                    }
                                    
                                }
                            }
                            printf("The shape is indeed a hexagon.\n");
                        }
^"heptagon "[A-H]{7}$   {
                            for(int j = 9; j < 16; ++j)
                            {
                                for(int i = j + 1; i < 16; ++i)
                                {
                                    if(yytext[i] == yytext[j])
                                    {
                                        printf("\nWrong input!\n");
                                        return 1;
                                    }
                                    
                                }
                            }
                            printf("The shape is indeed a heptagon.\n");
                        }
^"octagon "[A-H]{8}$    {
                            for(int j = 8; j < 16; ++j)
                            {
                                for(int i = j + 1; i < 16; ++i)
                                {
                                    if(yytext[i] == yytext[j])
                                    {
                                        printf("\nWrong input!\n");
                                        return 1;
                                    }
                                    
                                }
                            }
                            printf("The shape is indeed an octagon.\n");
                        }
                        
%%

int main()
{
    yylex();
    return 0;
}