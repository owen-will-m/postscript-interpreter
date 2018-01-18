#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int isoperator(char * w){
    return 
        (strcmp(w, "+")==0)
        || (strcmp(w, "-")==0)
        || (strcmp(w, "/")==0)
        || (strcmp(w, "*")==0)
        || (strcmp(w,"sqrt")==0)
        || (strcmp(w,"square")==0)
        || (strcmp(w,"sin")==0)
        || (strcmp(w,"/")==0);
}


int isnumber(char * w){
    double d;
    return sscanf(w, "%lf", &d);
}


int operationleft(char ops[100][100],int i){
    int j;
    for(j=0;j<i;j++){

    }

}


void interpret2(char stack[100][100],int i){
    int j=100,k;double temp,temp2;



    while(1){
        if(isnumber(stack[0]))break;    

        printf("\nj= %d\n",j);
        for(k=0;k<i;k++){
            printf("  %s  ",stack[k]);
        }

        //if(j==0)break;
        if(j==100)j=0;

        if(strcmp(stack[j],")")==0){
            //operate-- either ( op num num ) || ( op num ) is behind you
            if(isoperator(stack[j-2])){// op num 
                sscanf(stack[j-1],"%lf",&temp);

                if(strcmp(stack[j-2],"sin")==0){
                    temp = sin(temp);   
                }

                if(strcmp(stack[j-2],"sqrt")==0){
                    temp = sqrt(temp);    
                }
                if(strcmp(stack[j-2],"square")==0){
                    temp = temp*temp;    
                }
                sprintf(stack[j-2],"%lf",temp);


                for(k=j-1;k<50;k++){
                    strcpy(stack[k],stack[k+2]);
                }
                // strcpy(stack[j-1],")");


                j -= 2;
            }else{//op num num )

                sscanf(stack[j-1],"%lf",&temp);
                sscanf(stack[j-2],"%lf",&temp2);

                if(strcmp(stack[j-3],"+")==0){
                    temp = temp + temp2;    
                }
                else
                    if(strcmp(stack[j-3],"-")==0){
                        temp = temp2 - temp;    
                    }
                    else 
                        if(strcmp(stack[j-3],"*")==0){
                            temp = (double)temp * (double)temp2;    
                        }
                        else 
                            if(strcmp(stack[j-3],"/")==0){
                                temp = (double)temp2 / (double)temp;    
                            }
                sprintf(stack[j-3],"%lf",temp);
                for(k=j-2;k<50;k++){
                    strcpy(stack[k],stack[k+3]);
                }
                //strcpy(stack[j-2],")");
                j -= 3;
            }

        }else{
            j++;
        }
    }
    printf("Result: %s\n",stack[0]);
}


///////////////////////////////////////////
int main(int argc, char **argv)
{
    FILE *fin, *tmp ;
    int q ;
    if (argc != 2) {
        printf("Usage : pgm inputfile\n") ;
        exit(1) ;
    }
    fin = fopen(argv[1],"r") ;
    if (fin == NULL) {
        printf("can't open file %s\n",argv[1]) ;
        exit(1) ;
    }
    tmp = fopen("temporary_junk8765", "w") ;
    if (tmp == NULL) {
        printf("can't open temp file\n") ;
        exit(1) ;
    }
    q = fgetc(fin) ;
    while (q != EOF) {
        if ((q == '(') || (q == ')')) {
            fputc(' ', tmp) ;
            fputc(q, tmp) ;
            fputc(' ', tmp) ;
        } else {
            fputc(q, tmp) ;
        }
        q = fgetc(fin) ;
    }
    fclose(fin) ;
    fclose(tmp) ;
///////////////////////////////////////////

    // ------------------------------------------




















    char operators[100][100];
    int opind =0;
    char stack[100][100];
    int n ;
    char w[100] ;
    double numbers[100];
    int numind = 0;
    int sti=0;
    tmp = fopen("temporary_junk8765", "r") ;
    fclose(tmp);

    while (1) {
        n = fscanf(tmp,"%s",w) ;
        if (n != 1) { break ; }
            strcpy(stack[sti],w);
            sti++;
    }
    puts("\n");
    int j;
    for(j=0;j<sti;j++){
        printf("%s   ",stack[j]);
    }
    puts("\n");
    system("rm temporary_junk8765") ;
}


