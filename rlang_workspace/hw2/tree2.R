# Example: tree model to classify German credit data.
# Programmed by S.Y. Ohn, Korea Aerospace University
# This example shows applying tree package to classify German credit data set. 
# First, we will build a full tree and then prune it.

# load german credit data set from evtree package.
# caret package also includes GermanCredit data
# save it into a new var to avoid name confict
MyGerman2 <- evtree::GermanCredit

# OR
# library(evtree)
# data(GermanCredit, package = 'evtree')

# show me the structure 
str(MyGerman2)

# VVVERY IMPORTANT!!!
# first, need to check target var type  
# if target var is in type num / factor, tree func will give you regression / classification model.
is.factor(MyGerman2$credit_risk)
# ok, it's factor, 
# if it were a num type, convert it into factor as follows
# MyGerman$credit_risk = as.factor(MyGerman$credit_risk)

# sample training and test set
mystudentidnum2 = 20007
set.seed(mystudentidnum2)

train.idx2 = sample(1000, 700)
train.set2 = MyGerman2[train.idx2, ]
test.set2 = MyGerman2[-train.idx2, ]
# need to check if each variable is in right type, i.e. num or Factor
str(train.set2)
str(test.set2)

# build a tree model to classify credit_risk var. 
library(tree)

# target var is credit_risk, all the others are indpendent var
# formula = credit_risk ~ .


# now, build a full tree
tree2 = tree(formula = credit_risk ~ ., train.set2, split = "deviance",  mindev = 0, minsize = 2)
# show me the tree
plot(tree2)
text(tree2, pretty = 1)
# print the tree structure
tree2

# test the tree
# training(re-substition) set ?
predict.train2 = predict(tree2, newdata = train.set2, type = 'class')
# results
predict.train2

# confusion matrix
table(train.set2$credit_risk, predict.train2)

# confusion matrix and accuracies - gogeubjin bangbeob
library(caret)
# let bad class be positive class
cm.train.set2 = confusionMatrix(predict.train2, train.set2$credit_risk, positive = 'bad')
cm.train.set2
# i want accuracy only...
cm.train.set2$overall[1] 
# accuracy = 1.00 since this is a full tree
# test set ?
predict.test2 = predict(tree2, newdata = test.set2, type = 'class')
predict.test2
cm.test.set2 = confusionMatrix(predict.test2, test.set2$credit_risk, positive = 'bad')
cm.test.set2
cm.test.set2$overall[1] 

difference2 = cm.train.set2$overall[1] - cm.test.set2$overall[1]

# some difference between training and testining - we doubt overfitting

# prune the tree
# try prunning with training set by 5-cross validation
# we can also use new data set for validaton
prune.result2 = cv.tree(tree2, FUN = prune.tree, K = 5, method = "misclass")
prune.result2
plot(prune.result2)
# look for the size for the minimum misclass(=misclassification) 
# deviance(it's in fact miscalss) is min when size = 8, 17, 27, 
# we choose simpler model with less terminal node
# best number is 8
# prune the tree so that it has 8 terminal nodes
tree.prunned2 = prune.tree(tree2, best = 8, method = "misclass")
plot(tree.prunned2)
text(tree.prunned2)

# test the prunned tree
predict.test.prunned2 = predict(tree.prunned2, newdata = test.set2, type = 'class')
cm.test.set.prunned2 = confusionMatrix(predict.test.prunned2, test.set2$credit_risk, positive = 'bad')
cm.test.set.prunned2$overall[1] 

# we now got the improved overall accuracy. 
