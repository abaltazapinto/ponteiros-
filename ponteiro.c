#include <stdio.h>

int main() {
    // Definindo um parágrafo como uma string
    char *paragrafo = "Este é um exemplo de um parágrafo.\nEle consiste em várias frases e palavras.";

    // Usando um ponteiro de memória para percorrer o parágrafo
    char *ponteiro = paragrafo;

    // Imprimindo o parágrafo caractere por caractere junto com os endereços de memória relativos
    printf("Parágrafo:\n");
    while (*ponteiro != '\0') {
        printf("Caractere: %c | Endereço: %p\n", *ponteiro, (void *) ponteiro);
        ponteiro++;
    }

    return 0;
}
