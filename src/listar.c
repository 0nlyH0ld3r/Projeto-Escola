#include <stdio.h>
#include "../headers/base_projeto.h"

void listar_individuos(individuo* lista, size_t tam) {
	for (int i = 0; i < tam; ++i) {
		if (lista[i].matricula == VAGA_LIVRE) continue;

		if (lista[i].eh_doscente == true)	printf("Professor: %s", lista[i].nome);
		else					printf("Aluno: %s", lista[i].nome);

		printf("CPF: %d\n", lista[i].cpf);
		printf("Data de Nascimento: %d %d %d",	(lista[i].nascimento / 10000),
							((lista[i].nascimento % 10000) / 100), 
							(lista[i].nascimento % 100) );
		printf("Gênero: %s\n", lista[i].genero == 'M' ? "Masculino" : "Feminino");
		printf("Matricula: %d\n", lista[i].matricula);
		printf("Número de disciplinas: %d\n", lista[i].n_disciplinas);
		puts("\n\n");
	}
}

void listar_disciplinas(disciplina* lista, size_t tam) {
	for (int i = 0; i < tam; ++i) {
		if (lista[i].codigo[0] == VAGA_LIVRE) continue;
		printf("Nome da disciplina: %s\n", lista[i].nome);
		printf("Professor: %s",	lista[i].professor->nome);
		printf("Gênero: %s\n", lista[i].codigo);
		puts("\n\n");
	}
}
