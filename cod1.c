#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define true	1
#define false	0

// Declaração de disciplinas.
typedef struct Individuo Individuo; 
typedef struct Disciplina Disciplina;

void input_string(char *string, size_t t);
int input_char();
int procura_vaga (void* lista, size_t t, char tipo);
int cadastro (Individuo* lista, int index);
int cadastro_disciplina (Disciplina* lista, size_t t);

struct Individuo{
	char*		nome;		// Nota: Não tentem escrever nada por cima disso.
	Disciplina*	disciplinas;
	unsigned int	matricula;
	unsigned int	nascimento;
	unsigned int	cpf;
	unsigned int	n_disciplinas;	// Número de disciplinas do individuo;
	char		genero;		// F | M
	char	eh_doscente;
	
};

struct Disciplina {
	char*		nome;
	char*		codigo;
	Individuo*	professor;
	Individuo*	lista_alunos;
	unsigned int	nascimento;
};

int input_char() {
	struct termios old_t;
	tcgetattr(STDIN_FILENO, &old_t);
	struct termios new_t;
	new_t.c_lflag &= ~(ICANON | ECHO);

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

int cadastro_aluno (Individuo* lista, int index) {
	if (index == -1) return 1;

	Individuo* x = &lista[index];
	x->nome = "Bruno"; 


	return 0;
}

int cadastro_professor (Individuo* lista, size_t t);

int cadastro_disciplina (Disciplina* lista, size_t t);
