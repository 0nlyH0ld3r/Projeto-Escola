#include <unistd.h>

// Definindo macros para true e false caso não estejam definidas
// usando #ifndef (if not defined).
#ifndef true 
	#define true 1 
#endif

#ifndef false
	#define false	0
#endif

// Struct do invidivuo: pode ser tanto professor quanto aluno
typedef struct Individuo Individuo; 

// Struct das disciplinas
typedef struct Disciplina Disciplina;

// Função para limpar o buffer de input após outras funções como o scanf() que largam '\n' para trás
void clean_buffer();

// Recebe uma string e seu tamanho máximo, apaga o '\n'
void input_string(char *string, size_t t);

// Recebe input com ICANON desativado. Input é aceito sem apertar o enter. Retorna o ASCII do caracter.
int input_char();

// Recebe ponteiro pra uma lista e o tamanho máximo dela, junto com um tipo 'P' -> Pessoa ou 'D' -> Disciplina
// Retornar o index da lista onde há uma vaga disponível. Se não há, retorna -1.
int procura_vaga (void* lista, size_t t, char tipo);

struct Individuo {
	char*		nome;		// Nota: Não tentem escrever nada por cima disso.
	Disciplina*	disciplinas;	// Lista de disciplinas do individuo.
	unsigned int	n_disciplinas;	// Número de disciplinas do individuo.
	unsigned int	matricula;	// Matrícula. Também usa pro professor.
	unsigned int	nascimento;	// Data de nascimento no padrão DDMMYY.
	unsigned int	cpf;		// CPF do indivíduo.
	char		genero;		// F | M  -> Feminino | Masculino.
	char		eh_doscente;	// true -> Professor | false -> Aluno.
	
};

struct Disciplina {
	char*		nome;		// Nome da disciplina.
	char*		codigo;		// Código da disciplina. Ex: INF029
	Individuo*	professor;	// Ponteiro para Professor responsável
	Individuo*	lista_alunos;	// Lista de alunos matriculados
};
