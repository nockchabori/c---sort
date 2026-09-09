#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include <ctime>
#include <time.h>

using namespace std;
int num[10000] = { 0, };
int arr = 10000;
int inssort() { //삽입 정렬
	clock_t start = clock();
	for (int cnt = 0; cnt < arr; cnt++)
	{ 
		int x = cnt;
		for (int cnt2 = cnt - 1; cnt2 >= 0 ; cnt2--)
		{
			if (num[x] < num[cnt2])
			{
				swap(num[x] ,num[cnt2]);
				x = cnt2;
			}
			else
			{
				break;
			}
		}
	}
	clock_t end = clock();
	cout << "소요 시간: " << (end - start) / (double)CLOCKS_PER_SEC << "\n";
	return 0;
}
int shellsort() { //셸 정렬
	clock_t start = clock();
	for (int c = 1000; c > 0; c--)
	{
		for (int cnt = 0; cnt < arr; cnt += c)
		{
			int x = cnt;
			for (int cnt2 = cnt - 1; cnt2 >= 0; cnt2 -= c)
			{
				if (num[x] < num[cnt2])
				{
					swap(num[x], num[cnt2]);
					x = cnt2;
				}
				else
				{
					break;
				}
			}
		}
	}    
	clock_t end = clock();
	cout << "소요 시간: " << (end - start) / (double)CLOCKS_PER_SEC << "\n";
	return 0;
}
//int mergesort() { //병합 정렬
//
//}
//int heapsort() { //힙 정렬
//
//}
//int quicksort() { //퀵 정렬
//
//}
int main() {
	srand(time(NULL));
	int rn;
	for (int cnt = 0; cnt < arr; cnt++)
	{
		num[cnt] = cnt + 1;
	}
	for (int cnt = 0; cnt < arr - 1; cnt++)
	{
		rn = rand() % (arr - cnt) + cnt;
		swap(num[rn], num[cnt]);
	}
	inssort();
	for (int cnt = 0; cnt < arr;cnt++)
	{
		printf("%d ", num[cnt]);
	}
}