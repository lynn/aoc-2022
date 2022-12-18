#include "IO.HPP"

long current[99];
long sums[999];
long i, j, n;
long max[3];

int main() {
	FILE* f = Open("IN01.TXT");
	for (i = 0; (n = ReadLongParagraph(f, current)) > 0; i++) {
		sums[i] = 0;
		for (j=0; j<n; j++) sums[i] += current[j];

		if (sums[i] > max[0]) {
			max[2] = max[1]; max[1] = max[0]; max[0] = sums[i];
		} else if (sums[i] > max[1]) {
			max[2] = max[1]; max[1] = sums[i];
		} else if (sums[i] > max[2]) {
			max[2] = sums[i];
		}
	}
	printf(" * %ld\n", max[0]);
	printf("** %ld\n", max[0] + max[1] + max[2]);
	return 0;
}