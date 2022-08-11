#include <iostream>
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

// funcion para eliminar jugador
void eliminarJugador(int x, int &num){
	if(num>0){
		for(int i=x;i<num-1;i++)
			lista[i]=lista[i+1];
		num--;
	}
	else{
		cout<<"\n\tRegistro vacio..!";
	}
}

//Registro de jugadores
void registroJugadores(int n){
	for (int i=0;i<n;i++){
		fflush(stdin);
		cout<<"Digite su nombre: "<<endl; cin.getline(lista[i].nombre,cantMaxNombre, '\n');
		cout<<"Digite su apellido: "<<endl; cin.getline(lista[i].apellido,cantMaxNombre, '\n');
		cout<<"Digite su ciudad: "<<endl; cin.getline(lista[i].ciudad,cantMaxNombre, '\n');
  	cout<<"Digite su edad: "<<endl; cin>>(lista[i].edad);
  	cout<<"Ingrese la cantidad de dinero a jugar: "<<endl; cin>>(lista[i].dinero);
		if (lista[i].dinero < 1000){
			cout<<"No puede jugar el jugador que esta registrando por no cumplir con la cantidad minima de dinero"<<endl;
			eliminarJugador(i);
		}
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
bool dado(int numero){            //numero = lo que el usuario ingresa para apostar
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
bool moneda(int numero){
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
		resultadoMoneda = false;
		cout<<"Lamentablemente perdiste"<<endl;
	}
}

// funcion valor apuestas
float dineroJugador(float lista[i].dinero,int opcionJuego){
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
	int ed,num,numero,numeroGanador,opcion,opcionJuego,num_jugador;

    do{
    	fflush(stdin);
			cout<<"Digite su edad para permitir su acceso"<<endl; cin>>ed;
    	if (ed >= 18){
				menu(); cin>>opcion;
				switch (opcion){
					case 1:
						cout<<"\n Numero de jugadores: ";
            cin>> num;
						registroJugadores(num);
						break;
					case 2:
					  cout<<"\n Ingrese numero de jugador: ";
					  cin>> num_jugador;
						cout<<"\tQue desea jugar \n1. Dados\n2. Moneda"<<endl; cin>>opcionJuego;
						if(opcionJuego==1){
							cout<<"Digite el numero al que desea apostar (1 a 6)"<<endl; cin>>numero;
							dado(numero);
							dineroJugador(num_jugador-1,opcionJuego);
						}else if(opcionJuego == 2){
							cout<<"Digite el numero al que desea apostar (1. cara   2. sello)"<<endl; cin>>numero;
							moneda(numero);
							dineroJugador(num_jugador-1,opcionJuego);
						}
						break;
					case 3:
						cout<<"\n Ingrese numero de jugador que desea eliminar: ";
						cin>> num_jugador;
						eliminarJugador(num_jugador-1,num);
					  break;
					case 4:
						cout<<"\n Ingrese numero de jugador que desea ver: ";
						cin>> num_jugador;
						datosJugador(num_jugador-1,num);
					case 5:
						cout<<"\n Ingrese numero de jugador que desea ver: ";
						cin>> num_jugador;
						cout<<"Dinero actual del jugador: "<<lista[num_jugador-1].dinero<<endl;
				}

		}else{
			cout<<"No cumple con la edad minima requerida!!"<<endl;
		}
	}while(opcion!=6);
}
