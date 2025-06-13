# Uno Chapecó

**Professor:** Diego Turazzi
**Integrantes do grupo:** Gustavo Henrique, Guilherme Morais, Arthur Restello e Pamela Pietroski.

Tuma CX da Matéria de Fundamentos de Algoritimos e Programação.

![logo_unochapeco_TeV0vd](https://github.com/user-attachments/assets/3f3e57b7-9355-4fa6-b30d-c77bbd454576)

---


# 📋 Gerenciador de Tarefas em C

Um simples gerenciador de tarefas feito em linguagem C, com armazenamento em memória (array de `structs`) e funcionalidades básicas como criação, listagem, filtragem e ordenação de tarefas.

---

## ✅ Funcionalidades

- [x] Adicionar nova tarefa
- [x] Listar todas as tarefas
- [x] Pesquisar tarefa por prioridade (com ordenação)
- [x] Listar tarefa específica por ID
- [x] Verificar se existem tarefas antes de listar

---

## 🧠 Relato de Desenvolvimento

### 1. O que o programa faz?
Um **gerenciador de tarefas** simples baseado em `structs`, com todas as funções implementadas manualmente e utilizando **memória temporária** (array).

### 2. Parte mais fácil de implementar:
As partes mais simples de implementar foram as estruturas básicas e as funções iniciais como `criarTarefa`, `removerTarefa (somente jogar o indice em -1)` e `listarTarefas (usando um for com os indices)` .

### 3. Parte mais difícil de implementar:
A **pesquisa por prioridade** foi a mais desafiadora, pois exigiu a implementação de um algoritmo de ordenação (Bubble Sort). Foi difícil entender que essa era a solução necessária para o problema.

### 4. Desafios técnicos:
- Entender que precisávamos de uma **flag** e de uma função `contains` para verificar se havia tarefas criadas antes de listá-las.
- Modularizar o código em diferentes arquivos e fazer a correta **comunicação entre eles** (uso de headers, includes, etc).

### 5. Funções escritas do zero:
- `contains`: Verifica se há pelo menos uma tarefa criada.
- `listarTarefaEspecifica`: Permite buscar diretamente uma tarefa por ID, evitando código repetido.

### 6. Melhorias futuras:
Se tivéssemos mais tempo ou conhecimento:
- Persistência de dados em **arquivo ou banco de dados**.
- Interface gráfica simples ou interface de linha de comando mais intuitiva.
- Salvamento automático de tarefas.

### 7. O que foi pesquisado ou ajudado:
- Implementação do `Bubble Sort`
- Maneira de montar o `header` e `implementar a biblioteca`
- Estrutura de laços `for` com filtros específicos
- Ajuda na montagem do `**layout**` do `README.md`

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- OnlineGDB
- Estrutura com headers

---

## 📁 Link do codigo no OnlineGDB

- 👉 [Projeto no OnlineGDB](https://onlinegdb.com/CzM0vtqu5)


