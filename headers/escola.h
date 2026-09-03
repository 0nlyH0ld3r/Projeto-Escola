#include "constants.h"
#include <unistd.h>

#ifndef _BASE_PROJECT
	#define _BASE_PROJECT

	// Struct do invidivuo: pode ser tanto professor quanto aluno
	typedef struct Individuo individuo; ///MUDAR NOME DA TYPEDEF

	// Struct das disciplinas
	typedef struct Disciplina disciplina;


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
