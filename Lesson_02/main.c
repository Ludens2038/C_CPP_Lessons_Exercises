#include <stdio.h>
#include <stdlib.h>

int goodMorning(int i) {
    printf("good morning \n");
    return i * 2;
}
int goodEvening(int i) {
    printf("good evening \n");
    return i * 3;
}

typedef int (*PFN)(int); //pointer auf funktion, wird so gemacht wenn man array aus funktionen hat

void axel2(int i, PFN pfn) {
    printf("axel: %d\n", i);
    pfn(i);
}

int compareInt(void* a, void* b) { //void pointer sind generische pointer, beim derefernzieren von void pointern muss ich typecasten
    return ((int*)a) - ((int*)b); //typecasten von void pointer auf int pointer
}

int main() {

    printf("funktion axel2 \n");
    axel2(10, goodMorning);

    printf("--------------------\n");

    int i = 17;
    int* pi = &i;
    *pi = 5;

    printf("funktionen in array geben \n");

    //int (*pfn)(int); vorläufer vom polymprphismus
    PFN pfn;
    int a[] = {1, 2, 3};
    PFN funktions[] = {goodMorning, goodEvening};
    for (int i = 0; i < 2; i++) {
        funktions[i](10);
    }

    printf("--------------------\n");
    printf("funktionen in if else \n");

    if (i == 17) {
        pfn = goodMorning;
    } else {
        pfn = goodEvening;
    }

    printf("%d \n", pfn(10));
    printf("--------------------\n");

    printf("quicksort verwenden \n");
    int b[] = {3, 2, 1};
    qsort(b, 3, sizeof(int), compareInt);

    for (int i = 0; i < 3; i++) {
        printf("%d, ", b[i]);
    }
    printf("\n--------------------\n");

    return 0;
}

