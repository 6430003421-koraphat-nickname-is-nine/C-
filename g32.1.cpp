#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

//template <typename T1,typename T2, typename T3>
/*namespace fo{
    class order{
    public:
        int app,price,order;

    };
}*/
void print_q(queue<int> &q){
    auto u = q;
    cout << "now to queue has :";
    while(!u.empty()){
        cout << u.front()<<", ";
        u.pop();
    }
    cout << "\n";
}
int main()
{
    int n,m,inp,price,c,a,b;
    queue<int> ordera,orderb,backupa,backupb;
    int i;
    //map <int,int> order;
    //vector <int> target;
    queue<int> target,result;
    cin >> n>>m;
    for(i = 0; i < m;i++){
        cin >> inp;
        //target.push_back(inp);
        target.push(inp);
    }
    for(i = 0; i< n;i++){
        cout << "test2\n";
        cin >> inp;
        if (inp ==1){
            cout << "test2.1\n";
            cin >>a>>b;
            if (a == 1){
                ordera.push(b);
                backupa.push(b);
            }
            else if (a == 2){
                orderb.push(b);
                backupb.push(b);
            }
        }
        else if(inp == 2){
            cout << "test2.2\n";
            m = target.front();
            c = 0;
            target.pop();
            while(m > 0){
                if(ordera.empty()&&!orderb.empty()){
                    m -= orderb.front();
                    orderb.pop();
                    c+=1;
                    cout << "test2.2.1\n";
                }else if(orderb.empty()&&!ordera.empty()){
                    m -= ordera.front();
                    ordera.pop();
                    c+=1;
                    cout << "test2.2.2\n";
                }else if(orderb.empty()&&ordera.empty()){
                    cout << "test2.2.3\n";
                    if (m <= 0){
                        cout << "test2.2.3.1\n";
                        result.push(c);
                    }
                    else{
                        cout << "test2.2.3.2\n";
                        result.push(-1);
                    }
                }else if(ordera.front() == orderb.front()){
                        cout << "test2.2.4\n";
                        m -= ordera.front();
                        ordera.pop();
                        c+=1;
                        if (m > 0){
                            cout << "test2.2.4.1\n";
                            m -= orderb.front();
                            orderb.pop();
                            c+=1;
                        }
                        else{
                            cout << "test2.2.4.2\n";
                            result.push(c);
                        }
                    }
                if (i == n-1){
                    result.push(c);
                }

                }
            print_q(result);
            ordera = backupa;
            orderb = backupb;
        }
    }
    while(!result.empty()){
        cout << "test1\n";
        cout << result.front()<<" ";
        result.pop();
    }
}
