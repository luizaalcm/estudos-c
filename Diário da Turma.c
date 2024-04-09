#include <stdio.h>

typedef struct { //cria um tipo, nosso tipo é estudante e é instanciado com tipos diversos de dados
    long matricula;
    float nota[5];
    float aulas_freq;
    float aulas_ministradas;
} Estudante;

void menu(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]); //declarando as funções
void nota(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]); //instanciamento de funções
void freq(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]);

int main() {
    int num_alunos = 0; //declarando  a varivel pois n esta dentro da função
    
    while (num_alunos < 1 || num_alunos > 40) {
        printf("Insira o numero de alunos a serem cadastrados: ");
        scanf("%i", &num_alunos);

        if (num_alunos < 1 || num_alunos > 40) {
            printf("Insira um numero de alunos valido: entre 1 a 40./\n");
        }
    }
    Estudante Aluno[num_alunos]; 
    char nome[num_alunos][100]; //numero max de caracteres na string

    int i;
    for (i = 0; i < num_alunos; i++) {
        getchar(); //serve pra limpar o buffer (area temporária do cod)

        printf("Insira o nome do aluno %i: ", i + 1); //para n começar pelo indice 0
        gets(nome[i]); //get lê até enter, ele pode dar espaço
        printf("Insira a matricula do aluno %i: ", i + 1);
        scanf("%ld", &Aluno[i].matricula); //indica o indice de aluno que recebe o numero de matricula
        printf("\n");

    }
    menu(num_alunos, Aluno, nome); // chama o menu

    return 0;
}

void menu(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]) {

    int x;
    printf("-------MENU-------\n\n");
    printf("O que deseja fazer agora?\n");
    printf("1 - Insira e mostre em uma tabela a nota de cada aluno cadastrado.\n");
    printf("2 - Insira e mostre em uma tabela a frequencia de cada aluno cadastrado.\n");
    printf("0 - Encerre o programa.\n");
    scanf("%i", &x);

    if (x == 0 || x == 1 || x == 2) {
        switch (x) {
            case 0:{
                printf("\nPrograma encerrado.\n");
                break;
            }
            case 1:{
                nota(num_alunos, Aluno, nome);
                printf("\n-------MENU-------\n\n");
                printf("O que deseja fazer agora?\n");
                printf("1 - Insira e mostre em uma tabela a frequencia de cada aluno cadastrado.\n");
                printf("0 - Encerre o programa.\n");
                scanf("%i", &x);
                if(x == 1){
                    freq(num_alunos, Aluno, nome);
                    printf("\nPrograma encerrado.\n");
                    break;    
                }
                if(x == 0){
                    printf("\nPrograma encerrado.\n");
                    break;
                }
            }    
            case 2:{
                freq(num_alunos, Aluno, nome);
                printf("\n-------MENU-------\n\n");
                printf("O que deseja fazer agora?\n");
                printf("1 - Insira e mostre em uma tabela a nota de cada aluno cadastrado.\n");
                printf("0 - Encerre o programa.\n");
                scanf("%i", &x);
                if(x == 1){
                    nota(num_alunos, Aluno, nome);
                    printf("\nPrograma encerrado.\n");
                    break;    
                }
                if(x == 0){
                    printf("\nPrograma encerrado.\n");
                    break;
                }
            }
        }
    } else {
        printf("Insira uma opcao valida.\n");
        menu(num_alunos, Aluno, nome);
    }
}

void nota(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]) {

    int num_notas;
    printf("Insira o numero de notas que vai cadastrar de cada aluno:\n");
    scanf("%i", &num_notas);

    int i;
    for (i = 0; i < num_alunos; i++) {
        for (int j = 0; j < num_notas; j++) {
            printf("Insira a nota %i de %s: ", j + 1, nome[i]);
            scanf("%f", &Aluno[i].nota[j]);
        }
        printf("\n");
    }

    float media[num_alunos];
    // Calcular média de notas para cada aluno
    int i;
    for (i = 0; i < num_alunos; i++) {
        media[i] = 0; 
        for (int j = 0; j < num_notas; j++) {
            media[i] = media[i] + Aluno[i].nota[j];
        }
        media[i] = media[i] / num_notas; 
    }

    // Imprimir notas e médias
    int i;
    for ( i = 0; i < num_alunos; i++) {

        printf("%s:\n", nome[i]);
        printf("Notas:");
        for (int j = 0; j < num_notas; j++) {
            printf(" %.2f    ", Aluno[i].nota[j]);
        }
        printf("\nMedia: %.2f\n\n", media[i]);
    }
}

void freq(int num_alunos, Estudante Aluno[num_alunos], char nome[num_alunos][100]) {

    printf("Insira o número de aulas que foram dadas: ");
    scanf("%f", &Aluno[0].aulas_ministradas);

    printf("Insira a quantidade de aulas que cada aluno frequentou: ");
    int i;
    for (i = 0; i < num_alunos; i++) {
        printf("\n%s: ", nome[i]);
        scanf("%f", &Aluno[i].aulas_freq);
    }

    float freq_por[num_alunos];
    int i;
    for (i = 0; i < num_alunos; i++) {
        freq_por[i] = (Aluno[i].aulas_freq / Aluno[0].aulas_ministradas) * 100;
        printf("\n\nNumero de matricula: [%ld]      Aluno: [%s]     Numero de Aulas Totais: [%.f]       Numero de aulas frequentadas: [%.f]      Frequencia do aluno em porcentagem: [%.2f%]",
        Aluno[i].matricula, nome[i], Aluno[0].aulas_ministradas, Aluno[i].aulas_freq, freq_por[i]);
    }
    printf("\n");
}