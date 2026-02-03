#include <iostream>

using namespace std;

struct persona {
    string nombre;
    int edad;
 persona* siguiente;
};

bool estaVacia(persona* frente){
    if(frente == nullptr){
        cout<<"La persona esta vacia :( )"<<endl;
        return true;
    } else{
        return false;
    }
}

void push (persona*& frente, persona*& fin){
 persona*nuevo = new persona;
    cout<<"Ingrese nombre: "<<endl;
    getline (cin, nuevo->nombre);
    cout<<"Ingrese edad: "<<endl;
    cin>> nuevo->edad;

    nuevo->siguiente= nullptr;

    if(frente== nullptr){
        frente=nuevo;
    }else{
        fin->siguiente=nuevo;
        fin=nuevo;
    }
    fin = nuevo;

    cout<<"\n se agrego la nueva persona a la cola :D \n "<<endl;
}

void borrar (persona*& frente, persona*& fin){
    //funcion para eliminar un nodo de la persona
    if(estaVacia(frente))
        return;
 persona* aux = frente;

    if(frente == fin){
    frente = nullptr;
    fin = nullptr;
    } else{
        frente = frente->siguiente;
    }
cout<<"\n se atencio a "<<aux->nombre<<":D \n\n";
    delete aux;
}

void mostrar(persona*& frente, persona*& fin){
    if(estaVacia(frente))
        return;

    int i = 1;
    while(frente != nullptr){
        cout<<"\t|------persona"<< i << "------|"<<endl;
        cout<<"nombre: "<<frente->nombre<<endl;
        cout<<"edad: "<<frente->edad<<endl;
        i++;
        frente = frente->siguiente;
    }
    
}


int main(){
 persona* frente = nullptr;
 persona* fin = nullptr;

    int cantidad, opcion;

do{
    cout<<"Seleccione una opcion: "<<endl;
    cout<<"1. Agregar persona a la cola"<<endl;
    cout<<"2. Eliminar persona de la cola"<<endl;
    cout<<"3. Mostrar todas las personas que se encuentran en la cola"<<endl;
    cout<<"4. Salir"<<endl;
    cin>> opcion;

    switch(opcion){
        case 1: 
            push (frente, fin);
            break;
        case 2:
            borrar (frente, fin);
            break;
        case 3:
            break;
        case 4:
        cout<<" Arrivirederci :D "<<endl;
            break;
        default:
         cout<<" ingresar una opcion valida!!!"<<endl;
}
}while(opcion !=5);
    return 0;
}
