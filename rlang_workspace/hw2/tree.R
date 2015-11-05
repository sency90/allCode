# Example: tree model to classify German credit data.
# Programmed by S.Y. Ohn, Korea Aerospace University
# This example shows applying tree package to classify German credit data set. 
# First, we will build a full tree and then prune it.

# load german credit data set from evtree package.
# caret package also includes GermanCredit data
# save it into a new var to avoid name confict
MyGerman <- evtree::GermanCredit

# OR
# library(evtree)
# data(GermanCredit, package = 'evtree')

# show me the structure 
str(MyGerman)

# VVVERY IMPORTANT!!!
# first, need to check target var type  
# if target var is in type num / factor, tree func will give you regression / classification model.
is.factor(MyGerman$credit_risk)
# ok, it's factor, 
# if it were a num type, convert it into factor as follows
# MyGerman$credit_risk = as.factor(MyGerman$credit_risk)

# sample training and test set
mystudentidnum = 20007
set.seed(mystudentidnum)

train.idx = sample(1000, 700)
train.set = MyGerman[train.idx, ]
test.set = MyGerman[-train.idx, ]
# need to check if each variable is in right type, i.e. num or Factor
str(train.set)
str(test.set)

# build a tree model to classify credit_risk var. 
library(tree)

# target var is credit_risk, all the others are indpendent var
# formula = credit_risk ~ .


# now, build a full tree
tree = tree(formula = credit_risk ~ ., train.set, split = "deviance",  mindev = 0, minsize = 2)
# show me the tree
plot(tree)
text(tree, pretty = 1)
# print the tree structure
tree

# test the tree
# training(re-substition) set ?
predict.train = predict(tree, newdata = train.set, type = 'class')
# results
predict.train

# confusion matrix
table(train.set$credit_risk, predict.train)

# confusion matrix and accuracies - gogeubjin bangbeob
library(caret)
# let bad class be positive class
cm.train.set = confusionMatrix(train.set$credit_risk, predict.train, positive = 'bad')
cm.train.set
# i want accuracy only...
cm.train.set$overall[1] 
# accuracy = 1.00 since this is a full tree
# test set ?
predict.test = predict(tree, newdata = test.set, type = 'class')
predict.test
cm.test.set = confusionMatrix(test.set$credit_risk, predict.test, positive = 'bad')
cm.test.set
cm.test.set$overall[1] 

difference = cm.train.set$overall[1] - cm.test.set$overall[1]

# some difference between training and testining - we doubt overfitting

# prune the tree
# try prunning with training set by 5-cross validation
# we can also use new data set for validaton
prune.result = cv.tree(tree, FUN = prune.tree, K = 5, method = "misclass")
prune.result
plot(prune.result)
# look for the size for the minimum misclass(=misclassification) 
# deviance(it's in fact miscalss) is min when size = 8, 17, 27, 
# we choose simpler model with less terminal node
# best number is 8
# prune the tree so that it has 8 terminal nodes
tree.prunned = prune.tree(tree, best = 8, method = "misclass")
plot(tree.prunned)
text(tree.prunned)

# test the prunned tree
predict.test.prunned = predict(tree.prunned, newdata = test.set, type = 'class')
cm.test.set.prunned = confusionMatrix(test.set$credit_risk, predict.test.prunned, positive = 'bad')
cm.test.set.prunned$overall[1] 

# we now got the improved overall accuracy. 
