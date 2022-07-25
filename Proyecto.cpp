#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#define cantMaxNombre 50
#define cantMaxJugadores 50

using namespace std;

struct perfil{
	int edad;
	char nombre[cantMaxNombre];
	char apellido[cantMaxNombre];
	char ciudad[cantMaxNombre];
	float dinero;
};

struct perfil lista[cantMaxJugadores];


void registroJugadores(int n){
	for (int i=0;i<n;i++){
		cout<<"Digite su nombre"<<endl; cin.getline(lista[i].nombre,cantMaxNombre, '\n');
		cout<<"Digite su apellido"<<endl; cin.getline(lista[i].apellido,cantMaxNombre, '\n');
		cout<<"Digite su ciudad"<<endl; cin.getline(lista[i].ciudad,cantMaxNombre, '\n');
	    cout<<"Digite su edad"<<endl; cin>>lista[i].edad;
	    cout<<"Ingrese la cantidad de dinero a jugar"<<endl; cin>>lista[i].dinero;
	}
}

void datosJugador(int x, int num){
	if (num>0){
		cout<<"\n\tNombre: "<<lista[x].nombre<<' '<<lista[x].apellido<<endl;
		cout<<"\tCiudad: "<<lista[x].ciudad<<endl;
		cout<<"\tEdad: "<<lista[x].edad<<endl;;
		cout<<"\tDinero Inicial: "<<lista[x].dinero<<endl;;
	}
}







void menu(){
	cout<<"\n\t\tOPCIONES PARA JUGADORES\n\n";
	cout<<"1. Registrar jugadores"<<endl;
	cout<<"2. Mostrar datos del jugador"<<endl;
	cout<<"3. Mostrar dinero del jugador"<<endl;
	cout<<"4. Eliminar jugador"<<endl;
	cout<<"5. Jugar"<<endl;
	cout<<"6. Salir"<<endl;

	cout<<"\nIngrese una opción: ";
}






int main(){
  setlocale("LC_ALL,spanish");
	int ed,num,opcion;
    do{
	cout<<"Digite su edad para permitir su acceso"<<endl; cin>>ed;
    if (ed >= 18){
    	if (lista[num].dinero >= 1000){





		}else{
			cout<<"No puede jugar con esa cantidad de dinero, se requiere minimo un ingreso de $1000"<<endl;
			break;
		}
	}else{
		cout<<"No cumple con la edad minima requerida!!"<<endl;
	}
	}while(opcion==true);
}
