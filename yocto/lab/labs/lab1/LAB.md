# Laboratório 1
---------------

### Configure um build simples

O objetivo desse laboratório é entender um pouco como é possível gerar um *build* simples utilizando Yocto. Como fazer o download dos códigos fonte e projeto, bem como os comandos básicos.

Para isso não utilizaremos hardware real. Faremos uma demonstração simples utilizando QEMU x86_64. É possível utilizar uma arquitetura ARM 64 bits de emulação? Sim, porém levaria mais tempo que o comum devido a compilação cruzada e bibliotecas dependentes.

Primeiro, devemos fazer o download do Poky. Utilizaremos a versão Hardknott (3.3). Lembre-se sempre de fixar essa versão em qualquer *layer* que utilizar.

    $ git clone -b hardknott git://git.yoctoproject.org/poky yocto
    
Feito o download, carregue todo o ferramental do Poky com:

    $ cd yocto
    $ source oe-init-build-env
    
Aqui você verá algumas instruções de arquivos faltantes. Não se preocupa, ele criará automaticamente dos modelos predefinidos. Ainda aqui, ele trocará o diretório corrente para `yocto/build`. Note isso!

Caso você precise fazer alguma alteração local do *build*, utilize o arquivo `conf/local.conf`. Abra ele utilizando algum editor de sua preferência. Aqui utilizarei o **vim**.

    $ vim conf/local.conf
    
Notem algumas variáveis interessantes como o `MACHINE`, o `DISTRO`. Nesse ponto seria bastante interessante você configurar a quantidade de CPU cores utilizados pelo processo. Ainda com o arquivo aberto, adicione ou altere as variáveis:

    # 5 threads no processo de build e compitação com 4.
    BB_NUMBER_THREADS = "5"
    PARALLEL_MAKE = "-j4"

Agora já podemos iniciar o *build* da nossa imagem. Utilizaremos a receita `core-image-minimal` que criará uma imagem minima de boot.

    $ bitbake core-image-minimal
    
Ao término do processo, já é possível testá-la por conta utilizando QEMU.

    $ runqemu qemux86-64 nographic kvm
    
Se você estiver usando a maquina física ou uma máquina virtual, não há a necessodade de utilizar o argumento `nographic`.

Pronto! Até aqui você criou uma imagem mínima utilizando um kernel mínimo e poucas bibliotecas.

Extra: caso você ainda queira gerar uma imagem mais complexa ou utilizando QEMU ARM, basta trocar a variável `MACHINE` e o emulador para `qemuarm`. Além disso, caso você queira gerar uma imagem para algum hardware específico como uma *Raspberry Pi*. Você pode adicionar a BSP *layer*.

    # Ainda em yocto/build
    $ git clone -b hardknott git://git.yoctoproject.org/meta-raspberrypi ../meta-raspberrypi
    $ bitbake-layers add-layer ../meta-raspberrypi/
    
Para verificar que tudo ocorreu corretamente, verifique as *layers*.

    $ bitbake-layers show-layers
    layer                 path                                      priority
    ==========================================================================
    meta                  /home/poky/yocto/meta                     5
    meta-poky             /home/poky/yocto/meta-poky                5
    meta-yocto-bsp        /home/poky/yocto/meta-yocto-bsp           5
    meta-raspberrypi      /home/poky/yocto/meta-raspberrypi         9
    
Por último, lembre-se de alterar a váriável `MACHINE` para o novo *hardware*. Para verificar quais estão disponíveis, você pode consultar as receitas da BSP.

    $ ls ../meta-raspberrypi/conf/machine/ | grep conf
    raspberrypi0.conf
    raspberrypi0-wifi.conf
    raspberrypi2.conf
    raspberrypi3-64.conf
    raspberrypi3.conf
    raspberrypi4-64.conf
    raspberrypi4.conf
    raspberrypi-cm3.conf
    raspberrypi-cm.conf
    raspberrypi.conf
    
Um exemplo seria `MACHINE ??= "raspberrypi3-64"` sem o `.conf`. Caso você ainda queira criar uma imagem para ser diretamente utilizada em um cartão de memória ou HD. Basta alterar o tipo também em `conf/local.conf`. Utilize o valor `rpi-image`.

    IMAGE_FSTYPES = "rpi-sdimg"
    
Pronto, agora você também tem uma imagem para utilizar em sua *Raspberry Pi*.
