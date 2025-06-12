#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_TAREFAS 100

typedef struct {
    int id;
    char descricao[100];
    int prioridade;
    int concluida;
} Tarefa;

extern Tarefa tarefas[MAX_TAREFAS];

int adicionarTarefa();
void listarTarefas();
void listarTarefaEspecifica(int id);
void marcarComoConcluida(int id);
void removerTarefa(int id);
void editarTarefa(int id);
void filtrarPorPrioridade();
void filtrarPorStatus();
int contains(int id);
int contarEspacosLivres();
int buscarTarefaPorId(int id);

#endif
