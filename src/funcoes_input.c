#include "../headers/funcoes_input.c"
#include <stdio.h>
#include <string.h>
#include <termios.h>


void clean_buffer(void) {
	int c;
	do { c = getchar(); } while (  c!= '\n' && c != EOF );
}

void input_string(char* string, size_t tam) {
	fgets(string, tam, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int input_char_non_canon_non_canon(void) {
	struct termios old_t;
	tcgetattr(STDIN_FILENO, &old_t);
	struct termios new_t;
	new_t.c_lflag &= ~(ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &new_t );

	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t );

	return ch;
}
