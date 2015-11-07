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
RF = randomForest(col61 ~ ., sonar.train, ntree=1000)
#sonar.tree = tree(formula = col61 ~ ., sonar.train, split="deviance", mindev = 0, minsize = 2)

#sonar.train의 예측 모델을 만들어본다.
sonar.predict.train = predict(RF, sonar.train, type = 'response')
#sonar.predict.train = predict(sonar.tree, newdata = sonar.train, type='class')
sonar.predict.train

#만들어진 sonar.train의 예측 모델을 테이블로 나타내본다.
table(sonar.train$col61, sonar.predict.train)

cm.sonar.train = confusionMatrix(sonar.predict.train, sonar.train$col61, positive = "1")
cm.sonar.train

#아래의 코드는 accuracy만 보여준다.
cm.sonar.train$overall[1]

sonar.predict.test = predict(RF, sonar.test, type = 'response')
sonar.predict.test
cm.sonar.test = confusionMatrix(sonar.predict.test, sonar.test$col61, positive = "1")
cm.sonar.test$overall[1]