/*
Integrantes:
Equipo #12 Integrantes:
Carlos Servilla Silva A00826925
Edith Paulina Benvenuto Valerdi A00828840

Fecha: 20 Noviembre 2020

Descripción: 


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map> 
#include <iterator>

using namespace std;

//Struct donde se guarda cada registro leido
struct datos {
	 int index;
	 int fanOut;
};

//Complejidad O(n)
long long ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

int main(){
	string aux,fecha,ip,prob;
	long long ipL;
	int cont;
	bool contG;
  long long ipPas = 1;
	string nTemp, mTemp;
 // BST<datos> lista;
	ifstream data("bitacora.txt"); //Se lee el archivo bitacora
	if (data.is_open()){
		//Complejidad O(n)
    bool espacio = false;
    getline(data,aux);
    for (int i=0; i<=aux.size()-1;i++){
      if (!espacio){
        if (aux[i] == ' '){
          espacio = true;
        }else{
          nTemp = nTemp + aux[i];   
        }
      }
			else{
				mTemp = mTemp + aux[i];
			}
    }
    int n = stoi(nTemp);
    int m = stoi(mTemp);
    
    unordered_map<string, pair<int, int>> IPNode;
		datos temp;
		for(int i=0;i<n;i++){
      pair<int, int> iniMap;
			iniMap.first = i;
			iniMap.second = 0;
			getline(data,aux);
      IPNode[aux] = iniMap;
		}
		int mayor=0;
		for(int i=0;i<m;i++){
			string ip1, ip2;
			string aux,fecha,prob;
			getline(data,aux);
      bool dosPuntos = false;
      int cont = 0;
      for(int j=0;j<=aux.size()-1;j++){
				if(cont>4){
					prob+=aux[j];
				}
				if(aux[j] != ' '){
					if(cont<3){
						fecha+=aux[j]; 
					}else if(cont==3 && !dosPuntos){
						ip1+=aux[j];
            if(aux[j+1]==':')
              dosPuntos=true;

					}else if(cont==4 && !dosPuntos){
						ip2+=aux[j];
						if(aux[j+1]==':')
							dosPuntos=true;
					}
				}else{
					cont++;
					dosPuntos=false;
					if(cont<4)
						fecha+=' ';
				}
			}
      //cout<<IPNode[ip1].first<<" ";
      //cout<<ip1<<" "<<ip2<<endl;

/////////LISTA ADJACENCIA///////////////////

      vector<vector<int>> listAdj(n); 
			listAdj[IPNode[ip1].first].push_back(IPNode[ip2].second);

/////////LISTA ADJACENCIA////////////////////

      IPNode[ip1].second++;
      if(IPNode[ip1].second > mayor){
        mayor = IPNode[ip1].second;
      }
		}
    //cout << "repeticiones mayor: " << mayor << endl;
    
		
		cout<<"Nodos con mayor fan-out:\n";
    for (auto x : IPNode){
      if (x.second.second == mayor)
        cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }
    cout<<"Estos son los posibles bootmasters"<<endl;

	}
}
