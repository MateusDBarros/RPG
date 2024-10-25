#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Personagem
{
    int hp;
    int ataque;
    int defesa;
    int agilidade;
};

// Protagonista
struct Personagem protagonista = {100, 20, 10, 15};

// Inimigos
struct Personagem inimigos[3] = {
    {80, 15, 5, 10}, {70, 10, 10, 20}, {90, 25, 8, 12}
};

void batalha(struct Personagem player, struct Personagem inimigo);
int main(void)
{
    srand(time(0));

    int random = rand() % 3;
    struct Personagem inimigo = inimigos[random];

}

void batalha(struct Personagem player, struct Personagem inimigo) 
{
    int escolha;
    do
    {
        printf("HP:\t %-5d\n", player.hp);
        printf("HP Inimigo:\t %-5d\n", inimigo.hp);
        if (player.agilidade > inimigo.agilidade) {
            printf("1. Atacar.\n");
            printf("2. Defender.\n");
            printf("3. Itens.\n");
            scanf("%d", &escolha);
            switch (escolha)
            {
            case 1:
                inimigo.hp -= player.ataque;
                break;
            case 2:
                player.hp -= (inimigo.ataque - player.defesa);
                break;
            case 3:
                // Mostra os itens e da opçoes de usar ou de sair 
                break;
            
            default:
                printf("Escolha invalida!\n");
                break;
            }
        }
        else {
            player.hp -= inimigo.ataque;
        }

        
    } while (player.hp <= 0 && inimigo.hp <= 0);
    
}