#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;

string t = "";

bool cmp(psi a, psi b) {
    return a.second > b.second;
}

void permutation(vector<string>& temp, string str, int cnt, int start, int end) {
    if (cnt == end) {
        temp.push_back(t);
        return;
    }
    for (int k = start; k < str.size(); k++) {
        t += str[k];
        permutation(temp, str, cnt + 1, k + 1, end);
        t.pop_back();
    }
}

vector <string> make(string str) { // 모든 경우 생성
    vector <string> ret;
    int size = str.size();
    for (int i = 1; i <= size; i++) {
        t = "";
        permutation(ret, str, 0, 0, i);
    }
    return ret;
}

string sortStr(string str) { // 문자열 정렬
    vector<char>temp;
    for (int i = 0; i < str.size(); i++) temp.push_back(str[i]);
    sort(temp.begin(), temp.end());
    string ret = "";
    for (int i = 0; i < temp.size(); i++) ret += temp[i];
    return ret;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // map 2개 생성 - 1) 해당 문자열이 나왔는지 아닌지 확인할 배열, 2) 출현 개수 저장할 map
    // 1. 문자열이 들어오면 모든 경우의 수를 만들기 (미리 문자열 내의 각 문자 사전순으로 정렬시켜놓기)
    // 2. 각각의 문자열들을 1번 map을 통해 이미 나왔는지 확인
    //    1) 이미 나온 문자열이라면 2번 map에서 출현 개수 ++
    //    2) 처음 나온 문자열이라면 2번 map에 새로 push
    // 3. 2번 map에서 최대값들만 뽑아서 answer 배열에 넣어놓고 sort 후 출력

    map<string, int> m1, m2[11];

    for (int i = 0; i < orders.size(); i++) {
        string str = orders[i];
        str = sortStr(str);
        vector<string> allStr = make(str);
        for (int k = 0; k < allStr.size(); k++) {
            auto iter = m1.find(allStr[k]);
            if (iter == m1.end()) { // 처음 나온 문자열이라면
                m1.insert(psi(allStr[k], 1));
                m2[allStr[k].size()].insert(psi(allStr[k], 1));
            }
            else {
                iter = m2[allStr[k].size()].find(allStr[k]);
                iter->second++;
            }
        }
    }

    // 최대값들 뽑아서 answer 배열에 넣기
    for (int i = 0; i < course.size(); i++) {
        int s = course[i];
        if (!m2[s].empty()) {
            vector<psi> v (m2[s].begin(), m2[s].end());
            sort(v.begin(), v.end(), cmp);
            int maxs = v[0].second;
            if (maxs < 2) continue;
            for (int k = 0; k < v.size(); k++) {
                if (v[k].second < maxs) break;
                answer.push_back(v[k].first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
