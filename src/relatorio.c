#include <stdio.h>
#include <string.h>
#include "../headers/escola.h"
#include "../headers/utilidades.h"
#include "../headers/relatorio.h"

void listar_individuos(individuo* lista, size_t tam, ordenar ordenacao) {
	individuo buff_lista[tam];	// Buffer para o sort da função ordenacao
	memcpy(buff_lista, lista, sizeof(individuo) * tam); // Copia os dados de lista em buff_lista

	if (ordenacao != NULL) ordenacao(buff_lista, tam); // Passar NULL caso não deseje ordenar

	for (int i = 0; i < tam; ++i) {
		if (buff_lista[i].estado == NAO_ATIVO) continue;

		if (buff_lista[i].eh_doscente == true)	printf("Professor: %s", buff_lista[i].nome);
		else					printf("Aluno: %s", buff_lista[i].nome);

		printf("CPF: %d\n", buff_lista[i].cpf);
		printf("Data de Nascimento: %d %d %d",	(buff_lista[i].nascimento / 10000),
							((buff_lista[i].nascimento % 10000) / 100), 
							(buff_lista[i].nascimento % 100) );

		printf("Gênero: %s\n", buff_lista[i].genero == 'M' ? "Masculino" : "Feminino");
		printf("Matricula: %d\n", buff_lista[i].matricula);
		printf("Número de disciplinas: %d\n", buff_lista[i].n_disciplinas);
		puts("\n\n");
	}
}


void listar_disciplinas(disciplina* lista, size_t tam, ordenar ordenacao) {
	individuo buff_lista[tam];	// Buffer para o sort da função ordenacao
	memcpy(buff_lista, lista, tam); // Copia os dados de lista em buff_lista

	if (ordenacao != NULL) ordenacao(buff_lista, tam); // Passar NULL caso não deseje ordenar

	for (int i = 0; i < tam; ++i) {
		if (lista[i].estado == NAO_ATIVO) continue;

		printf("Nome da disciplina: %s\n", lista[i].nome);
		printf("Professor: %s",	lista[i].professor->nome);
		printf("Gênero: %s\n", lista[i].codigo);
		puts("\n\n");
	}
}

void ordenar_nascimento(individuo* buff_lista, size_t tam) {
	for (int i = 1; i < tam; ++i) {
		individuo tmp = buff_lista[i];
		int j = i;

		while (tmp.nascimento % 100 < buff_lista[j - 1].nascimento % 100 && j > 0) {
			tmp = buff_lista[i];
			buff_lista[j - 1] = buff_lista[j];

			--j;

			continue;
		}
		buff_lista[j] = tmp;
	}
}

