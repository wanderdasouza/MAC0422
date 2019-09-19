## Relatório EP1 - MAC0422

<div style="text-align:center"><b>Thiago Santos Teixeira - nUSP 10736987</b></div>

<div style="text-align:center"><b>Wander Souza - nUSP 10737011</b></div>

### Instalação do Minix:

​	O primeiro passo para iniciar esse EP foi a instalação de uma máquina virtual com Minix funcional. Para isso, utilizamos o script oferecido pelos monitores e publicado [aqui](https://www.ime.usp.br/~belinass/mac0422/), que usa QEMU para rodar a máquina virtual.

### 1- Criando a shell

#### O `fork`

​	Para criarmos a shell *`mac422shell`*, nosso primeiro passo foi aprender mais sobre o comando *`fork`*, isso já que rodar comandos na shell principal faria com que, em caso de erro, toda a shell pararia de funcionar, o que não é desejável. 

​	Assim, usamos o *`fork`* para evitar isso, já que sua função é criar um processo similar ao processo pai com um PID (*process ID*) único. Com isso, fizemos com que cada chamada de comando use o fork para ter seu proprio *process block* e PID.

![Imagem relacionada](https://pythontic.com/fork_python.png)

<div style="text-align:center"><i>1-Representação visual do comando fork e seus PIDs</i></div>

#### O *`exec`*

​	Após entender o `fork` e como implementá-lo, nosso próximo passo foi o `exec`. Diferentemente do `fork`, o exec é uma família de comandos, mas decidimos usar o `execve()`, já que recebe o nome de um arquivo, que pesquisará no `$PATH`, e um array de argumentos que serão executados.

​	Para rodar um comando, recebemos o input do usuário e realizamos um `fork`, e chamamos a `execve` no processo filho. Assim, caso a chamada do `execve` seja bem sucedida, ele não dara return e terminara o processo, fazendo com que qualquer linha de código no processo filho que esteja após sua chamada não seja executado.

![Resultado de imagem para fork()](https://i.stack.imgur.com/3JwdZ.png)

<div style="text-align:center"><i>2-Representações visuais do funcionamento do exec e execvp</i></div>

### 2- Parametrizando a proteção de arquivos

Para criar as chamadas `protegepracaramba` e`liberageral`, utilizamos a propria chamada de sistema do Minix: `chmod()`, que recebe o nome do arquivo e um parâmetro de proteção.

### 3- rodeveja() e rode()

#### rodeveja()

​	A ideia principal do `rodeveja` é a mesma da apresentada na imagem 2, ou seja, o `execve` rodando no processo filho, equanto o pai aguarda com o `wait`, fazendo isso, garantimos que chamadas do `rodeveja` funcionassem de maneira correta. 

​	Porém ainda precisávamos imprimir a mensagem de retorno, para isso, colocamos uma condicional e um `printf` no processo pai, para que então fosse impressa apenas no final da execução.

#### rode()

​	Para o `rode` seguimos uma ideia similar à do `rodeveja`, mas com algumas diferenças, a primeira foi que incluímos a linha `close(STDIN_FILENO);`, que fez com que a entrada do teclado fosse monopolizada durante a execução, como desejado. 

​	Além disso, como não podíamos mais usar o `wait`, deixamos apenas a linha `signal(SIGCHLD, SIG_IGN);` para o processo pai, ela serve para que ele receba o sinal de que seu filho foi terminado, deixando assim de acumulá-lo como processo defunto, e portanto evitando que a tabela de processos fique cheia.

​	Para testar o funcionamento do `rode`, como ele não imprime a mensagem de execução, usamos um arquivo `teste` que se encontra na pasta `root` da máquina, ele apenas imprime uma mensagem, espera 5 segundos e imprime novamente.





