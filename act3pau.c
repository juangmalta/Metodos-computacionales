// Programa que implementa un motor de expresiones regulares que toma expresiones regulares
// y escanea los elementos léxicos de cualquier archivo y lo convierte a html
// Autor: Paulina Lizet Gutiérrez Amezcua A01639948
// Fecha de creación: 20 de marzo de 2022
// Actividad Integradora 3.3 Resaltador de sintaxis

#include <stdio.h>
#include "expresiones.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

// Char con las 12 expresiones regulares
char *names[] = {NULL, "Negacion_Cplusplus", "Negacion_Python", "Negacion_Pascal", "Elevacion_Cplusplus",
				"Elevacion_Python", "Elevacion_Pascal", "Comentarios_Cplusplus", "Comentarios_Python", 
				"Comentarios_Pascal", "Imprimir_Cplusplus", "Imprimir_Python", "Imprimir_Pascal", "Espacio", "Texto"};

int main(void){
	int token;
	FILE *archivo;
	archivo = fopen("analizador_léxico.html", "w+"); // Crea un archivo para lectura y escritura.
	if (archivo == NULL){
		printf("%s\n", "No se puede abrir"); // En caso de que no pueda abrir el archivo.
		return 1;
	}

	// Se utiliza fprintf para agregar los elementos html al archivo.
	fprintf(archivo, "%s", "<!DOCTYPE html> \n");
	fprintf(archivo, "%s", "<html> \n");
	fprintf(archivo, "%s", "	<meta charset = 'utf-8'>  \n");
	fprintf(archivo, "%s", "	<head> \n");
	fprintf(archivo, "%s", "		<link href='./style.css' rel='stylesheet'> \n");
    fprintf(archivo, "%s", "	<br/> \n");
	fprintf(archivo, "%s", "		<title>Actividad Integradora 3.3 Resaltador de sintaxis</title> \n");
	fprintf(archivo, "%s", "	</head>\n");
	fprintf(archivo, "%s", "	<body> \n");
	fprintf(archivo, "%s", "		<h1 class='al'>Analizador léxico</h1>\n");
	fprintf(archivo, "%s", "		<h2 class='pr'>Lenguajes de programación:</h2> \n");
	fprintf(archivo, "%s", "		<ul> \n");
    fprintf(archivo, "%s", "		<h3 class='C'>Lenguaje C++</h3> \n");
	fprintf(archivo, "%s", "			<style =' color:blue'>Negacion_C++</li> \n");
	fprintf(archivo, "%s", "			<li id='E_C'>Elevacion_C++</li> \n");
	fprintf(archivo, "%s", "			<li id='C_C'>Comentarios_C++</li> \n");
	fprintf(archivo, "%s", "			<li id='Imp_C'>Imprimir_C++</li> \n");
	fprintf(archivo, "%s", "		<h3 class='Python'>Lenguaje Python</h3> \n");
	fprintf(archivo, "%s", "			<li id='Neg_Python'>Negacion_Python</li> \n");
	fprintf(archivo, "%s", "			<li id='E_Python'>Elevacion_Python</li> \n");
	fprintf(archivo, "%s", "			<li id='C_Python'>Comentarios_Python</li> \n");
	fprintf(archivo, "%s", "			<li id='Imp_Python'>Imprimir_Python</li> \n");
	fprintf(archivo, "%s", "		<h3 class='Pascal'>Lenguaje Pascal</h3>\n");
	fprintf(archivo, "%s", "			<li id='Neg_Pascal'>Negacion_Pascal</li> \n");
	fprintf(archivo, "%s", "			<li id='E_Pascal'>Elevacion_Pascal</li> \n");
	fprintf(archivo, "%s", "			<li id='C_Pascal'>Comentarios_Pascal</li> \n");
	fprintf(archivo, "%s", "			<li id='Imp_Pascal'>Imprimir_Pascal</li> \n");
	fprintf(archivo, "%s", "		<ul> \n");
    fprintf(archivo, "%s", "	<br/> \n");
    fprintf(archivo, "%s", "		<p class='texto'> \n");
	
    token = yylex();
    // Dependiendo del token que encuentra en el archivo le da el formato y lo imprime.
	while(token) {
		printf("%d\n", token);
		if (token == Negacion_Cplusplus){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Neg_C'>", yytext,"</span>");
        }
		else if(token == Negacion_Python){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Neg_Python'>", yytext,"</span>");
		}
		else if(token == Negacion_Pascal){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Neg_Pascal'>", yytext,"</span>");
		}
		else if(token == Elevacion_Cplusplus){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='E_C'>", yytext,"</span>");
		}
		else if(token == Elevacion_Python){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='E_Python'>", yytext,"</span>");
		}
		else if(token == Elevacion_Pascal){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='E_Pascal'>", yytext,"</span>");
		}
		else if(token == Comentarios_Cplusplus){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='C_C'>", yytext,"</span>");
		}
		else if(token == Comentarios_Python){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='C_Python'>", yytext,"</span>");
		}
		else if(token == Comentarios_Pascal){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='C_Pascal'>", yytext,"</span>");
		}
		else if(token == Imprimir_Cplusplus){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Imp_C'>", yytext,"</span>");
		}
		else if(token == Imprimir_Python){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Imp_Python'>", yytext,"</span>");
		}
		else if(token == Imprimir_Pascal){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s","<span id='Imp_Pascal'>", yytext,"</span>");
		}
        else if(token == Espacio){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s", "<br/> \n");
		}
        else if(token == Texto){
			printf("%s is: %s\n", names[token],yytext);
			fprintf(archivo,"%s%s%s", "<span>", yytext, "</span>");
		}
        // Si no imprime error
		else{
			printf("Syntax error in line %d\n",yylineno);
		}
	token = yylex();
	}

    // Cierra los elementos del html
    fprintf(archivo, "%s", "		</p> \n");
    fprintf(archivo, "%s", "	<br/> \n");
    fprintf(archivo, "%s", "	<footer class='footer'> \n");
	fprintf(archivo, "%s", "		<p><b>Autor:</b> Paulina Lizet Gutierrez Amezcua A01639948</p> \n");
	fprintf(archivo, "%s", "	</footer>\n");
	fprintf(archivo, "%s", "	<body> \n");
	fprintf(archivo, "%s", "<html> \n");

    fclose(archivo); // Cierra el archivo html

    return 0;
}
