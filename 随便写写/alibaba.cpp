#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;
template <class T1, T2> T1 func(T1 a, T2 b) {
}
int sum_array(const int *a, int b) {
	int sum = 0;
	for(int i = 0; i < b; ++i){
		sum += *(a + i);
	}
	return sum;
}

void func(string a){
	bool check = true;
	bool positive = true;
	bool point = false;
	double ans = 0;
	double wei = 0.1;
	for(int i = 0; i < a.size(); i++){
		if(a.at(i) == '-' && i == 0){
			positive = false;
		} else if(a.at(i) >= '0' && a.at(i) <= '9' && !point){
			ans *= 10;
			ans += a.at(i) - '0';
		} else if (a.at(i) >= '0' && a.at(i) <= '9' && point){
			ans = ans + (a.at(i) - '0') * wei;
			wei /= 10;
		} else if(a.at(i) == '.' && !point){
			point = true;
		} else {
			cout << "ret=false, result 不设置" << endl;
			return ;
		}
	}
	if(!positive){
		ans *= -1;
	}
	printf("%f\n",ans);
	cout << "ret=true, result=" << ans << endl;
}

void fun(){
	func("124.0123");
	char (*p2)[10];
	char *p[10];
	cout << sizeof(p) << endl;
	cout << sizeof(p2) << endl;
	char str[] = "123456";
	char *a = str;
	cout << sizeof(a) << endl;
	cout << strlen(a) << endl;
	cout << strlen(str) << endl;
}
int main(){
/*
	const int array[] = {1,2,3,4};
cout << 	sum_array(array, sizeof(array)/ sizeof(array[0]));

	char str[] = "123456";
*/
func("124.012300");
}
