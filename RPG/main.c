#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Nave
{
    char nome[25];
    int ataque;
    int defesa;
    int energia;
};

struct Nave naves[4] = {
        {"Astro", 18, 15, 120},
        {"Apollo", 25, 10, 100},
        {"Sombra", 13, 15, 150},
        {"Umbra", 19, 15, 105}
        };


void ataque(struct Nave *nave1, struct Nave *nave2);
void status(struct Nave nave1, struct Nave nave2);
int vitoria(struct Nave nave1, struct Nave nave2);
int main(void)
{
    srand(time(0));
    int escolha;
    struct Nave jogador;
    struct Nave computador;
    int index = rand() % 4;
    
    printf("| %-10s | %-5s | %-5s | %-5s\n", "Nome", "Ataque", "Defesa", "Energia");
    printf("----------------------------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("| %-10s | %-6d | %-6d | %-5d\n",naves[i].nome, naves[i].ataque, naves[i].defesa, naves[i].energia);
        
    }
    do {
        printf("Escolha sua nave: \n");
        printf("1. Astro\n2. Apollo\n3. Sombra\n4. Umbra\n(Aperte 5 para sair)\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            jogador = naves[0];
            break;
        case 2:
            jogador = naves[1];
            break;
        case 3:
            jogador = naves[2];
            break;
        case 4:
            jogador = naves[3];
            break;
        case 5:
            printf("Encerrando programa...\n");
            return 0;
            break;
        
        default:
            printf("opcao invalida!\n");
            break;
        }
        
        //Seleciona uma da opções aleatoriamente e previne matchup espelhadas
        while (index == escolha) {
            index = rand() % 4;
        }
        computador = naves[index];

        //Inicio da batalha
        status(jogador, computador);
        while (jogador.energia > 0 && computador.energia > 0) {
            ataque(&jogador, &computador);
            if (vitoria(jogador, computador) == 0) {
                printf("Voce venceu, %s foi derrotado, muito bem piloto!\n", computador.nome);
                break;
            }
            ataque(&computador, &jogador);
            if (vitoria(computador, jogador) == 0) {
                printf("%s derrotou voce, mais sorte da proxima piloto!\n", computador.nome);
                break;
            }
        }
    } while(escolha != 5);

    return 0;
}

void ataque(struct Nave *nave1, struct Nave *nave2) {
    int dano = nave1->ataque - nave2->defesa;
    nave2->energia -= dano;
    printf("%s ataca %s causando %d de dano.\n", nave1->nome, nave2->nome, dano);
    status(*nave1, *nave2);
}

void status(struct Nave nave1, struct Nave nave2) {
    printf("Energia '%s': %d\n",nave1.nome, nave1.energia);
    printf("Energia '%s': %d\n",nave2.nome, nave2.energia);
}

int vitoria(struct Nave nave1, struct Nave nave2) {
    if (nave2.energia <= 0) {
        return 0;
    }
    else 
        return -1;
}
