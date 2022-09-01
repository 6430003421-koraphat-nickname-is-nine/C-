#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Letter{
    public:
    string name; string address; string province; string district; int zip;
    bool operator <(const Letter& other)const {
        if ( this->zip != other.zip){
            return this->zip < other.zip;
        }
        else{
            if(this->address != other.address){
                return this->address < other.address;
            }
            else {return this->name < other.name; }
        }
    //**Begin Insert**
    //**End Insert**
    }
    };
class ZipInfo{
public:
    int zip;
    string province;
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo> &zipinfo, vector<Letter> &letters) {
 //**Begin Insert**
    for(auto &l: letters){
        bool found = false;
        int i = 0;
        while(!found){//l.zip != zipinfo[i].zip &&
            if (l.province == zipinfo[i].province && l.district == zipinfo[i].district){
                found = true;
                l.zip = zipinfo[i].zip;
            }
            i++;
            if (i == zipinfo.size()){break;}
        }
    }
    sort(letters.begin(),letters.end());
 //**End Insert**
}
int main() {
    int nzip;
    cin>>nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin>>z.zip>>z.district>>z.province;
        zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
    Letter l;
    cin>>l.name>>l.address>>l.district>>l.province>>l.zip;
    letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    //cout << "\n===============================================\n";
    for (auto& l:letters) {
    cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}
