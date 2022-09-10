#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n,m,a,inp,i;
    string t;

    vector<int> cargo;//cargo:the quantity of that cargo
    //map<int,int> bidder;//Nth bidder:their current bidding
    cin >>n>>m>>a;
    vector<int> price_max(n);/*vector of maximum price the bider
                            gave to the index+1 th cargo
                            ex. |50|200|60|100|
                            meaning: the cargo No.1 has the maximum price = 50,
                                     the 2nd = 200...*/
    vector<vector<pair<int,int>>> bidder_v(n);//,vector<pair<int,int>>);
                                                /*vector of vector of pair
                                               at the index n is the vector of (n+1)th's list
                                               of pair which is bidder:there current bidding

    */
    for(i=1;i < n+1;i++){
        cin >> inp;
        cargo[i-1] = inp;
    }
    for(i=0;i<a;i++){
        cin >> t;
        int u,l,v;
        if( t=="B" ){
            cin >> u >> l >> v;
            bidder_v[l][u-1] = make_pair(v,u);
        }
        else if(t == "W"){
            cin >> u >> l;
            bidder_v[l][u-1] = make_pair(0,u);

        }

    }
    vector<vector<int>> result_win(m);//,vector<int>);
    for(i = 0; i < n; i++){
        sort(bidder_v[i].begin(),bidder_v[i].end());
    }
    for(i = 1; i < m+1; i++){//เข้าไปทีละคน
        for(int j = 0;j<n;j++){//เข้าไปที cargo
            int size_bv =  bidder_v[j].size();
                //auto endv = bidder_v[j][size_bv - 1];
            if(bidder_v[j][size_bv - 1].second == i){
                if(bidder_v[j][size_bv - 1].first !=0){
                    result_win[i-1].push_back(j+1);
                    cargo[j]-=1;
                    bidder_v[j].pop_back();
                }
            }
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
