#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
// St.Petersburg Paradox
int flipCoin() {
    return (rand() % 2);
}

int spp(int stake, int threshold) {
    // return total winning
    while(!flipCoin() && stake <= threshold) {
        stake *= 2;
    }
    return stake;
}

int main()
{
    srand (time(NULL));
    const int st = 2; // stake = $2
    const int thres = 1000000; // threshold = 1M
    // for (int i = 0; i < 10; i++) {
    //     cout << "player " << i << " has won " << spp(st, thres) << " dollars" << endl;
    // }
    int cnt = 0;
    int curr_max = 0;
    while (curr_max < thres) {
        int winning = spp(st, thres);
        if (winning > curr_max) {
            curr_max = winning;
        }
        cnt++;
    }
    cout << "player " << cnt << " has won " << curr_max << " dollars" << endl;
    return 0;
}
