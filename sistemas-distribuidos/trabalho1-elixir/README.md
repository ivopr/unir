# **Elixir**: A História
##  *Bogdan/Björn’s Erlang Abstract Machine (BEAM)*
Assim como Java é executado em uma *Java Virtual Machine*, todo código Erlang/Elixir é executado em uma instância *BEAM*. Essa máquina virtual é a responsável pela paralelização da linguagem e é o núcleo da Plataforma Aberta de Telecomunicações Erlang (OTP).

## *Plataforma Aberta de Telecomunicações Erlang (OTP)*
É um conjunto de bibliotecas Erlang, que consiste no *Erlang Runtime System* (ERTS), uma série de componentes prontos para uso escritos principalmente em Erlang e um conjunto de princípios de design para programas Erlang.

É o que provê módulos e comportamentos que representam implementações padrão de práticas comuns como supervisionamento de processos, passagem de mensagens, invocação de tarefas e várias outras. 

## *Erlang Runtime System (ERTS)*
É o responsável por compilar códigos Erlang e Elixir em *bytecode*, possibilitando que códigos Elixir possam chamar códigos Erlang e vice versa. Vale notar que o BEAM é uma parte do ERTS.

O Runtime do Elixir é uma instância BEAM. Assim que a compilação termina, o processo do sistema inicia e o Erlang "sequestra" o controle total. Tudo é executado dentro desse processo.

## *Scheduler* (Agendador)
Uma instância BEAM é iniciada em um único processo do sistema operacional, onde para cada CPU disponível é criada uma *Thread*, tornando sistemas Erlang escaláveis uma vez que aproveitam todos os núcleos livres.

O BEAM é responsável por agendar os processos Erlang. Cada *Thread* executa exatamente um Agendador, que é responsável por popular a fila de processos Erlang, além de removê-los da fila e alocar um espaço de tempo para sua execução.

## Processos Erlang
O Erlang em si não possui *Threads*, mas sim processos, chamados de Procesos Erlang. Não confundir com Processos do Sistema Operacional.

Geralmente um sistema Erlang executa milhões desse tipo de processo. Eles possuem apenas acesso à sua própria memória, eles não compartilham essa memória entre si, também não existe uma memória global para ser compartilhada entre eles. Como eles não compartilham suas memórias, a falha de um desses processos não representa um risco de falha total no sistema.

Isso quer dizer que eles não se comunicam? Eles se comunicam sim, através de mensagens. Um processo não tem acesso aos dados de outro processo a não ser que esse outro processo os envie uma cópia de seus dados através de uma mensagem. Cada processo tem uma fila de mensagens para gerenciar o envio e recebimento delas.

## *Simultaneidade/Paralelismo*
Que o BEAM é o responsável pelo agendamento de tarefas a gente já sabe, o que a gente não sabe é que ele faz isso MUITO rápido, e MUITAS vezes.

Cada processo ao ser movido da fila para a execução, é dado um tempo para sua execução, se ele ultrapassa esse tempo, o BEAM pausa ele e o retorna para a fila, e trabalha no próximo processo agendado (Isso é chamado de **Preempção** (***Saudades Borges***)). Dessa forma o BEAM consegue executar processos Erlang de forma paralela ao fazer essa troca muito rápida de processos na fila e executando.

Para fins de simultaneidade, o Erlang BEAM fornece mecanismos de suspensão e agendamento. Um processo de suspensão armazena seu estado atual em seu registro de suspensão e é adicionado a uma fila do agendador. Para garantir uma programação justa, um processo é suspenso após um número fixo de reduções e, em seguida, o primeiro processo da fila é retomado.


# **Elixir**: A Parte Divertida
## Instalação
- MacOS
  - Hombrew: `brew install elixir`
  - Macports: `sudo port install elixir`
- Linux
  - Arch Linux: `sudo pacman -S elixir`
  - Ubuntu/Debian:
    - Adicione o repositório: `wget https://packages.erlang-solutions.com/erlang-solutions_2.0_all.deb && sudo dpkg -i erlang-solutions_2.0_all.deb`
    - Atualize os pacotes disponíveis: `sudo apt update`
    - Instale o **Erlang OTP**: `sudo apt install esl-erlang`
    - Instale o Elixir: `sudo apt install elixir`
  - Windows
    - Utilize o [instalador](https://github.com/elixir-lang/elixir-windows-setup/releases/download/v2.2/elixir-websetup.exe)
    - ou utilize o `Chocolatey`: `cinst elixir`

## Tipos Básicos

| **Valor**    |   **Tipo**   |
|:------------ |:------------ |
| 1            | int          |
| 0x1F         | int          |
| 1.0          | float        |
| :apple       | atom         |
| true         | boolean      | 
| "elixir"     | string       |
| [1, 2, 3]    | list         |
| {1, 2, 3}    | tuple        |

## Operações Básicas
#### Soma
```elixir
iex> 1 + 2
3
iex> 1.3 + 2
3.3
```

#### Subtração
```elixir
iex> 1 - 2
-1
iex> 1.5 - 2
-0.5
```

#### Multiplicação
```elixir
iex> 1 * 2
2
iex> 1.5 * 2
3.0
```

#### Divisão
```elixir
iex> 1 / 1
1.0
iex> 2.5 / 3
0.8333333333333334
```
Na operação de divisão, independente se ambas as entradas são `int`, o resultado sempre será `float`. Para divisão de `int` com resultado `int` temos a seguinte função:
```elixir
iex> div(1,1)
1
```
E para encontrar o resto da divisão temos essa outra função:
```elixir
iex> rem(5,2)
1
```

## Reconhecimento de números binários, octais e hexadecimais
O Elixir é capaz de reconhecer, ou melhor, converter valores binários, octais e hexadecimais para valores decimais por padrão.

Para valores em binário basta acrescentar `0b` antes do valor em binário:
```elixir
iex> 0b0011
3
```
Para valores em octal, basta acrescentar `0o` antes do valor em octal:
```elixir
iex> 0o007
7
```
Para números em hexadecimal, basta acrescentar `0x` antes do valor em hexadecimal:
```elixir
iex> 0x123
291
```

