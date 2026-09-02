#include <stdio.h>
#include "busca_structs.h"
#include <termios.h>
#include <unistd.h>

#define true	1
#define false	0

void input_string(char *string, size_t t);
int input_char();
int procura_vaga (void* lista, size_t t, char tipo);

struct Individuo{
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

int input_char() {
	struct termios old_t;
	tcgetattr(STDIN_FILENO, &old_t);
	struct termios new_t;
	new_t.c_lflag &= ~(ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &new_t );

	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t );

	return ch;
}

int procura_vaga (void* lista, size_t t, char tipo) {
	if (tipo == 'P') {
		Individuo* p = (Individuo*)lista;

		for (int i = 0; i < t; ++i) {
			if (p[i].matricula == 0) {
				return i;
			}
		}
	}

	else if (tipo == 'D') {
		Disciplina* p = (Disciplina*)lista;

		for (int i = 0; i < t; ++i) {
			if (p[i].codigo[0] == '\0') { 
				return i;
			}
		}
	}

	return -1;
}
