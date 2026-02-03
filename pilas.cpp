#include <iostream>  

using namespace std;

struct Habitacion{
    int numEnemigos;
    Habitacion* siguiente;
};
void push(Habitacion*& habitacion){
    Habitacion* nuevo = new Habitacion;
    cout<<"Ingrese la cantidad de enemigos : " << endl;
    cin>> nuevo->numEnemigos;
    nuevo->siguiente = habitacion;
    habitacion = nuevo;

    cout<<"Se agrego la habitacion :D"<<endl;
}

bool estaVacia(Habitacion* habitacion){
    if(habitacion == nullptr){
        cout<<"la pila esta vacia"<<endl;
        return true;
    } else{
        return false;
    }
}

void pop(Habitacion*& habitacion){
    if(estaVacia(habitacion))
        return;

    Habitacion* aux = new Habitacion;
    aux = habitacion;
    habitacion = habitacion->siguiente;

    delete aux;
    cout<<"Se elimino lel elmento :D"<<endl;
}   

void mostrar(Habitacion* habitacion){
    if(estaVacia(habitacion))
        return;

    int i = 1;

    while(habitacion != nullptr){
        cout<<"\t|------Sala"<< i << "------|"<<endl;
        cout<<"cantidad de enemigos:" << habitacion->numEnemigos << endl;

        habitacion = habitacion->siguiente;
        i++;
        
    }
}


int main(){
    Habitacion* habitacion= nullptr;
     int opcion;
     do{
        cout<<"Seleccione una opcion:"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1: push(habitacion);
                break;
            case 2: pop(habitacion);
                break;
            case 3: mostrar(habitacion);
                break;
            case 4: 
                cout<<"Hasta la proxima!!"<<endl;
                break;
            default:
                cout<<"Seleccione una opcion valida!!"<<endl;
        }


     }while(opcion!=5);


    return 0;
}
