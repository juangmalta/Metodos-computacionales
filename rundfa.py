import Dfa


archivo = Dfa.openFile("inputs.txt")
mensaje = 'Token' + ' ' * 55 + 'Tipo'
print(mensaje)
for i in range(len(archivo)):
    result = Dfa.lexerAritmetico(archivo[i])
    for j in range(len(result)):
        print(result[j], end="\n")
