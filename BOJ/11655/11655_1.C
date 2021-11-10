/*
* 메모리: 2016 KB, 시간: 0 ms
* 타이머 시간: null
* 2021.11.10
* by Alub
**/
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int main() {
	while (getline(cin, str)) {
		for (int i = 0; i < str.size(); i++) {
			char cur = str[i];
			if ('A' <= cur && cur <= 'Z') {
				char changed = (cur - 'A' + 13) % 26 + 'A';
				cout << changed;
			}
			else if ('a' <= cur && cur <= 'z') {
				char changed = (cur - 'a' + 13) % 26 + 'a';
				cout << changed;
			}
			else
				cout << cur;
		}
		cout << "\n";
	}
	return 0;
}