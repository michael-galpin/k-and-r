#include <iostream>
#include <stdlib.h>
using namespace std;

class Sieve{
	int max;
	int *nums;
	int num_primes;
public:
	Sieve(int max);
	int* primes();
	bool is_prime(int n);
};

Sieve::Sieve(int max){
	this->max = max;
	nums = new int[max-1];
	num_primes = 0;
	int i;
	for (i = 0; i < max-1; i++){
		nums[i] = i + 2;
	}
	for (i = 0; i < max - 1; i++){
		if (nums[i] != 0){
			num_primes++;
			int c = 2*nums[i];
			while (c <= max){
				nums[c-2] = 0;
				c += nums[i];
			}
		}
	}
}

int* Sieve::primes(){
	int *primes = new int[num_primes];
	int i,j = 0;
	for (i = 0; i < max - 1; i++){
		if (nums[i] != 0){
			primes[j++] = nums[i];
		}
	}
	return primes;
}

bool Sieve::is_prime(int n){
	return nums[n-2] != 0;
}

int main(int argc, char* argv[]){
	int max = 100;
	if (argc >= 2){
		max = atoi(argv[1]);
	}
	Sieve *sieve = new Sieve(max);
	for (max = 2; max < argc; max++){
		int n = atoi(argv[max]);
		cout << "is " << n << " prime? " << sieve->is_prime(n) << endl;
	}
	int *primes = sieve->primes();
	int i = 0;
	while (primes[i]){
		cout << primes[i++] << " ";
	}
	cout << endl;
}