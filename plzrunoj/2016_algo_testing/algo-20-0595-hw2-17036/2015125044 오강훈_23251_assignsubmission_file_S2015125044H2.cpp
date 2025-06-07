#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
		    int n,num;
			    int count=0;
				    scanf("%d",&n);
					    vector<int> a;
						    
						    for(int i=0; i<n;i++){
									        scanf("%d",&num);
											        a.push_back(num);
													    }
							    
							    sort(a.begin(),a.end());
								    
								    for(int i=n-1;i>-1;i--){
											        for(int j=n-1;j>-1;j--){
															            if(a[i]<=a[j]){
																				count++;
																				if(count>=a[i]) {
																						printf("%d\n",a[i]);
																						return 0;
																				}

																		}
													}
													count=0;
									}
}
