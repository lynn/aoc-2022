#include "IO.HPP"

int a, b, c, d;
long full, overlap;

int main() {
	FILE* f = Open("IN04.TXT");
    while (fscanf(f, "%d-%d,%d-%d\n", &a, &b, &c, &d) == 4) {
		full += (a <= c && d <= b || c <= a && b <= d);
		overlap += !(c > b || d < a);
	}
	printf(" * %ld\n", full);
	printf("** %ld\n", overlap);
	return 0;
}