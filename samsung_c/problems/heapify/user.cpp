#define MAX_N 100000
#define MAX_OP 2000000
#define MAX_REGISTER 4
enum OPTYPE {
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
extern void op(int type, int p, int q);
void make_operation(int n) {
    op(LINE_BEGEIN,0,0);
    //정렬을 하고나서... 그냥 정렬해서 저장하는거 말고는 큰 수가 없는거 같은데
    //쉬운 정렬 방식을 고려해야 할까?
    //일단 정렬말고 다른 방식으로 짤 수 있는지 생각해보..
    //정 없으면 정렬을 이거 make_operation() 통해서 구해보자.
}