#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
int A[MAXN];
int keys[MAXN];
int freeslot = 1;

void initializare(void)
{
    int i;
    for (i = 1; i < MAXN; i++)
    {
        A[i] = -1;
        keys[i] = -1;
    }
}

void insert(char key, int father)
{
    if (freeslot == MAXN)
    {
        printf("No memory\n");
        return;
    }
    A[freeslot] = father;
    keys[freeslot] = key;
    freeslot++;
}

void stergere_stramosi(int tatal)
{
    int i = 0;
    for (i = 1; i < freeslot; i++)
    {
        if (A[i] == tatal)
        {
            stergere_stramosi(i);
            A[i] = -1;
            keys[i] = -1;
        }
    }
}

void stergere(char key)
{
    int i;
    for (i = 1; i < freeslot; i++)
    {
        if (keys[i] == key)
        {
            A[i] = -1;
            keys[i] = -1;
        }
    }
}

void print_tablou()
{
    int i;
    printf("\nGraful este alcatuit din :\n");
    for (i = 1; i < freeslot; i++)
    {
        printf("Nodul %d cu key-ul %c are ca si tata pe %d\n", i, keys[i], A[i]);
    }
}

int main()
{
    int opt, father;
    char key;
    initializare();
    do
    {
        printf("\nMeniu:\n");
        printf("0. Iesire\n");
        printf("1. Insertie.\n");
        printf("2. Stergere.\n");
        printf("3. Printare.\n");
        printf("Optiunea: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            getchar();
            printf("Introduceti key-ul nodului : ");
            scanf("%c", &key);
            printf("Introduceti tatal nodului : ");
            scanf("%d", &father);
            insert(key, father);
            break;
        case 2:
            getchar();
            printf("Introduceti key-ul nodului : ");
            scanf("%c", &key);
            stergere(key);
            break;
        case 3:
            printf("Printare tabel dupa A.\n");
            print_tablou();
            break;

        default:
            printf("Optiune gresita. ");
            break;
        }
    } while (1);
    return 0;
}