#include "IO.HPP"

char sack[52+1];
char badge[52+1];
char line[99];
long l, i, j, n;
long total1, total2;

long priority(char c) {
    return c >= 'a' ? (c-'a'+1) : (c-'A'+27);
}

int main() {
	FILE* f = Open("IN03.TXT");
    for (l = 0; fgets(line, sizeof(line), f); l++) {
        memset(sack, 0, sizeof(sack));

        // *:
        n = strlen(line) / 2;
        for (i = 0; i < n; i++) {
            sack[priority(line[i])] = 1;
        }
        for (i = n; i < 2 * n; i++) {
            j = priority(line[i]);
            if (sack[j]) { total1 += j; break; }
        }

        // **:
        switch (l % 3) {
        case 0:
            memset(badge, 0, sizeof(badge));
            for (i = 0; line[i]; i++) {
                badge[priority(line[i])] = 3;
            }
            break;
        case 1:
            for (i = 0; line[i]; i++) {
                badge[priority(line[i])] &= 1;
            }
            break;
        case 2:
            for (i = 0; line[i]; i++) {
                j = priority(line[i]);
                if (badge[j] == 1) { total2 += j; break; }
            }
        }
    }
	printf(" * %ld\n", total1);
	printf("** %ld\n", total2);
	return 0;
}