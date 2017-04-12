#include <stdio.h>                                            
#include <string.h>                                           
#include <stdarg.h>                                           
                                                                
/*函数原型声明,至少需要一个确定的参数,注意括号内的省略号*/    
int demo(char *, ...);                                          
void main(void)                                              
{                                                           
   demo("DEMO", "This", "is", "a", "demo!", "");               
}                                                               
                                                                
/*ANSI标准形式的声明方式,括号内的省略号表示可选参数*/          
int demo(char *msg, ...)                                       
{
   va_list argp;                                              
   int argno = 0;                                               
   char *para;                                                  
   va_start(argp, msg);                                       
   while (1)                                                    
   {                                                        
        para = va_arg(argp, char*);                             
           if ( strcmp(para, "") == 0 )                        
               break;                                           
           printf("Parameter #%d is: %s\n", argno, para);       
           argno++;                                             
    }                                                               
va_end(argp); 
return 0;                                                       
}
