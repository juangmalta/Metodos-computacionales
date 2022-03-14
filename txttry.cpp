#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define q0 0
#define q1 1
#define q2 2
#define q3 3

int main()
{
    string line = "23b323";
    int estado = q0;
    char *linechar = strdup(line.c_str());
    for (int i = 0; i < line.length(); i++)
    {

        switch (estado)
        
        {

        case q0:
            if (linechar[i] == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')
            {
                estado = q1;
                cout << linechar[i] << endl;
            }
            else
            {
                estado = q2;
            }
            break;

        case q1:
            if (linechar[i] == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')
            {
                estado = q1;
                cout << linechar[i] << endl;
                if (i == line.length() - 1)
                {
                    estado = q3;
                }
            }
            else
            {
                estado = q2;
            }
            if (i == line.length() - 1)
            {
                estado = q3;
            }

            break;
        case q2:
            cout << "not a num" << endl;
            break;
        case q3:
            cout << "this is an int" << endl;
            break;
        }
    }

    return 0;
}