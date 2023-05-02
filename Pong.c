#include <stdio.h>

int draw_table(int ball_x, int ball_y, int racket_l, int racket_2, int l_score, int r_score);

int main() {
    char key = '\0';
    int ball_x = 80 / 2;
    int ball_y = 25 / 2;
    int vec_x = 1;
    int vec_y = -1;
    int racket_l = 11;
    int racket_r = 11;
    int l_score = 0;
    int r_score = 0;
    while (key != 'e') {
        printf("\e[1;1H\e[2J");
        ball_x += vec_x;
        ball_y += vec_y;
        if (ball_x == 77 && (ball_y >= racket_r && ball_y <= (racket_r + 2))) {
            vec_x *= -1;
        } else if (ball_x == 77 && (ball_y < racket_r || ball_y > (racket_r + 2))) {
            ball_x = 80 / 2;
            ball_y = 25 / 2;
            l_score++;
        }
        if (ball_x == 1 && (ball_y >= racket_l && ball_y <= (racket_l + 2))) {
            vec_x *= -1;
        } else if (ball_x == 1 && (ball_y < racket_l || ball_y > (racket_l + 2))) {
            ball_x = 80 / 2;
            ball_y = 25 / 2;
            r_score++;
        }
        if (ball_y == 1 && ball_x > 2 && ball_x < 78) vec_y *= -1;
        if (ball_y == 24 && ball_x > 2 && ball_x < 78) vec_y *= -1;
        draw_table(ball_x, ball_y, racket_l, racket_r, l_score, r_score);
        key = getchar();
        if (l_score == 21 || r_score == 21) break;
        if (key == 'a' && racket_l != 1) racket_l--;
        if (key == 'z' && racket_l != 21) racket_l++;
        if (key == 'k' && racket_r != 1) racket_r--;
        if (key == 'm' && racket_r != 21) racket_r++;
        if (key == ' ') continue;
    }
    return 0;
}

int winner(int l_score, int r_score) {
    if (l_score == 21) {
        printf(" Left player is winner!");
    } else if (r_score == 21) {
        printf("Right player is winner!");
    }
    return 0;
}

int linner_with_score(int x_pos, int score_start, int score) {
    if (x_pos >= score_start && x_pos <= score_start + 3) {
        if (score >= 10) printf("%s%d%s", " ", score, " ");
        if (score < 10) printf("%s%d%d%s", " ", 0, score, " ");
    }
    return score_start + 4;
}

int ball_rackets(int x_pos, int y_pos, int racket_l, int racket_r, int ball_x, int ball_y) {
    int racket_l_2 = racket_l + 2;
    int racket_r_2 = racket_r + 2;
    if (x_pos == ball_x && y_pos == ball_y) {
        printf("@");
    } else if (x_pos == 0 && y_pos >= racket_l && y_pos <= racket_l_2) {
        printf("]");
    } else if (x_pos == 77 && y_pos >= racket_r && y_pos <= racket_r_2) {
        printf("[");
    } else {
        printf(" ");
    }
    return 0;
}

int draw_table(int ball_x, int ball_y, int racket_l, int racket_r, int l_score, int r_score) {
    int x_lenght = 80;
    int y_lenght = 25;
    for (int y_pos = 0; y_pos < y_lenght; y_pos++) {
        if (y_pos == 0 || y_pos == y_lenght - 1) {
            for (int x_pos = 0; x_pos < x_lenght; x_pos++) {
                if (x_pos >= 5 && x_pos <= 8) {
                    x_pos = linner_with_score(x_pos, 5, l_score);
                } else if (x_pos >= 72 && x_pos <= 76) {
                    x_pos = linner_with_score(x_pos, 72, r_score);
                }
                printf("=");
            }
        } else {
            printf(" ");
            for (int x_pos = 0; x_pos < x_lenght - 2; x_pos++) {
                if ((l_score == 21 || r_score == 21) && y_pos == 10 && x_pos == 21) {
                    winner(l_score, r_score);
                    x_pos = 44;
                }
                ball_rackets(x_pos, y_pos, racket_l, racket_r, ball_x, ball_y);
            }
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}