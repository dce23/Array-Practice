#include<iostream>
#include<string>

using namespace std;

// A function that sums the arithmetic series
// 1+2+3+...+N recursively
long sumSeries(long N) {
	if (N == 0) {	//Base Case
		return 0;
	}
	else {
		return sumSeries(N) + sumSeries(N - 1);
	}
}


// A function that sums the arithmetic series
// X + (X+1)+(X+2) + ... + (Y-1) + Y recursively. Here, X <= Y
long SumXY(long X, long Y) {
	if (X > Y) {	//Base Case
		return 0;
	}

	else if (X == Y)
		return X;

	else
		return X + Y + SumXY(X + 1, Y - 1);
}


/* A function that will output the contents of a character string
in reverse order recursively. Assume that you are passed the string
and the index of the last character in the string.
*/
void outputRev(char S[], int index) {
	if (index >= 0) {
		cout << S[index];
		outputRev(S, index - 1);
	}
}

/* This function determines the largest common factor 
between two integers recursively. Continues until a 
remainder of zero is computed. P >= Q.
*/
int euclid(int P, int Q) {
	if (P%Q == 0) {
		return Q;
	}
	else {
		return euclid(Q, P%Q);
	}
}


/* A Tower of Hanoi game function that tells you how
to solve the problem given the three original number of disks.
*/
void Hanoi(int disks, int source, int destination, int buffer) {
	if (disks != 0) {
		Hanoi(disks - 1, source, buffer, destination);
		cout << "Move " << disks << " from " << source << " to "
			<< destination << endl;
		Hanoi(disks - 1, buffer, destination, source);
	}
	// 2^n-1 moves
	else {
		cout << "Move " << disks << " from " << source << " to "
			<< destination << endl;
	}
}

int main() {

	SumXY(5, 9);	//35

	char x[] = { 'a','b','c' };
	outputRev(x, 2);

	Hanoi(12, 1, 2, 3);

	return 0;
}