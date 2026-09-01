#include <stdio.h>
#include <termios.h>
#include <unistd.h>

typedef struct {
	unsigned int	matricula;
	unsigned int	nascimento;
	unsigned int	cpf;
	char		nome[40];
	char		genero; // F | M
} Aluno;

typedef struct {
	unsigned int	matricula;
	unsigned int	nascimento;
	unsigned int	cpf;
	char		nome[40];
	char		genero; // F | M
} Professor;

typedef struct {
	unsigned int	nascimento;
	Professor*	professor;
	Aluno*		lista_alunos;
	char		nome[40];
	char		codigo[6];
} Disciplina;

int vaga_vazia (void* lista, size_t t, char tipo);
int cadastro_aluno (Aluno* lista, int index);
int cadastro_professor (Professor* lista, size_t t);
int cadastro_disciplina (Disciplina* lista, size_t t);



int vaga_vazia (void* lista, size_t t, char tipo) {
	if (tipo == 'A') {
		Aluno* p = (Aluno*)lista;

		for (int i = 0; i < t; ++i) {
			if (p[i].matricula == 0) {
				return i;
			}
		}
	}

	else if (tipo == 'P') {
		Professor* p = (Professor*)lista;
		
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

int cadastro_aluno (Aluno* lista, int index) {
	if (index == -1) return 1;

	Aluno* x = &lista[index];


	return 0;
}

int cadastro_professor (Professor* lista, size_t t);

int cadastro_disciplina (Disciplina* lista, size_t t);
