#include<stdio.h>
#include<stdlib.h>

unsigned long long gcdd(unsigned long long n1,unsigned long long n2){
    while(n2!=0){
        unsigned long long temp=n2;
        n2=n1%n2;
        n1=temp;
    }
    return n1;
}

unsigned long long expp(unsigned long long base,unsigned long long expo,unsigned long long mod){
    long long res=1;
    base=base%mod;
    while(expo>0){
        if(expo%2==1)
            res=(res*base)%mod;
        expo=expo>>1;
        base=(base*base)%mod;
    }
    return res;
}

unsigned long long inverse(unsigned long long e,unsigned long long phi){
    long long t1=0,t2=1,a=phi,b=e,q;
    while(b!=0){
        q=a/b;
        long long temp=t2;
        t2=t1-q*t2;
        t1=temp;
       
        temp=b;
        b=a-q*b;
        a=temp;
    }
    if(b>1)return 0;
    if(t1<0)t1+=phi;
    return t1;
}

int main(){
    unsigned long long p,q,n,phi,e,d,data,cipher,plain;
    scanf("%llu %llu",&p,&q);
    n=p*q;
    phi=(p-1)*(q-1);
    e=0;
    for(e=5;e<=100;e++){
        if(gcdd(e,phi)==1)break;
    }
    d=inverse(e,phi);
    printf("%llu %llu\n",e,d);
    scanf("%llu",&data);
    cipher=expp(data,e,n);
    plain=expp(cipher,d,n);
    printf("%llu %llu",cipher,plain);
}

