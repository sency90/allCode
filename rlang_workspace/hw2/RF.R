# Example: Random Forest model to classify German credit data.
# S.Y. Ohn, Korea Aerospace University
# This example shows applying randomForest package to classifying German credit data set. 

# load german credit data set from evtree package.
# caret package also includes GermanCredit data
# save it into a new var to avoid name confict
MyGerman <- evtree::GermanCredit

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
mystudentidnum = 27
set.seed(mystudentidnum)

train.idx = sample(1000, 700)
train.set = MyGerman[train.idx, ]
test.set = MyGerman[-train.idx, ]
# need to check if each variable is in right type, i.e. num or Factor
str(train.set)
str(test.set)

# build a RF model to classify credit_risk var. 
library(randomForest)

# target var is credit_risk, all the others are indpendent var
# formula = credit_risk ~ .
# RF with 1000 trees, you can try other option parameters with different values
RF = randomForest(credit_risk ~ ., train.set, ntree = 1000)
# show me the tree

# test the tree
# training set ?
predict.train = predict(RF, train.set, type = 'response')
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

# testing set ?
predict.test = predict(RF, newdata = test.set, type = 'response')
predict.test
cm.test.set = confusionMatrix(test.set$credit_risk, predict.test, positive = 'bad')
cm.test.set
cm.test.set$overall[1] 



# **********************************************************
# Advanced stuff: you dont need to go through the following. 
# Note on RF
# oob samples : remaining samples from bootstrapping sampling. 
# bootstrapped sample sets are used to build trees. 
# oob samples are used to calculate the generalization error(= oob error)
# how to calculate oob errors
# an oob sample is tested on the trees which didn't use the oob sample as the training sample. 
# let the trees vote to classify the sample.
# Why is it important?
# The study of error estimates for bagged classifiers in Breiman [1996b], 
# gives empirical evidence to show that the out-of-bag estimate is as accurate 
# as using a test set of the same size as the training set. 
# Therefore, using the out-of-bag error estimate removes the need for a set aside test set.
# https://www.quora.com/What-is-the-out-of-bag-error-in-Random-Forests

# oob error rate ?
predict.train = predict(RF, type = 'response') # no data set given, use oob samples
predict.train
table(train.set$credit_risk, predict.train)
cm.train.set = confusionMatrix(train.set$credit_risk, predict.train, positive = 'bad')
cm.train.set
cm.train.set$overall[1] 