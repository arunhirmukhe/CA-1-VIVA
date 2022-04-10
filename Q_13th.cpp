#include<iostream>
using namespace std;

/*
Represent any real-world graph using adjacency matrix:
a. Create a graph
b. Display
*/
/* graph example
    1----2----3
    \   /
    \ /
     4
*/
class graph{
    public:
    int matrix[5][5];
    void createAM(int vertex,int edges);
    void displayAM(int vertex);
};

void graph::createAM(int vertex, int edges){

    for(int i = 1; i<=vertex; i++){
        for(int j = 1; j<=vertex; j++){
            matrix[i][j] = 0;
        }
    }

    for(int m = 0; m<edges; m++){
        cout<<"Enter edge: ";
        int i,j;
        cin>>i>>j;
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }

}

void graph::displayAM(int vertex){
    for(int i = 1; i<=vertex; i++){
        for(int j = 1; j<=vertex; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int vertex,edges;
    cout<<"Enter number of vertex: ";
    cin>>vertex;
    cout<<"Enter number of edges: ";
    cin>>edges;
    graph g;
    g.createAM(vertex, edges);
    cout<<"Adjacency Matrix"<<endl;
    g.displayAM(vertex);
}