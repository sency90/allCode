#assignment
#to do

#iris data의 독립변수에 z-score normalization을 적용한다.
#정규화를 적용한 iris data를 iris.indep.zsc에 저장한다.
library(class)
iris.target = iris$Species
iris.indep = iris[,1:4]
iris.indep.zsc = as.data.frame(lapply(iris.indep, scale))

#iris 데이터 들을 섞어준다.
#딱히 섞어줄 필요는 없지만 자료의 형태를 다르게 하기 위해서 적용하였다.
set.seed(7979);
trainSize = floor(nrow(iris)*0.75)
iris.idn = sample(seq_len(nrow(iris)), trainSize)
iris.tVar.train = iris.target[iris.idn]
iris.tVar.test = iris.target[-iris.idn]
iris.iVar.train = iris.indep.zsc[iris.idn, ]
iris.iVar.test = iris.indep.zsc[-iris.idn, ]

#변수를 선언하고 초기화 해준다.
accu = c()
max.accu = 0
max.k = 0 

#각 k값마다 knn을 적용해서 정확도를 구한다.
totalSize = length(iris.target)
testSize = totalSize - trainSize
for( i in c(1:testSize) ) {
  iris.fit.cv = knn(iris.iVar.train, iris.iVar.test, iris.tVar.train, k=i)
  accu[i] = (sum(iris.tVar.test==iris.fit.cv))/length(iris.tVar.test)
  if(max.accu < accu[i]) {
    max.k = i
    max.accu = accu[i]
  }
}

#정확도를 비교해보기 위해 plot으로 그려본다.
plot(1:testSize, accu, xlab="k-value", ylab="accuracy", ylim=c(0.8, 1), xlim=c(1, testSize) )
max.k
max.accu