# Configurando chaves para GitHub (Ubuntu)

A seguir veremos como podemos adicionar chaves ao GitHub com o objetivo de podermos
sicronizar nosso repositorio local com o repositório online.

**1) Gerar novo par de chaves assimetricas**
 
Comando: `ssh-keygen -t ed25519 -C "seu_email_git@exemplo.com"`

 * `-t ed25519` --> Especifica o tipo de algoritimo criptográfico utilizado na geração das chaves
 * `-C "seu_email_git@exemplo.com"` --> Especifica o e-mail associado ao par de chaves. Substituir este exemplo pelo seu e-mail no GitHub
 
Ao executar o comando de geração de chaves acima mencionado serão solicitadas duas informações, sendo ambas de preenchimento opcional: 

Informar o Local de salvamento e nome das chaves: `~/.ssh/GitHub`

Informar senha e repeti-la (caso não queira, pressionar enter)

**2) Verificar se o programa gerenciador do SSH está funcionando em segundo plano**

Comando: `eval "$(ssh-agent -s)"`

Ao executar o comando devemos ver na tela um numero "pid", o que significa que o processo referente ao gerenciador do SSH está funcionando

**3) Adicionar a chave gerada anteriormente no gerenciador do SSH**
 
Comando: `ssh-add ~/.ssh/GitHub`

 * `~/.ssh/GitHub` --> Especifica o local em que as chaves foram salvas
 
**4) Adicionar a chave publica no GitHub**
 
Primeiramente devemos copiar a chave publica que acabamos de gerar.

Comando: `cat ~/.ssh/GitHub.pub`

 * Este comando `cat` imprime na tela o conteudo do arquivo `~/.ssh/GitHub.pub` que foi passado como argumento

Selecionamos a chave publica com o mouse, clicamos com o botão direito do mouse em cima do texto selecionado e depois clicamos em "copiar". [Imagem exemplo.](../img/terminal_copy_pub.png)

Com a chave publica copiada vamos ao GitHub e seguimos o seginte caminho: 

[Settings](https://docs.github.com/assets/images/help/settings/userbar-account-settings.png) -->
[SSH and GPG keys](https://docs.github.com/assets/images/help/settings/settings-sidebar-ssh-keys.png) -->
[New SSH key](https://docs.github.com/assets/images/help/settings/ssh-add-ssh-key.png)

Criar um titulo para sua chave (ex: computador casa, ubuntu, etc) e em seguida colar a chave no campo "key" e clicar em "add SSH key". [Imagem exemplo](https://docs.github.com/assets/images/help/settings/ssh-key-paste.png)

Agora seu computador e o site do GitHub podem se comunicar sem a necessidade de senhas cada vez que quiser sincronizar o seu repositorio local com o online.

DICA: Caso pretenda fazer o upload de alterações no repositorio local para o GitHub (será o caso desta diciplina) você deve clonar o repositorio utilizando o link referente a aba SSH. [Imagem exemplo](../img/aba_SSH.png)
