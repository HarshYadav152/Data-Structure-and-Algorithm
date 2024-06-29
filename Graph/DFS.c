#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};
    /*
        0-----1
        | \   |
        |  \  |
        |   \ |
        2-----3
         \   /
          \ /
           4
          / \
         /   \
        5     6
    */
    // adjacency matrx representation of the above graph

void DFS(int i){
    int j;
    printf("%d", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++){
        if (a[i][j] == 1 && !visited[j]){
            DFS(j);
        }
        
    }
}
int main()
{
    // DFS implementation
    DFS(0);

    return 0;
}