#include <iostream>
#include <vector>
using namespace std;

 main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n;
    cin >> t;
    //t = # of orders,  n = # of roommates

    while(t--){
        cin >> n;
        vector<long int> price(n, 0), paid(n, 0), change(n, 0), money(7, 0);
        // for (int i = 0; i < n; i++){
        //     price[i] = 0;
        //     paid [i] = 0;
        //     change[i] = 0;
        // }
        // for(int i = 0; i < 7; i++)
        //     money[i] = 0;

        for (int i = 0; i < n; i++){
            cin >> price[i];
            for (int j = 0; j < 7; j++){
                long int count;
                cin >> count;
                money[j] += count;
                switch(j){
                    case 0:
                        paid[i] += 1000 * count;
                        break;
                    case 1:
                        paid[i] += 500 * count;
                        break;
                    case 2:
                        paid[i] += 100 * count;
                        break;
                    case 3:
                        paid[i] += 50 * count;
                        break;
                    case 4:
                        paid[i] += 10 * count;
                        break;
                    case 5:
                        paid[i] += 5 * count;
                        break;
                    case 6:
                        paid[i] += count;
                }
            }
            change[i] = paid[i] - price[i];
        }

        bool ans = true;
        long int need;
        for (int i = 0; i < n; i++){
            if (change[i] == 0)
                continue;
            if (change[i] >= 1000){
                need = change[i] / 1000;
                if (money[0] >= need){
                    change[i] = change[i] % 1000;
                    money[0] -= need;
                }
                else{
                    change[i] -= 1000 * money[0];
                    money[0] = 0;
                }
            }
            if (change[i] >= 500){
                need = change[i] / 500;
                if (money[1] >= need){
                    change[i] = change[i] % 500;
                    money[1] -= need;
                }
                else{
                    change[i] -= 500 * money[1];
                    money[1] = 0;
                }
            }
            if (change[i] >= 100){
                need = change[i] / 100;
                if (money[2] >= need){
                    change[i] = change[i] % 100;
                    money[2] -= need;
                }
                else{
                    change[i] -= 100 * money[2];
                    money[2] = 0;
                }
            }
            if (change[i] >= 50){
                need = change[i] / 50;
                if (money[3] >= need){
                    change[i] = change[i] % 50;
                    money[3] -= need;
                }
                else{
                    change[i] -= 50 * money[3];
                    money[3] = 0;
                }
            }
            if (change[i] >= 10){
                need = change[i] / 10;
                if (money[4] >= need){
                    change[i] = change[i] % 10;
                    money[4] -= need;
                }
                else{
                    change[i] -= 10 * money[4];
                    money[4] = 0;
                }
            }
            if (change[i] >= 5){
                need = change[i] / 5;
                if (money[5] >= need){
                    change[i] = change[i] % 5;
                    money[5] -= need;
                }
                else{
                    change[i] -= 5 * money[5];
                    money[5] = 0;
                }
            }
            if (change[i] >= 1){
                need = change[i];
                if (money[6] >= need){
                    change[i] = 0;
                    money[6] -= need;
                }
                else{
                    change[i] -= money[6];
                    money[6] = 0;
                }
            }
            
            if (change[i] != 0){
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}