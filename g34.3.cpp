#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

void contribute(map<int,int> &bidding,vector<int> &cargo,vector<set<int>> &result_win, int l){
    auto endit = bidding.end();
    //while(cargo[l] != 0){
    for(int m = 0; m < bidding.size();m++){
        endit--;
        if((endit->second) > 0){
            result_win[(endit->first) - 1].insert(l);
            cargo[l-1]-=1;
            if(cargo[l-1] == 0){
                break;
            }
        }
    }
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

    int r = 0;
    int u,l,v,before_l;
    cin >> t >> u >> l ;

    before_l = l;
    for(i=0;i<a;i++){
    //while (r < a){
        if( t=="B" ){
            cin >> v;
            if(l != before_l){
                //เริ่มเเจกของ
                contribute(bidding,cargo,result_win,l);
                bidding.clear();
                before_l = l;
            }
            //bidder_v[l][u-1] = make_pair(v,u);
            if (bidding[u] >= 0){
                bidding[u] = v;
            }
        }
        else if(t == "W"){
            //bidder_v[l][u-1] = make_pair(0,u);
            bidding[u] = -1;
        }

    }

    for(i = 0;i < m;i++){
        if (result_win[i].size() == 0){cout <<"NONE\n";}
        else {for(auto &x:result_win[i]){
            cout << x << "\n";
        }
        }
    }
}
//2 3 4 1 1 B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100
//2 3 5 1 1 B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100 B 2 2 98
//2 2 4 1 2 B 1 1 5 B 1 1 4 B 1 1 10 B 2 1 9 B 1 1 8
