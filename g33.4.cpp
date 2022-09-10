#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void print_vector_v3(vector<int> &v){
    cout << "now this vector has : {";
    for(auto &x:v){
        cout << x << ", ";
    }
    cout << "}\n";
}

int main()
{
    int n,m,inp,i,c;
    vector<int> chef;
    vector<vector<int>> ins;
    cin >> n >> m;
    for (i=0;i<n;i++){
        cin >> inp;
        vector<int> v = {0};
        ins.push_back(v);
        chef.push_back(inp);
    }
    //c = n;
    /*if (n>=m){
        for(i=0;i<m;i++){
            cout << 0 << "\n";
        }
        return 0;
    }*/
    //cout << "test1\n";
    //c = n;
    /*for(i = 0;i<n;i++){
        //ins[i].push_back(chef[i]);
        cout << "i = "<< i << "\n";
        print_vector_v3(ins[i]);
    }*/
    c = n;
    i = 0;
    //cout << "test2\n";
    while(c < m){
        i+=1;
        for(int j = 0;j < n;j++){

            int num = ins[j][ins[j].size() - 1];
            int chef_t = chef[j%n];
            int dif = i - num;

            /*cout << "j = " << j << "\n";
            cout << "num = "<<  num << "\n";
            cout << "chef_t = "<< chef_t << "\n";
            cout << "dif = "<< dif << "\n";*/
            if(((i - num ) % chef[j%n]) == 0){
                ins[j].push_back(i);
                c +=1;
            }
            //
            //print_vector_v3(ins[j]);
            //c+=1;
        }
    }
    vector<int> sumv;
    for (i=0;i<n;i++){
        sumv.insert(sumv.end(),ins[i].begin(),ins[i].end());

    }
    sort(sumv.begin(),sumv.end());
    int k = sumv.size();
    if (k > m){
        k = m;
    }
    for(i = 0; i < k;i++){
        cout << sumv[i] << "\n";
    }
}
