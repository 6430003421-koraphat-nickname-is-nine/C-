#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
void print_map_v1(map<int,int> &m){
    cout << "this map:{ ";
    for(map<int,int>::iterator x = m.begin(); x!=m.end(); x++){
        cout << x->first << " : " << x->second << ", ";
    }
    cout << " }\n";

}

void print_set_v1(set<int> &s){
    cout << "this set:{ ";
    for(set<int>::iterator x = s.begin(); x!=s.end(); x++){
        cout << *x << ", ";
    }
    cout << " }\n";

}
int main()
{
    int n,m,a,inp,i;
    string t;
    cin >>n>>m>>a;
    vector<int> cargo(n);//cargo:the quantity of that cargo

    map<pair<int,int>,int> bidding;

    for(i=0;i < n;i++){
        cin >> inp;
        cargo[i] = inp;
    }
    // collect data
    for(i = 0;i < a;i++){
        int u , l , v;
        cin >> t >> u >> l;
        if(t == "B"){
            cin >> v;
            bidding[{u,l}] = v;
        }
        else if(t == "W"){
            bidding[{u,l}] = -1;
        }
    }
    vector<set<pair<int,int>>> process(n);//vector index i contain the set of pair of money:bidder of the i+1 th cargo
    vector<set<int>> re(m);

    for(auto mit = bidding.begin();mit != bidding.end();mit++){
        int u , l , v;
        u = (mit->first).first;
        l = (mit->first).second;
        v = mit->second;
        /*cout << "u = " << u <<"\n";
        cout << "l = " << l <<"\n";
        cout << "v = " << v <<"\n";*/
        if(v  > 0){
                process[l-1].insert({v,u});
        }
    }

    for(i = 0;i < n;i++){
        auto endit = process[i].end();
        for(int j = 0; j < process[i].size() ;j++){
            endit--;
            /*cout << "(endit->second)-1 = " << (endit->second)-1 << "\n";
            cout << "i = " << i << " so i+1 = "<<i+1<<"\n";
            cout << "before:cargo[i] = " << cargo[i]<<"\n";
            cout << "before:re[(endit->second)-1] = ";print_set_v1(re[(endit->second)-1]);
*/

            re[(endit->second)-1].insert(i+1);
            cargo[i] -=1;

            /*cout << "after:re[(endit->second)-1] = ";print_set_v1(re[(endit->second)-1]);
            cout << "after:cargo[i] = " << cargo[i]<<"\n";*/
            if(cargo[i] < 1){
                break;
            }
        }
    }
    for(i = 0;i < m;i++){
        if (re[i].size() == 0){cout <<"NONE\n";}
        else {for(auto &x:re[i]){
            cout << x <<" ";
        }
        cout << "\n";
        }
    }

}
//2 3 4 1 1 B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100
//2 3 5 1 1 B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100 B 2 2 98
//2 2 4 1 2 B 1 1 5 B 1 1 4 B 1 1 10 B 2 1 9 B 1 1 8
//1 3 4 1 B 2 1 100 B 1 1 500 W 1 1 B 3 1 150
//1 3 4 1 B 2 1 100 B 1 1 500 W 1 1 B 3 1 150
//1 3 4 3 B 2 1 100 B 1 1 500 B 2 1 600 B 3 1 150
//1 2 2 2 B 1 1 100 B 2 1 100
//1 2 2 1 B 2 1 100 B 1 1 100
//2 3 3 2 1 B 1 1 10 B 2 1 100 B 2 2 1

//1 3 3 2 B 2 1 100 B 1 1 100 B 3 1 50
//1 3 4 2 B 2 1 100 B 1 1 100 B 3 1 50 W 1 1
