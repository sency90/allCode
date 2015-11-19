library(randomForest)
library(caret)

sonar.test = read.csv('sonar_test.csv')
sonar.train = read.csv('sonar_train.csv')

#levels(sonar.test$col61) = c(1, -1)
#levels(sonar.train$col61) = c(1, -1)
sonar.test$col61 = as.factor(sonar.test$col61)
sonar.train$col61 = as.factor(sonar.train$col61)

#61번째 column이 sonar.train에서의 종속변수(목표변수; target variable)이다.
sonar.train$col61


#sonar.train data를 바탕으로 randomForest 모델을 만든다.
ntree_val = seq(1, 500, 1)
RF = c()
for(i in 1:length(ntree_val)) {
  RF[[i]] <- randomForest(col61 ~ ., sonar.train, ntree = ntree_val[i])
}

#ntree_val = as.factor(ntree_val)

sonar.predict.test = c()
cm.sonar.test = c()
for(i in 1:length(ntree_val)) {
  sonar.predict.test[i] = predict(RF[i], sonar.test, type = 'response')
}

for(i in 1:length(ntree_val)) {
  cm.sonar.test[[i]] = confusionMatrix(sonar.predict.test[[i]], sonar.test$col61, positive = "1")
}

accu = c()
for(i in 1:length(ntree_val)) {
accu[i] = cm.sonar.test[[i]]$overall[1]
}
#accu = as.factor(accu)

df = data.frame(accu, ntree_val)
plot(df)

#ggplot(df, aes(x=ntree_val, y=accu)) + geom_histogram() + stat_identity()
plot(ntree_val, accu, xlab="N-tree", ylab="accuracy", ylim=c(0.4, 1), xlim=c(1,500))
