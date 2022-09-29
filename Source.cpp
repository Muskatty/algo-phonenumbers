//#include <fstream>
//#include <string>
//#include <map>
//#include <iostream>
//#include <algorithm>
//#include <time.h>
//
//int findfirst(char* str, char c, int leftside, int rightside);
//bool comp(const std::string&, const std::string&);
//
//std::map<char, char> mymap;
//
//struct counter {
//	int backpos;
//	int minjumps;
//	int backstring;
//	bool canstart = false;
//	counter() {
//		backpos = -1;
//		minjumps = INT_MAX;
//		backstring = -1;
//	}
//	counter(int b, int j, int bs) {
//		backpos = b;
//		minjumps = j;
//		backstring = bs;
//	}
//};
//
//int main() {
//	std::ifstream input("input.txt");
//	std::ofstream output("output.txt");
//
//	mymap['I'] = '1', mymap['J'] = '1', mymap['1'] = '1';
//	mymap['A'] = '2', mymap['B'] = '2', mymap['C'] = '2', mymap['2'] = '2';
//	mymap['D'] = '3', mymap['E'] = '3', mymap['F'] = '3', mymap['3'] = '3';
//	mymap['G'] = '4', mymap['H'] = '4', mymap['4'] = '4';
//	mymap['K'] = '5', mymap['L'] = '5', mymap['5'] = '5';
//	mymap['M'] = '6', mymap['N'] = '6', mymap['6'] = '6';
//	mymap['P'] = '7', mymap['R'] = '7', mymap['S'] = '7', mymap['7'] = '7';
//	mymap['T'] = '8', mymap['U'] = '8', mymap['V'] = '8', mymap['8'] = '8';
//	mymap['W'] = '9', mymap['X'] = '9', mymap['Y'] = '9', mymap['9'] = '9';
//	mymap['O'] = '0', mymap['Q'] = '0', mymap['Z'] = '0', mymap['0'] = '0';
//	std::string mainstring;
//	int n;
//	int maxlen = 0;
//	input >> mainstring;
//	input >> n;
//	std::string* maschar = new std::string[n];
//	std::string* masnum = new std::string[n];
//	std::string temp, numstr = "";
//	for (int i = 0; i < n; i++) {
//		input >> temp;
//		int len = temp.length();
//		if (len > maxlen) {
//			maxlen = len;
//		}
//		maschar[i] = temp;
//	}
//
//	std::sort(maschar, maschar + n, comp);
//	for (int i = 0; i < n; i++) {
//		numstr = "";
//		int len = maschar[i].length();
//		for (int j = 0; j < len; j++) {
//			char c = maschar[i][j];
//			if (c >= 'A' && c <= 'Z') {
//				numstr += mymap[c];
//			}
//			else {
//				numstr += c;
//			}
//		}
//		masnum[i] = numstr;
//	}
//	char** arr = new char*[maxlen + 1];
//	for (int i = 0; i <= maxlen; i++) {
//		arr[i] = new char[n];
//		for (int j = 0; j < n; j++) {
//			if (i >= masnum[j].length()) {
//				arr[i][j] = '/';
//			}
//			else {
//				arr[i][j] = masnum[j][i];
//			}
//			std::cout << arr[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
//	int mainlen = mainstring.length();
//	if (maxlen > mainlen) {
//		maxlen = mainlen;
//	}
//	counter* mascount = new counter[mainlen];
//	mascount[0].canstart = true;
//	int jump = 1, left = 0, right = n - 1, nleft = 0, nright = n - 1;
//	for (; jump <= maxlen ; jump++) {
//		left = findfirst(arr[jump - 1], mainstring[jump - 1], left, right);
//		right = findfirst(arr[jump - 1], mainstring[jump - 1] + 1, left, right);
//		if (arr[jump - 1][left] == mainstring[jump - 1] && arr[jump][left] == '/') {
//			mascount[0].backpos = 0;
//			mascount[0].minjumps = 1;
//			mascount[jump - 1].backpos = 0;
//			mascount[jump - 1].minjumps = 1;
//			mascount[jump - 1].backstring = left;
//			if (jump < mainlen) {
//				mascount[jump].canstart = true;
//			}
//		}
//	}
//	jump = 0;
//	for (int i = 1; i < mainlen; i++) {
//		nleft = left =  0;
//		nright = right = n - 1;
//		while (i + jump < mainlen && jump < maxlen) {
//			jump++;
//			if (mascount[i].canstart) {
//				left = findfirst(arr[jump - 1], mainstring[i + jump - 1], nleft, nright);
//				right = findfirst(arr[jump - 1], mainstring[i + jump - 1] + 1, nleft, nright);
//				nleft = left;
//				nright = right;
//				if (left > right) {
//					break;
//				}
//				if (arr[jump - 1][left] == mainstring[i + jump - 1] && arr[jump][left] == '/') {
//					if (i + jump < mainlen) {
//						mascount[i + jump].canstart = true;
//					}
//					if (mascount[i].minjumps - 1 >= mascount[i - 1].minjumps) {
//						mascount[i].backpos = i;
//						mascount[i].minjumps = mascount[i - 1].minjumps + 1;
//						mascount[i].backstring = left;
//					}
//					if (mascount[i].minjumps <= mascount[i + jump - 1].minjumps - 1) {
//						mascount[i + jump - 1].backpos = i;
//						mascount[i + jump - 1].minjumps = mascount[i - 1].minjumps + 1;
//						mascount[i + jump - 1].backstring = left;
//					}
//				}
//				else if (arr[jump - 1][left] == '/') {
//					break;
//				}
//			}
//			else break;
//		}
//		jump = 0;
//	}
//	if (mascount[mainlen - 1].backstring == -1) {
//		output << "No solution";
//	} 
//	else {
//		int velichina = mascount[mainlen - 1].minjumps;
//		std::string* ans = new std::string[velichina];
//		output << mascount[mainlen - 1].minjumps << '\n';
//		int count = 0;
//		for (int i = mainlen - 1; i >= 0;) {
//			ans[velichina - 1 - count] = maschar[mascount[i].backstring];
//			count++;
//			i = mascount[i].backpos - 1;
//		}
//		for (int i = 0; i < velichina; i++) {
//			output << ans[i] << " ";
//		}
//	}
//	return 0;
//}
//
//
//
//int findfirst(char* str, char c, int leftside, int rightside) {
//	while (leftside < rightside) {
//		int medium = (leftside + rightside) / 2;
//		if (c <= str[medium]) {
//			rightside = medium;
//		}
//		else {
//			leftside = medium + 1;
//		}
//	}
//	return leftside;
//};
//
//bool comp(const std::string& str1, const std::string& str2) {
//	int len1 = str1.length(), len2 = str2.length();
//	int len = std::min(len1, len2);
//	for (int i = 0; i < len; i++) {
//		char c1 = mymap[str1[i]];
//		char c2 = mymap[str2[i]];
//		if (c1 != c2) {
//			return c1 < c2;
//		}
//	}
//	return len1 < len2;
//}

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <time.h>

int findfirst(int pos, char c, int leftside, int rightside);
bool comp(const std::string&, const std::string&);

char mymap['Z' + 1];

char arr[101][50001];
std::string maschar[50001];
std::string masnum[50001];
int jumps[100001];
int backStrings[100001];
bool canStart[100001];
std::string ans[100001];

int main() {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");

	mymap['I'] = '1', mymap['J'] = '1', mymap['1'] = '1';
	mymap['A'] = '2', mymap['B'] = '2', mymap['C'] = '2', mymap['2'] = '2';
	mymap['D'] = '3', mymap['E'] = '3', mymap['F'] = '3', mymap['3'] = '3';
	mymap['G'] = '4', mymap['H'] = '4', mymap['4'] = '4';
	mymap['K'] = '5', mymap['L'] = '5', mymap['5'] = '5';
	mymap['M'] = '6', mymap['N'] = '6', mymap['6'] = '6';
	mymap['P'] = '7', mymap['R'] = '7', mymap['S'] = '7', mymap['7'] = '7';
	mymap['T'] = '8', mymap['U'] = '8', mymap['V'] = '8', mymap['8'] = '8';
	mymap['W'] = '9', mymap['X'] = '9', mymap['Y'] = '9', mymap['9'] = '9';
	mymap['O'] = '0', mymap['Q'] = '0', mymap['Z'] = '0', mymap['0'] = '0';
	std::string mainstring;
	int n;
	int maxlen = 0;
	input >> mainstring;
	input >> n;
	std::string temp, numstr = "";
	for (int i = 0; i < n; i++) {
		input >> temp;
		int len = temp.length();
		if (len > maxlen) {
			maxlen = len;
		}
		maschar[i] = temp;
	}

	std::sort(maschar, maschar + n, comp);
	for (int i = 0; i <= maxlen; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= maschar[j].length()) {
				arr[i][j] = '/';
			}
			else {
				arr[i][j] = mymap[maschar[j][i]];
			}
		}
	}
	int mainlen = mainstring.length();
	if (maxlen > mainlen) {
		maxlen = mainlen;
	}

	for (int i = 0; i < mainlen + 1; i++) {
		jumps[i] = INT_MAX;
		backStrings[i] = -1;
		canStart[i] = false;
	}
	jumps[0] = 0;
	backStrings[0] = -1;
	canStart[0] = true;
	for (int i = 0; i < mainlen; i++) {
		int newleft = 0;
		int newright = n;
		int border = std::min(mainlen, i + maxlen);
		if (canStart[i] == false) {
			continue;
		}
		for (int j = i; j < border; j++) {
			int left = findfirst(j - i, mainstring[j], newleft, newright);
			int right = findfirst(j - i, mainstring[j] + 1, newleft, newright);
			newleft = left;
			newright = right;
			if (left >= right) {
				break;
			}

			if (arr[j - i][left] == mainstring[j] && arr[j - i + 1][left] == '/') {
				if (jumps[j + 1] > jumps[i] + 1) {
					jumps[j + 1] = jumps[i] + 1;
					backStrings[j] = left;
					canStart[j + 1] = true;
				}
			}
			if (arr[j - i][left] == '/') {
				break;
			}
		}
	}
	if (backStrings[mainlen - 1] == -1) {
		output << "No solution\n";
	}
	else {
		int velichina = jumps[mainlen];
		output << jumps[mainlen] << '\n';
		int count = 0;
		for (int i = mainlen - 1; i >= 0;) {
			ans[velichina - 1 - count] = maschar[backStrings[i]];
			count++;
			i -= maschar[backStrings[i]].length();
		}
		for (int i = 0; i < velichina; i++) {
			output << ans[i] << " ";
		}
	}
	return 0;
}

int findfirst(int pos, char c, int leftside, int rightside) {
	while (leftside < rightside) {
		int medium = (leftside + rightside) / 2;
		if (c <= arr[pos][medium]) {
			rightside = medium;
		}
		else {
			leftside = medium + 1;
		}
	}
	return leftside;
};

bool comp(const std::string& str1, const std::string& str2) {
	int len1 = str1.length(), len2 = str2.length();
	int len = std::min(len1, len2);
	for (int i = 0; i < len; i++) {
		char c1 = mymap[str1[i]];
		char c2 = mymap[str2[i]];
		if (c1 != c2) {
			return c1 < c2;
		}
	}
	return len1 < len2;
}