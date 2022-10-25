#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

template <class T>
struct SegmentTree{
  int N;
  vector <T> tree;

  SegmentTree(vector<T> &init) {
    N = init.size();
    tree.resize(4*N);
    build(0, 0, N-1, init);
  }

    

  T merge(T a, T b) {
    int count = 0;

    if (get<0>(a) == get<0>(b)) {
        count = get<1>(a) + get<1>(b);
        return make_tuple(get<0>(a), count);
    }

    int mcd = gcd(get<0>(a),get<0>(b));

    if (mcd == get<0>(a)) {
        count = get<1>(a);
    }
    if (mcd == get<0>(b)) {
        count = get<1>(b);
    }
    return make_tuple(mcd, count); 
  }

  void build(int n, int i, int j, vector<T> &init){
    if(i == j){
      tree[n] = init[i];
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid, init);
    build(2*n+2, mid+1, j, init);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  T query(int l, int r){
    return query(0, 0, N-1, l, r);
  }

  T query(int n, int i, int j, int l, int r){
    if(l <= i && j <= r) return tree[n];
    //[l, [i ,   j]    r]

    int mid = (i+j)/2;

    if(mid < l || r < i)
    //[i,mid][l,r] || [l,r][i,mid]
      return query(2*n+2, mid+1, j, l, r);

    if(j < l || r < mid+1)
    //[mid+1, j][l, r] || [l, r][mid+1, j]
      return query(2*n+1, i, mid, l, r);

    //[l (i, r], mid) || (mid+1, [l,   j)  r] 
    return merge(
        query(2*n+1, i, mid, l, r),
        query(2*n+2, mid+1, j, l, r));
  }

  void update(int t, T val){
    update(0, 0, N-1, t, val);
  }
  
  void update(int n, int i, int j, int t, T val){
    if(t < i || j < t) return;
    if(i == j){
      tree[n] = val;
      return;
    }
    int mid = (i+j)/2;
    update(2*n+1, i, mid, t, val);
    update(2*n+2, mid+1, j, t, val);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};
//

int main(){
    int n;  // Cantidad de elenentos
    int num;
    cin >> n;
    vector<tuple<int, int>> a(n);
    for(int i=0; i<n;i++){
        cin >> num; 

        a.push_back(make_tuple(num, 1));
    }

    cout << "me llené\n";

    SegmentTree<tuple<int, int>> st(a); // arbol
    int c;
    cin >> c; // cantidad de consultas 

    while(c > 0){
        int l,r;
        cin >> l;
        cin >> r;
        int ans = get<0>(st.query(l-1,r-1)); //gcd en [l-1, r-1]
        cout << "Las hormigas " << ans <<" ganan\n";

        int freed = get<1>(st.query(l-1,r-1));
        cout << "Voy a soltar " << freed << " hormigas\n";
        cout << (r-l+1)-freed << "\n";
        c--;
    }
    return 0;
}