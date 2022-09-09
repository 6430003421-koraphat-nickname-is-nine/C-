#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


void timeplus(map<int,int> &m){
    for(map<int,int>::iterator x; x!=m.end(); x++){
        x->second+=1;
    }
}
void clear_table(map<int,int> &m,map<int,int> &ct,queue<int> &q){
    for(map<int,int>::iterator x; x!=m.end(); x++){
        if (ct[x->first] == x->second){
            q.push(x->second);
            m.erase(x);
        }
    }
}

int main(){
    int n,m, inp , t =0,i,j,time;
    queue<int>outs,table;
    map<int,int> ins,chef_table;
    cin >> n >> m;
    //int timer = 0;
    vector<int> chef;
    for(i = 0; i < n;i++){
        cin >>time;
        //cout << i + " ";
        chef.push_back(time);
        table.push(i);
        chef_table[i] = time;
    }
    //print_vector_v3(chef);
    for(i = 0;i < m; i++){
        outs.push(i+1);
    }
    while(!outs.empty()){
        clear_table(ins,chef_table,table);
        while(ins.size()< n){
            //ins[table] = time
            ins[table.front()] = t;
            cout << t << "\n";
            table.pop();
            outs.pop();
        }
        timeplus(ins);
        t++;
    }
}
