#include <iostream>
#include<set>
#define MAX 10000
using namespace std;
int N, M;
int u[MAX];
int v[MAX];
int c[MAX]; // c[i] la trong so cua canh (u[i], v[i])
int rank1[MAX]; // rank[v] rank cua set v
int p[MAX];
// 8 15
// 1 3 1
// 1 7 1
// 1 8 1
// 1 6 8
// 2 4 6
// 2 5 2
// 2 6 5
// 3 5 1
// 3 6 1
// 4 6 7
// 4 7 1
// 4 8 3
// 5 6 1
// 6 7 8
// 7 8 2

int link(int x, int y){
    if(rank1[x]> rank1[y]) p[y] = x;
    else{
        p[x] = y;
        if(rank1[x]== rank1[y]) rank1[y] = rank1[y]+1;
    }
}
void makeSet(int x){
    p[x] = x;
    rank1[x] = 0;
}
int findSet(int x){
    if(x!=p[x]) p[x] = findSet(p[x]);
    return p[x];
}
void input(){
    cin>>N>>M;
    for(int i=0;i<M; i++){
        int ui, vi, ci;
        cin>>ui>>vi>>ci;
        u[i] = ui;
        v[i] = vi;
        c[i] = ci;
    }
    
}
void swap(int &a, int &b){
    int temp = a;
    a=b; b= temp;
}
void swapEdge(int i, int j){
    swap(c[i], c[j]);
    swap(u[i], u[j]);
    swap(v[i], v[j]);
}
int partion(int L, int R, int index){
    int pivot = c[index];
    swapEdge(index, R);
    int storeIndex = L;
    for(int i=L; i<R-1; i++){
        if(c[i]<pivot){
            swapEdge(storeIndex, i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex, R);
    return storeIndex;
    
}
void quicksort(int L, int R){
    if(L<R){
        int index = (L+R)/2;
        index = partion(L, R, index);
        if(L<index) quicksort(L, index-1);
        if(R> index) quicksort(index+1, R);
    }
}

void solve(){
    for(int x =1; x<M; x++){
        makeSet(x);
        
    }
    quicksort(0, M-1);
    int rs =0;
    int count =0;
    for(int i=0;i<M; i++){
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru!=rv){
            link(ru, rv);
            rs +=c[i];
            count++;
            if(count==N-1) break;
        }
    }
    cout<<rs;
}

int main()
{
   input();
   solve();
   
   return 0;
}