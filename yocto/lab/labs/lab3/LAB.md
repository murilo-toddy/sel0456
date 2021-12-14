# Laboratório 3
---------------

## Criando um patch para o kernel

No laboratório 3, iremos aprender como criar um *patch* para um projeto e como utilizá-lo em nosso kernel padrão. Para isso, iremos rever alguns comandos básicos de Git durante as etapas.

Utilizando tudo o que foi feito nos laboratórios anteriores, vamos utilizar a versão do kernel que está em sua máquina proveniente do download do *build*. Os códigos fontes encontram-se dentro da pasta temporária. No caso do kernel, o caminho é o `tmp/work-shared/qemux86–64/kernel-source`.

    $ cd tmp/work-shared/qemux86–64/kernel-source

Verifique a branch corrente e mude para uma nova a partir dela. **Obs:** verifique a versão do kernel antes com `make kernelversion`.

    $ git branch
    $ git checkout -b lab_sel
    
Vamos fazer uma alteração exemplo. Que tal alterarmos o `arch/x86/kernel/setup.c`? Abra o arquivo e faça as alterações que desejar.

    $ vim arch/x86/kernel/setup.c

Verifique as alterações.

    $ git diff
    diff --git a/arch/x86/kernel/setup.c b/arch/x86/kernel/setup.c
    index 28c89fce0dab..d24c9b66ed46 100644
    --- a/arch/x86/kernel/setup.c
    +++ b/arch/x86/kernel/setup.c
    @@ -817,6 +817,7 @@ void __init setup_arch(char **cmdline_p)
            __flush_tlb_all();
     #else
            printk(KERN_INFO "Command line: %s\n", boot_command_line);
    +       printk(KERN_INFO "Welcome to SEL0456\n");
            boot_cpu_data.x86_phys_bits = MAX_PHYSMEM_BITS;
     #endif
     

Faça o commit das alterações. Utilize o `-s` para mostrar que você é o dono do *patch*.

    $ git commit -as
    
Crie o patch e exclua sua área de trabalho.

    $ git format-patch -1 -o ../../../../
    ../../../../0001-x86_64-simple-change-to-test-Yocto-patch.patch
    $ git checkout v5.10/standard/tiny/base
    $ git branch -D lab_sel

Agora, com o *patch* pronto, vamos criar a nossa receita utilizando a *layer* anterior e mover o arquivo.

    $ mkdir -p ../meta-sel/recipes-kernel/linux/linux-yocto
    $ mv 0001-x86_64-simple-change-to-test-Yocto-patch.patch ../meta-sel/recipes-kernel/linux/linux-yocto/
    
Crie a mesma receita pra versão do kernel utilizada.

    $ vim ../meta-sel/recipes-kernel/linux/linux-yocto_5.10.bb
    
A receita requer apenas a inclusão do patch, bem como a importação da receita base.

    require recipes-kernel/linux/linux-yocto_5.10.bb
    
    SRC_URI += "file://0001-x86_64-simple-change-to-test-Yocto-patch.patch"
    
Hora de executar um novo *build*.

    $ bitbake core-image-minimal
    
Vamos testar novamente com QEMU.

    $ runqemu qemux86-64 nographic kvm
    
Conseguem ver os resultados?
