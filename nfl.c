#include <stdio.h>

int main() {
    int score;
    printf("Enter the score: ");
    while (scanf("%d", &score) && score > 0) {
        printf("Combinations for score: %d\n", score);
        for (int td = 0; td * 6 <= score; td++) {
            for (int fg = 0; fg * 3 + td * 6 <= score; fg++) {
                for (int s = 0; s * 2 + fg * 3 + td * 6 <= score; s++) {
                    for (int tp = 0; tp * 8 + s * 2 + fg * 3 + td * 6 <= score; tp++) {
                        for (int xp = 0; xp * 7 + tp * 8 + s * 2 + fg * 3 + td * 6 <= score; xp++) {
                            if (xp * 7 + tp * 8 + s * 2 + fg * 3 + td * 6 == score) {
                                printf("TDs: %d, FGs: %d, Safeties: %d, 2-PT Conversions: %d, Extra Points: %d\n", td, fg, s, tp, xp);
                            }
                        }
                    }
                }
            }
        }
        printf("Enter the score: ");
    }
    return 0;
}
