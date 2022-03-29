#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    char data;
    int contadorcolumna = 0;
    int contadorfila = 1;
    int tokeninvalido = 0;
    int casoanterior = 0;
    int casoactual = 0;
    int casosiguiente = 0;
    ifstream is("inputs.txt");

    while(is.get(data) && tokeninvalido == 0){
        contadorcolumna = contadorcolumna + 1;
    
        // ASCII ESPACIO
        if (int(data) == 32){
            if (casoactual != 16){
            casosiguiente = 0;
            }
            }
        // ASCII SALTO LINEA
        else if (int(data) == 10){
            casosiguiente = 0;
            contadorcolumna = 0;
            contadorfila = contadorfila + 1;
        }

        //ASCII ENTEROS
        else if (int(data) == 48 || int(data) == 49 || int(data) == 50 || int(data) == 51 || int(data) == 52 || int(data) == 53 || int(data) == 54 || int(data) == 55 || int(data) == 56 || int(data) == 57)
            if (casoactual == 0){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 2){
            casosiguiente = 3;
            cout << data;
            }
            else if (casoactual == 3){
            casosiguiente = 3;
            cout << data;
            }
            else if (casoactual == 4){
            casosiguiente = 6;
            cout << data;
            }
            else if (casoactual == 5){
            casosiguiente = 6;
            cout << data;
            }
            else if (casoactual == 6){
            casosiguiente = 6;
            cout << data;
            }
            else if (casoactual == 7){
            casosiguiente = 3;
            cout << data;
            }
            else if (casoactual == 8){
            casosiguiente = 1;
            //
            }
            else if (casoactual == 9){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 1;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 1;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 17;
            cout << data;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            }      

        //ASCII PUNTO
        else if (int(data) == 46)
            if (casoactual == 0){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 2;
            cout << data;
            }
            else if (casoactual == 2){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 3){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            cout << data;
            }
            else if (casoactual == 8){
            casosiguiente = 7;
            //
            }
            else if (casoactual == 9){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 7;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 7;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            }     

        // ASCII E/e E69 e101
        else if (int(data) == 69 || int(data) == 101)
            if (casoactual == 0){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 17;
            }
            else if (casoactual == 2){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 3){
            casosiguiente = 4;
            cout << data;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 17;
            //
            }
            else if (casoactual == 9){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 17;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 17;
            cout << data;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 

        // ASCII RESTA
        else if (int(data) == 45) 
            if (casoactual == 0){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 8;
            }
            else if (casoactual == 2){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 3){
            casosiguiente = 8;
            cout << " -----> REAL \n" << data;
            }
            else if (casoactual == 4){
            casosiguiente = 5;
            cout << data;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 8;
            cout << " -----> REAL \n" << data;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 8;
            }
            else if (casoactual == 9){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 8;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 8;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            }  

        // ASCII SUMA
        else if (int(data) == 43) 
            if (casoactual == 0){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 9;
            }
            else if (casoactual == 9){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 9;
            cout << data << " -----> SUMA" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 9;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            }  

        // ASCII MULTIPLICACION
        else if (int(data) == 42)
            if (casoactual == 0){ 
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 10;
            }
            else if (casoactual == 9){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 10;
            cout << data << " -----> MULTIPLICACION" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 10;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 
        
        // ASCII POTENCIA
        else if (int(data) == 94)
            if (casoactual == 0){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 11;
            }
            else if (casoactual == 9){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 11;
            cout << data << " -----> POTENCIA" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 11;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 

        // ASCII IGUAL
        else if (int(data) == 61)
            if (casoactual == 0){ 
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 12;
            }
            else if (casoactual == 9){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 12;
            cout << data << " -----> ASIGNACION" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 12;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 

        // ASCII PARENTESIS QUE ABRE
        else if (int(data) == 40)
            if (casoactual == 0){ 
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 13;
            }
            else if (casoactual == 9){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 13;
            cout << data << " -----> PARENTESIS QUE ABRE" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 13;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 

        // ASCII PARENTESIS QUE CIERRA
        else if (int(data) == 41) 
            if (casoactual == 0){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 1){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 2){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 3){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 14;
            }
            else if (casoactual == 9){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 10){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 11){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 12){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 13){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 14){
            casosiguiente = 14;
            cout << data << " -----> PARENTESIS QUE CIERRA" << endl;
            }
            else if (casoactual == 15){
            casosiguiente = 14;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 
        
        // ASCII DIVISION
        else if (int(data) == 47) 
            if (casoactual == 0){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 15;
            }
            else if (casoactual == 2){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 3){
            casosiguiente = 15;
            cout << " -----> REAL \n" << data;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 15;
            cout << " -----> REAL \n" << data;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 15;
            }
            else if (casoactual == 9){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 15;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 
        
        // ASCII a-z A-Z 
        else if (int(data) == 65 || int(data) == 66 || int(data) == 67 || int(data) == 68 || int(data) == 69 || int(data) == 70 || int(data) == 71 || int(data) == 72 || int(data) == 73 || int(data) == 74 || int(data) == 75 || int(data) == 76 || int(data) == 77 || int(data) == 78 || int(data) == 79 || int(data) == 80 || int(data) == 81 || int(data) == 82 || int(data) == 83 || int(data) == 84 || int(data) == 85 || int(data) == 86 || int(data) == 87 || int(data) == 88 || int(data) == 89 || int(data) == 90 || int(data) == 97 || int(data) == 98 || int(data) == 99 || int(data) == 100 || int(data) == 101 || int(data) == 102 || int(data) == 103 || int(data) == 104 || int(data) == 105 || int(data) == 106 || int(data) == 107 || int(data) == 108 || int(data) == 109 || int(data) == 110 || int(data) == 111 || int(data) == 112 || int(data) == 113 || int(data) == 114 || int(data) == 115 || int(data) == 116 || int(data) == 117 || int(data) == 118 || int(data) == 119 || int(data) == 120 || int(data) == 121 || int(data) == 122)
            if (casoactual == 0){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 1){
            casosiguiente = 17;
            }
            else if (casoactual == 2){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 3){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 17;
            }
            else if (casoactual == 9){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 10){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 11){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 12){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 13){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 14){
            casosiguiente = 17;
            cout << data;
            }
            else if (casoactual == 15){
            casosiguiente = 17;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 17;
            cout << data;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            } 
            
        //ASCII _
        else if (int(data) == 95)
            if (casoactual == 0){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 1){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 2){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 3){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 4){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 5){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 6){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 7){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 8){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 9){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 10){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 11){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 12){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 13){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 14){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 15){
            casosiguiente = 18;
            tokeninvalido = 1;
            }
            else if (casoactual == 16){
            casosiguiente = 16;
            cout << data;
            }
            else if (casoactual == 17){
            casosiguiente = 17;
            cout << data;
            }
            else{
            casosiguiente = 18;
            tokeninvalido = 1;
            }

        casoanterior = casoactual;
        casoactual = casosiguiente;

        if (casosiguiente == 0 && casoanterior == 1)
        cout << " -----> ENTERO" << endl;
        else if (casosiguiente == 8 && casoanterior == 1)
        cout << " -----> ENTERO" << "\n" << data;
        else if (casosiguiente == 15 && casoanterior == 1)
        cout << " -----> ENTERO" << "\n" << data;
        else if (casosiguiente == 17 && casoanterior == 1)
        cout << " -----> ENTERO" << "\n" << data;
        else if (casosiguiente == 0 && casoanterior == 2)
        cout << " -----> REAL" << endl;
        else if (casosiguiente == 0 && casoanterior == 3)
        cout << " -----> REAL" << endl;
        else if (casosiguiente == 0 && casoanterior == 6)
        cout << " -----> REAL" << endl;
        else if (casosiguiente == 0 && casoanterior == 8)
        cout << " -----> RESTA" << endl;
        else if (casosiguiente == 1 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 6 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 7 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 8 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 9 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> SUMA" << endl;
        else if (casosiguiente == 10 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> MULTIPLICACION" << endl;
        else if (casosiguiente == 11 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> POTENCIA" << endl;
        else if (casosiguiente == 12 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> ASIGNACION" << endl;
        else if (casosiguiente == 13 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> PARENTESIS QUE ABRE" << endl;
        else if (casosiguiente == 14 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data << " -----> PARENTESIS QUE CIERRA" << endl;
        else if (casosiguiente == 15 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 17 && casoanterior == 8)
        cout << " -----> RESTA" << "\n" << data;
        else if (casosiguiente == 0 && casoanterior == 15)
        cout << " -----> DIVISION" << endl;
        else if (casosiguiente == 1 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data;
        else if (casosiguiente == 6 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data;
        else if (casosiguiente == 8 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data;
        else if (casosiguiente == 9 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> SUMA" << endl;
        else if (casosiguiente == 10 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> MULTIPLICACION" << endl;
        else if (casosiguiente == 11 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> POTENCIA" << endl;
        else if (casosiguiente == 12 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> ASIGNACION" << endl;
        else if (casosiguiente == 13 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> PARENTESIS QUE ABRE" << endl;
        else if (casosiguiente == 14 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data << " -----> PARENTESIS QUE CIERRA" << endl;
        else if (casosiguiente == 17 && casoanterior == 15)
        cout << " -----> DIVISION" << "\n" << data;
        else if (casosiguiente == 0 && casoanterior == 16)
        cout << " -----> COMENTARIO" << endl;
        else if (casosiguiente == 0 && casoanterior == 17)
        cout << " -----> VARIABLE" << endl;

        else if (casosiguiente == 0 && casoanterior == 7)
        tokeninvalido = 1;
    }
    if (tokeninvalido == 1){    
            cout << "Se ha detectado un token no valido" << endl;
            cout << "Fila de error: " << contadorfila << endl;
            cout << "Columna de error: " << contadorcolumna << endl;
    }
    return 0;
}