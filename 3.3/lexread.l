%{
#include"definiciones.h"
 
%}

%option nounput yylineno

%%
[//].*    return comentarioC;
[#].*     return comentarioP;
[--].*    return ComentarioSQL;
"if"      return comparacion;
"+"       return suma;
"-"       return resta;
"cout"    return impresionc;
"print"   return impresionp;
"not"     return negacionp;
"!="      return negacionc;
"."       return texto;
"pow"     return powerP;  
"||"      return orC;
"++"      return suma1;
"+="      return varsum1;
"=="      return compar;
%%

int yywrap(void){
  return 1;
}