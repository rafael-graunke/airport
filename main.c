#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airport.h"
#include "list.h"

void main()
{
    int choice;
    Airport airport = create_airport();
    while (1)
    {
        printf("---------------------------------------\n");
        printf("Airport Menu\n");
        printf("1 - Cadastrar Avião\n");
        printf("2 - Listar Aviões Cadastrados\n");
        printf("3 - Autorizar Decolagem\n");
        printf("4 - Realizar Decolagem\n");
        printf("5 - Autorizar Aterrissagem\n");
        printf("6 - Realizar Aterrissagem\n");
        printf("7 - Listar Próximas Decolagens\n");
        printf("8 - Listar Próximas Aterrissagens\n");
        printf("9 - Relatório Aeroporto\n");
        printf("0 - Sair\n");
        printf("---------------------------------------\n");
        printf("Digite o número da operação:\n");
        scanf("%d", &choice);
        excecute(&airport, choice);
    }
}

void excecute(Airport **airport, int choice)
{
    Airport *aaux = &(*airport);
    char plane_id[5];
    int i;
    switch (choice)
    {
    case 1:
        printf("Escreva o código do avião a ser inserido:\n");
        scanf("%s", &plane_id);
        if (insert_plane(&(*airport), plane_id))
        {
            printf("Avião registrado com sucesso: %s\n", plane_id);
        }
        else
        {
            printf("Avião já estava registrado: %s\n", plane_id);
        }
        break;
    case 2:
        printf("Lista de aviões registrados:\n");
        for (i = 0; i < 26; i++)
        {
            if (aaux->ldisp[i].size > 0)
            {
                printf("%c:\n", i + 'A');
                print_queue(aaux->ldisp[i].head);
            }
        }
        break;
    case 3:
        printf("Escreva o código do avião a ser autorizado a decolar:\n");
        scanf("%s", &plane_id);
        if (queue_liftoff(&(*airport), plane_id))
        {
            printf("Avião autorizado: %s\n", plane_id);
        }
        else
        {
            printf("Avião não consta em nossa lista: %s\n", plane_id);
        }
        break;
    case 4:
        break;
    case 5:
        printf("Escreva o código do avião a ser autorizado a aterrisar:\n");
        scanf("%s", &plane_id);
        if (queue_landing(&(*airport), plane_id))
        {
            printf("Avião autorizado: %s\n", plane_id);
        }
        else
        {
            printf("Avião não consta em nossa lista: %s\n", plane_id);
        }
        break;
    case 6:
        break;
    case 7:
        printf("Listar Próximas Decolagens:\n");
        if (aaux->fdec.size > 0)
        {
            print_queue(aaux->fdec.head);
        }        
        else
        {
            printf("Lista de decolagens vazia.\n");
        }
        break;
    case 8:
        printf("Listar Próximas Aterrissagens:\n");
        if (aaux->fate.size > 0)
        {
            print_queue(aaux->fate.head);
        }
        else
        {
            printf("Lista de aterrissagens vazia.\n");
        }
        break;
    case 9:
        break;
    case 0:
        printf("Finalizando aplicação.");
        exit(1);
        break;
    default:
        printf("Operação não listada.");
        break;
    }
}

void print_queue(Node *aux)
{
    while (aux->next != NULL)
    {
        printf("%s\n", aux->plane_id);
        aux = aux->next;
    }
    printf("%s\n", aux->plane_id);
}