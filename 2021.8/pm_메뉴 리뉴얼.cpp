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

vector <string> make(string str) { // ��� ��� ����
    vector <string> ret;
    int size = str.size();
    for (int i = 1; i <= size; i++) {
        t = "";
        permutation(ret, str, 0, 0, i);
    }
    return ret;
}

string sortStr(string str) { // ���ڿ� ����
    vector<char>temp;
    for (int i = 0; i < str.size(); i++) temp.push_back(str[i]);
    sort(temp.begin(), temp.end());
    string ret = "";
    for (int i = 0; i < temp.size(); i++) ret += temp[i];
    return ret;
}

int main() {
    vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = { 2,3,4 };
    vector<string> answer;

    // map 2�� ���� - 1) �ش� ���ڿ��� ���Դ��� �ƴ��� Ȯ���� �迭, 2) ���� ���� ������ map
    // 1. ���ڿ��� ������ ��� ����� ���� ����� (�̸� ���ڿ� ���� �� ���� ���������� ���Ľ��ѳ���)
    // 2. ������ ���ڿ����� 1�� map�� ���� �̹� ���Դ��� Ȯ��
    //    1) �̹� ���� ���ڿ��̶�� 2�� map���� ���� ���� ++
    //    2) ó�� ���� ���ڿ��̶�� 2�� map�� ���� push
    // 3. 2�� map���� �ִ밪�鸸 �̾Ƽ� answer �迭�� �־���� sort �� ���

    map<string, int> m1, m2[11];

    for (int i = 0; i < orders.size(); i++) {
        string str = orders[i];
        str = sortStr(str);
        vector<string> allStr = make(str);
        for (int k = 0; k < allStr.size(); k++) {
            auto iter = m1.find(allStr[k]);
            if (iter == m1.end()) { // ó�� ���� ���ڿ��̶��
                m1.insert(psi(allStr[k], 1));
                m2[allStr[k].size()].insert(psi(allStr[k], 1));
            }
            else {
                iter = m2[allStr[k].size()].find(allStr[k]);
                iter->second++;
            }
        }
    }

    // �ִ밪�� �̾Ƽ� answer �迭�� �ֱ�
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

    for (int k = 0; k < answer.size(); k++) cout << answer[k] << "\n";
}