#include "IO.HPP"

char cx, cy;
long x, y;
long score1, score2;

int main() {
	FILE* f = Open("IN02.TXT");
	while (fscanf(f, "%c %c\n", &cx, &cy) > 0) {
		x = cx - 'A' + 1;
		y = cy - 'X' + 1;
		score1 += (y+3-x+1)%3*3 + y;
		y = (x+y)%3 + 1;
		score2 += (y+3-x+1)%3*3 + y;
	}
	printf(" * %ld\n", score1);
	printf("** %ld\n", score2);
	return 0;
}