#include <stdio.h>
#include <string.h>
#include <termios.h>
#include "busca_structs.h"


void clean_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void input_string(char* string, size_t t) {
	fgets(string, t, stdin);
	string[strcspn(string, "\n")] = '\0';
}

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
	if (tipo == 'P' || tipo == 'p') {
		Individuo* p = (Individuo*)lista;

		for (int i = 0; i < t; ++i) {
			if (p[i].matricula == 0) {
				return i;
			}
		}
	}

	else if (tipo == 'D' || tipo == 'd') {
		Disciplina* p = (Disciplina*)lista;

		for (int i = 0; i < t; ++i) {
			if (p[i].codigo[0] == '\0') { 
				return i;
			}
		}
	}

	return -1;
}
