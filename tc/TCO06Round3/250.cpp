#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 100001;
int dp[MAXN];

class LastStone {
    public:
        int bobWin(vector<int> &turns, int state, int now_bob){
            if(dp[state]!=-1){
                return dp[state];
            }
            bool cur_win = false;
            for(int i=0; i<turns.size(); i++){
                if(state-turns[i]==0){
                    cur_win = true;
                    break;
                }
            }
            int win_state = -1;
            if(cur_win){
                win_state = 1;
            }else{
                int next_win = 1;
                for(int i=0; i<turns.size(); i++){
                    int next = state-turns[i];
                    if(next>=0){
                        int res = bobWin(turns, next, now_bob^1);
                        if(res!=1){
                            next_win = 0;
                            break;
                        }
                    }
                }
                if(next_win == 1){
                    win_state = 0;
                }else{
                    win_state = 1;
                }

            }
            dp[state] = win_state;
            return dp[state];
        }


        int numWins(vector <int> turns, int m, int n) {
            memset(dp,0,sizeof(dp));
            for(int i=0; i<turns.size(); i++)dp[turns[i]] = 1;
            for(int pos = 0; pos<=n; pos++){
                for(int i=0; i<turns.size(); i++){
                    if(pos-turns[i]>=0 && dp[pos-turns[i]]==0){
                        dp[pos] = 1;
                    }
                }
            }
            int cnt = 0;
            for(int i=m; i<=n; i++)if(dp[i])cnt++;

            return cnt;
            //memset(dp,-1,sizeof(dp));
            /*
            int cnt = 0;
            for(int i=m; i<=n; i++){
                cout<<"testing for "<<i<<endl;
                int res = bobWin(turns,i,1);
                cout<<"res is "<<res<<endl;
                if(res==1){
                    cnt+=1;
                }
            }*/
            return cnt;



        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << p1 << "," << p2;
    cout << "]" << endl;
    LastStone *obj;
    int answer;
    obj = new LastStone();
    clock_t startTime = clock();
    answer = obj->numWins(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <int> p0;
    int p1;
    int p2;
    int p3;

    {
        // ----- test 0 -----
        int t0[] = {1,3,4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        p2 = 5;
        p3 = 4;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        int t0[] = {1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        p2 = 100;
        p3 = 50;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {1,2,3,4,5,6,7,8,9,10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        p2 = 10;
        p3 = 10;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {1,2,3};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        p2 = 8;
        p3 = 6;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}