#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <utility>


using namespace std;

int main(){
    map<int, pair<string, vector<int>>> grafoColores;
    vector<string> colores;
    ifstream ent ("entrada.in");
    ifstream col("colores.in");
    string color;
    while(col>>color){
        colores.push_back(color);
    }
    char dato;
    int inicial;
    while(ent>>inicial)
    {
        pair<string,vector<int>> datos;
        vector<int> conexiones;
        ent>>dato;
        while (dato != '|')
        {
            conexiones.push_back(atoi(&dato));
            ent>>dato;
        }
        datos.second= conexiones;
        grafoColores[inicial] = datos;
    }
    for(auto node : grafoColores)
    {
        vector<string> coloresRestantes;
        coloresRestantes = colores;
        for( int i = 0; i< node.second.second.size(); i++)
        {
            for( int j = 0; j<coloresRestantes.size(); j++)
            {
                if( grafoColores[node.second.second[i]].first.compare(coloresRestantes[j]) == 0)
                {
                        coloresRestantes.erase(coloresRestantes.begin()+j);
                }
            }
        }
        grafoColores[node.first].first = coloresRestantes[0];
    }

    for(auto node: grafoColores)
    {
        cout<<"nodo: "<<node.first<<" tiene color "<<node.second.first<<endl;
    }

} 