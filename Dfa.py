from importlib.metadata import SelectableGroups
from lib2to3.pgen2.token import tok_name
from operator import pos
from turtle import dot

Digitos = '0123456789'
Caracteres = 'abcdefghijklmnñopqrstuvxyzABCDEFGHIJKLMNÑOPQRSTUVXYZ'


class Tokens:
    def __init__(self, toktype_, valor=None):
        self.toktype = toktype_
        self.valor = valor

    def __repr__(self):
        length = len(self.value)
        spaces = ' ' * (60-length)
        return f'{self.valor}{spaces}{self.type}'


class Lexer:
    def __init__(self, archivo):
        self.entrada = {0: 'A', 1: 'N', 2: 'E', 3: '+', 4: '=', 5: '*',
                        6: '-', 7: '/', 8: '^', 9: '(', 10: ')', 11: '_', 12: '.'}
        self.salida = {'': 'Error', 1: 'Resta', 2: 'Entero', 4: 'Real', 5: 'Real', 6: 'Suma', 7: 'Asignacion', 8: 'Multiplicacion',
                       9: 'Division', 10: 'Potencia', 11: 'Variable', 12: 'Parentesis que abre', 13: 'Parentesis que Cierra', 14: 'Comentario'}
        self.transition = {
            0: {'A': 11, 'N': 2, 'E': '', '+': 6, '=': 7, '*': 8, '-': 1, '/': 9, '^': 10, '(': 12, ')': 13, '_': '', '.': 5},
            1: {'A': '', 'N': 2, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            2: {'A': '', 'N': 2, 'E': 3, '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': 5},
            3: {'A': '', 'N': 4, 'E': '', '+': '', '=': '', '*': '', '-': 4, '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            4: {'A': '', 'N': 4, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            5: {'A': '', 'N': 5, 'E': 3, '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            6: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            7: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            8: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            9: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': 14, '^': '', '(': '', ')': '', '_': '', '.': ''},
            10: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            11: {'A': 11, 'N': 11, 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': 11, '.': ''},
            12: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            13: {'A': '', 'N': '', 'E': '', '+': '', '=': '', '*': '', '-': '', '/': '', '^': '', '(': '', ')': '', '_': '', '.': ''},
            14: {'A': 14, 'N': 14, 'E': 14, '+': 14, '=': 14, '*': 14, '-': 14, '/': 14, '^': 14, '(': 14, ')': 14, '_': 14, '.': 14}
        }
        self.archivo = archivo
        self.pos = -1
        self.current_char = None
        self.current_state = 0
        self.final_state = 0
        self.advance()

        def advance(self):
            self.pos += 1
            self.current_char = self.archivo[self.pos] if self.pos < len(
                self.archivo) else None

        def maketok(self):
            tokens = []

            while self.current_char != None:
                token_nuevo = self.traverse_states()
                tokens.append(token_nuevo)
                self.current_state = 0
            return tokens

        def traverse_states(self):
            state_str = ''
            while self.current_state != '' and self.current_char != None:
                if self.current_char == 'E' and (self.current_state == 2 or self.current_state == 5):
                    self.current_state = self.transition[self.current_state][self.input[2]]
                elif self.current_char in Caracteres:
                    self.current_state = self.transition[self.current_state][self.input[0]]
                elif self.current_char in Digitos:
                    self.current_state = self.transition[self.current_state][self.input[1]]
                elif self.current_char == '+':
                    self.current_state = self.transition[self.current_state][self.input[3]]
                elif self.current_char == '=':
                    self.current_state = self.transition[self.current_state][self.input[4]]
                elif self.current_char == '*':
                    self.current_state = self.transition[self.current_state][self.input[5]]
                elif self.current_char == '-':
                    self.current_state = self.transition[self.current_state][self.input[6]]
                elif self.current_char == '/':
                    self.current_state = self.transition[self.current_state][self.input[7]]
                elif self.current_char == '^':
                    self.current_state = self.transition[self.current_state][self.input[8]]
                elif self.current_char == '(':
                    self.current_state = self.transition[self.current_state][self.input[9]]
                elif self.current_char == ')':
                    self.current_state = self.transition[self.current_state][self.input[10]]
                elif self.current_char == '_':
                    self.current_state = self.transition[self.current_state][self.input[11]]
                elif self.current_char == '.':
                    self.current_state = self.transition[self.current_state][self.input[12]]
                
                if self.current_state != '':
                    state_str += self.current_char
                    self.final_state = self.current_state
                    self.advance()                
            if self.output[self.final_state] == 'Error':
                return Tokens(self.output[self.final_state])
            else:
                return Tokens(self.output[self.final_state], state_str)
def lexerAritmetico(archivo):
    lexer = Lexer(archivo)
    tokens = lexer.make_tokens()

    return tokens   
def openFile(texto):
    with open(texto) as archivo:
        texts = []
        for line in archivo:
            txt = line.replace("\n", "")
            texts.append(txt)
    return texts         