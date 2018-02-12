//https://www.urionlinejudge.com.br/judge/en/problems/view/1048
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    //freopen("input.txt","r",stdin);

    double salary, new_salary;
    scanf("%lf", &salary);

    if(salary > 2000){
        new_salary = salary + (salary*4)/100.0;
        printf("Novo salario: %.2lf\n", new_salary);
        printf("Reajuste ganho: %.2lf\n", new_salary-salary);
        printf("Em percentual: 4 %\n");
    }else 
        if(salary > 1200){
            new_salary = salary + (salary*7)/100.0;
            printf("Novo salario: %.2lf\n", new_salary);
            printf("Reajuste ganho: %.2lf\n", new_salary-salary);
            printf("Em percentual: 7 %\n");
    }else
        if(salary > 800){
            new_salary = salary + (salary*10)/100.0;
            printf("Novo salario: %.2lf\n", new_salary);
            printf("Reajuste ganho: %.2lf\n", new_salary-salary);
            printf("Em percentual: 10 %\n");
    }else
        if(salary > 400){
            new_salary = salary + (salary*12)/100.0;
            printf("Novo salario: %.2lf\n", new_salary);
            printf("Reajuste ganho: %.2lf\n", new_salary-salary);
            printf("Em percentual: 12 %\n");
    }else
        if(salary >= 0){
            new_salary = salary + (salary*15)/100.0;
            printf("Novo salario: %.2lf\n", new_salary);
            printf("Reajuste ganho: %.2lf\n", new_salary-salary);
            printf("Em percentual: 15 %\n");
        }

    return 0;
}
