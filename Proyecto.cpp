#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>

#define cantMaxNombre 50
#define cantMaxJugadores 50

using namespace std;

struct perfil{
	int edad;
	char nombre[cantMaxNombre];
	char apellido[cantMaxNombre];
	char ciudad[cantMaxNombre];
	float dinero;
} lista[cantMaxJugadores];

//Registro de jugadores
void registroJugadores(int n){
	for (int i=0;i<n;i++){
		fflush(stdin);
		cout<<"Digite su nombre"<<endl; cin.getline(lista[i].nombre,cantMaxNombre, '\n');
		cout<<"Digite su apellido"<<endl; cin.getline(lista[i].apellido,cantMaxNombre, '\n');
		cout<<"Digite su ciudad"<<endl; cin.getline(lista[i].ciudad,cantMaxNombre, '\n');
	  	cout<<"Digite su edad"<<endl; cin>>(lista[i].edad);
	  	cout<<"Ingrese la cantidad de dinero a jugar"<<endl; cin>>(lista[i].dinero);
	}
}
//Muestra los datos del jugador
void datosJugador(int x, int num){
	if (num>0){
		fflush(stdin);
		cout<<"\n\tNombre: "<<lista[x].nombre<<' '<<lista[x].apellido<<endl;
		cout<<"\tCiudad: "<<lista[x].ciudad<<endl;
		cout<<"\tEdad: "<<lista[x].edad<<endl;
		cout<<"\tDinero Inicial: $"<<lista[x].dinero<<endl;
	}
}

//Funcion de Resultados de los juegos
int dado(int numero){            //numero = lo que el usuario ingresa para apostar
	bool resultadoDado;
	numeroGanador= 1 + rand() %6;							//numero aleatorio entre 1 y 6
	cout<<"El numero ganador es "<<numeroGanador<<endl;
	if (numero==numeroGanador){
		resultadoDado = true;
		cout<<"FELICIDADES GANO!!!"<<endl;
	}else{
		resultadoDado = false;
		cout<<"Lamentablemente perdiste"<<endl;
	}
}
int moneda(int numero){
	string nombre = "";			//numero = lo que el usuario ingresa para apostar
	bool resultadoMoneda;
	numeroGanador= 1 + rand() %2;
	if (numeroGanador == 1){
		nombre="Cara";
	}else{
		nombre="Sello";
	}
	cout<<"El lado ganador es "<<nombre<<endl;
	if (numero == numeroGanador){
		resultadoMoneda = true;
		cout<<"FELICIDADES GANO!!!"<<endl;
	}else{
		resultadoMonea = false;
		cout<<"Lamentablemente perdiste"<<endl;
	}
}

// funcion valor apuestas
float dineroJugador(lista[i].dinero,int opcionJuego){
	float ganancias=0, perdidas=0;
	cout<<"\tDinero Inicial: $"<<lista[x].dinero<<endl;
	if (opcionJuego == 1){					//juego es dado
		if (resultadoDado == true){
			ganacias+=500;
			lista[x].dinero += ganancias;
		}else{
			perdidas+=350;
			lista[x].dinero -= perdidas
		}	
	}else if(opcionJuego == 2){
		if (resultadoMoneda == true){
			ganacias+=100;
			lista[x].dinero += ganancias;
		}else{
			perdidas+=150;
			lista[x].dinero -= perdidas;
	}
	cout<<"Su dinero actual es: $"<<lista[x].dinero;
}

void eliminarJugador(){  // funcion para eliminar jugador 'ejemplo eliminar_vendedor'
	
	
	
	
}


void menu(){
	fflush(stdin);
  	cout<<"\n\t\tOPCIONES PARA JUGADORES\n\n";
	cout<<"1. Registrar jugadores"<<endl;
	cout<<"2. Jugar"<<endl;
	cout<<"3. Eliminar jugador"<<endl;
	cout<<"4. Mostrar datos del jugador"<<endl;
	cout<<"5. Mostrar dinero del jugador"<<endl;
	cout<<"6. Salir"<<endl;

	cout<<"\nIngrese una opción: ";
}



int main(){
  setlocale("LC_ALL,spanish");
	int ed,num,opcion,opcionJuego;
	
    do{
    	fflush(stdin);
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
	}while(opcion!=6);
}
