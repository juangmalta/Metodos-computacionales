%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
 
%}

%option noyywrap

%%
[//].*    {printf("Comentario en c is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#968F48'>", yytext, "</p>");}
[#].*     {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#24C9C9'>", yytext, "</p>");}
[--].*    {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#489696'>", yytext, "</p>");}
"if"      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#14FC79'>", yytext, "</p>");}
"+"       {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#FD537B'>", yytext, "</p>");}

"cout"    {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#243AC9'>", yytext, "</p>");}
"print"   {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#485396'>", yytext, "</p>");}
"not"     {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#53B5FD'>", yytext, "</p>");}
"!="      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#14ADFC'>", yytext, "</p>");}
"."       {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#C95024'>", yytext, "</p>");}
"pow"     {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#C9B924'>", yytext, "</p>");}
"||"      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#FCB614'>", yytext, "</p>");}
"++"      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#24AFC9'>", yytext, "</p>");}
"+="      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#BD4E0F'>", yytext, "</p>");}
"=="      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#green'>", yytext, "</p>");}
"&&"      {printf(" is %s\n",yytext);fprintf(yyout, "%s%s%s", "<p style =' color:#cian'>", yytext, "</p>");}
%%

int main(void){
    char *inputs[]={"exprs.txt","exps2.txt"};
    char *outputs[]={"results.html","res2.html"};
    clock_t timestart, timened;
    double segundos;

    // Inicia clock
    timestart = clock();
    int pid;
    pid = fork();
    if(pid==-1){
        fprintf(stderr,"Error al hacer fork");
    }else if(pid==0){
    extern FILE *yyin,*yyout;
    yyin = fopen(inputs[1], "r"); 
    yyout = fopen(outputs[1], "w+");
    if (yyout == NULL || yyin == NULL) {
            printf("%s\n", "Nof");
            return 1;
        }
    fprintf(yyout, "<!DOCTYPE HTML> \n");
    fprintf(yyout, "<html> \n");
    fprintf(yyout, "\t<body> \n");
    fprintf(yyout, "\t\t<pre style=\"font-family:Source Code Pro Medium\"> \n");
    fprintf(yyout, "\t\t</pre> \n");
    fprintf(yyout, "\t<body> \n");
    yylex();
    fclose(yyout);
    }else{
    extern FILE *yyin,*yyout;
    yyin = fopen(inputs[0], "r"); 
    yyout = fopen(outputs[0], "w+");
    if (yyout == NULL || yyin == NULL) {
            printf("%s\n", "Nof");
            return 1;
        }
    fprintf(yyout, "<!DOCTYPE HTML> \n");
    fprintf(yyout, "<html> \n");
    fprintf(yyout, "\t<body> \n");
    fprintf(yyout, "\t\t<pre style=\"font-family:Source Code Pro Medium\"> \n");
    fprintf(yyout, "\t\t</pre> \n");
    fprintf(yyout, "\t<body> \n");
    yylex();
    fclose(yyout);
    }
      
    
    timened=clock();
    segundos = (double)(timened - timestart) / CLOCKS_PER_SEC; 
    printf("%f\n",segundos);
    return 0;
}