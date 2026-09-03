#include <stdio.h>
#include <string.h>
#include "../headers/base_projeto.h"

int main(){
	Individuo listaAlunos[3];

	int sair = 0;
	int qtdAlunos = 0;
	int opcao;
	while(!sair){ //sair == 0
		printf("Digite a opção: \n\n");
		printf("\t0 - Sair \n");
		printf("\t1 - Inserir \n");
		printf("\t2 - Listar \n");
		printf("\t3 - Atualizar \n");
		printf("\t4 - Deletar \n");

		scanf("%d", &opcao);
		clean_buffer();

		switch (opcao){
			case 0: {
				sair = 1;
				break;
			}

			case 1: {
				puts("Digite o nome:\n");
				input_string(listaAlunos[qtdAlunos].nome, 100);

				do{
					puts("Digite gênero (M - Masculino | F - Feminino):");
					scanf("%c", &listaAlunos[qtdAlunos].genero);
					clean_buffer();
					if(listaAlunos[qtdAlunos].genero == 'm' || listaAlunos[qtdAlunos].genero == 'm')
						listaAlunos[qtdAlunos].genero -= 32;

				} while(listaAlunos[qtdAlunos].genero != 'M' && listaAlunos[qtdAlunos].genero != 'F');

				puts("Digite a data de nascimento (DiaMêsAno | DDMMAA):\n");
				scanf("%d", &listaAlunos[qtdAlunos].nascimento);
				clean_buffer();
				puts("Digite o CPF:\n");
				scanf("%d", &listaAlunos[qtdAlunos].cpf);
				clean_buffer();

				//falta o resto, salvei por que tive que sair
				qtdAlunos++;
				break;
			}
				
			case 2: {
				printf("Lista Alunos\n");

				for (int i = 0; i < qtdAlunos; i++)
					printf("Aluno: %s \n.", listaAlunos[i].nome);

				break;
			}

			case 3: {
				printf("Atualizar");
				break;
			}

			case 4: {
				printf("Deletar");
				break;
			}

			default: { 
				printf("Opção Inválida");
			}
		}
	}
}
