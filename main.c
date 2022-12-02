//
//  main.c
//  baghche mo bill bezan
//
//  Created by Armin on 11/29/22.
//

#include <stdio.h>
#include <math.h>
double length(double x_a,double y_a,double x_b,double y_b){
    double l=sqrt( ( (x_a-x_b)*(x_a-x_b) ) + ( (y_a-y_b)*(y_a-y_b) ) );
    return l;
}
double maxf(double a , double b){
    double m= (a>b) ? a : b;
    return m;
}
double surf(double a_x,double a_y,double b_x,double b_y,double c_x,double c_y){
    double s,m,b,x_p,y_p,ertefa,ghaede;
    ghaede = length(b_x, b_y, c_x, c_y);
    if((b_x - c_x) == 0){
        ertefa= sqrt((a_x - b_x)*(a_x - b_x));
    }
    else if((b_y - c_y) == 0){
        ertefa = sqrt((a_y-b_y)*(a_y-b_y));
    }
    else{
        m = (b_y - c_y) / (b_x - c_x);
        b = b_y - m * b_x;
        x_p =(a_y + a_x / m - b) / (m + 1/m);
        y_p = m * x_p + b;
        ertefa = length(a_x, a_y, x_p, y_p);
    }
    s = ertefa * ghaede / 2;
    return s;
    
}
int main() {
    double x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
    double tot_surf,circumference;
    double ratio,max_ratio=0;
    int n;
    scanf("%d",&n);
    for (int i = 0 ; i < n; i++) {
        scanf("%lf %lf",&x_1,&y_1);
        scanf("%lf %lf",&x_2,&y_2);
        scanf("%lf %lf",&x_3,&y_3);
        scanf("%lf %lf",&x_4,&y_4);
        tot_surf = surf(x_1, y_1, x_2, y_2, x_3, y_3) + surf(x_1, y_1, x_4, y_4, x_3, y_3);
        circumference = length(x_1, y_1, x_2, y_2) + length(x_3, y_3, x_2, y_2) + length(x_3, y_3, x_4, y_4) + length(x_1, y_1, x_4, y_4);
        ratio = tot_surf / circumference;
        max_ratio = maxf(ratio, max_ratio);
        printf("%0.2lf\n",tot_surf);
        printf("%0.2lf\n",circumference);
    }
    printf("%0.2lf",max_ratio);
    
    return 0;
}
