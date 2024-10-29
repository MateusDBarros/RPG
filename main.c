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
    int velocidade;
};

struct Nave naves[4] = {
        {"Astro", 18, 15, 120, 50},
        {"Apollo", 25, 10, 100, 40},
        {"Sombra", 18, 15, 150, 48},
        {"Umbra", 19, 15, 105, 45}
        };


void ataque(struct Nave *nave1, struct Nave *nave2, int acao);
void status(struct Nave nave1, struct Nave nave2);
int velocidade(struct Nave nave1, struct Nave nave2);
int vitoria(struct Nave nave1, struct Nave nave2);
int main(void)
{
    srand(time(0));
    int escolha; //Armazena a escolha da nave
    int acaoJogador; //Armazena qual ação o jogador tera
    int acaoComputador; //Armazena a ação do computador;
    int turno;

    struct Nave jogador;
    struct Nave computador;
    
    
    printf("| %-10s | %-5s | %-5s | %-5s| %-5s\n", "Nome", "Ataque", "Defesa", "Velocidade","Energia");
    printf("----------------------------------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("| %-10s | %-6d | %-6d | %-5d\n",naves[i].nome, naves[i].ataque, naves[i].defesa, naves[i].velocidade ,naves[i].energia);
        
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
        int index = rand() % 4;
        while (index == escolha - 1) {
            index = rand() % 4;
        }
        computador = naves[index];

        //Inicio da batalha
        do
        {
            
            system("cls");
            status(jogador, computador);
            printf("1. Atacar\n");
            printf("2. Defender\n");
            scanf("%d", &acaoJogador);
            acaoComputador = rand() % 2;
            turno = velocidade(jogador, computador);
            switch (acaoJogador)
            {
                case 1:
                    if (turno == 0) {
                        ataque(&jogador, &computador, acaoComputador);
                    }
                    else {
                        ataque(&computador, &jogador, acaoComputador);
                    }
                break;

                case 2:
                    ataque(&computador, &jogador, acaoJogador);
                break;

                default:
                printf("Escolha invalida!\n");
                break;
            }
            if (turno == 1) {

            }
        } while (jogador.energia != 0 && computador.energia != 0 );
        
        
    } while(escolha != 5);

    return 0;
}

void ataque(struct Nave *nave1, struct Nave *nave2, int acao) {
    int dano;
    if (acao == 1) {
        nave2->energia -= nave1->ataque;
        printf("%s ataca %s causando %d de dano.\n", nave1->nome, nave2->nome, nave1->ataque);
        return;
    }
    else {
        dano = nave1->ataque - nave2->defesa;
        if (dano < 0)
            dano = 0;
        nave2->energia -= dano;
        if (nave2->energia < 0)
            nave2->energia = 0;
        printf("%s ataca %s causando %d de dano.\n", nave1->nome, nave2->nome, dano);
        printf("\n");        
    }
}

int velocidade(struct Nave nave1, struct Nave nave2) {
    if(nave1.velocidade > nave2.velocidade)
        return 0;
    else
        return 1;
}
void status(struct Nave nave1, struct Nave nave2) {
    printf("Energia '%s': %d\n",nave1.nome, nave1.energia);
    printf("Energia '%s': %d\n",nave2.nome, nave2.energia);
}

int vitoria(struct Nave nave1, struct Nave nave2) {
    if (nave1.energia == 0) {
        printf("Voce perdeu!\n");
        return -1;
    }
    if (nave2.energia == 0) {
        printf("Voce venceu!!!\n");
        return 0;
    }
    
}
