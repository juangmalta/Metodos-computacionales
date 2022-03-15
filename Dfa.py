# Colección de digitos y caracteres

Digitos = '0123456789'
Caracteres = 'abcdefghijklmnñopqrstuvxyzABCDEFGHIJKLMNÑOPQRSTUVXYZ'


class Tokens:
    def __init__(self, tipotok_, valor=None):  # Tokens basicos
        self.tipotok = tipotok_
        self.valor = valor

    def __repr__(self):  # Formato
        largo = len(self.valor)
        espacio = ' ' * (60-largo)
        return f'{self.valor}{espacio}{self.tipotok}'


class Lexer:
    def __init__(self, archivo):
        self.entrada = {0: 'Aa/Zz', 1: '0-9', 2: 'E', 3: '+', 4: '=', 5: '*',
                        6: '-', 7: '/', 8: '^', 9: '(', 10: ')', 11: '_', 12: '.'}  # diccionario de entradas
        self.salida = {'': 'Error', 1: 'Resta', 2: 'Entero', 4: 'Flotante', 5: 'Flotante', 6: 'Suma', 7: 'Asignacion', 8: 'Multiplicacion',
                       9: 'Division', 10: 'Potencia', 11: 'Variable', 12: 'Parentesis que abre', 13: 'Parentesis que Cierra', 14: 'Comentario'}  # diccionario de salidas
        self.tablaTransciciones = { 
            # Tabla de transiciones Creada con la asesoria de Adrian Becerra
            0: {'Aa/Zz': 11, '0-9': 2, 'E': '', '+': 6, '=': 7, '*': 8, '-': 1, '/': 9, '^': 10, '(': 12, ')': 13, '_': '', '.': 5},
            1: {'Aa/Zz': '', '0-9': 2, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            2: {'Aa/Zz': '', '0-9': 2, 'E': 3, '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': 5},
            3: {'Aa/Zz': '', '0-9': 4, 'E': '', '+': '', '=': '', '*': '', '-': 4, '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            4: {'Aa/Zz': '', '0-9': 4, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            5: {'Aa/Zz': '', '0-9': 5, 'E': 3, '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            6: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            7: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            8: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            9: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': 14, '^': '', '(': '', ')': '', '_': '', '.': ''},
            10: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            11: {'Aa/Zz': 11, '0-9': 11, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': 11, '.': ''},
            12: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            13: {'Aa/Zz': '', '0-9': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            14: {'Aa/Zz': 14, '0-9': 14, 'E': 14, '+': 14, '=': 14, '*': 14, '-': 14, '/': 14, '^': 14, '(': 14, ')': 14, '_': 14, '.': 14}
        }
        self.archivo = archivo  # metodos
        self.pos = -1
        self.caracterAct = None
        self.EstadoAct = 0
        self.EstadoFinal = 0
        self.siguiente()

    def siguiente(self):  # siguiente caracter
        self.pos += 1
        self.caracterAct = self.archivo[self.pos] if self.pos < len(
            self.archivo) else None

    def creartoks(self):  # crea un token con la informacion dada por la tabla con el caracter actual
        tokens = []

        while self.caracterAct != None:
            token_nuevo = self.conexiones()
            tokens.append(token_nuevo)
            self.EstadoAct = 0
        return tokens

    def conexiones(self):  # Crea la conexion entre los estados
        state_str = ''
        while self.EstadoAct != '' and self.caracterAct != None:
            if self.caracterAct == 'E' and (self.EstadoAct == 2 or self.EstadoAct == 5):
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[2]]
            elif self.caracterAct in Caracteres:
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[0]]
            elif self.caracterAct in Digitos:
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[1]]
            elif self.caracterAct == '+':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[3]]
            elif self.caracterAct == '=':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[4]]
            elif self.caracterAct == '*':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[5]]
            elif self.caracterAct == '-':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[6]]
            elif self.caracterAct == '/':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[7]]
            elif self.caracterAct == '^':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[8]]
            elif self.caracterAct == '(':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[9]]
            elif self.caracterAct == ')':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[10]]
            elif self.caracterAct == '_':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[11]]
            elif self.caracterAct == '.':
                self.EstadoAct = self.tablaTransciciones[self.EstadoAct][self.entrada[12]]

            if self.EstadoAct != '':
                state_str += self.caracterAct
                self.EstadoFinal = self.EstadoAct
                self.siguiente()
        if self.salida[self.EstadoFinal] == 'Error':
            return Tokens(self.salida[self.EstadoFinal])
        else:
            return Tokens(self.salida[self.EstadoFinal], state_str)


# Combina lo que hay en el archivo con las funciones anteriores
def lexerAritmetico(archivo):
    lexer = Lexer(archivo)
    tokens = lexer.creartoks()

    return tokens


def openFile(texto):  # Abre el archivo de texto
    with open(texto) as archivo:
        texts = []
        for line in archivo:
            txt = line.replace("\n", "")
            texts.append(txt)
    return texts


archivo = openFile("inputs.txt")  # archivo deseado
mensaje = 'Token' + ' ' * 55 + 'Tipo'  # header de la tabla
print(mensaje)
for i in range(len(archivo)):
    result = lexerAritmetico(archivo[i])
    for j in range(len(result)):
        print(result[j], end="\n")  # impresion de resultados
