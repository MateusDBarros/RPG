#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nave
{
    char nome[25];
    int ataque;
    int defesa;
    int energia;
};

void ataque();
void status();
int main(void)
{
    struct Nave naves[4] = {
        {"Astro", 18, 15, 120},
        {"Apollo", 25, 10, 100},
        {"Sombra", 13, 15, 150},
        {"Umbra", 19, 15, 105}
        };


}

void ataque(struct Nave nave1, struct Nave nave2) {
    int dano = nave1.ataque - nave2.defesa;
    nave2.energia -= dano;
    printf("%s ataca %s causando %d de dano.\n", nave1.nome, nave2.nome, dano);
    status(nave1, nave2);
}

void status(struct Nave nave1, struct Nave nave2) {
    printf("Energia '%s': %d\n",nave1.nome, nave1.energia);
    printf("Energia '%s': %d\n",nave2.nome, nave2.energia);
}
