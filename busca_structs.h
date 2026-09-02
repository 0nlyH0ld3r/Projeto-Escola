#include <unistd.h>

// Definindo macros para true e false caso não estejam definidas
// usando #ifndef (if not defined).
#ifndef true 
	#define true 1 
#endif

#ifndef false
	#define false	0
#endif

#ifndef VAGA_LIVRE
	#define VAGA_LIVRE	-2
#endif

#ifndef SEM_VAGA 
	#define SEM_VAGA	-1 
#endif

#ifndef HORARIO_VAGO
	#define HORARIO_VAGO	'\0'
#endif

#ifndef TIPO_INVALIDO
	#define TIPO_INVALIDO	-2
#endif

// Struct do invidivuo: pode ser tanto professor quanto aluno
typedef struct Individuo Individuo; 

// Struct das disciplinas
typedef struct Disciplina Disciplina;

/** @brief: Limpa o buffer de escrita para remover o caractere '\n' que remanece após certas funções.
 *
 *	@par Exemplo:
 *	scanf("%d", &x);
 *	clean_buffer();
 *
 *	@par @warning:
 *  Se utilizada após funções que não abandonem o '\n', irá travar o código até que algum input seja fornecido,
 *  tal qual um getchar() comum.
 */
void clean_buffer(void);


/** @brief Recebe string do usuário t e remove o caractere de nova linha \n do final da string.
 *
 *	@par Exemplo:
 *	input_string(string, 20);
 *
 * @param? string	<- Ponteiro pra string que irá receber a entrada.
 * @param: t		<- Tamanho máximo de string.
 *
 */
void input_string(char *string, size_t tam);


/** @brief: Recebe um caractere, tal qual o getchar(). Entretanto, sem a necessidade de apertar enter pra enviar o caractere.
 *	@par Exemplo: 
 *	char variavel = input_char();
 *
 *	@par @note:
 * Desativa o buffer de linha temporariamente para ler um caractere sem o enter para enviar o input.
 *
 */
int input_char(void);

/** @brief: Encontra espaço vazio em uma lista de tamanho t
 *
 *	@par Exemplo: 
 *	int vaga_livre = procura_vaga(lista_aluno, 40, 'P');
 *	int vaga_professor = procura_vaga(lista_professore, 10, 'P');
 *	int horario_livre = procura_vaga(lista_disciplinas, 6, 'D');
 *
 *
 * @param: lista - Ponteiro para a lista (Individuo ou Disciplina).
 * @param: tipo - Tipo da lista ('P' para individuo e 'D' para disciplina).
 * @param: t - Tamanho máximo da lista
 *
 * @return: Index do espaço vazio em sucesso, SEM_VAGA se não houver vaga, TIPO_INVALIDO se *tipo* não for 'P' ou 'D'.
 *
 * @par @note:
 * Verifica um vetor (lista) de tamanho fornecido pelo código (tam) procurando por, caso seja um
 * indivíduo, a sua matrícula, caso seja uma disciplina, o seu código (checa se o primeiro caractere é um \0 ou não).
 *
 * @par @note
 * O objetivo dessa função é retornar o index para um vetor que conterá: Alunos, Professores ou Disciplinas para que
 * possa ser cadastrado um novo item para o vetor. Caso o vetor esteja cheio (sem espaço para cadastro), irá retornar a
 * macro de vetor cheio e caso o tipo seja especificado incorretamente, irá retornar a macro de tipo inválido.
 *
 * @par @note
 * A função busca, para o tipo indivíduo, um valor de matrícula == VAGA_LIVRE (0) e, para o tipo disciplina, busca o
 * valor codigo[0] == HORARIO_VAGO (\0)  (Busca o primeiro caractere como um NULL Terminator). Esses são os critérios
 * para determinar se há ou não espaço para um novo Aluno/Professor ou Disciplina
 */
int procura_vaga(void* lista, size_t tam, char tipo);

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
