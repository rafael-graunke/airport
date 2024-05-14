#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airport.h"
#include "list.h"


void print_queue(Node *aux)
{
    while (aux->next != NULL)
    {
        printf("%s\n", aux->plane_id);
        aux = aux->next;
    }
    printf("%s\n", aux->plane_id);
}

void excecute(Airport *airport, int choice)
{
    char plane_id[5];
    int i;
    switch (choice)
    {
    case 1:
        printf("Escreva o código do avião a ser inserido:\n");
        scanf("%s", plane_id);
        if (insert_plane(airport, plane_id))
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
            if (airport->ldisp[i].size > 0)
            {
                printf("%c:\n", i + 'A');
                print_queue(airport->ldisp[i].head);
            }
        }
        break;
    case 3:
        printf("Escreva o código do avião a ser autorizado a decolar:\n");
        scanf("%s", plane_id);
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
        printf("Decolagem:\n");
        char *dec_plane_id = dequeue_liftoff(&(*airport));
        if (dec_plane_id != NULL)
        {
            printf("Avião decolado: %s\n", dec_plane_id);
        }
        else
        {
            printf("Nenhum avião consta em nossa lista de decolagem.\n");
        }
        free(dec_plane_id);
        break;
    case 5:
        printf("Escreva o código do avião a ser autorizado a aterrisar:\n");
        scanf("%s", plane_id);
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
        printf("Aterrissagem:\n");
        char *ate_plane_id = dequeue_landing(&(*airport));
        if (ate_plane_id != NULL)
        {
            printf("Avião aterrissado: %s\n", ate_plane_id);
        }
        else
        {
            printf("Nenhum avião consta em nossa lista de aterrissagem.\n");
        }
        free(ate_plane_id);
        break;
    case 7:
        printf("Listar Próximas Decolagens:\n");
        if (airport->fdec.size > 0)
        {
            print_queue(airport->fdec.head);
        }
        else
        {
            printf("Lista de decolagens vazia.\n");
        }
        break;
    case 8:
        printf("Listar Próximas Aterrissagens:\n");
        if (airport->fate.size > 0)
        {
            print_queue(airport->fate.head);
        }
        else
        {
            printf("Lista de aterrissagens vazia.\n");
        }
        break;
    case 9:
        printf("Relatório:\n");
        if (airport->hist.size > 0)
        {
            Record *aux = airport->hist.head;
            while (aux->next != NULL)
            {
                if (aux->hist_kind)
                {
                    printf("%s: decolagem.\n", aux->plane_id);
                }
                else
                {
                    printf("%s: aterrissagem.\n", aux->plane_id);
                }
                aux = aux->next;
            }
            if (aux->hist_kind)
            {
                printf("%s: decolagem.\n", aux->plane_id);
            }
            else
            {
                printf("%s: aterrissagem.\n", aux->plane_id);
            }
        }
        else
        {
            printf("Lista de aterrissagens vazia.\n");
        }
        break;
    case 10:
        printf("Escreva o código do avião a ser removido:\n");
        scanf("%s", plane_id);
        if (remove_plane(&(*airport), plane_id))
        {
            printf("Avião removido com sucesso: %s\n", plane_id);
        }
        else
        {
            printf("Avião não consta em nossa lista: %s\n", plane_id);
        }
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

void main()
{
    int choice;
    Airport airport = create_airport();
    while (1)
    {
        printf("---------------------------------------\n");
        printf("Airport Menu\n");
        printf("01 - Cadastrar Avião\n");
        printf("02 - Listar Aviões Cadastrados\n");
        printf("03 - Autorizar Decolagem\n");
        printf("04 - Realizar Decolagem\n");
        printf("05 - Autorizar Aterrissagem\n");
        printf("06 - Realizar Aterrissagem\n");
        printf("07 - Listar Próximas Decolagens\n");
        printf("08 - Listar Próximas Aterrissagens\n");
        printf("09 - Relatório Aeroporto\n");
        printf("10 - Remover Avião\n");
        printf("00 - Sair\n");
        printf("---------------------------------------\n");
        printf("Digite o número da operação:\n");
        scanf("%d", &choice);
        excecute(&airport, choice);
    }
}