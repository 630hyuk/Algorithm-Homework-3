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
    cin >> m; // ���ڿ��� ���� �Է�

    if (m < 1 || m > 100) { // m�� ���� Ȯ��
        cout << "m�� 1�̻� 100���ϸ� �Է��� �� �ֽ��ϴ�" << endl;
        return 0; // ������ ��� ��� ���α׷� ����
    }

    cin >> p; // ���ڿ� �Է�

    auto pi = getPi(p);
    int max_pi = 0;

    for (auto i : pi) {
        if (i > max_pi)
            max_pi = i;
    }

    cout << max_pi << endl; // �ִ� ���� �Լ� �� ���

    return 0;
}