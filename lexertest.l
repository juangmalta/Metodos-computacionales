 %{
     #include <stdio.h>
     #include<stdlib.h>    
 }

 %option c++
 %option oufile = "scanner.cpp"
 %option case-insensitive
 %option noyywrap

 Digito [0-9]
 Letra [a-zA-ZñÑ]
 
 Entero {Digito}+
 Real {Digito}+"."{Digito}+
 Identificador{Letra}({Letra}|{Digito}|"_")*

 Delimitador [\t\r\f" "]

 %%
{Entero} {printf("Numero Entero %s\n",yytext);}
{Real} {printf("Numero Real %s\n",yytext);}
{Identificador} {printf("Identificador %s\n",yytext);}

{Delimitador} {}
              {printf("Error LExico");}
 %%

