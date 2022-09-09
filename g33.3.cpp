#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


void print_q_v2(queue<int> &q){
    auto u = q;
    cout << "now this queue has :";
    while(!u.empty()){
        cout << u.front()<<", ";
        u.pop();
    }
    cout << "\n";
}

void print_map_v1(map<int,int> &m){
    cout << "this map:{ ";
    for(map<int,int>::iterator x = m.begin(); x!=m.end(); x++){
        cout << x->first << " : " << x->second << ", ";
    }
    cout << " }\n";

}
void clear_table(map<int,int> &m,map<int,int> &ct,queue<int> &ta){
    if (m.size() > 0){
        for(map<int,int>::iterator x = m.begin(); x!=m.end(); x++){
            x->second+=1;
            if(m.size() == 0){
                    return;
            }
            if ( x->second % ct[x->first] == 0){
                ta.push(x->first);
                m.erase(x);
                if(m.size() == 0){
                    return;
                }
            }
            //cout << "test9\n";
        }
        //cout << "test10\n";
    }
}

int main(){
    int n,m, inp , t,i,j,time;
    queue<int>outs,table,prints;
    map<int,int> ins;
    map<int,int> chef_table;// table:time use by that table's chef
    cin >> n >> m;
    vector<int> chef;
    for(i = 0; i < n;i++){
        cin >>time;
        chef.push_back(time);
        table.push(i+1);
        chef_table[i+1] = time;
    }
    //cout << "test1\n";
    for(i = 0;i < m; i++){
        outs.push(i+1);
    }
    //cout << "test2\n";
    t = 0;
    while(!outs.empty()){
        //cout << "test3\n";
        while(ins.size()< n){
            int ta = table.front();
            ins[ta] = t;
            cout <<t  <<"\n";
            //prints.push(t);
            table.pop();
            outs.pop();

        }
        clear_table(ins,chef_table,table);
         t += 1;
    }
}
