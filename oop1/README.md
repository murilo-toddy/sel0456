# Programação Orientada a Objetos

- A linguagem que utilizada para resolver um problema tem grande impacto na forma de resolução do problema.

## Alguns equívocos que devem ser evitados:

- É uma técnica de programação e é independente da linguagem, por exemplo: usar linguagens como *C++*, *Smaltalk*, *C#*, *Objective-C*, *Go*, *Python*, *Java*, etc., não garante uma programação orientada a objetos, nem tampouco utilizar linguagens com pouco suporte garante uma programação sem nenhuma orientação a objetos.
- *Programação Orientada a Objetos* não é o oposto a *Programação Estruturada*, essas técnicas coexeistem em um programa. *Programação Estruturada* é oposta à *Programação Não Estruturada*.
- **Nem todos os problemas do mundo são melhor resolvidos com uma única técnica de programação:** o programador deve ter o *bom senso* de identificar a melhor técnica para o seu problema.
- *C++* não é uma "evolução" de C, mas sim uma linguagem própria. Foi uma tentativa de adicionar maior suporte à programação orientada a objetos na sintaxe conhecida de C, com seus operadores e sua sintaxe *peculiares*.
- Talvez o melhor exemplo de programa feito em C que usa OOP seja o GTK que usa todo sistema do [GObject](https://developer.gnome.org/gobject/stable/gobject-The-Base-Object-Type.html).
- A primeira linguagem orientada a objetos que foi oficialmente padronizada foi *ANSI Common Lisp* (1994, ANSI X3J13)
- A primeira linguagem que teve como objetivo um suporte maior à Orientação a Objetos foi *Simula* (em 1966).

## Principais conceitos de Programação Orientada a Objetos:

- Classes/Abstração
- Encapsulamento
- Protocolos/APIs
- Herança
- Polimorfismo

## Interesse em *C++*:

- Syntaxe conhecida (*C*).
- Fácil integração com códigos já escritos em *C*, como bibliotecas, etc.
- Não é tão *RAM hungry* quanto outras linguages modernas, como *Common-LISP*, *Python*, *Java*, etc.

# Armadilhas de *C++* (e de POO)

- Excesso de hierarquização (Heranças) excessivas (exemplo em C: GTK 2.XX).
- Tornar as abstrações desnecessariamente excessivas.
- Utilização de *Orientação a Objetos* desnecessárias.
- Uso do operador referência pode trazer a problemas difíceis de se identificar.
- Multiplas heranças sem necessidade.
- Sobrecarga de operadores indiscriminadamente pode tornar o programa ilegível.
- ...

