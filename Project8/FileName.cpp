#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;
    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];

        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

int main()
{
    int m;
    string p;
    cin >> m; // 문자열의 길이 입력

    if (m < 1 || m > 100) { // m의 범위 확인
        cout << "m은 1이상 100이하만 입력할 수 있습니다" << endl;
        return 0; // 범위를 벗어날 경우 프로그램 종료
    }

    cin >> p; // 문자열 입력

    auto pi = getPi(p);
    int max_pi = 0;

    for (auto i : pi) {
        if (i > max_pi)
            max_pi = i;
    }

    cout << max_pi << endl; // 최대 실패 함수 값 출력

    return 0;
}