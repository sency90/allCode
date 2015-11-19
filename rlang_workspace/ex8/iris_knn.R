#assignment
#to do

#iris data를 target variable과 independent variable로 나눠서 저장한다.
#iris data의 target variable은 이미 factor type이므로 factor로 변환할 필요가 없다.
library(class)
iris.target = iris$Species
iris.indep = iris[,1:4]

#iris 데이터 들을 섞어준다.
#딱히 섞어줄 필요는 없지만 자료의 형태를 다르게 하기 위해서 적용하였다.
set.seed(7979)
trainSize = floor(nrow(iris)*0.75)
#iris data에서 75%는 train set으로 지정하고 나머지는 test set으로 지정한다.
iris.idn = sample(seq_len(nrow(iris)), trainSize)
iris.tVar.train = iris.target[iris.idn]
iris.tVar.test = iris.target[-iris.idn]
iris.iVar.train = iris.indep[iris.idn, ]
iris.iVar.test = iris.indep[-iris.idn, ]

#변수를 선언하고 초기화 해준다.
accu = c()
max.accu = 0
max.k = 0 

#각 k값마다 knn()을 적용해서 정확도를 구한다.
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