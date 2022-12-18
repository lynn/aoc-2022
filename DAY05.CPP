#include "IO.HPP"

#define STACKS 9
char init[10][100];
char stack[STACKS+1][500];
char stack2[STACKS+1][500];
int size[STACKS+1];
int n, i, j;

void push(int i, char c) { stack[i][size[i]++] = c; }
char pop(int i) { return stack[i][--size[i]]; }

#define print_tops(s) \
	for (i=1; i<=STACKS; i++) putchar(s[i][size[i]-1]); puts("");

int main() {
	FILE* f = Open("IN05.TXT");

	// Parse the initial array.
	for (i = 0; fgets(init[i], sizeof(init[0]), f)[0] >= ' '; i++);
	for (i -= 2; i >= 0; i--) {
		for (j = 1; j <= STACKS; j++) {
			char c = init[i][4*j-3];
			if (c > ' ') push(j, c);
		}
	}

	// Compute ** and * moves simultaneously.
	memcpy(stack2, stack, sizeof(stack));
	while (fscanf(f, " move %d from %d to %d ", &n, &i, &j) == 3) {
		memcpy(stack2[j] + size[j], stack2[i] + size[i] - n, n);
		while (n--) push(j, pop(i));
	}

	printf(" * "); print_tops(stack);
	printf("** "); print_tops(stack2);
	return 0;
}