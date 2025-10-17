//
//  main.c
//  S2011122190
//
//  Created by 이민석 on 2016. 12. 11..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    // insert code here…
    int *a;
    int *b;
    int n;
    int i, j = 0;
    int max = 0;
    
    scanf("%d",&n);
    
    a = (int *)malloc(sizeof(int)*n);
    b = (int *)malloc(sizeof(int)*n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(j = 0; j < n; j++)
        for(i = 0; i < n; i++)
            if(a[j] <= a[i])
                b[j]++;
    
    for(i = 0; i < n; i++)
        if(a[i] == b[i])
            max = a[i];
    
    printf("%d", max);
    
    return 0;
}