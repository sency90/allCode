library(class)
train = read.csv("sonar_train.csv", header=FALSE)
test = read.csv("sonar_test.csv", header=FALSE)

library(class)
#target variable을 numeric type에서 factor로 바꾼다.
train.targetVar = as.factor(train[,61])
#target var를 제외한 나머지 변수들을 전부 independent variable로 지정한다.
train.indepVar = train[,1:60]

#test와 관련된 데이터도 위와 같은 방법으로 처리한다.
test.targetVar = as.factor(test[,61])
test.indepVar = test[,1:60]

accu = c()
for(i in c(1:100)) {
  #test.fit = knn(train.indepVar, test.indepVar, train.targetVar, k=i)
  train.fit.cv = knn.cv(train.indepVar, train.targetVar, k=i)
  accu[i] = sum(train.targetVar==train.fit.cv)/length(train.targetVar)
}

plot(1:100, accu, xlab="k-value", ylab="accuracy", ylim=c(0.4, 0.9), xlim=c(1, 100))



