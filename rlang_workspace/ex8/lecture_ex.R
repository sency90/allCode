x = matrix(c(1,1,2,2,2,3,4,5,5,4,6,7,7,6), nrow = 7)
x
d2 = dist(x, method = "euclidean")
d2

iris.indep = iris[,1:4]
i30 = rbind(iris.indep[41:50,], iris.indep[91:100,], iris.indep[141:150,])

dim(i30)
i30

hc = hclust(dist(i30, method="manhattan"), method="single")
plot(hc)

# k=5 -> cluster 개수를 5개로 주겠다는 뜻임.
cutree(hc, k=5)
plot(hc)
rect.hclust(hc, k=5)

# 위에서는 iris raw data를 clustering 했는데, 이번에는 z-score로 변환해서 clustering 시도
i30std = scale(i30)
i30std

hcstd = hclust(dist(i30std, method="manhattan"), method="single")
plot(hcstd)


# ex 3. diana
library(cluster)
hcdiana = diana(i30, metric="manhattan", stand=FALSE) # 방법은 hcluster 와 비슷.
plot(hcdiana) # can use cutree
cutree(as.hclust(hcdiana), k = 5)



# ex 4.
hcagnes <- agnes(i30, metric = "manhattan", stand = FALSE)
plot(hcagnes)



# ex 5. k-mean
km = kmeans(i30, 3)
km
km$centers

# 아래의 plot결과에서 다른 색깔들은 다른 꽃종류를 의미하는 것이 아니라 각각의 cluster(묶음)를 의미하는 것이다.
plot(i30, col = km$cluster)



# 
mydata = na.omit(iris[,-5])
mydata

mydata = scale(mydata)
mydata

wss = 0
for (i in 1:15) {
  wss[i] = sum(kmeans(mydata, centers = i)$withinss)
}

plot(1:15, wss, type="b", xlab="Number of Clusters", ylab="Within group sum of squares")



#군집분석 테스트용 데이터 생성
data(iris)
newiris = iris
newiris$Species = NULL

#군집분석 테스트: 3집단
kc = kmeans(newiris, 3)
kc

table(iris$Species, kc$cluster)

#visualization
plot(newiris[c("Sepal.Length", "Sepal.Width")], col=kc$cluster)
#visualization
points(kc$centers[,c("Sepal.Length", "Sepal.Width")], col=1:3, pch=8, cex=2)

#군집분석 테스트: 4집단
kc4 = kmeans(newiris, 4)
table(iris$Species, kc4$cluster)