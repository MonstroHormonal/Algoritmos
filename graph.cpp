#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct{

    int[][] matrix;
    int numEdge;
    int[] Mark;

}G;

G create_graph(int n){

    G g;
    g.Mark = new int[n];
    g.matrix = new int[n][n];
    g.numEdge = 0;
    return g;
}

int n(G g){

    return 
}

int first(G g, int v){

    int i;
    for(i = 0; i < n(g) - 1; i++){
        if (g.matrix[v][i] != 0) return i;
    }
    return n(g);
}

int next(G g, int v, int w){

    int i;
    for(i = 0; i < w + 1; i++){
        if(g.matrix[v][i] != 0) return i;
    }
    return n(g);
}

void setEdge(G g, int i, int j, int wt){

    if(wt == 0) exit 1;
    if(g.matrix[i][j] == 0) g.numEdge++;
    g.matrix[i][j] = wt;
}

void delEdge(G g, int i, int j){
    if(matrix[i][j] != 0) g.numEdge--;
    g.matrix[i][j] = 0;
}

void graphTaverse(G g){

    int v;
    for(v = 0; v < n(g) - 1; v++){
        setMark(g, v, UNVISITED);
    }
    for(v = 0; v < n(g) - 1; v++){
        if(getMark(g, v) == UNVISITED) traverse(g, v);
    }
}

void DFS(G g, int v){

    preVisit(g, v);
    setMark(g, v, VISITED);
    w = first(g, v);
    while(w < n(g)){
        if(getMark(g, w) == UNVISITED) DFS(g, w)
        w = next(g, v, w);
    }
    posVisit(g, v);
}

void graphTaverseDFS(G g){

    int v;
    for(v = 0; v < n(g) - 1; v++){
        setMark(g, v, UNVISITED);
    }
    for(v = 0; v < n(g) - 1; v++){
        if(getMark(g, v) == UNVISITED) DFS(g, v);
    }
}

void BFS(G g, int v){

    int Q = create_queue();
    enqueue(Q, start);
    setMark(g, start, VISITED);
    wihle(lenght(Q) > 0){
        v = dequeue(Q);
        preVisit(g, v);
        w = first(g, v);
        while(w < n(g)){
            if(getMark(g, w) == UNVISITED){
                setMark(g, w, VISITED);
                enqueue(Q, w);
            }
            w = next(g, v, w);
        }
        posVisit(g, v);
    }
}

void graphTraverseBFS(G g){

    int v; 
    for(v = 0; v < n(g) - 1; v++){
        setMark(g, v, UNVISITED);
    }
    for(v = 0; v < n(g) - 1; v++){
        if(getMark(g, v) == UNVISITED) BFS(g, v);
    }
}

void toposort(G g, int v, STACK s){
    
    setMark(g, v, VISITED);
    w = first(g, v);
    while(w < n(g)){
        if(getMark(g, w) == UNVISITED)toposort(g, w, s);
        w = next(g, v, w);
    }
    push(s, v);
}

int main(){



    return 0;
}