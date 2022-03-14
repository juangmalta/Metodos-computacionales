/* Este programa es un ejemplo de como se puede implementar un analizador de
lexico. El lenguaje que se reconoce, tiene como elementos a las constantes
numericas (enteras y reales), los operadores aritmeticos y los parentesis.
El programa lee de teclado, caracter por caracter, y al momento de reconocer un
elemento, lo identifica con un letrero en pantalla. La ejecucion termina cuando
el usuario teclea el simbolo '$'.
Por RMM, para la clase de IMECO.
*/
using namespace std;
#include <iostream>
#include <conio.h>

// Matriz de transiciones
//               dig  op  (     )  raro  esp  .    $
int MT[4][8] = {{1, 101, 105, 106, 200, 0, 200, 107},
				{1, 100, 200, 100, 200, 100, 2, 100},
				{3, 200, 200, 200, 200, 200, 200, 200},
				{3, 100, 200, 100, 200, 100, 200, 100}};

int filtro(char c)
{
	switch (c)
	{
	case '0': case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return 0;
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	case '(':
		return 2;
	case ')':
		return 3;
	case ' ':
	case 13:
		return 5;
	case '.':
		return 6;
	case '$':
		return 7;
	default:
		return 4;
	}
}

main()
{
	char c;
	int edo = 0;
	c = getch();
	cout << c;
	while (c != '$')
	{
		while (edo < 100)
		{
			edo = MT[edo][filtro(c)];
			switch (edo)
			{
			case 100:
				cout << "\nSe reconocio cte." << endl;
				break; // como hay regresion, no lee caracter
			case 101:
				cout << "Se reconocio operador" << endl;
				c = getch();
				cout << c;
				break;
			case 105:
				cout << "Se reconocio (" << endl;
				c = getch();
				cout << c;
				break;
			case 106:
				cout << "Se reconocio )" << endl;
				c = getch();
				cout << c;
				break;
			case 107:
				break;
			case 200:
				cout << "ERROR!" << endl;
				c = getch();
				cout << c;
				break;
			default:
				c = getch();
				cout << c;
			}
		}
		edo = 0; // despues de reconocer token o marcar error, regresa al inicio
	}
	cout << "Fin del analisis" << endl;
}
