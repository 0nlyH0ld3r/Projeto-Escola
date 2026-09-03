#include "constants.h"
#include <unistd.h>

#ifndef _BASE_PROJECT
	#define _BASE_PROJECT

	// Struct do invidivuo: pode ser tanto professor quanto aluno
	typedef struct Individuo individuo; ///MUDAR NOME DA TYPEDEF

	// Struct das disciplinas
	typedef struct Disciplina disciplina;


	/** @brief Encontra espaço vazio em uma lista de tamanho t
	 *
	 * @param lista - Ponteiro para a lista (Individuo ou Disciplina).
	 * @param tipo - Tipo da lista ('P' para individuo e 'D' para disciplina).
	 * @param t - Tamanho máximo da lista
	 *
	 * @return Index do espaço vazio em sucesso, SEM_VAGA se não houver vaga, TIPO_INVALIDO se *tipo* não for 'P' ou 'D'.
	 *
	 * @par @note
	 * Verifica um vetor (lista) de tamanho fornecido pelo código (tam) procurando por, caso seja um
	 * indivíduo, a sua matrícula, caso seja uma disciplina, o seu código (checa se o primeiro caractere é um \0 ou não).
	 *
	 * @par @note
	 * O objetivo dessa função é retornar o index para um vetor que conterá: Alunos, Professores ou Disciplinas para que
	 * possa ser cadastrado um novo item para o vetor. Caso o vetor esteja cheio (sem espaço para cadastro), irá retornar a
	 * macro de vetor cheio e caso o tipo seja especificado incorretamente, irá retornar a macro de tipo inválido.
	 * A função busca, para o tipo indivíduo, um valor de matrícula == VAGA_LIVRE (0) e, para o tipo disciplina, busca o
	 * valor codigo[0] == HORARIO_VAGO (\0)  (Busca o primeiro caractere como um NULL Terminator). Esses são os critérios
	 * para determinar se há ou não espaço para um novo Aluno/Professor ou Disciplina
	 *
	 */
	int procura_vaga(void* lista, size_t tam, char tipo);
	void listar_individuos(individuo* lista, size_t tam);
	void listar_disciplinas(disciplina* lista, size_t tam);

	struct Individuo {
		char		nome[MAX_CARACTERE_NOME];		// Nota: Não tentem escrever nada por cima disso.
		disciplina*	disciplinas[MAX_DISCIPLINAS];	// Lista de disciplinas do individuo.
		unsigned int	n_disciplinas;	// Número de disciplinas do individuo.
		unsigned int	matricula;	// Matrícula. Também usa pro professor.
		unsigned int	nascimento;	// Data de nascimento no padrão DDMMYY.
		unsigned int	cpf;		// CPF do indivíduo.
		char		genero;		// F | M  -> Feminino | Masculino.
		char		eh_doscente;	// true -> Professor | false -> Aluno.
		char		estado;		// NAO_ATIVO <- Vaga livre pra uso
		
	};


	struct Disciplina {
		char		nome[MAX_CARACTERE_NOME];		// Nome da disciplina.
		char		codigo[MAX_CHAR_COD_DISCIPLINA];		// Código da disciplina. Ex: INF029
		individuo*	professor;	// Ponteiro para Professor responsável
		individuo*	lista_alunos[MAX_NUMERO_ALUNOS];	// Lista de alunos matriculados
		char		estado;		// NAO_ATIVO <- Vaga livre pra uso
	};

#endif
