#1번 문제
#데이터 iris에서 45개의 개체를 종류별로 층화추출
iris.indep = iris[,1:4]
i45 = rbind(iris.indep[36:50,], iris.indep[86:100,], iris.indep[136:150,])

#average link와 euclidean dist를 이용
hc = hclust(dist(i45, method="euclidean"), method="average")

#dendrogram(tree) 그리기
plot(hc)
#이제 클러스터 덴드로그램을 보고 적절한 군집의 개수(k) 및 중심점을 구한다.

#여기서 여러개의 k를 테스트해보고 어떻게 클러스터링 하는것이 좋을지 판단해본다.
#cutree(hc, k=5)
for(i in 2:44) {
  rect.hclust(hc, k=i)
}

#plot해보고 난 다음 내린 결론은 k=3일때 clustering의 결과가 가장 좋다고 판단했다.
plot(hc)
rect.hclust(hc, k=3)


#2번 문제
library(cluster)
iris.indep.scale = scale(iris.indep)

#각 결과에 대하여 중심으로 부터 제곱 거리 합을 구한다.
wss = 0
for( i in 1:45) {
  wss[i] = sum(kmeans(iris.indep.scale, centers = i)$withinss)
}

#위에서 구한 각 클러스터에 대한 제곱 거리합을 k에 대하여 plot 해본다.
plot(1:45, wss, type="b", xlab="Number of Clusters", ylab="Within group sum of squares")



#3번 문제
#군집분석용 테스트 데이터 (이전에 만들어 뒀던 iris.indep을 이용)
iris.indep

#위에서 선택된 k와 중심점을 초기값으로 하여 kmean clustering
#군집분석 테스트: k = 3
kc = kmeans(iris.indep, 3)


#scatter plot
plot(iris.indep[c("Sepal.Length", "Sepal.Width")], col=kc$cluster)

#중심점 표시
#kmeans로 구한 클러스터들의 중심을 kc$centers인데 이걸 pch=8에 해당하는 표시로 그려준다.
#cex=2라는 것은 보통 character크기보다 2배 확대해서 보여주라는 뜻
points(kc$centers[,c("Sepal.Length", "Sepal.Width")], col=1:3, pch=8, cex=2)

#중심과 개체 간의 평균 거리
kc$centers[,c("Sepal.Length", "Sepal.Width")]

#군집의 결과와 실제 class를 비교
table(iris$Species, kc$cluster)

#위에서 Sepal에 대해 clustering을 했던것 처럼 Petal에 대해서도 해본다.
plot(iris.indep[c("Petal.Length", "Petal.Width")], col=kc$cluster)
points(kc$centers[,c("Petal.Length", "Petal.Width")], col=1:3, pch=8, cex=2)
