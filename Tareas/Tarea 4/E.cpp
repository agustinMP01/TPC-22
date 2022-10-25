#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

template <class T>
struct SegmentTree{
  int N; 
  vector <T> tree; 

  //Constructor de la clase, &init es la dirección del vector que se usará al inicializar
  SegmentTree(vector<T> &init) { 
    N = init.size(); //El tamaño es el tamaño del vector inicial
    tree.resize(4*N); // Cuando N no es potencia de 2, hay que alinear, así todo apunta a algo.
    build(0, 0, N-1, init); //Construyo el segment tree desde el nodo 0, en [0,N-1] con el arreglo init
  }

  T merge(T a, T b){ 

    if (get<0>(a) == get<0>(b)) {
        return a;
    }

    int max_val = max(get<0>(a), get<0>(b));
    int index = 0;
    
    if (max_val == get<0>(a)) {
        index = get<1>(a);
    } 
  
    if (max_val == get<0>(b)) {
        index = get<1>(b);
    }

    return make_tuple(max_val, index);
  }

  void build(int n, int i, int j, vector<T> &init){
    //n: id del nodo actual
    //i, j: el intervalo en donde estamos construyendo
    //&init la direccion del vector que vamos a usar

    if(i == j){ //Caso base, Estamos en una hoja del arbol
      tree[n] = init[i]; //Entonces, el nodo n, una hoja, le ponemos el valor del arreglo que estamos mirando
      return;
    }

    //Caso en un nodo cualquiera
    int mid = (i+j)/2; //Dividimos el intervalo a la mitad
    build(2*n+1, i, mid, init); //Construye el hijo izquierdo
    build(2*n+2, mid+1, j, init); //Construye el hijo derecho
    tree[n] = merge(tree[2*n+1], tree[2*n+2]); //Guardamos el valor del nodo actual, que es la operacion entre los hijos
  }

  T query(int l, int r){
    //Retorna la cabeza de ese intervalo
    return query(0, 0, N-1, l, r); //Llama desde la raiz, mira todo el arreglo [0, N-1] y quiero buscar en [l, r]
  }

  T query(int n, int i, int j, int l, int r){

    if(l <= i && j <= r) return tree[n];//Caso base

    int mid = (i+j)/2; //Busco la mitad del arreglo

    if(mid < l || r < i) //Si estoy fuera totalmente del arreglo, es decir, quiero buscar a la izq o a la der
    //[i, mid][l, r] || [l, r][i, mid]
      return query(2*n+2, mid+1, j, l, r); //Query desde el hijo derecho, y "subo el piso" del rango en donde estoy buscando

    if(j < l || r < mid+1)
    //[mid+1, j][l, r] || [l, r][mid+1, j]
      return query(2*n+1, i, mid, l, r); //Query desde el hijo izquierdo, "bajo el techo" del rango en donde estoy buscando

    //Si no se cumple ninguno, significa que estoy con medio rango metido en el otro  
    return merge(
        query(2*n+1, i, mid, l, r), //Hijo izq
        query(2*n+2, mid+1, j, l, r)); //Hijo derecho
  }

  void update(int t, T val){
    //Actualiza el indice t con el valor val 
    update(0, 0, N-1, t, val); //Llama en el nodo 0, viendo el intervalo [0, N-1], busca el indice t y el valor
  }
  
  void update(int n, int i, int j, int t, T val){

    if(t < i || j < t) return; //Caso base, si no ecuentra t, no hce nada

    if(i == j){ //Llegamos a t y actualizamos el valor
      //cout << "en " << n << " puse " << get<0>(val) << " con indice " << get<1>(val) << "\n";
      tree[n] = val;
      //cout << "en " << n << " puse " << get<0>val << " con indice " << get<1>val << "\n";
      return;
    }

    int mid = (i+j)/2; //Veo la mitad
    update(2*n+1, i, mid, t, val); //Busco en el hijo izquierdo
    update(2*n+2, mid+1, j, t, val); //Busco en el hijo derecho

    tree[n] = merge(tree[2*n+1], tree[2*n+2]); //Al actualizar los dos hijos, tenemos que volver a mergear el nodo actual
  }

};

int main(){
    int n, num, q;
    cin >> n;
    
    vector<tuple<int,int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> num;
        tuple<int, int> my_tuple = {num, i};
        a[i] = my_tuple;
    }
    
    SegmentTree< tuple<int,int> > st(a); //Hace un arbol st de tuplas int 

    cin >> q; //Cantidad de querys a hacer

    while (q>0) {
        char type;
        int x,y; //(Indice, valor) || (rango inf, rango sup)

        cin >> type;
        cin >> x;
        cin >> y;

        if (type == 'U') {
            //x parte desde 1
            tuple<int, int> my_tuple = {y, x-1};
            //a[x-1] = my_tuple;
            //SegmentTree< tuple<int,int> > st(a);

            //cout << "voy a poner "<< get<0>(my_tuple) << " con indice " << get<1>(my_tuple) << "\n";
            st.update(x-1, my_tuple);
            a[x-1] = my_tuple; 
            q--;
            continue;
        }

        if (type == 'Q') {
            // x e y parten desde 1
            int imax1 = get<1>(st.query(x-1,y-1)); //Consigo el indice del valor maximo en el rango [x, y]
            //cout << "mi indice 1 es " << imax1 << "\n";
            int max1 = get<0>(a[imax1]); //Guardo el valor maximo del rango [x, y]
            //cout << "en mi indice 1 encontré: " << max1 << "\n";
            st.update(imax1, make_tuple(-1, imax1)); //Cambia el valor del maximo a -1

            int imax2 = get<1>(st.query(x-1,y-1)); //Consigo el indice del nuevo valor maximo en el rango [x, y]
            //cout << "mi indice 2 es " << imax2 << "\n";
            int max2 = get<0>(a[imax2]); //Guardo el nuevo valor maximo
            //cout << "en mi indice 2 encontré: " << max2 << "\n";

            st.update(imax1, make_tuple(max1, imax1)); //Devuelvo el arbol a su estado original

            cout << max1 + max2 << "\n";
        }
        q--;
    }

    return 0;
}
