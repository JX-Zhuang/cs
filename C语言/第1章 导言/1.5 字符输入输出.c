// 1.5.1 文件复制
#include <stdio.h>
#define IN 1
#define OUT 0
main1(){
    int c;
    while((c = getchar())!=EOF){
        putchar(c);
    }
} 
// 练习 1-6
practice16(){
    int c;
    while(c=getchar()!=EOF){
        printf("%d\n",c);
    }
    printf("%d - at EOF\n",c);
}
// 练习 1-7
practice17(){
    int c;
    printf("%d\n",EOF);
}
// 1.5.2 字符计数
main2(){
    // long nc;
    // nc = 0;
    // while(getchar()!=EOF)
    //     ++nc;
    // printf("%ld\n",nc);
    double nc;
    for(nc = 0;getchar()!=EOF;++nc) ;
    printf("%.0f\n",nc);
}
// 1.5.3 行计数
main3(){
    int c,nl;
    nl = 0;
    while((c=getchar())!=EOF){
        if(c=='\n')
            ++nl;
    }
    printf("%d\n",nl);
}
// 练习 1-8
practice18(){
    int c,nl,tl,bl;
    nl = 0,tl = 0,bl = 0;
    while((c=getchar())!=EOF){
        if(c=='\n') ++nl;
        if(c=='\t') ++tl;
        if(c==' ') ++bl;
    }
   printf("空格数：%d，制表符数：%d，换行符数：%d\n",bl,tl,nl);  
}
// 练习 1-9
practice19(){
    int c,lastC;
    while((c=getchar())!=EOF){
        if(c!=' ' || lastC!=' ')
            putchar(c);
        lastC = c;
    }
}
// 练习 1-10
practice110(){
    int c;
    while((c = getchar())!=EOF){
        if(c == '\t') printf("\\t");
        if(c=='\b') printf("\\b");
        if(c=='\\') printf("\\\\");
        if(c!='\t'&&c!='\b'&&c!='\\') putchar(c);
    }
}
// 1.5.4 单词计数
main4(){
    int c ,nl,nw,nc,state;
    state = OUT;
    nl = nw = nc = 0;
    while((c=getchar())!=EOF){
        ++nc;
        if(c=='\n') ++nl;
        if(c==' '||c=='\n'||c=='\t'){
            state = OUT;
        }else if(state == OUT){
            ++nw;
            state = IN;
        }
    }
    printf("%d %d %d\n",nl,nw,nc);
}
// 练习 1-12
practice112(){
    int c,state;
    state = OUT;
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'||c=='\t'){
            if(state==IN){
                putchar('\n');
                state = OUT;
            }
        }else if(state == OUT){
            state = IN;
            putchar(c);
        }else{
            putchar(c);
        }
    }
}
main(){
    // main1();
    // practice16();
    // practice17();
    // main2();
    // main3();
    // practice18();
    // practice19();
    // practice110();
    // main4();
   practice112();
}