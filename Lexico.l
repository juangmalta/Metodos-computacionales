%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    FILE *yyin;
%}

%option noyywrap
%option yylineno

DIGITO [0-9]
LETRA [a-zA-Z]
