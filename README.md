# SPLAY TREES

Uma árvore splay é um tipo de árvore de busca binária balanceada. Estruturalmente, é idêntica a uma árvore de busca binária comum; a única diferença está nos algoritmos para localizar, inserir e excluir entradas.

Todas as operações de splay tree são executadas em tempo O(log n) na média, onde n é o número de entradas na árvore. Qualquer operação única pode levar tempo O(n) no pior caso. Mas qualquer sequência de k operações de splay tree, com a árvore inicialmente vazia e nunca excedendo n itens, leva O(k log n) tempo de pior caso.

As árvores Splay são projetadas para fornecer acesso especialmente rápido às entradas que foram acessadas recentemente, de modo que realmente se destacam em aplicativos em que uma pequena fração das entradas é o alvo da maioria das operações de localização. Como exemplos de
aplicação podemos citar:

- no Windows na implementação da memória virtual, rede e código do sistema de arquivos,
- no compilador gcc e a biblioteca GNU C++,
- em algorimos de roteadores (rede),
- implementação do Unix malloc, 
- módulos carregaveis do kernel do linux, e em muitos outros softwares

**Vantagens das Árvores Splay**:

- Útil para implementar caches e algoritmos de coleta de lixo.
- Requer menos espaço, pois não são necessárias informações de balanceamento.
- Árvores Splay fornecem bom desempenho com nós contendo chaves idênticas.

**Desvantagens das Árvores Splay**:

- A altura de uma árvore splay pode ser linear ao acessar elementos em ordem não decrescente.
- O desempenho de uma árvore splay será pior do que uma árvore de busca binária simples balanceada em caso de acesso uniforme.

## Rotações

Como muitos tipos de árvores de busca balanceadas, as árvores de splay são mantidas balanceadas com a ajuda de mudanças estruturais chamadas *rotações*. Existem dois tipos - uma rotação à esquerda e uma rotação à direita - e cada um é o inverso do outro. Suponha que X e Y sejam nós de árvore binária, e A, B e C são subárvores. Uma rotação transforma qualquer uma das configurações ilustradas acima na outra. Observe que a invariante da árvore de busca binária é preservada: as chaves em A são menores ou iguais a X; chaves em C são maiores ou iguais a Y; e as chaves em B são >= X e <= Y.

       Y                             X     
      / \        rotate left        / \    
     X   ^      <------------      ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^         ------------>         ^  ^ 
  /A\/B\         rotate right        /B\/C\

## Operações

### find(Object k)

A operação find() em uma árvore splay começa exatamente como a operação find() em uma árvore de busca binária comum: descemos a árvore até encontrarmos a entrada com a chave k, ou chegamos a um beco sem saída (um nó a partir do qual o próxima etapa lógica leva a um ponteiro nulo).

No entanto, uma árvore splay não termina seu trabalho aqui. Seja X o nó onde a busca terminou, contendo ou não a chave k. Nós elevaremos o nó X na árvore através de uma sequência de rotações, de modo que X se torne a raiz da árvore. Por quê? Uma razão é que as entradas acessadas recentemente estão próximas à raiz da árvore e, se acessarmos as mesmas poucas entradas repetidamente, os acessos serão muito rápidos. Outra razão é porque se X estiver profundamente abaixo de um ramidicação desequilibrada da árvore, a operação de splay melhorará o equilíbrio ao longo desse ramo.

Quando estendemos um nó até a raiz da árvore, existem três casos que determinam as rotações que usamos.

**Caso 1: Rotação zig-zag**

X é o filho direito de um filho esquerdo (ou o filho esquerdo de um filho direito): seja P o pai de X e seja G o avô de X.
Primeiro giramos X e P para a esquerda e depois giramos X e G para a direita, conforme ilustrado à direita. A imagem espelhada deste caso - onde X é um filho à esquerda e P é um filho à direita - usa as mesmas rotações na imagem espelhada: gire X e P para a direita, depois X e G para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zag".

      G               G               X     
     / \             / \             / \    
    P   ^           X   ^           P   G   
   / \ /D\  ==>    / \ /D\  ==>    / \ / \  
   ^  X            P  ^            ^  ^ ^  ^ 
  /A\/ \          / \/C\          /A\/BVC\/D\
     ^  ^        ^  ^                        
    /B\/C\      /A\/B\     Zig-Zag

A imagem espelhada deste caso - onde X é um filho à esquerda e P é um filho à direita - usa as mesmas rotações na imagem espelhada: gire X e P para a direita, depois X e G para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zag".

**Caso 2: Rotação Zig-Zig**

X é o filho esquerdo de um filho esquerdo (ou o filho direito de um filho direito): a ORDEM das rotações é INVERTIDA do caso 1. Começamos com o avô e giramos G e P para a direita. Então, giramos P e X para a direita.

      G               P               X       
     / \             / \             / \      
    P   ^           X   G           ^   P     
   / \ /D\  ==>    / \ / \    ==>  /A\ / \    
   X  ^            ^  ^ ^  ^            ^  G   
  / \/C\          /A\/BVC\/D\          /B\/ \  
  ^  ^                                     ^  ^ 
 /A\/B\                       Zig-Zig     /C\/D\

A imagem espelhada deste caso - onde X e P são ambos filhos à direita - usa as mesmas rotações na imagem espelhada: gire G e P para a esquerda, depois P e X para a esquerda. Tanto o caso ilustrado acima quanto sua imagem espelhada são chamados de caso "zig-zig".

Aplicamos repetidamente rotações em zig-zag e zig-zig a X; cada par de rotações eleva X dois níveis acima na árvore. Eventualmente, ou X alcançará a raiz (e terminamos), ou X se tornará o filho da raiz. Para esta ultima situação, aplica-se mais um caso.

**Caso 3: Rotação zig**

O pai de X, P, é a raiz: giramos X e P para que X se torne a raiz. Isso é chamado de caso "zig"

     P             X     
    / \           / \    
   X   ^         ^   P   
  / \ /C\  ==>  /A\ / \  
  ^  ^               ^  ^ 
 /A\/B\     Zig     /B\/C\

