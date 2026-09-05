# escola.c

## cadastrar (WIP)
```
void cadastrar(individuo* lista, int index);
```

Recebe uma lista de individuos e o index da lista. Pode receber matrícula em index para utilizar como uma função de atualizar.
Cria um invidíduo. (Professor ou Aluno).


### Coleta de data de nascimento (WIP)

A ideia dessa coleta anteriormente seria somente receber um número formatado em DDMMAA, mas,
para facilitar outras funções, como por exemplo a ordenar_nascimento(), será redesenhada para
receber a data DDMMAA e separar DD MM AA em uma struct data, que recebe Dia, Mês e Ano.

- Exemplo de funcionamento ainda a ser desenhado

# relatorio.c

## lista_individuos

```
void listar_individuos(individuo* lista, size_t tam, ordenar ordenacao);
```

Recebe uma lista de individuos, o tamanho da lista e uma função de ordenação. A função pode ser omitida usando NULL.
Printa as informações dos individuos (Adicionar uma forma de diferenciar doscentes de discentes).

## listar_disciplina

```
void listar_disciplinas(disciplina* lista, size_t tam, ordenar ordenacao);
```

O mesmo que a função acima, mas somente pra disciplinas.

## ordenar_nascimento (WIP)

```
void ordenar_nascimento(individuo* buff_lista, size_t tam);
```

Recebe uma lista de individuos (de preferência ser utilizada dentro de listar_individuos e receber um buffer para 
passar cópia da lista) e o tamanho.

# utilidades.c

## scanf_limpo_simples

```
void scanf_limpo_simples(char* format, void* variavel);
```

A função scanf_limpo_simples recebe uma string de formatação ("%d" ou "%f") e um ponteiro para
uma única variável. É esperado somente dois argumentos, **format** que indica se é um int ou 
float (Pretenção para adicionar strings pro Código), e **variavel**, que recebe a variável a
Retorna vazio (diferente de scanf que retorna o número de caracteres lidos).

Pode receber char também, pois char é uma skin de int de tamanho de 1 byte.
Pensando em criar abstração pra receber caracteres.

## input_string

```
void input_string(char* string, size_t tam);
```

A função input_string recebe uma string e o seu tamanho
Retorna vazio.

## compara_strins

```
int compara_strings(const char* string1, const char* string2);
```

É só um strcmp (String compare) que retorna 1 (verdadeiro) se as strigs forem iguais.
Recebe duas strings.
Retorna inteiros.

## procura_vaga

```
int procura_vaga (void* lista, size_t tam, char tipo);
```

A função procura_vaga recebe uma lista do tipo indivíduo ou disciplina, o tamanho da lista e
um caractere para especificar qual o tipo da lista passada 
('p' = Pessoa (individuo), 'd' = disciplina. Pode ser maiúsculo ou não).

Retorna inteiros ou LISTA_CHEIA se não houver espaço

## destrincha_nascimento (DELETE?)

```
int destrincha_nascimento(int data_nascimento, char DMA);
```

A função destrincha_nascimento recebe uma data de nascimento (DMA) e um char para designar qual
parte da data é desejada como retorno, para então retornar, por exemplo, o dia de um inteiro DMA
passado para a função. Retorna inteiros.
Possívelmente será remodelada / mudada completamente / deletada em função da nova abordagem
para a data de nascimento na struct individuo, por meio da nova struct data.

## input_char_non_canon

```
int input_char_non_canon(void);
```

Retorna inteiros com o valor do ASCII

projeto-escola
│
├── explicando_funcoes.md
├── headers
│   ├── constants.h
│   ├── escola.h
│   ├── relatorio.h
│   └── utilidades.h
├── README.md
└── src
    ├── escola.c
    ├── main.c
    ├── relatorio.c
    └── utilidades.c

 directories, 15 files
