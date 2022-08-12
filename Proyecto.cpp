#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <cstdlib>

#define cantMaxNombre 50
#define cantMaxJugadores 50

using namespace std;

//estructura de cada jugador por separado
struct perfil{
	int edad;
	char nombre[cantMaxNombre];
	char apellido[cantMaxNombre];
	char ciudad[cantMaxNombre];
	float dinero; 
	float ganancias;
	float perdidas;
} lista[cantMaxJugadores];	//vector de los jugadores

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
void registroJugadores(int x, int num){
	for (int i=0;i<num;i++){
		fflush(stdin);
		cout<<"Digite su nombre: "<<endl; cin.getline(lista[i].nombre,cantMaxNombre, '\n');
		cout<<"Digite su apellido: "<<endl; cin.getline(lista[i].apellido,cantMaxNombre, '\n');
		cout<<"Digite su ciudad: "<<endl; cin.getline(lista[i].ciudad,cantMaxNombre, '\n');
	  	cout<<"Digite su edad: "<<endl; cin>>(lista[i].edad);
	  	cout<<"Ingrese la cantidad de dinero a jugar: "<<endl; cin>>(lista[i].dinero);
		if (lista[i].dinero < 1000){
			cout<<"No puede jugar el jugador que esta registrando por no cumplir con la cantidad minima de dinero"<<endl;
			eliminarJugador(x,num);		//llamada de la funcion eliminar para quitar el jugador que no cumple con la cantidad minima de dinero
		}
		system("pause");
		system("cls");
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

//Funcion del juego de dado
void dado(int x, int numero){
int numeroGanador=0,num_jugador;            //numero = lo que el usuario ingresa para apostar
	numeroGanador= 1 + rand() %6;							//numero aleatorio entre 1 y 6
	cout<<"El numero ganador es "<<numeroGanador<<endl;
	if (numero==numeroGanador){
		lista[num_jugador-1].dinero += 500;		//añade las ganancias al dinero del jugador
		lista[num_jugador-1].ganancias += 500;	//añade las ganancias a las ganancias de la estructura del jugador
		cout<<"FELICIDADES GANO!!!"<<endl;
	}else{
		lista[num_jugador-1].dinero -= 350;		//añade las perdidas al dinero del jugador
		lista[num_jugador-1].perdidas += 350;	//añade las perdidas a las perdidas de la estructura del jugador
		cout<<"Lamentablemente perdiste"<<endl;
	}
}

//funcion del juego de la moneda
void moneda(int num_jugador, int numero){
	string nombre = "";	
	int numeroGanador=0;		//numero = lo que el usuario ingresa para apostar
	numeroGanador= 1 + rand() %2;
	if (numeroGanador == 1){
		nombre="Cara";
	}else{
		nombre="Sello";
	}
	cout<<"El lado ganador es "<<nombre<<endl;
	if (numero == numeroGanador){
		lista[num_jugador-1].dinero += 100;		//añade las ganancias al dinero del jugador
		lista[num_jugador-1].ganancias +=100;	//añade las ganancias a las ganancias de la estructura del jugador
		cout<<"FELICIDADES GANO!!!"<<endl;
	}else{
		lista[num_jugador-1].dinero -= 150;		//añade las perdidas al dinero del jugador
		lista[num_jugador-1].perdidas += 150;	//añade las perdidas a las perdidas de la estructura del jugador
		cout<<"Lamentablemente perdiste"<<endl;
	}
}

//funcion de menu
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


//funcion main
int main(){
  setlocale(LC_ALL,"spanish");
	int ed,num,numero,numeroGanador,opcion,opcionJuego,num_jugador,x;		//declaracion de variables
	
	cout<<"Bienvenido a su casino de confianza\n\n"<<endl;
	fflush(stdin);						//funcion para limpiar el buffer y  evitar inconvenientes
	cout<<"Digite su edad para permitir su acceso"<<endl; cin>>ed;
	system("pause");
	system("cls");
	if (ed >= 18){
    	do{
			menu(); cin>>opcion;		//llamada de la funcion menu
			system("pause");
			system("cls");
			switch (opcion){
				case 1:
					registro:			//destino del goto para registrar jugadores asi se seleccione otra opcion primero que no sea la de regitrar jugadores
					cout<<"\n Numero de jugadores: ";
       		    	cin>>num;
					registroJugadores(x,num);		//llamada de la funcion registro de jugadores
					system("pause");
					system("cls");
					break;
				case 2:
					if(num>0){
						cout<<"\n Ingrese numero de jugador: ";
				  		cin>> num_jugador;
						cout<<"\tQue desea jugar \n1. Dados\n2. Moneda"<<endl; cin>>opcionJuego;
						if(opcionJuego==1){
							cout<<"Digite el numero al que desea apostar (1 a 6)"<<endl; cin>>numero;
							dado(num_jugador,numero);			//llamada de la funcion del juego del dado
						}else if(opcionJuego == 2){
							cout<<"Digite el numero al que desea apostar (1. cara   2. sello)"<<endl; cin>>numero;
							moneda(num_jugador,numero);			//llamada de la funcion del juego de la moneda
						}
						}else{
							cout<<"Registro vacio!!"<<endl;
							goto registro;
						}
						system("pause");
						system("cls");
						break;
				case 3:
					if(num>0){
						cout<<"\n Ingrese numero de jugador que desea eliminar: ";
						cin>> num_jugador;
						eliminarJugador(num_jugador-1,num);			//llamada de la funcion eliminar jugador
					}else{
						cout<<"Registro vacio!!"<<endl;
						goto registro;
					}
					system("pause");
					system("cls");
				 	break;
				case 4:
					if(num>0){
						cout<<"\n Ingrese numero de jugador que desea ver: ";
						cin>> num_jugador;
						datosJugador(num_jugador-1,num);	//llamada de la funcion para mostrar los datos del jugador seleccionado
					}else{
						cout<<"Registro vacio!!"<<endl;
						goto registro;	
					}
					system("pause");
					system("cls");
					break;
				case 5:
					if(num>0){
						cout<<"\n Ingrese numero de jugador que desea ver: ";
						cin>> num_jugador;
						cout<<"Ganancias: "<<lista[num_jugador-1].ganancias<<endl;		//muestra las ganacias totales despues del tiempo de juego
						cout<<"Perdidas: "<<lista[num_jugador-1].perdidas<<endl;		//muestra las perdidas totales despues del tiempo de juego
						cout<<"Dinero actual del jugador: "<<lista[num_jugador-1].dinero<<endl;			//muestra el dinero total despues del tiempo de juego
					}else{
						cout<<"Registro vacio!!"<<endl;
						goto registro;		
					}
					system("pause");
					system("cls");
					break;
			}
		}while(opcion!=6 && opcion<6);
	}else{
			cout<<"No cumple con la edad minima requerida!!"<<endl;
	}
}
