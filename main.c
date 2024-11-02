#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int genera_mossa_casuale() {
    return rand() % 3;
}
int converte_mossa(int mossa) {
    switch (mossa) {
        case 0: return 0;
        case 1: return 2;
        case 2: return 5;
    }
    return -1;
}
int controlla_vincitore(int giocatore, int macchina) {
    if (giocatore == macchina) return 0;
    if ((giocatore == 0 && macchina == 2) || (giocatore == 2 && macchina == 5) || (giocatore == 5 && macchina == 0))
        return 1;
    else
        return -1;
}
int main() {
    int giocatore, macchina, risultato;
    int vittorie_giocatore = 0, vittorie_macchina = 0;
    srand(time(NULL));
    printf("Benvenuto a Sasso-Carta-Forbici!\n");
    printf("Inserisci 0 per Sasso, 2 per Forbici, 5 per Carta, -1 per uscire.\n");
    while (1) {
        printf("La tua scelta: ");
        scanf("%d", &giocatore);
        if (giocatore == -1) {
            printf("Hai terminato il gioco.\n");
            break;
        }
        if (giocatore != 0 && giocatore != 2 && giocatore != 5) {
            printf("Scelta non valida. Riprova.\n");
            continue;
        }
        macchina = converte_mossa(genera_mossa_casuale());
        printf("La macchina ha scelto: %d\n", macchina);
        risultato = controlla_vincitore(giocatore, macchina);
        if (risultato == 1) {
            printf("Hai vinto!\n");
            vittorie_giocatore++;
        } else if (risultato == -1) {
            printf("La macchina ha vinto!\n");
            vittorie_macchina++;
        } else {
            printf("Pareggio!\n");
        }
    }
    printf("Risultato finale:\n");
    printf("Vittorie giocatore: %d\n", vittorie_giocatore);
    printf("Vittorie macchina: %d\n", vittorie_macchina);
    if (vittorie_giocatore > vittorie_macchina) {
        printf("Sei il vincitore!\n");
    } else if (vittorie_macchina > vittorie_giocatore) {
        printf("La macchina è la vincitrice!\n");
    } else {
        printf("Il gioco è terminato in pareggio.\n");
    }
    return 0;
}