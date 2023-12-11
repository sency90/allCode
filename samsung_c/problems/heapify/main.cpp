#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

static unsigned long long seed = 70;
static unsigned int random()
{
    seed = seed * 214013 + 2531011;
    return (unsigned int)((seed >> 16) & 0x7fff);
}
static int nextint(int s, int t)
{
    if (t - s + 1 <= 0x7fff)
    {
        return (int)(random() % (t - s + 1)) + s;
    }
    else
    {
        return (int)(((random() << 15) | random()) % (t - s + 1)) + s;
    }
}

#define MAX_N 100000
#define MAX_OP 2000000
#define MAX_REGISTER 4
static struct Operator
{
    int type;
    int p, q;
    int next;
} opnode[MAX_OP + 1];
static int opl = 1;
static int os[MAX_OP + 1];
static int osl = 0;
enum OPTYPE
{
    LINE_BEGEIN = 0,

    MOV_REGISTER = 100,
    MOV_REGISTER_IF,
    ADD_REGISTER,
    SUB_REGISTER,

    MOV_CONST = 200,
    ADD_CONST,
    SUB_CONST,

    DIV_BY_2 = 300,

    COMPARE = 400,
    SWAP = 500,
    SWAP_IF,
    NEXT_LINE_IF = 600,
};
extern void make_operation(int n);

void op(int type, int p, int q)
{
    if (opl > MAX_OP)
    {
        printf("NO MORE OPERATIONS!\n");
        return;
    }
    int pid;
    static int last_pid = 0;
    switch (type)
    {
    case LINE_BEGEIN:
    {
        // Jump to next operation list
        if (osl == 0 || last_pid > 0)
        {
            last_pid = 0;
            osl++;
        }
        break;
    }
    case MOV_REGISTER:
    case MOV_REGISTER_IF:
    case MOV_CONST:
    case ADD_REGISTER:
    case ADD_CONST:
    case SUB_REGISTER:
    case SUB_CONST:
    case DIV_BY_2:
    case COMPARE:
    case SWAP:
    case SWAP_IF:
    case NEXT_LINE_IF:
    {
        if (osl == 0)
            break;
        pid = opl++;
        opnode[pid].type = type;
        opnode[pid].p = p;
        opnode[pid].q = q;
        opnode[pid].next = 0;
        if (last_pid == 0)
        {
            os[osl - 1] = pid;
        }
        else
        {
            opnode[last_pid].next = pid;
        }
        last_pid = pid;
        break;
    }
    }
}

static int tv = 0;
static int a[MAX_N + 1];
static void build_array() {
    for (register int i = 1; i <= MAX_N; i++) {
        a[i] = i;
    }
    if (tv <= 10) {
        if (tv <= 9) {
            //약 10만/50 = 2천개의 자리를 변경함. (어떤 숫자를 고르면 꼭 뒤에서 swap하는데..)
            for (register int i = 1; i < MAX_N; i += nextint(1, MAX_N / 100)) { //i+=random[1,1000]
                register int ti = nextint(i, MAX_N); //random[1,100000]
                if (i != ti) {
                    register int tmp = a[i];
                    a[i] = a[ti];
                    a[ti] = tmp;
                }
            }
        }
    }
    else if (tv <= 20) {
        //테케 11~20까지는 앞뒤 순서를 바꿈.
        for (register int i = 0; i < MAX_N / 2; i++) { 
            register int tmp = a[i + 1];
            a[i + 1] = a[MAX_N - i];
            a[MAX_N - i] = tmp;
        }
        if (tv <= 19) {
            //테케 11~19까지는 아까 테케1~9에서 했던짓 그대로 반복.
            for (register int i = 1; i < MAX_N; i += nextint(1, MAX_N / 100)) {
                register int ti = nextint(i, MAX_N);
                if (i != ti) {
                    register int tmp = a[i];
                    a[i] = a[ti];
                    a[ti] = tmp;
                }
            }
        }
    }
    else {
        //그 외의 테케에선 그냥 전부다 변경하기 시작.
        for (register int i = 1; i < MAX_N; i++) {
            register int ti = nextint(i, MAX_N);
            if (i != ti) {
                register int tmp = a[i];
                a[i] = a[ti];
                a[ti] = tmp;
            }
        }
    }
}

static int reg[MAX_REGISTER];
static int call_cnt;
static int max_call_cnt;
static int sum_call_cnt;
static int state;
static void run()
{
    int osi = 0;
    call_cnt = 0;
    state = 0;
    while (osi < osl)
    {
        int me = os[osi];
        int osj = 0;
        bool line_assert = false;
        for (int i = 0; i < MAX_REGISTER; i++)
        {
            reg[i] = 0;
        }
        while (!line_assert && me)
        {
            call_cnt++;
            //printf("%d %d  %3d %d %d\n", osi, me, opnode[me].type, opnode[me].p, opnode[me].q);
            switch (opnode[me].type)
            {
            case MOV_REGISTER:
            case ADD_REGISTER:
            case SUB_REGISTER:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                if (opnode[me].q < 0 || opnode[me].q >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int &p = reg[opnode[me].p];
                int q = reg[opnode[me].q];
                if (opnode[me].type == MOV_REGISTER)
                    p = q;
                if (opnode[me].type == ADD_REGISTER)
                    p += q;
                if (opnode[me].type == SUB_REGISTER)
                    p -= q;
                break;
            }
            case MOV_CONST:
            case ADD_CONST:
            case SUB_CONST:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int &p = reg[opnode[me].p];
                int q = opnode[me].q;
                if (opnode[me].type == MOV_CONST)
                    p = q;
                if (opnode[me].type == ADD_CONST)
                    p += q;
                if (opnode[me].type == SUB_CONST)
                    p -= q;
                break;
            }
            case MOV_REGISTER_IF:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                if (opnode[me].q < 0 || opnode[me].q >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int &p = reg[opnode[me].p];
                int q = reg[opnode[me].q];
                if (reg[0])
                {
                    p = q;
                }
                break;
            }
            case DIV_BY_2:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int &p = reg[opnode[me].p];
                p /= 2;
                break;
            }
            case COMPARE:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                if (opnode[me].q < 0 || opnode[me].q >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int p = reg[opnode[me].p];
                int q = reg[opnode[me].q];
                if (p >= 1 && p <= MAX_N && q >= 1 && q <= MAX_N)
                {
                    reg[0] = (a[p] < a[q]) ? 1 : 0;
                }
                break;
            }
            case SWAP:
            {
                if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                if (opnode[me].q < 0 || opnode[me].q >= MAX_REGISTER)
                {
                    state = 1;
                    return;
                }
                int p = reg[opnode[me].p];
                int q = reg[opnode[me].q];
                if (p >= 1 && p <= MAX_N && q >= 1 && q <= MAX_N)
                {
                    int tmp = a[p];
                    a[p] = a[q];
                    a[q] = tmp;
                }
                break;
            }
            case SWAP_IF:
            {
                if (reg[0])
                {
                    if (opnode[me].p < 0 || opnode[me].p >= MAX_REGISTER)
                    {
                        state = 1;
                        return;
                    }
                    if (opnode[me].q < 0 || opnode[me].q >= MAX_REGISTER)
                    {
                        state = 1;
                        return;
                    }
                    int p = reg[opnode[me].p];
                    int q = reg[opnode[me].q];
                    if (p >= 1 && p <= MAX_N && q >= 1 && q <= MAX_N)
                    {
                        int tmp = a[p];
                        a[p] = a[q];
                        a[q] = tmp;
                    }
                }
                break;
            }
            case NEXT_LINE_IF:
            {
                if (reg[0])
                    line_assert = true;
                break;
            }
            }
            /*
            for (int i = 0; i < MAX_REGISTER; i++) {
                printf("reg[%d] : %5d, ", i, reg[i]);
            }
            printf("\n");
            for (int i = 1; i <= MAX_N; i++) {
                printf("a[%d] : %2d\n", i, a[i]);
            }
            */
            osj++;
            me = opnode[me].next;
        }
        if (state == 1)
        {
            printf("Assert! line : %d, col : %d, opid : %d\n", osi, osj, me);
        }
        osi++;
    }
    if (max_call_cnt < call_cnt)
        max_call_cnt = call_cnt;
    sum_call_cnt += call_cnt;
}
static bool check_valid()
{
    for (register int i = 1;; i++)
    {
        if (i + i > MAX_N)
            break;
        if (i + i + 1 <= MAX_N)
        {
            if (a[i + i] < a[i])
                return false;
            if (a[i + i + 1] < a[i])
                return false;
        }
        else
        {
            if (a[i + i] < a[i])
                return false;
            break;
        }
    }
    return true;
}
int main()
{
    int t = 100;
    int i, j, k;
    int score = 100;
    int mark = 0;

    scanf("%d", &mark);

    seed = time(NULL);

    make_operation(MAX_N);

    max_call_cnt = 0;
    sum_call_cnt = 0;
    while (t--)
    {
        ++tv;
        build_array();
        run();
        if (state == 1 || !check_valid())
        {
            score = 0;
            break;
        }
    }
    if (score == 100)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL at %d\n", tv);
    }
    if (mark == 0)
    {
        printf("opl : %d\n", opl);
        printf("max call cnt   : %d\n", max_call_cnt);
        printf("total call cnt : %lf ( %d / %d)\n", (double)sum_call_cnt / tv, sum_call_cnt, tv);
    }
}