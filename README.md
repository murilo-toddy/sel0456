# Desenvolvimento de Software para Sistemas Embarcados com Sistemas Operacionais (SEL0456)

## Aula 1

### Assuntos da aula:

- Discussão sobre licenças de software
- Diferenças entre kernel e sistemas operacionais
- Sistemas operacionais
- Kernel - funções:
    1. gerenciamento de tarefas
    2. comunicação entre processos
    3. gerenciamento de memória

## Aula 2

### Assuntos da aula:

- Instalação Linux: os alunos precisam instalar Linux, pelo menos em uma máquina virtual para poder acompanhar o curso.
- Os alunos precisam abrir uma conta no Github
- Exemplo de arquivo [markdown](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
- [Criação da chave ssh para GitHub](./texto/tutorial_chaves_github.md)
- Commit para o github
- Utilizaremos as linguagens: C, C++ e Python
- Emacs

### Utilizando o Emacs como IDE

Para instalar o Emacs no Ubuntu:

```bash
sudo apt install emacs
```

Infelizmente o Emacs não vem comn as opções habilitadas, e habilitá-las requer um esforço e um tempo muito grande. Felizmente, existem alguns utilitários para isso. Um bom exemplo disso é o [Spacemacs](https://www.spacemacs.org/).
Para instalar o Spacemacs, você pode seguir os passos indicados na web page anterior ou:
  
  ```bash
  cd ~
  git clone https://github.com/syl20bnr/spacemacs ~/.emacs.d
  ```
  
  Aí é só executar o emacs normalmente: 
  
  ```bash
  emacs
  ```
  
  Ele vai perguntar se você prefere o estilo `vim` ou `emacs`. Se você não sabe o que isso quer dizer, escolha `emacs`.
  
  > **Algumas dicas úteis:** pelo fato do Emacs ter sido escrito muito antes do DOS existir, quanto mais do Windows, ele utiliza algumas combinações de teclas pouco familiares aos iniciantes, devido aos diversos modelos de teclados existentes.
  
  > > Quando se quer indicar uma tecla pressionada simultaneamente com a tecla `Control`, por exemplo a tecla `Control` pressionada com a tecla `x`, simultaneamente, indica-se por `C-x`. Para a tecla `Alt` pressionada simultaneamente com uma tecla m, por exemplo, utiliza-se a notação: `M-m`. Em sistemas anteriores ao PC, a tecla `Alt` se chamava `Meta`, por isso o `M-`.
  
  > > A combinação `C-g` é utilizado como `CANCEL`, quando se quer, por exemplo, abortar alguma entrada de texto ou comando.
  
  > > O Emacs usa as teclas de **Cut**, **Copy** e **Paste** diferentes. Para o **Cut**, ele usa `C-w`, para o **Copy**, ele usa `M-w` e para o **Paste**, usa-se C-y. **No entanto**, se você preferir usar `C-x`, `C-c` e `C-v`, você pode escolher a opção `CUA Mode` no menu: `F10`->`Options`->`Use CUA keys`. Para ativar o menu, caso ele não esteja aparecendo, pressione `F10` **ou** `M-x menu-bar-mode`, para deixá-lo permanente. Nessa última opção, a combinação `M-x` irá abrir uma linha de comando para chamar funções internas escrita em `emacs-lisp`, que no caso foi `menu-bar-mode`.
  
  > > Em muitos casos é interessante ativar a barra de ferramentas, com: `M-x tool-bar-mode`.
  
  > > Para se visualizar as opções de comandos pelo menu de teclas, pressione `M-m`, tanto no modo `Emacs` quanto no modo `vim`, ou a tecla `Espaço` no modo `vim`.
  
  Existem muitos guias e tutoriais para o `Emacs` disponíveis na rede. O site oficial é: https://www.gnu.org/savannah-checkouts/gnu/emacs/emacs.html.
  
  Em português: no [IME](https://www.ime.usp.br/~rbrito/texts/emacs.html), [EmacsWiki](https://www.emacswiki.org/emacs/NovatoNoEmacs) e [MIT](http://web.mit.edu/Emacs/source/emacs-23.1/etc/tutorials/TUTORIAL.pt_BR).
  
#### Editando programas em C

Um modo que ajuda muito para programação em C, ou mesmo C++, é através do commando: `M-x semantic-mode` e o `M-x auto-complete-mode`.
  
## Aula 3

### Assuntos da aula:

- Estrutura de programas em C
	- Arquivos de código fonte (.c)
	- Arquivos objeto (.o)
	- Arquivos de cabeçalho (.h)
- Compilador GCC e suas flags
- Makefile:
    Para criação e utilização do makefile no VS Code é necessário instalar uma extensão chamada Makefile Tools.
    Para instalar abra o Quick Open (Ctrl + P) e cole o seguinte comando:
    `ext install ms-vscode.makefile-tools`

## Aula 4

### Assuntos da aula:

- Aplicação dos qualificadores `static`, `volatile`, `register`
- Criação de arquivo `.gitignore`
- Realizando "merge" no repositorio do GitHub
- Utilizando threads
	1. `pthread_create()`
	2. `pthread_join()`
	3. `pthread_exit()`

## Aula 5 (02/09)

### Assuntos da aula:

- Processos: criando processos com `fork` e `exec`
- Usando `man <fcn>` para obter documentação sobre função `<fcn>`
- Uso de semaforo (semaphore.h)
	1. `sem_init()`
	2. `sem_wait()`
	3. `sem_post()`

## Aula 6 (09/09)

### Assuntos da aula:

- [cmake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- argp
- popen
- pipe
- malloc

## Aula 7

### Assuntos da aula 7:

- gdb: rodando direto em linha de comando e rodando com a IDE Emacs
- lib electric-fence (-lefence): melhor detecção falhas de segmentação de memória

```bash
 sudo apt install electric-fence
```

- assert: testar partes do programa na fase de depuração
- esp32: esp-idf

### Instalação do `esp-idf`

Para instalar o IoT Development Framework da Espressif, siga os seguintes passos:

```bash
cd ~
mkdir esp
cd esp
git clone -b v4.3 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
```

O processo de instalação está finalizado nesse ponto.

Pode-se copiar um exemplo, dos vários disponíveis e rodar:

```bash
cd ~
mkdir Code
cd Code
cp -a ~/esp/esp-idf/examples/peripherals/ledc .
cd ledc
. ~/esp/esp-idf/export.sh
```

Para editar o exemplo:
```bash
emacs main/ledc_example_main.c
```

```bash
idf.py menuconfig
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

## Aula 8

### Assuntos da aula

- [Programação Orientada a Objetos](oop1/README.md)
- Exemplo de orientação a objetos em C com opacidade, encapsulamento e integridade. Métodos mínimos: construtor, destrutor, representação em stream e inicializador [range.c](oop1/range.c), [range.h](oop1/range.h) e [oop1/main.c](oop1/main.c)

## Aula 9

### Assuntos da aula

- Programação Orientada a Objetos, utilizando linguagem com suporte a OOP: `C++`
- Exemplo do objeto `range_t` definido em `C` escrito agora em `C++`:
  - sobrecarga de funções e operadores
  - `protected`, `private` e `public`
  - passagem de argumentos por referência &
  - Construtores
  - `cout` e `<<`
  - chamada de código em `C` com `extern "C"`
  - `namespace`
  - `stdlibc++`: `std::`

## Aula 10

### Assuntos da aula

- Repassando alguns conceitos de OOP com `C++`:
  - herança
  - polimorfismo
- Polimorfismo em Python
- Manipulando arquivos de imagem:
  - gparted
  - cfdisk
  - extended filesystem: ext2, ext3 e ext4
  - ntfs
  - vfat ou fat32
  - partições primárias, partição extendida e partições lógicas

## Aula 11

### Assuntos da aula 11

- arquivos de imagens e ferramentas para manipulação desses arquivos no HD local:
  - `dd`: copia blocos de dados binários.
  - `lsblk`: lista os dispositivos de armazenamento do sistema, útil para mostrar a qual *device*  um pen drive foi associado, por exemplo.
  - `truncate`: altera o tamanho de um arquivo no HD, útil para criar um espaço vazio em uma imagem para expandir uma partição ou mesmo criar uma nova partição. Pode também diminuir o tamanho do arquivo, portanto use com atenção para não perder dados.
  - `parted`, `fdisk`, `cfdisk`: ferramentas em modo texto para alterar partições em um dispositivo ou mesmo em um arquivo, da interface mais simples à mais sofisticada.
  - `Disks`: aplicativo GNOME para editar e visualizar partições.
  - `gparted`: aplicativo com boa interface gráfica para editar partições.
  - `losetup`: /dev/loop0...
- estrutura de arquivos do Linux:
  - `/bin` link para `/usr/bin`: executáveis do sistema e aplicativos.
  - `/boot`: onde ficam as imagens do kernel e demais arquivos auxiliares, como as imagens RAM DISK (.rd).
  - `/dev`: arquivos que dão acesso drivers aos dispositivos de hardware conectados no sistema, é gerenciado pelo aplicativo `udev`
  - `/etc`: arquivos de configuração globais dos aplicativos e do sistema
  - `/home`: onde se localizam os diretórios (ou pastas) dos usuários.
  - `/lib`: link para `/usr/lib`
  - /lib32 -> usr/lib32
  - /lib64 -> /usr/lib64
  - /libx32 -> /usr/libx32
  - `/media`: ponto de montagem dos dispositivos de armazenamento removíveis.
  - `/mnt`: ponto de montagem temporário, mais utilizado para manutenção.
  - `/opt`: diretório utilizado para instalação de aplicativos, onde os componentes ficam armazenados juntos, diferentemente da instalação tradicional, onde os arquivos de um aplicativo ficam distribuídos entre `/etc`, `/usr/bin`, `/usr/lib`, `/usr/share`, `/var`, etc.
  - `/proc`: ponto de montagem virtual com informações do estado do sistema.
  - `/run`: ponto de montagem virtual com informações do estado do sistema.
  - `/sbin` -> /usr/sbin
  - `/srv`: ponto de montagem virtual com informações do estado do sistema.
  - `/sys`: ponto de montagem virtual com informações do estado do sistema.
  - `/tmp`: arquivos temporários do sistema, de aplicativos e de usuários, são apagados dependendo das configurações: em cada boot, a cada período de tempo de inatividade, ou se o processo que o gerou finalizou
  - `/usr`: principais:
    - `bin`: executáveis
    - `include`: arquivos de cabeçalho, libc, glib, etc.
    - `lib*`: bibliotecas do sistema e dos aplicativos.
    - `local`: contém os subdiretórios `etc`, `bin`, `lib`, como `usr`, mas para os aplicados gerados e instalados manualmente.
    - `man`: contém a documentação de aplicativos e funções.
    - `sbin`: executáveis do sistema, manutenção e de uso privilegiado, superusuário.
    - `share`: contém dados dos aplicativos.
    - `src`: contém código fonte de aplicativos, bibliotecas e comumente do kernel.
  - `/var`:
    - `cache`: usado para armazenar dados temporários de estado ou de memória.
    - `log`: contém os arquivos de log do sistema e de aplicativos e serviços
    - `lock`: contém arquivos de trava e sincronização entre aplicativos.

## Aula 12

### Assuntos da aula

- Python

## Aula 13

A aula consiste em uma atividade que será realizada pelos alunos. O exercício da aula 13 encontra-se na pasta [exerc-1](./exerc-1), ver [README](./exerc-1/README.md).

## Aula 14

### Análise da atividade da aula anterior.

- **Não reinvente a roda!** Use bibliotecas
- Sempre dê preferência às bibliotecas padrão: um maior número de programadores a usa, com certeza, conferindo maior legibilidade e portabilidade ao seu código; já foram extensamente testadas, apresentando uma probabilidade muito menor de possuírem *bugs*.
- Dominar uma linguagem de programação não se resume à sintaxe e tipos de dados, é essencial saber utilizar a biblioteca padrão da linguagem.

> **Atenção:** *Header files* não são bibliotecas, as bibliotecas são adicionadas na etapa de lincagem (*linker*), e os módulos da biblioteca só serão acrescentados ao executável final caso esses utilizem as funções desses módulos em específico, não apenas pela diretriz #include <arquivo de cabeçalho>. **Biblioteca não é igual a arquivo de cabeçalho!**

Com esses conceitos em mente, refaça o exercício 1 (mas agora na pasta [exerc-2](./exerc-2)), utilizando a [GLIB](https://docs.gtk.org/glib/index.html). Essa pasta contém um código exemplo em [sort.c](./exerc-2/sort.c).

## Aula 15

### Atividade da aula

Refazer a tarefa das aulas anteriores em C++, na pasta exerc-3 e utilizando `cmake`, que já foi criado. Após criar o arquivo `sort.cpp`, utilize:

```bash
$ cmake -B build
```

somente uma vez, após isso, utilize somente:

```bash
$ make -C build
$ build/sort
```

Não se esqueça: utilize a biblioteca padrão C++ [`stdlibc++`](https://gcc.gnu.org/onlinedocs/libstdc++/)!

**Alternativa:** refaça em Python, ou outra linguagem de alto nível.

## Aula 16

### Tema da aula

Crinado interfaces gráficas com Python + [Gtk](https://docs.gtk.org/gtk3/) + [Glade](https://glade.gnome.org/).

O Gtk é a biblioteca base do [GNOME](https://www.gnome.org/) que, a partir da versão 3.39, houve uma alteração na numeração. A versão que deveria ser a 3.40, é a versão 40 e atualmente o GNOME está na versão 41.

Primeiros *widgets*:

1. GtkButton
2. GtkEntry
3. GtkCheckButton
4. GtkLabel

Acessando os *widgets* através de seu Id com o método `get_object()` em Python. Atribuindo sinais aos *widgets*.

### Atividade

Construa um aplicativo que calcule a seção de um fio com base na corrente eficaz que o atravessa. O usuário entra com um valor de corrente e o comprimeto e ele devolve a seção do fio e o fusível indicado. Use também um máximo de queda de tensão de 2,5%. Realize essa atividade na pasta `exerc-4`.

## Aula 17

### Tema da aula: Yocto

## Aula 18

### Tema da aula: Yocto

Veja as atividades propostas para o Yocto ([LAB](yocto/lab/README.md)), tente realizá-las como exercício para entender como funciona a criação de imagens para um SO mínimo.

É bem interessante consultar a [documentação do Yocto](https://docs.yoctoproject.org/brief-yoctoprojectqs/index.html).

## Aula 19

### Tema da aula

Utilizando a interface gráfica `toaster` do Yocto:

Supondo que o diretório que você baixou o yocto seja: `~/yocto`, digite a sequência de comandos abaixo para ativar o `toaster`:

```bash
~/yocto$ virtualenv venv # se não tiver o virtualenv instalado: sudo apt install python3-virtualenv
~/yocto$ source venv/bin/activate
~/yocto$ pip install -r bitbake/toaster-requirements.txt
~/yocto$ source oe-init-build-env
~/yocto/build$ source toaster start
~/yocto/build$ ../bitbake/lib/toaster/manage.py createsuperuser
```

Isso deve iniciar o servidor HTTP no localhost, então abra a página `localhost:8000` em seu navegador.

Para parar o processo `toaster`, use:

```bash
~/yocto/build$ source toaster stop
```

 Os comandos acima (virtualenv, pip, manage.py) devem ser utilizados apenas uma vez, não é necessário utilizar todas as vezes que quiser rodar o `toaster`, exceto pelo comando `venv/bin/activate`, pois o ambiente virtual deve ser ativado, caso não esteja, para que os pacotes Python baixados pelo `pip` fiquem disponíveis. Para isso, basta iniciar o servidor com:
 
 ```bash
 ~/yocto/build$ source toaster start
 ```
 e parar sua execução com:
 
 ```bash
 ~/yocto/build$ source toaster stop
 ```
 
![Screenshot from 2021-11-16 18-34-56](https://user-images.githubusercontent.com/11684801/142069608-e60688e3-7cf6-4f45-8945-7767ee3059bc.png)

## Aula 20

### Assunto da aula

Retomando a atividade de construção de interface gráfica com Gtk+Glade+Python: mais *widgets*:

1. GtkSpinButton
2. GtkAdjustment
3. Janelas de diálogos pré-formatadas como o `GtkFileChooserDialog`, duas formas de ser utilizado: criando pela interface Glade ou construindo diretamente no código.

## Aula 21

Utilizando `GtkMenuBar`e `GtkMenuItem`, aceleradores, sinais e botões de estoque.

Atividade: propor um aplicativo com interface gráfica e implementá-lo na linguagem de sua preferência. Faça o desenvolvimento na pasta `exerc-5`.

## Aula 22

### Assuntos da Aula

**Flask Web Server**

## Aula 23

### Assuntos da Aula

- `app3.py`: enviando dados para o banco de dados;
- arquivo de configuração simples modo texto;
- configurando o *web server* para iniciar com o `systemd`

### Exemplo de arquivo `systemd` com processo com privilégio de usuário


```ini
[Unit]
Description=Web Data Acquisition
After=network.target

[Service]
User=user
Group=user
WorkingDirectory=/home/user/flask-app
ExecStart=/home/user/flask-app/venv/bin/python /home/user/flask-app/flask_app.py
Restart=on-failure

[Install]
WantedBy=multi-user.target
```

Colocar o arquivo acima no diretório `/etc/systemd/system/`, por exemplo sob o nome de `flask-app.service`.

### Exemplo de lançador para o Desktop

Por exemplo, você pode baixar o firefox (do site oficial da Mozila) e descompactá-lo no diretório `/home/user/firefox/` e então, no diretório `/home/user/.local/share/applications`, criar o arquivo `firefox.desktop`, com o seguinte conteúdo:

```ini
[Desktop Entry]
Version=94
Type=Application
Name=Firefox
Exec=/home/user/firefox/firefox
Path=/home/user/firefox/
Terminal=false
StartupNotify=true
Categories=Application;Network;
Icon=/home/user/firefox/browser/chrome/icons/default/default128.png
```

O lançador ficará disponível no *Window Manager*.

> Notem que as variáveis `Exec`, `Path` e `Icon` não tem aspas. A variável `Path` se refere ao diretório de trabalho do aplicativo.

Um lançador para o aplicativo Python+Gtk visto na aula 20, pode ser escrito abaixo:

```ini
[Desktop Entry]
Type=Application
Name=Aplicativo GTK+PYTHON+GLADE
GenericName=Arduino GTK
Comment=Open-source test Glade app
Exec=/home/user/sel0456/aula_20/main.py
Path=/home/user/sel0456/aula_20
Icon=/usr/share/icons/spyder.png
Terminal=false
Categories=Development;IDE;Electronics;
MimeType=text/x-arduino;
Keywords=embedded electronics;electronics;avr;microcontroller;
StartupWMClass=processing-app-Base
```
> Considerando que você clonou o repositório sel0456 no seu "home" e lembre de trocar o `user` pelo seu nome de usuário.
