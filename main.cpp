/*
Equipo 12 integrantes:
Carlos Servilla Silva A00826925
Edith Paulina Benvenuto Valerdi A00828840

Fecha: 9 Septiembre 2020

Descripción: 
El programa lee los datos almacenados en el archivo bitácora.txt, donde se lee el mes, dia, hora, IP y la falla, estos datos son leídos y posteriormente almacenados en un vector de struct.
Después se lee la consulta del usuario donde se ingresan las primeras tres letras del mes inicial en ingles y el dia, seguido de las tres primeras letras del mes final y el día.
Para devolver el rango de datos pedido por el usuario, utilizamos dos búsquedas binarias O(logn) para poder realizar dichas búsquedas, es necesario que el vector se encuentre ordenado, por lo que usamos la función sort O(n^2) para encontrar el indice donde inicia el rango pedido y otra para encontrar el indice donde termina dicho rango.

Al final usamos un ofstream para imprimir, con un for, los datos del vector creado, de la posicion inicial obtenida a la final.
*/
#include <iostream>
#include <vector> /// vector
#include <fstream> // leer/imprimir el archivo
#include <algorithm> // sort
#include <stdlib.h> //convertir string a int para tener la clave en int
using namespace std;


//datos es el struct
//data es el archivo.txt
//datas es el vector donde almacenamos cosas

//Struct que almacena diferentes tipos de datos donde todos son almacenados en un vector
struct datos {
   int clave;
   int claveRedux;
	 string mes;
	 string dia;
	 string hora;
	 string falla; 
	 string IP;
};

//Cambia el mes a cifras, del strig del mes lo convierte en numero para facilitar su uso, constante, ejemplo: Aug -> 08 
//Siempre se considera el mes con las 3 primera letras del mes en ingles
string mesANum(string month){ 
	string m;
	if(month=="Jan") 
		m="01";
	else if(month=="Feb")
		m="02";
	else if(month=="Mar")
		m="03";
	else if(month=="Apr")
		m="04";
	else if(month=="May")
		m="05";
	else if(month=="Jun")
		m="06";
	else if(month=="Jul")
		m="07";
	else if(month=="Aug")
		m="08";
	else if(month=="Sep")
		m="09";
	else if(month=="Oct")
		m="10";
	else if(month=="Nov")
		m="11";
	else if(month=="Dec")
		m="12";
	return m;
}

//diaCifra pregunta si solo es una cifra y le pone el 0 antes para que al ser agregado a la clave como 0 decenas y n unidades, ejemplo 9 -> 09
string diaCifra(string day){ 
	string fecha;
	if(day.size()<2)
		fecha+="0";
	fecha+=day;
	return fecha;
}

//sobrecarga del sort, ya que al ser un struct se requiere especificar por cual de sus datos guardados ordenará el sort
bool orden_Fecha(datos a, datos b){
	return a.clave<b.clave;
}

//Para encontrar la primera posicion de la consulta O(log n)
int binariaIni(vector<datos>&v,int c){ 
	int mid,ini=0,fin=v.size()-1;
	while(ini<fin){
		mid=(ini+fin)/2;
		if(c==v[mid].claveRedux){
			while(v[mid].claveRedux==c) //En el caso que hayan mas datos iguales a él anteriormente
				mid--;
			return mid;
		}
		else if(c<v[mid].claveRedux)
			fin=mid-1;
		else 
			ini=mid+1;	
	}
	return -1;
}

//Para encontrar la ultima posicion de la consulta O(log n)
int binariaFin(vector<datos>&v,int c){ 
	int mid,ini=0,fin=v.size()-1;
	while(ini<fin){
		mid=(ini+fin)/2;
		if(c==v[mid].claveRedux){
			while(v[mid].claveRedux==c) //En el caso que hayan mas datos iguales a él posteriormente
				mid++;
			return mid;
		}
		else if(c<v[mid].claveRedux)
			fin=mid-1;
		else 
			ini=mid+1;	
	}
	return -1;
}

// proceso principal donde se lee el archivo de texto con los datos proporcionados, aqui se separan es partes que son almacenadas en un vector de un struct. 
int main() {
    vector<datos> datas;
    string aux,month,day,hour,ip,prob,fecha;
	int cont=0,key;
    ifstream data("bitacora.txt");
	if (data.is_open()){
    while (getline(data,aux)){ 
      month="";
      day="";
      hour="";
      ip="";
      prob="";
      cont=0;
			fecha=" ";
			key=0;

//Ciclo que lee cada linea del archivo y separa los datos, para que esto sirva es necesario que se proporcione un archivo con los datos: mes, dia, hora, ip, problema. Todos separados por un espacio de por medio.

      for(int i=0;i<=aux.size()-1;i++){
        if(cont>3){
          prob+=aux[i];
        }
        if(aux[i] != ' '){
            if(cont==0){
                month+=aux[i];
            }else if(cont == 1){
                day+=aux[i];
            }else if(cont==2){
                hour+=aux[i];
            }else if(cont==3){
                ip+=aux[i];
            }
        }else{
          cont++;
        }
      }
      datos temp;
      temp.mes = month;
      temp.dia = day;
      temp.hora = hour;
      temp.IP = ip;
      temp.falla = prob;

// Se crea una llave constituida por mes/dia/hora/minuto/segundo en un string de caracteres que es convertido a un entero para ayudar con el facil ordenamiento de los datos.

			fecha=mesANum(month)+diaCifra(day);
			key=stoi(fecha);
			temp.claveRedux=key;
			for(int i=0;i<8;i++){
				if(hour[i]!=':')
					fecha+=hour[i];
			}
			key= stoi(fecha);// lo convertimos int
      temp.clave = key; //clave con el mes, dia, hora, minuto, segundo: 0312113833
      datas.push_back(temp);
    }
  }
	sort(datas.begin(),datas.end(),orden_Fecha); //Ordenamiento O(n^2)

// Se piden los datos de entrada para desplegar el rango de consultas deseado

	string fechaIni,fechaFin,DiaIni,DiaFin,MesIni,MesFin;
	int claveIni,claveFin;
	cout<<"Ingresa los intervalos de fecha para realizar la búsqueda:\n\nFecha de inicio\nMes: ";
	cin>>MesIni; 
	cout<<"Día: ";
	cin>>DiaIni;
	cout<<"\n\nFecha final\nMes: ";
	cin>>MesFin;
	cout<<"Dia: ";
	cin>>DiaFin;
	claveIni=stoi(fechaIni=mesANum(MesIni)+diaCifra(DiaIni));
	claveFin=stoi(fechaFin=mesANum(MesFin)+diaCifra(DiaFin));

// Busqueda de las posiciones inicial y final del rango de datos deseados utilizando un sort binario.

	int posInicial=binariaIni(datas,claveIni);
	int posFinal=binariaFin(datas,claveFin);

	if(posInicial==-1)
		cout<<"Fecha no registrada\n";
  for(int i = posInicial; i<=posFinal; i++){ // O(n)
    cout << datas[i].mes << " " << datas[i].dia << " " << datas[i].hora << " " << datas[i].IP << " " << datas[i].falla << endl;
	}
  data.close();
  
  //guardado en archivo.txt utilizando un ciclo que escribe desde la posicion inicial encontrada, hasta la final.
  ofstream Save("Resultado.txt");
  if(Save.is_open()){
    for(int i = posInicial; i<=posFinal; i++){//O(n)
    Save << datas[i].mes << " " << datas[i].dia << " " << datas[i].hora << " " << datas[i].IP << " " << datas[i].falla << endl;
  }
  Save.close();
  }else{
    cout<< "No se pudo escribir" <<endl;
  }
	return 0;
}
