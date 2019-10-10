# Relatório EP2- MAC0422

###### Thiago Santos Teixeira - nUSP 10736987

###### Wander Souza - nUSP 10737011

#### Tarefa 1:

​	Para realizar a primeira tarefa do EP, precisávamos criar uma nova fila de prioridade para o MINIX. Pensando nisso, começamos a editar o arquivo header `proc.h`, já que segundo o livro as filas de processos eram definidas seguindo o padrão da seguinte imagem:

![](/home/tst/Imagens/Captura de tela de 2019-10-09 18-54-07.png)

​	A partir dela, começamos a identificar no código os parâmetros que teríamos que alterar para que nossa nova fila tivesse prioridade entre os processos de usuário e o IDLE, que deve ter sempre prioridade mínima (ou seja, a de maior número). Primeiro, alteramos o parâmetro `NR_SCHED_QUEUES` , que recebe a propriedade mínima + 1, ou seja, a quantidade de filas que o sistema terá, e como iremos inserir um novo nível de prioridade, teremos que o incrementar em uma unidade, indo de 16 para 17.

​	O mesmo foi feito com com `IDLE_Q` , que representa o nível do IDLE, que deverá sempre ser o mínimo e então também precisa ser incrementado, mas dessa vez de 15 para 16. Após isso, para definir a nova fila, apenas inserimos a linha `#define BATCH_Q 15`, assim criando uma nova fila com prioridade 15, entre a `MIN_USER_Q`, que é 14 e a do IDLE, que é 16.

#### 

#### Tarefa 2:

