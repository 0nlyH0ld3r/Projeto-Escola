#include <stdio.h>
#include <string.h>
#include "../headers/escola.h"


int procura_vaga (void* lista, size_t tam, char tipo) {
	if (tipo == 'P' || tipo == 'p') {
		individuo* p = (individuo*)lista;

		for (int i = 0; i < tam; ++i) {
			if (p[i].matricula == NAO_ATIVO) {
				return i;
			}
		}
	}

	else if (tipo == 'D' || tipo == 'd') {
		disciplina* p = (disciplina*)lista;

		for (int i = 0; i < tam; ++i) {
			if (p[i].codigo[0] == NAO_ATIVO) { 
				return i;
			}
		}
	}
	else {
		return TIPO_INVALIDO;
	}

	return SEM_VAGA;
}

void listar_individuos(individuo* lista, size_t tam) {
	for (int i = 0; i < tam; ++i) {
		if (lista[i].estado == NAO_ATIVO) continue;

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
		if (lista[i].codigo[0] == NAO_ATIVO) continue;
		printf("Nome da disciplina: %s\n", lista[i].nome);
		printf("Professor: %s",	lista[i].professor->nome);
		printf("Gênero: %s\n", lista[i].codigo);
		puts("\n\n");
	}
}
