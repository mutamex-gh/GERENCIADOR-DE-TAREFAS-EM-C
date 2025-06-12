#include <stdio.h>
#include <string.h>
#include "functions.h"

Tarefa tarefas[MAX_TAREFAS];

    int adicionarTarefa() {
        int id, prioridade, concluida;
        char descricao[100];
        
        for (int i = 1; i < MAX_TAREFAS; i++) {
            if (tarefas[i].id == -1) {  
                
                printf("\nVamos criar uma task!\n");
                printf("Digite a prioridade: ");
                scanf("%d", &prioridade);
                
                printf("Digite o andamento [0.Pendente, 1.Concluida]: ");
                scanf("%d", &concluida);
                
                getchar();
                
                printf("Digite a descrição [max.100]: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';
                
                tarefas[i].id = i;  
                strcpy(tarefas[i].descricao, descricao);
                tarefas[i].prioridade = prioridade;
                tarefas[i].concluida = concluida;
                
                printf("\nSucesso! Tarefa adicionada na posição n.%d.\n", i);
                return 1;  
            }
        }
    return 0; 
    }
    
    
    void listarTarefas() {
    int flag = 0;

    printf("\n--- Tarefas ---\n");
    for(int i = 1; i < MAX_TAREFAS; i++) {
        if(tarefas[i].id != -1) {
            printf("\nTarefa de ID n.%d:\n", tarefas[i].id);
            printf("  Prioridade: %d\n", tarefas[i].prioridade);
            printf("  Status: %s\n", tarefas[i].concluida ? "Concluída" : "Pendente");
            printf("  Descrição: %s\n", tarefas[i].descricao);
            flag = 1;
        }
    }
        if(!flag) {
            printf("Nenhuma tarefa para exibir.\n");
        }
    }

    
    void listarTarefaEspecifica(int id) {
        if(tarefas[id].id != -1) {
            printf("\nTarefa de ID n.%d:\n", tarefas[id].id);
            printf("  Prioridade: %d\n", tarefas[id].prioridade);
            printf("  Status: %s\n", tarefas[id].concluida ? "Concluída" : "Pendente");
            printf("  Descrição: %s\n", tarefas[id].descricao);
        }
    }
    
    
    void marcarComoConcluida(int id) {
        int flag = 0;
        
        printf("\n--- Tarefa ---\n");
        if(tarefas[id].id != -1) {
            if(tarefas[id].concluida == 0) {
                tarefas[id].concluida = 1;
            
                listarTarefaEspecifica(id);
            }else {
                printf("Esta tarefa já está marcada como concluida!\n");
            }
            flag = 1;
        }
        if(!flag) {
            printf("Nenhuma tarefa para modificar.\n");
        }
    }
    
    
    void removerTarefa(int id) {
        tarefas[id].id = -1;
        printf("Tarefa removida com sucesso!\n");
    }
    
    
    void editarTarefa(int id) {
        int prioridade, concluida, num, flag = 0;
        char descricao[100];
        
        printf("O que deseja editar da tarefa ID n.%d?\n", id);
        
        printf("Opções: \n");
        printf("    1.Prioridade\n");
        printf("    2.Status\n");
        printf("    3.Descrição\n");
        printf("    4.Sair\n");
        
        scanf("%d", &num);
        
        switch(num) {
            case 1: 
                printf("Digite a nova prioridade: ");
                scanf("%d", &prioridade);
                
                tarefas[id].prioridade = prioridade;
                break;
            case 2: 
                printf("Digite o andamento [0.Pendente, 1.Concluida]: ");
                scanf("%d", &concluida);
                
                tarefas[id].concluida = concluida;
                break;
            case 3:
                printf("Digite a nova descrição [max.100]: ");
                
                getchar();
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';
                strcpy(tarefas[id].descricao, descricao);
                break;
            case 4:
                printf("Saindo....\n");
                break;
            default:
                break;
        }
        
        printf("Tarefa ID.%d editada com sucesso!\n", id);
    }
    
    
    void filtrarPorPrioridade() {
        Tarefa ordenadas[MAX_TAREFAS];
        int count = 0;

        for (int i = 0; i < MAX_TAREFAS; i++) {
            if (tarefas[i].id != -1) {
                ordenadas[count++] = tarefas[i];
            }
        }

        //bubble sort
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (ordenadas[j].prioridade > ordenadas[j + 1].prioridade) {
                    Tarefa temp = ordenadas[j];
                    ordenadas[j] = ordenadas[j + 1];
                    ordenadas[j + 1] = temp;
                }
            }
        }

        printf("\n--- Tarefas ordenadas por prioridade ---\n");
        for (int i = 0; i < count; i++) {
            printf("\nTarefa de ID n.%d:\n", ordenadas[i].id);
            printf("  Prioridade: %d\n", ordenadas[i].prioridade);
            printf("  Status: %s\n", ordenadas[i].concluida ? "Concluída" : "Pendente");
            printf("  Descrição: %s\n", ordenadas[i].descricao);
        }

        if (count == 0) {
            printf("Nenhuma tarefa para exibir.\n");
        }
    }
    
    
    void filtrarPorStatus(int status) {
        for(int i = 0; i < MAX_TAREFAS; i++) {
            if(tarefas[i].id != -1 && tarefas[i].concluida == status) {
                printf("\nTarefa de ID n.%d:\n", tarefas[i].id);
                printf("  Prioridade: %d\n", tarefas[i].prioridade);
                printf("  Status: %s\n", tarefas[i].concluida ? "Concluída" : "Pendente");
                printf("  Descrição: %s\n", tarefas[i].descricao);
            }
        }
    }
    
    
    int contarEspacosLivres() {
        int count = 100;
        
        for(int i = 0; i < MAX_TAREFAS; i++) {
            if(tarefas[i].id != -1) {
                count--;
            } 
        }
        return count;
    }
    
    
    int contains(int id) {
        for (int i = 0; i < MAX_TAREFAS; i++) {
            if (tarefas[i].id == id) {
                return 1; 
            }
        }
        return 0; 
    }
 
    