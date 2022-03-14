#include <iostream>
#include <string>
#include <fstream>
#define max 10

using namespace std;

string strings[max];

void lexerAritmetico(string archivo)
{
    string line;
    int i=0;
    ifstream inputs(archivo);
    if (inputs.is_open())
    {
        while (getline(inputs, line))
        {
            strings[i]=line;
            i++;
        }
        inputs.close();
    }

    else
        cout << "Unable to open file";
}

void printArray(string array1[])
{
    for (int i = 0; i < max; i++)
    {
        cout << array1[i] << endl;
    }
}



int main()
{
    lexerAritmetico("inputs.txt");
    printArray(strings);
    return 0;
}
// string entrada;
// cin >> entrada;
// string enteros,
//     flotantes,
//     asignacion = "=",
//     suma = "+",
//     resta = "-",
//     multiplicacion = "*",
//     division = "/",
//     potencia = "^",
//     variables,
//     p1 = "(",
//     p2 = ")",
//     comentarios = "//";
