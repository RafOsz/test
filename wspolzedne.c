#include <stdio.h>
#include <stdlib.h>
typedef struct{
float x;
float y;
float z;
} wsp;
typedef struct {
    unsigned int p;
    unsigned int q;
    unsigned int r;
} cell_t;
cell_t *indeksy;
wsp *position_t;
unsigned int latom;
wsp b;
cell_t podzial;
int wyz_id() {
    int i;
    printf("Podaj ilosc podzialow pudla obliczeniowego wzdloz osi x: ");
    if (scanf("%d", &podzial.p) != 1) {printf("Wprowadzono ciag znakow nie bedacy liczba calkowita\n");
    return -1;
    }
    return 0;
        printf("Podaj ilosc podzialow pudla obliczeniowego wzdloz osi y: ");
    if (scanf("%d", &podzial.q) != 1) {printf("Wprowadzono ciag znakow nie bedacy liczba calkowita\n");
    return -1;
    }
    return 0;
        printf("Podaj ilosc podzialow pudla obliczeniowego wzdloz osi z: ");
    if (scanf("%d", &podzial.r) != 1) {printf("Wprowadzono ciag znakow nie bedacy liczba calkowita\n");
    return -1;
    }
    return 0;
    for(i=0;i<latom;i++){
        indeksy[i].p = (int) (position_t[i].x / (b.x / podzial.p));
        if (indeksy[i].p == podzial.p) indeksy[i].p--;
    }
    for(i=0;i<latom;i++){
        indeksy[i].q = (int) (position_t[i].y / (b.y / podzial.q));
        if (indeksy[i].q == podzial.q) indeksy[i].q--;
    }
    for(i=0;i<latom;i++){
        indeksy[i].r = (int) (position_t[i].z / (b.z / podzial.r));
        if (indeksy[i].r == podzial.r) indeksy[i].r--;
    }
}
int readData(char *filename) {
    int i;
    FILE *f;
    f =fopen(filename, "r");
    if (f == NULL) return -1;
    if (fscanf(f, "%d", &latom) != 1) return -1;
    position_t = malloc(latom *sizeof(wsp));
    indeksy = malloc(latom *sizeof(cell_t));
    if (position_t == NULL) return -1;
    if (indeksy == NULL) return -1;
    if (fscanf(f, "%f %f %f", &b.x, &b.y,
    &b.z) != 3) return -1;
    for(i=0;i<latom;i++){
        if (fscanf(f, "%f %f %f", &position_t[i].x, &position_t[i].y,
        &position_t[i].z) != 3) return -1;
    
    if ((position_t[i].x < 0) || (position_t[i].x > b.x)) return -1;
    if ((position_t[i].y < 0) || (position_t[i].y > b.y)) return -1;
    if ((position_t[i].z < 0) || (position_t[i].z > b.z)) return -1;
    }
    fclose(f);
    return 0;
}
int punkt(){
    int numer;
    printf("Podaj numer punktu: \n");
    if (scanf("%d", &numer) != 1) {
        printf("Wprowadzono ciąg znaków nie bedacy liczba calkowita\n");
        return -1;
    }
    if(numer > 1000000){
        printf("Podano numer poza zakresem\n");
        return -1;
    }
    printf("X: %f\nY: %f\nZ: %f\n", position_t[numer].x, position_t[numer].y, position_t[numer].z);
    printf("Komorka = P: %d\nQ: %d\nR: %d\n", indeksy[numer].p, indeksy[numer].q, indeksy[numer].r);
    return 0;
}
int main(int argc, char *argv[]){
    char filename[512];
    printf("Podaj nazwę pliku: ");
    if (scanf("%s", filename) != 1) {
        printf("Blad w nazwie pliku\n");
        return -1;
    }
    if(readData(filename) == -1){
        printf("Błąd wczytywania danych z pliku\n");
        return -1;
    }
    else{
        return wyz_id();
        if(wyz_id() != 0) return -1;
        punkt();
    }
    if(position_t != NULL)
    free(position_t);
    if(indeksy != NULL)
    free(indeksy);
    return 0;
}