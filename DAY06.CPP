#include "IO.HPP"

char data[9999];

int find(int size) {
    char a[14];
    unsigned char count[26];
    memset(count, 0, 26);
    int i, j;
    for (i = 0;; i++) {
        if (i >= size) {
            for (j=0; j<26; j++) if (count[j]>1) goto nope;
            return i;
        nope:
            --count[a[i % size]];
        }
        a[i % size] = data[i] - 'a';
        ++count[a[i % size]];
    }
}

int main() {
	FILE* f = Open("IN06.TXT");
    fgets(data, sizeof(data), f);
    printf(" * %d\n", find(4));
    printf("** %d\n", find(14));
	return 0;
}