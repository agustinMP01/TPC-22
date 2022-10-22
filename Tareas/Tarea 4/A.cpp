#include<bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree{
  int N; 
  vector <T> tree;

  SegmentTree(vector<T> &init) { 
    N = init.size(); //El tamaño es el tamaño del vector inicial
    tree.resize(4*N); // Cuando N no es potencia de 2, hay que alinear, así todo apunta a algo.
    if( ((int)log2(N) % 2) == 0){
        build(0, 0, N-1, init,1);
    }
    else{
        build(0, 0, N-1, init,0);
    }
  }

  T merge_xor(T a, T b){
    return a^b;
  }
  T merge_or(T a, T b){
    return a|b;
  }

  void build(int n, int i, int j, vector<T> &init, int flag){

    if(i == j){ //Caso base, Estamos en una hoja del arbol
      tree[n] = init[i]; //Entonces, el nodo n, una hoja, le ponemos el valor del arreglo que estamos mirando
      return;
    }

    //Caso en un nodo cualquiera
    int mid = (i+j)/2; //Dividimos el intervalo a la mitad
    if(flag == 0){
        build(2*n+1, i, mid, init,1);
        build(2*n+2, mid+1, j, init, 1);
        tree[n] = merge_or(tree[2*n+1], tree[2*n+2]);
    }
    if (flag == 1){
        build(2*n+1, i, mid, init, 0);
        build(2*n+2, mid+1, j, init, 0);
        tree[n] = merge_xor(tree[2*n+1], tree[2*n+2]);
    }
  }

  T query(int l, int r){
    //Retorna la cabeza de ese intervalo
    return query(0, 0, N-1, l, r, 0); //Llama desde la raiz, mira todo el arreglo [0, N-1] y quiero buscar en [l, r]
  }

  T query(int n, int i, int j, int l, int r, int flag){
    //"Builder de Query"
    //n: nodo actual
    //i, j: rango donde estoy mirando
    //l, r: rango objetivo, donde YO quiero ver

    if(l <= i && j <= r) return tree[n];//Caso base
    //Si contengo todo mi [i, j] en [l, r], significa que estoy mirando DENTRO de el objetivo
    //entonces, devuelvo el valor del nodo en donde estoy

    int mid = (i+j)/2; //Busco la mitad del arreglo

    if (flag == 1){
        return merge_xor(
            query(2*n+1, i, mid, l, r, 0), //Hijo izq
            query(2*n+2, mid+1, j, l, r, 0)); //Hijo derecho
    } else{
        return merge_or(
            query(2*n+1, i, mid, l, r, 1), //Hijo izq
            query(2*n+2, mid+1, j, l, r, 1)); //Hijo derecho
    } 

  }

  void update(int t, T val){
    //Actualiza el indice t con el valor val 
    if( ((int)log2(N) % 2) == 0){
        update(0, 0, N-1, t, val, 1);
    }
    else{
        update(0, 0, N-1, t, val, 0);
    }
  }
  
  void update(int n, int i, int j, int t, T val, int flag){

    if(t < i || j < t) return; //Caso base, si no ecuentra t, no hce nada

    if(i == j){ //Llegamos a t y actualizamos el valor
      tree[n] = val;
      return;
    }

    int mid = (i+j)/2; //Veo la mitad

    if (flag == 0){
        update(2*n+1, i, mid, t, val, 1); //Busco en el hijo izquierdo
        update(2*n+2, mid+1, j, t, val, 1); //Busco en el hijo derecho

        tree[n] = merge_or(tree[2*n+1], tree[2*n+2]); //Al actualizar los dos hijos, tenemos que volver a mergear el nodo actual
    } else if (flag == 1){
        update(2*n+1, i, mid, t, val, 0); //Busco en el hijo izquierdo
        update(2*n+2, mid+1, j, t, val, 0); //Busco en el hijo derecho

        tree[n] = merge_xor(tree[2*n+1], tree[2*n+2]); //Al actualizar los dos hijos, tenemos que volver a mergear el nodo actual
    }

  }
};

int main(){
    int n, m, i, x;
    cin >> n; //Para el largo 2^n
    long long largo = 1 << n;
    cin >> m; //Cuantas query se harán
    vector<int> a(largo); //Defino el vector a con los numeros base del arbol

    for (int i = 0; i < largo; i++){ //Lleno a
        cin >> a[i];
    }

    SegmentTree<int> st(a); //Creo el segment tree con a

    while (m>0){
        cin >> i; //Indice a cambiar
        cin >> x; //Valor a cambiar

        //Quiero actualizar el valor y devolver la cabeza
        st.update(i-1, x);
        cout << st.query(0, largo-1) << "\n";
        m--;
    }
    
    return 0;
}