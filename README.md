# SplayTree

Uma árvore splay é uma árvore binária de busca autoajustável, com a propriedade adicional de tornar os elementos recentemente acessados, fáceis de acesso novamente, pois os mantém em sua raiz. Suas operações básicas, como remoção e inserção, são executadas em O(log n). Todas as suas operações colocam o elemento envolvido na operação na raiz, através de rotações. Para muitas sequências de operações não aleatórias, as árvores splay têm melhor desempenho do que outras árvores de busca, mesmo quando o padrão específico da sequência é desconhecido. A árvore splay foi inventada por Daniel Sleator e Robert Tarjan em 1985 [[1]](https://link.springer.com/article/10.1007/BF02579253)

## Objetivos:
Nesta atividade implementaremos algumas das principais operações que envolve uma SplayTree, a saber: a rotina splay, uma das rotações e remoção.


## O que deve ser feito:
- Ler o material [splay](splay.md)
- Analisar os códigos-fontes [splay.h](splay.h) e [splay_node.h](splay_node.h) que implementam uma árvore de busca binária splay.
- Implementar as rotina com comentários TODO.

# Para Compilar:

- No diretorio com código fonte, crie a pasta build:

```
mkdir build

```
Depois chame o comando cmake de dentro da pasta build para construir seu projeto.
```
cd build && cmake ..

```
Chame CTest para testar a sua implementação. 
```
ctest

```


  
