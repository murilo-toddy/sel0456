# Laboratório 2
---------------

## Criando sua própria layer com seu app

Nesse segundo laboratório, iremos criar uma *layer* e modificá-la para incluir nosso aplicativo dentro do *build* para QEMU. Nesse exmeplo utilizaremos uma aplicação bem simples chamada `sl`.

Primeiramente, vamos listar quais *layers* estão disponíveis no nosso *build*.

    $ cd yocto/
    $ source oe-init-build-env
    $ bitbake-layers show-layers
    layer                 path                                      priority
    ==========================================================================
    meta                  /home/poky/yocto/meta                     5
    meta-poky             /home/poky/yocto/meta-poky                5
    meta-yocto-bsp        /home/poky/yocto/meta-yocto-bsp           5
    
**Opcional:** se vc adicionou a *layer* extra do laboratório anterior, lembre-se de reverter as alterações feitas para *Raspberry Pi* se for seu caso. Para remover a *layer* existe também um comando específico.

    $ bitbake-layers remove-layer meta-raspberrypi
    
Agora, vamos criar a nossa própria.

    $ bitbake-layers create-layer ../meta-sel --priority 6
    
E então adicioná-la nas nossas configurações.

    $ bitbake-layers add-layer ../meta-sel
    
Confirme, listando as *layers*.

    $ bitbake-layers show-layers
    layer                 path                                      priority
    ==========================================================================
    meta                  /home/poky/yocto/meta                     5
    meta-poky             /home/poky/yocto/meta-poky                5
    meta-yocto-bsp        /home/poky/yocto/meta-yocto-bsp           5
    meta-sel              /home/poky/yocto/meta-sel                 6
    
Vamos criar nossa primeira receita.

    $ mkdir -p ../meta-sel/recipes-sl/sl/
    $ vim ../meta-sel/recipes-sl/sl/sl_5.02.bb
    
Na nossa primeira receita definida em `sl_5.02.bb`, percebam as variáveis `SRC_URI` e as seções `do_compile` e `do_install`.

    DESCRIPTION = "SL(1): Cure your bad habit of mistyping"
    SECTION = "console/utils"
    LICENSE="GPLv3"
    LIC_FILES_CHKSUM = "file://LICENSE;md5=74e9dd589a0ab212a9002b15ef2b82f0"
    
    # sl depends on ncurses package
    DEPENDS = "ncurses"
    
    SRCREV = "923e7d7ebc5c1f009755bdeb789ac25658ccce03"
    SRC_URI = "git://github.com/mtoyoda/sl.git"
    
    S = "${WORKDIR}/git"
    
    TARGET_CC_ARCH += "${LDFLAGS}"
    
    do_compile() {
             # make is broken
             ${CC} ${CFLAGS} -o sl ${S}/sl.c ${LDFLAGS} -I${STAGING_DIR_TARGET}/${libdir}/ncurses/ -lncurses
    }
    
    do_install() {
             install -d ${D}${bindir}
             install -m 0755 sl ${D}${bindir}
    }
    
Com a receita criada, é hora de adicionar o binário na composição da imagem. Crie os arquivos que irão estender as configurações do *build*.

    $ mkdir -p ../meta-sel/recipes-core/images
    $ vim core-image-minimal.bb
    
Então, inclua a seguinte linha no arquivo.

    IMAGE_INSTALL += " sl"
    
Hora de testar novamente.

    $ bitbake core-image-minimal
    
Execute o QEMU e teste o aplicativo `sl`.

    $ runqemu qemux86-64 nographic kvm
    
Voilà!
