library(tree)
library(caret)

sonar.test2 = read.csv('sonar_test.csv')
sonar.train2 = read.csv('sonar_train.csv')

# regression이 아닌 classification으로 만들기 위해서 target varialbe이 되는 곳에 factor를 만들어 준다.
sonar.test2$col61 = as.factor(sonar.test2$col61)
sonar.train2$col61 = as.factor(sonar.train2$col61)

#61번째 column이 sonar.train2에서의 종속변수(목표변수; target variable)이다.
sonar.train2$col61

#sonar.train data를 바탕으로 tree형태의 모델을 만든다.
sonar.tree2 = tree(formula = col61 ~ ., sonar.train2, split="deviance", mindev = 0, minsize = 2)

#만들어진 sonar.tree를 그린다.
plot(sonar.tree2)
text(sonar.tree2, pretty=NULL)

#sonar.train2의 예측 모델을 만들어본다.
sonar.predict.train2 = predict(sonar.tree2, newdata = sonar.train2, type='class')
sonar.predict.train2

cm.sonar.train2 = confusionMatrix(sonar.predict.train2, sonar.train2$col61, positive = "1")
cm.sonar.train2

#아래의 코드는 accuracy만 보여준다.
#prunning을 하지 않았으므로 당연히 accuracy는 1이다.
cm.sonar.train2$overall[1]

#여기서 FUN은 사용할 function을 의미한다.
#cv.tree에서 cv는 cross validation을 의미한다.
#여기서 cross-validation이란, training set을 K개로 쪼갠 다음,
#이 중에 하나만을 test set으로 만들고 나머지(K-1개)를 training set으로 해서 모델을 만들고,
#이 과정을 test set을 바꾸면서 K번 반복할 수 있으므로 그렇게 해서 K개의 모델을 만들면
#그 중에서 가장 중복되는 형태가 많은 모델을 택해서 모델의 정확도를 높이는 방법이다.
sonar.prune.result2 = cv.tree(sonar.tree2, FUN = prune.tree, K=5)
sonar.prune.result2

#sonar.prune.result2의 결과를 visualization 해본다.
plot(sonar.prune.result2)

#위에서 visualization한 그래프를 바탕으로 분류가 가장 잘 되었을 때의 노드 값을 구한다.
#참고로 여기서는 노드의 개수가 2일때 가장 좋은 분류 성능을 나타낸다. 그래서 best값을 2로 한다.
sonar.prunned.tree2 = prune.tree(sonar.tree2, best=2)
plot(sonar.prunned.tree2)
text(sonar.prunned.tree2)

sonar.predict.prunned.tree2 = predict(sonar.prunned.tree2, newdata = sonar.test2, type="class")
cm.sonar.test.prunned2 = confusionMatrix(sonar.predict.prunned.tree2, sonar.test2$col61, positive = "1")
cm.sonar.test.prunned2$overall[1]
