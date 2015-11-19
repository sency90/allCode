#assignment
#to do

#iris data를 독립변수와 종속변수(목표변수)로 나눈다.
library(class)
iris.target = iris$Species
iris.indep = iris[,1:4]

#iris 데이터 들을 섞어준다.
#딱히 섞어줄 필요는 없지만 자료의 형태를 다르게 하기 위해서 적용하였다.
set.seed(100);
iris.idn = sample(seq_len(nrow(iris)), nrow(iris))
iris.targetVar = iris.target[iris.idn]
iris.indepVar = iris.indep[iris.idn, ]

#각 k값마다 knn.cv를 적용해서 정확도를 구한다.
accu = c()
max.accu = 0
max.k = 0
for(i in c(1:149)) {
  iris.fit.cv = knn.cv(iris.indepVar, iris.targetVar, k=i)
  accu[i] = (sum(iris.targetVar==iris.fit.cv))/length(iris.targetVar)
  if(max.accu < accu[i]) {
    max.k = i
    max.accu = accu[i]
  }
}

#정확도를 비교해보기 위해 plot으로 그려본다.
plot(1:149, accu, xlab="k-value", ylab="accuracy", ylim=c(0, 1), xlim=c(1, 149))
max.k
max.accu