# escola.c

## cadastrar (WIP)
```
void cadastrar(individuo* lista, int index);
```

Função de retorno vazio que recebe uma lista de alunos e um index da lista para cadastrar.
Desenhado para funcionar em conjunto com **procura_vaga()** para receber o argumento index
de uma vaga vazia ou com **listar_individuo** para atualizar um indivíduo utilizando a sua
matrícula.
Deve informar que não há espaço na lista caso index seja NAO_ATIVO (-1).

Considerando tornar genérica para cadastar disciplinas e indivíduos.

```
	if (index / ANO_ATUAL) {
		index %= ANO_ATUAL;
	}

	lista[index].estado	= ATIVO;
	lista[index].matricula	= index;
```

O código abaixo exemplifica a lógica por trás da função. Caso index seja divido por ANO_ATUAL
(que consiste no ano de 2026 * 100000), significa que o index na verdade referencia a matrícula
de um indivíduo e remove a formatação de matrícula para deixar somente o index 
(index % ANO_ATUAL).

A função então pede input das informações do indivíduo:

É doscente?                     <- Se trata de um professor ou aluno?

Digite seu nome                 <- Coleta nome

Digite seu CPF                  <- Coleta CPF

Digite seu gênero               <- Coleta gênero (M ou F)

Digite sua data de nascimento   <- Coleta data de nascimento

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

A função listar_individuos recebe uma lista de indivíduos, o tamanho da lista e uma função de
ordenação para filtrar a listagem. Retorna vazio.

A magia dessa função é, justamente, a opção de passar (ou não) uma função de ordenação para 
filtrar o output. Um resumo de como a função é:

O tipo ordenar refere a um ponteiro para função de ordenação padrão (É o padrão pra todas as 
funções de ordenação para esse projeto, mais informações em algum dos headers) e é passado para
a função, que então passa um buffer cópia de **lista** e seu respectivo tamanho para que o buffer
seja reorganizado e printado (Isso evita reorganizar desnecessáriamente o objeto original).

Caso não deseje ordenar, é possível passar um ponteiro nulo (NULL) como ponteiro para a função
de ordenação, para indicar que nenhuma função foi passada para **ordenacao**.
O código só executará **ordenacao** caso uma função válida de ordenação (Ou pelo menos algo com
os exatos mesmos parâmetros e tipo que uma função de ordenação) seja passada.

Lista todas as informações de **cadastrar**, com output diferente para o caso de ser um doscente
ou não.

## listar_disciplina

```
void listar_disciplinas(disciplina* lista, size_t tam, ordenar ordenacao);
```

A função listar_disciplinas recebe uma lista de disciplinas, o tamanho da lista e uma função de
ordenação para filtrar a listagem. Retorna vazio.

A mesma coisa que a função acima, exceto que para disciplinas. Lista todas as informações das 
disciplinas, exceto a lista de alunos (será feito em uma função separada).

## ordenar_nascimento (WIP)

```
void ordenar_nascimento(individuo* buff_lista, size_t tam);
```

A função ordenar_nascimento recebe uma lista (buff_lista. Nomeado assim pra indicar que é
para ser passado um buffer. Espero que passe o sentimento adiante) e o tamanho dessa lista.
Retorna vazio.

É praticamente um insertion_sort que ordena os alunos pela data de nascimento. Ainda em trabalho
para garantir a organização por meses e dias, mas a organização por ano está funcional (apesar
de que será remodelada após a adição da struct data no lugar de um int como data de nascimento
dentro da struct individuo).

# utilidades.c

## scanf_limpo_simples

```
void scanf_limpo_simples(char* format, void* variavel);
```

A função scanf_limpo_simples recebe uma string de formatação ("%d" ou "%f") e um ponteiro para
uma única variável. É esperado somente dois argumentos, **format** que indica se é um int ou 
float (Pretenção para adicionar strings pro Código), e **variavel**, que recebe a variável a
receber um valor.
Após receber o valor, faz juz ao "limpo" eu seu nome e limpa o buffer.
Retorna vazio (diferente de scanf que retorna o número de caracteres lidos).

## input_string

```
void input_string(char* string, size_t tam);
```

A função input_string recebe uma string e o seu tamanho e lê a string pela stream **stdin**,
logo em seguida, remove a quebra de linha ('\n') caso haja.
Retorna vazio.

## compara_strins

```
int compara_strings(const char* string1, const char* string2);
```

É só um strcmp (String compare) que retorna 1 (verdadeiro) se as strigs forem iguais.
Retorna inteiros.

## procura_vaga

```
int procura_vaga (void* lista, size_t tam, char tipo);
```

A função procura_vaga recebe uma lista do tipo indivíduo ou disciplina, o tamanho da lista e
um caractere para especificar qual o tipo da lista passada 
('p' = Pessoa (individuo), 'd' = disciplina. Pode ser maiúsculo ou não).

A função procura pelo elemento de estados para saber se o elemento está ATIVO ou não.
Caso encontre algum elemento ATIVO, retorna seu index. Caso não encontre, retorna NAO_ATIVO.
Retorna inteiros.

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

A função input_char_non_canon altera o comportamento do terminal, desativando o modo canônico,
o que permite que inputs sejam lidos por um getchar() sem a necessidade de apertar enter para
enviar o input. Essa função desativa o modo canônico, lê um caractere, reativa o modo canônico e
3 directories, 10 files
Retorna inteiros (Código ASCII).

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
