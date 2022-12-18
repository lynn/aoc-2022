#include "IO.HPP"
FILE* f;
char buf[80];
long answer1;

long all[999];
long i;

long scan() {
    long n = 0;
    fgets(buf, sizeof(buf), f); // $ ls
    long size;

    while (fgets(buf, sizeof(buf), f)) {
        if (strncmp("$ cd ..", buf, 7) == 0) {
            break;
        } else if (strncmp("$ cd", buf, 4) == 0) {
            n += scan();
        } else if (sscanf(buf, "%ld", &size) == 1) {
            n += size;
        }
    }
    if (n < 100000) answer1 += n;
    all[i++] = n;
    return n;
}

int main() {
    f = Open("IN07.TXT");
    fgets(buf, sizeof(buf), f);
    long root = scan();
    printf(" * %ld\n", answer1);

    long need_to_free = root - (70000000 - 30000000);
    long best = 70000000;
    while (--i >= 0) {
        if (all[i] >= need_to_free && all[i] < best) {
            best = all[i];
        }
    }
    printf("** %ld\n", best);
    return 0;
}
