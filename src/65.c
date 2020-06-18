#include<stdio.h>
#include<stdbool.h>
#include<string.h>

enum STATE {
    INVALID,
    FLAG_1,
    DIGIT_1,
    POINT,
    DIGIT_2,
    DIGIT_2p,
    E,
    FLAG_2,
    DIGIT_3,
    DIGIT_3p,
    END,
    STATE_NUM
};

enum FLAGS {
    f, d, p, e, o, end, FLAGS_NUM
};

enum STATE state[STATE_NUM][FLAGS_NUM] = {
    [FLAG_1] = {[f] = DIGIT_1, [d] = POINT, [p] = DIGIT_2p},
    [DIGIT_1] = {[d] = POINT, [p] = DIGIT_2p},
    [POINT] = {[d] = POINT, [p] = DIGIT_2, [e] = FLAG_2, [end] = END},
    [DIGIT_2] = {[d] = E, [e] = FLAG_2, [end] = END},
    [DIGIT_2p] = {[d] = E},
    [E] = {[d] = E, [e] = FLAG_2, [end] = END},
    [FLAG_2] = {[f] = DIGIT_3p, [d] = DIGIT_3},
    [DIGIT_3] = {[d] = DIGIT_3, [end] = END},
    [DIGIT_3p] = {[d] = DIGIT_3}
};

enum FLAGS get_token(char **bs, char *es) {
    if (*bs == es)
        return end;
    char t = **bs;
    ++*bs;
    switch (t) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return d;
        case '+':
        case '-':
            return f;
        case '.':
            return p;
        case 'e':
            return e;
    }
    return o;
}

bool isNumber(char *str) {
    char *bs = str, *es = str + strlen(str);
    enum FLAGS f;
    enum STATE s = FLAG_1;
    while (*bs ==  ' ')
        ++bs;
    while (es >= bs && *(es - 1) == ' ')
        --es;
    while ((f = get_token(&bs, es)) != end) {
        s = state[s][f];
        if (s == INVALID)
            return false;
    }
    s = state[s][end];
    return s == END;
}

int main(int argc, char **argv) {
    printf("%d\n", isNumber(argv[1]));
    return 0;
}
