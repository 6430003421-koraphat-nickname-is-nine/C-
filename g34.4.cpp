#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

void print_map_v1(map<int,int> &m){
    cout << "this map:{ ";
    for(map<int,int>::iterator x = m.begin(); x!=m.end(); x++){
        cout << x->first << " : " << x->second << ", ";
    }
    cout << " }\n";

}
void print_vector_v3(vector<int> &v){
    cout << "now this vector has : {";
    for(auto &x:v){
        cout << x << ", ";
    }
    cout << "}\n";
}
map<int,int> map_key_value_flip(map<int,int> &m){
    map<int,int> re;
    for(map<int,int>::iterator mit = m.begin(); mit != m.end(); mit++){
        re[mit->second] = mit->first;
    }
    return re;
}

void contribute(map<int,int> &bidding,vector<int> &cargo,vector<set<int>> &result_win, int l){
    //cout << "============================\n";
    //print_map_v1(bidding);
    map<int,int> re_bidding = map_key_value_flip(bidding);
    //print_map_v1(re_bidding);
    auto endit = re_bidding.end();
    //while(cargo[l] != 0){
    for(int m = 0; m < bidding.size();m++){
        endit--;
       // cout <<"endit->first = " << endit->first << ",endit->second = "<<endit->second<<"\n";
        if((endit->first) > 0){
            //cout << "test1\n";
            //cout << "before : cargo[l-1] = cargo[" << l-1 << "] = " << cargo[l-1] << "\n";
            result_win[(endit->second) - 1].insert(l);
            //cout << "l =" << l<<"\n";
            cargo[l-1]-=1;
            //cout << "after : cargo[l-1] = cargo[" << l-1 << "] = " << cargo[l-1] << "\n";
            if(cargo[l-1] < 1){
                //cout << "test2\n";
                break;
            }
            //cout << "test6\n";
        }
    }
    //cout << "============================\n";
    //}

}

int main()
{
    int n,m,a,inp,i;
    string t;
    cin >>n>>m>>a;
    vector<int> cargo(n);//cargo:the quantity of that cargo
    map<int,int> bidding;
    vector<set<int>> result_win(m);//,vector<int>);

    for(i=0;i < n;i++){
        cin >> inp;
        cargo[i] = inp;
    }
    //print_vector_v3(cargo);
    int r = 0;
    int u,l,v,before_l;
    cin >> t >> u >> l ;

    before_l = l;
    for(i=0;i<a;i++){
        //cout << "t =" << t <<"\n";
        //cout << "u =" << u <<"\n";
        //cout << "l =" << l <<"\n";
        if( t=="B" ){
            cin >> v;
            if(l != before_l){
                //เริ่มเเจกของ
                //cout << "test3\n";
                contribute(bidding,cargo,result_win,before_l);
                bidding.clear();
                before_l = l;
            }
            //bidder_v[l][u-1] = make_pair(v,u);
            if (bidding[u] >= 0){
                bidding[u] = v;
                //cout << "test4\n";
            }
        }
        else if(t == "W"){
            //bidder_v[l][u-1] = make_pair(0,u);
            bidding[u] = -1;
            //cout << "test5\n";
        }
        if (i < a-1){cin >> t >> u >> l;}

    }
    //cout << "test7\n";
    contribute(bidding,cargo,result_win,l);
    //cout << "test8\n";
    for(i = 0;i < m;i++){
        if (result_win[i].size() == 0){cout <<"NONE\n";}
        else {for(auto &x:result_win[i]){
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
//1 3 4 3 B 2 1 100 B 1 1 500 B 2 1 600 B 3 1 150
//1 2 2 1 B 1 1 100 B 2 1 100
//2 3 3 2 1 B 1 1 10 B 2 1 100 B 2 2 1
