library(arules)
data("Adult")

#minsup을 0.01로 설정하고 min confidence를 0.6으로 설정하겠다는 얘기이다.
rules = apriori(Adult, parameter = list(support = 0.01, confidence = 0.6))

#위의 minsup과 minconf를 적용한 규칙들을 찾아내는 것을 apriori 함수가 수행해준다.
#즉 모든 itemset에서 frequent itemset을 가려낸 다음
#그 frequent itemset을 가지고 associative rule을 만드는 것이다. (프루닝까지 전부 해준 규칙들이 들어온다.)
#그리고 이렇게 찾은 규칙들이 rules라는 변수에 저장되고,
#이 변수들 중에서 오른쪽 부분이 "income=small"이고 lift값이 1.2보다 큰 애들만 다시 골라준다.
#여기서 lift가 말하는 것은 lhs->rhs의 두 요소들의 상관관계정도를 나타내는 값으로
#statistical dependence를 고려하는 척도인데,
#lift(interest)값이 1이면 independent, lift>1이면 positively correlated, lift<1이면 negatively correlated이다.
rulesIncomeSmall = subset(rules, subset = rhs %in% "income=small" & lift > 1.2)

#위에서 걸러낸 규칙들을 이번에는 confidence순서대로 정렬하고 그 중에서 1~3번째 까지만 화면에 나타내도록 한다.
inspect(sort(rulesIncomeSmall, by = "confidence")[1:3])

#바로 위에까지 코드를 입력해서 나온 연관규칙(Associative Rules) 결과를 확인해보면,
#백수면서 파트타임잡은 뛰는데, 애있는 남자면서 아직 결혼은 안한 사람들의 소득이 매우 낮음을 확인할 수 있다.
#그러면 이렇게 lhs에 공통적으로 들어가는 조건들을 넣어서 규칙들을 뽑아내 보자. 코드는 아래와 같다.
rulesincomeSmall = subset(rules, subset = lhs %ain% c("workclass=Private", "relationship=Own-child") & lift > 1.2)
inspect(sort(rulesIncomeSmall, by = "confidence")[1:3])

#그랬더니 rhs의 결과가 전부 소득이 작은부분이 가장 연관있는 항목이라고 나타났다.
#즉, 마지막 코드를 풀어서 설명하면, "비근로소득자(백수)인데 애가 있는 경우 수입이 적은경우가 많다"라는 것을 알 수 있다.

#그럼 이제 좀 더 흥미있는 연관규칙 5개를 더 찾아보자.
