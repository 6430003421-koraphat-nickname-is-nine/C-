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

void print_map_v1(map<int,int> &m){
    cout << "this map:{ ";
    for(map<int,int>::iterator x; x!=m.end(); x++){
        cout << x->first << " : " << x->second << ", ";
    }
    cout << " }\n";

}
void clear_table(map<int,int> &m,map<int,int> &ct,queue<int> &ta){
    cout << "test6\n";
    print_map_v1(m);
    for(map<int,int>::iterator x; x!=m.end(); x++){
        x->second+=1;
        cout << "test7\n";
        //cout << x->second << "\n";
        if (x->second % ct[x->first] == 0){
            ta.push(x->first);
            cout << "test8\n";
            m.erase(x);
        }
        cout << "test9\n";
    }
}

int main(){
    int n,m, inp , t,i,j,time;
    queue<int>outs,table;
    map<int,int> ins;
    map<int,int> chef_table;// table:time use by that table's chef
    cin >> n >> m;
    //int timer = 0;
    vector<int> chef;
    for(i = 0; i < n;i++){
        cin >>time;
        //cout << i + " ";
        chef.push_back(time);
        table.push(i+1);
        chef_table[i+1] = time;
    }
    cout << "test1\n";
    //print_vector_v3(chef);
    for(i = 0;i < m; i++){
        outs.push(i+1);
    }
    cout << "test2\n";
    t = 0;
    while(!outs.empty()){
        cout << "test3\n";
        while(ins.size()< n){
            //ins[table] = time
            int ta = table.front();
            cout << ta << "," << t <<"\n";
            ins[ta] = t;
            print_map_v1(ins);
            cout << t << "\n";
            table.pop();
            outs.pop();
        }
        cout << "test4\n";
        clear_table(ins,chef_table,table);
        //timeplus(ins);
        t += 1;
        cout << "test5\n";
    }
}
//3 10 1 3 4
//1 10 4
