#include <stdio.h>
#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/utilidades.h"

void cadastrar(individuo* lista, int index) {
	if (index / 10000000) {
		index %= 1000;
	}

	lista[index].estado = ATIVO;
	lista[index].matricula = (2026 * 10000) + index;

	puts("É doscente?\n");

	switch (input_char_non_canon()) {
	case 's':
		lista[index].eh_doscente = true;

	case 'n':
		lista[index].eh_doscente = false;
	}

	puts("Digite seu nome: ");
	input_string(lista[index].nome, 40);
	puts("\n");

	puts("Digite seu CPF: ");
	scanf_limpo_simples("%d", &lista[index].cpf);

	puts("Digite seu gênero (M - masculino | F - feminino) ");
	lista[index].genero = input_char_non_canon();

	puts("Digite sua data de nascimento (DDMMAA): ");
	scanf_limpo_simples("%d", &lista[index].nascimento);
	puts("\n");

	lista[index].n_disciplinas = 0;
}

