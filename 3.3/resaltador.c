// Lenguajes a usar: C++, python y SQL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definiciones.h"
// Para aprender a usar Flex se investigo y tomo como referencia este video https://www.youtube.com/watch?v=AyB7gVNor9U&ab_channel=EducacionOnLine
extern int yylex();
extern int yylineno;
extern char *yytext;
char *defs[] = {NULL, "comentarioC", "comentarioP", "ComentarioSQL", "if", "suma", "resta", "impresionc", "impresionp", "negacionc", "texto", "powerP", "orC"};
int main()
{
    int token;
    extern FILE *yyin, *yyout;

    yyin = fopen("exprs.txt", "r");
    yyout = fopen("results.html", "w+");
    fprintf(yyout, "<!DOCTYPE HTML> \n");
    fprintf(yyout, "<html> \n");
    fprintf(yyout, "\t<body> \n");
    fprintf(yyout, "\t\t<pre style=\"font-family:Source Code Pro Medium\"> \n");

    fprintf(yyout, "\t\t</pre> \n");

    fprintf(yyout, "\t<body> \n");

    token = yylex();
    while (token)
    {
        printf("%d\n", token);
        if (token == comentarioP)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#24C9C9'>", yytext, "</p>");
        }
        else if (token == ComentarioSQL)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#489696'>", yytext, "</p>");
        }
        else if (token == comparacion)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#14FC79'>", yytext, "</p>");
        }
        else if (token == suma)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#FD537B'>", yytext, "</p>");
        }
        else if (token == resta)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#C9249E'>", yytext, "</p>");
        }
        else if (token == impresionc)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#243AC9'>", yytext, "</p>");
        }
        else if (token == impresionp)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#485396'>", yytext, "</p>");
        }
        else if (token == negacionc)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#14ADFC'>", yytext, "</p>");
        }
        else if (token == impresionp)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#FD9953'>", yytext, "</p>");
        }
        else if (token == texto)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#C95024'>", yytext, "</p>");
        }
        else if (token == powerP)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#C9B924'>", yytext, "</p>");
        }
        else if (token == comentarioC)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#968F48'>", yytext, "</p>");
        }
        else if (token == orC)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#FCB614'>", yytext, "</p>");
        }
        else if (token == negacionp)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#53B5FD'>", yytext, "</p>");
        }
        else if (token == suma1)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#24AFC9'>", yytext, "</p>");
        }
        else if (token == varsum1)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#BD4E0F'>", yytext, "</p>");
        }
          else if (token == compar)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#green'>", yytext, "</p>");
        }
          else if (token == andp)
        {
            printf("%s is %s\n", defs[token], yytext);
            fprintf(yyout, "%s%s%s", "<p style =' color:#cian'>", yytext, "</p>");
        }

        token = yylex();
    }
    fclose(yyout);
    return 0;
}