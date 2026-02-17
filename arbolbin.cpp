#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *hI;
    nodo *hD;
};

class ArbolBinario{
    private:
        nodo *pArbol;
    public:
        ArbolBinario();
        void menu(void);
        void mostrarPre(void);
        void mostrarPre(nodo *);
        void mostrarPost(void);
        void mostrarPost(nodo *);
        void mostrarIn(void);
        void mostrarIn(nodo *);
        void insertar(void);
        void insNodo(nodo **, int);
        void buscar(void);
        void buscar(nodo *, int);
        bool borrarNodo(nodo **, int);
};

ArbolBinario::ArbolBinario(){
    pArbol = NULL;
}

void ArbolBinario::mostrarPre(void){
    cout << "Los nodos en pre orden son:" << endl;
    mostrarPre(pArbol);
}

void ArbolBinario::mostrarPre(nodo *s){
    if(s != NULL){
        cout << s->dato << endl;
        mostrarPre(s->hI);
        mostrarPre(s->hD);
    }
}

void ArbolBinario::mostrarPost(void){
    cout << "Los nodos en post orden son:" << endl;
    mostrarPost(pArbol);
}

void ArbolBinario::mostrarPost(nodo *s){
    if(s != NULL){
        mostrarPost(s->hI);
        mostrarPost(s->hD);
        cout << s->dato << endl;
    }
}

void ArbolBinario::mostrarIn(void){
    cout << "Los nodos en in orden son:" << endl;
    mostrarIn(pArbol);
}

void ArbolBinario::mostrarIn(nodo *s){
    if(s != NULL){
        mostrarIn(s->hI);
        cout << s->dato << endl;
        mostrarIn(s->hD);
    }
}

void ArbolBinario::insertar(void){
    char resp;
    int dato;

    do{
        cout << "Desea insertar una llave (s/n? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Proporcione una llave: ";
            cin >> dato;
            insNodo(&pArbol, dato);
        }
    }while(resp == 's');
}

void ArbolBinario::insNodo(nodo **s, int dato){
    if(*s == NULL){
        *s = new nodo;
        (*s)->dato = dato;
        (*s)->hI = NULL;
        (*s)->hD = NULL;
    }
    else
        if(dato < (*s)->dato)
            insNodo(&((*s)->hI), dato);
        else
            if(dato > (*s)->dato)
                insNodo(&((*s)->hD), dato);
            else
                cout << "La llave ya se encuentra en el arbol." << endl;
}

void ArbolBinario::buscar(void){
    int dato;
    cout << "Digite la llave a buscar: ";
    cin >> dato;
    buscar(pArbol, dato);
}
void ArbolBinario::buscar(nodo *s, int dato){
    if(s == NULL)
        cout << "La llave no esta en el arbol." << endl;
    else
        if(dato < s->dato)
            buscar(s->hI, dato);
        else
            if(dato > s->dato)
                buscar(s->hD, dato);
            else
                cout << "La llave se encuentra en el arbol." << endl;
}

bool ArbolBinario::borrarNodo(nodo **s, int dato)
{
    nodo *p, *q;
    
    if(*s == NULL) //Si se llegó a un NULL.
        return false;
    else
        if(dato < (*s)->dato) //Buscar por subárbol izquierdo del nodo.
            borrarNodo(&((*s)->hI), dato);
        else
            if(dato > (*s)->dato) //Buscar por subárbol derecho del nodo.
                borrarNodo(&((*s)->hD), dato);
            else{ //El borrado del nodo se hace a partir de aquí:
                if((*s)->hI == NULL && (*s)->hD == NULL){ //Si el nodo a borrar
                    p = *s;                               //es una hoja.
                    *s = NULL;
                }
                else
                    if((*s)->hI == NULL && (*s)->hD != NULL){ //Si el nodo a borrar
                        p = *s;                               //solo tiene hijo derecho.
                        *s = (*s)->hD;
                    }
                    else
                        if((*s)->hI != NULL && (*s)->hD == NULL){ //Si nodo a borrar
                            p = *s;                               //solo tiene hijo izquierdo.
                            *s = (*s)->hI;
                        }
                        else
                            if((*s)->hI != NULL && (*s)->hD != NULL){ //Si el nodo a borrar
                                p = q = (*s)->hI;                     //tiene dos hijos.
                                while(p->hD != NULL){
                                    q = p;
                                    p = p->hD;
                                }
                                if(q != p){
                                    (*s)->dato = p->dato;
                                    q->hD = p->hI;
                                }
                                else{
                                    (*s)->dato = p ->dato;
                                    (*s)->hI = p->hI;
                                    
                                }
                            }
                delete p;
                return true;
            }
}

void ArbolBinario::menu(void){
    int opcion;
    do{
        cout << "Las opciones son:" << endl;
        cout << "1) Insertar llaves." << endl;
        cout << "2) Mostrar todas las llaves." << endl;
        cout << "3) Buscar una llave." << endl;
        cout << "4) Salir." << endl;
        cout << "Digite su opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                insertar();
                break;
            case 2:
                mostrarIn();
                break;
            case 3:
                buscar();
                break;
        }
    }while(opcion != 4);
}

int main(void){
    ArbolBinario miArbol;

    miArbol.menu();

    return 0;
}