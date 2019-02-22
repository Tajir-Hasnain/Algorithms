#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(vector < int > &v , int i,int heapSize) {
	int l = 2*i;
	int r = l+1;
	int largest = i;

	if(l < heapSize && v[l] > v[i])
		largest = l;
	if(r < heapSize && v[r] > v[largest])
		largest = r;

	if(largest != i) {
		swap(v[i] , v[largest]);
		MaxHeapify(v,largest,heapSize);
	}
}

void BuildMaxHeap(vector < int > &v) {
	int heapSize = v.size();
	for(int i = v.size()/2 ; i >= 0; --i)
		MaxHeapify(v,i,heapSize);
}

void HeapSort(vector < int > &v) {
	BuildMaxHeap(v);

	int heapSize = v.size();

	for(int i = v.size()-1; i > 0; --i) {
		swap(v[0] , v[i]);
		MaxHeapify(v,0,--heapSize);
	}
}

int main() {
	vector < int > v;
	int n;

	cin >> n;

	v.assign(n,0);

	for(int i = 0; i < n; ++i)
		cin >> v[i];

	HeapSort(v);

	for(int i = 0; i < n; ++i)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}
