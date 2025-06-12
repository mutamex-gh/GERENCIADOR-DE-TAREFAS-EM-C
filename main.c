#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {
    
    for (int i = 0; i < MAX_TAREFAS; i++) {
        tarefas[i].id = -1; 
    }

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("Espaços livres: %d\n", contarEspacosLivres());
        printf("1. Adicionar tarefa\n2. Listar tarefas\n3. Marcar como concluída\n4. Remover tarefa\n");
        printf("5. Editar tarefa\n6. Filtrar por prioridade\n7. Filtrar por status\n8. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarTarefa(); break;
            case 2: listarTarefas(); break; 
            case 3:
                int id;
                printf("\nDigite o ID da tarefa que deseja marcar como concluida: ");  
                scanf("%d", &id);
                
                marcarComoConcluida(id);
                break;
            case 4:
                printf("\nDigite o ID da tarefa que deseja remover: ");  
                scanf("%d", &id);
                
                if(!contains(id)) {
                    printf("\n--- Tarefa ---\n");
                    printf("Nenhuma tarefa que possa ser removida e/ou ID invalido.\n");
                    break;
                }
                
                removerTarefa(id);
                break;
            case 5: 
                printf("\nDigite o ID da tarefa que deseja editar: ");  
                scanf("%d", &id);
                
                if(!contains(id)) {
                    printf("\n--- Tarefa ---\n");
                    printf("Nenhuma tarefa que possa ser editada.\n");
                    break;
                }
                
                editarTarefa(id);
                break;
            case 6: filtrarPorPrioridade(); break;
            case 7: 
                int status;
                printf("Digite o status que deseja filtrar\n");  
                printf("[0. Pendente / 1. Concluido]: ");
                scanf("%d", &status);
                
                filtrarPorStatus(status);
                break;
            case 8:
                printf("Saindo....\n");
                break;
            default: 
                break;
        }
    } while (opcao != 8);

    return 0;
}

    