#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
void member_multiply(vector<int> &v,vector<pair<vector<int>::iterator,int>> &multiply) {
    vector<int> u;
    sort(multiply.begin(),multiply.end());
    for (vector<int>::iterator it = v.begin(); it != v.end() ; it++){
        vector<pair<vector<int>::iterator,int>>::iterator itm = lower_bound(multiply.begin(),multiply.end(),make_pair(it,0));
        //if (itm == multiply.end()){continue;}


        if(itm != multiply.end() && *itm->first == *it ){
            /*cout << *(itm->first) <<" vs " << *it<< endl;
            cout << "test1\n";
            cout << itm->second <<endl;
            cout << "test2\n";*/
            for (int r = 0; r < (itm->second)+1 ; r++){u.push_back(*it);}
            //u.insert(u.end(),itm->second + 1,*it);
            //cout << "test3\n";
        }
        else{
            u.push_back(*it);
        }
        /*cout << "vector u is now:{ ";
        for(auto &x: u){
            cout <<  x << " ";
        }
        cout << "}\n===========\n";*/
    }
    v = u;

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
        int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
