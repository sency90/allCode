prime-factorization.cc
    소인수 분해
    input: 60
    output: 2 2 3 5


factor.cc
    약수
    input: 50
    output: 1 2 5 10 25 50


trie.cpp
    prefix tree
    input:
        3
        ABCD
        DEFGED
        DAG
        2
        DEFGA
        DAG
    output:
        DEFGED NOT FOUND!!
        DAG FOUND!!
    구성요소:
        void insert(const char*)
        TrieNode* find(const char*)
    주의사항:
        해당 trie 자료구조는 대문자만을 위한 트라이노드임. 소문자로 바꾸려면 수정이 필요함.


howToMakeX.cpp
    1부터 N까지 숫자를 이용하여 숫자 X를 만드는 조합을 출력합
    만들 수 없는 경우 -1을 리턴함.
    input: (1 ~ 100까지의 숫자를 더해서 1000을 만들 수 있는 조합을 찾아냄)
        100 1000
    output:
        45 91 92 93 94 95 96 97 98 99 100
    원리:
        Greedy Algorithm.
        X의 값이 폐구간 [1, N(N+1)/2]에 있을 경우, [1, N] 구간의 숫자를 더해서 반드시 X를 만들 수 있다.
        증명:
            X에서 N을 제거하면 X-N을 [1, N-1]의 숫자를 가지고 만들어야 한다.
            그런데 X는 [1, N(N+1)/2] 범위에 있었고 N을 빼게되면 X-N은 [1, N(N+1)/2 - N] 구간에 존재하게 된다.
            N(N+1)/2 - N = (N-1)N/2가 된다. 결국 이것은 [1, N-1]의 숫자를 가지고 반드시 만들 수 있으므로,
            X를 [1,N]의 숫자의 합으로 구성하기 위해서는 그냥 N부터 차례대로 줄여나가면서 X에서 빼주면
            O(N)시간안에 X를 구성하는 숫자들을 찾아낼 수 있다.

