//
//  main.c
//  prelab1
//
//  Created by Weiren Lai on 1/19/20.
//  Copyright © 2020 Weiren Lai. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *FP;

int main(int argc, char *argv[ ], char *env[ ])
{
  int a,b,c;
  printf("enter main\n");

  printf("&argc=%d argv=%d env=%d\n", &argc, argv, env);
  printf("&a=%8x &b=%8x &c=%8x\n", &a, &b, &c);

//(1). Write C code to print values of argc and argv[] entries//
// argc stands as argument count %, argv stands as argument value %s
//    for each i in the range from 1 to argc, print the ith element of argv onto stdout
    int i;
    printf("%d\n", argc);
    for (i=1;i<argc;i++)
    {
        print("%s", argv[i]);
    }


  a=1; b=2; c=3;
  A(a,b);
  printf("exit main\n");
}

int A(int x, int y, int argc, char *argv[ ], char *env[])
{
  int d,e,f;
  printf("enter A\n");
  // write C code to PRINT ADDRESS OF d, e, f
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&d=%8x &e=%8x &f=%8x\n", &d, &e, &f);
  d=4; e=5; f=6;
  B(d,e);
  printf("exit A\n");
    return 0;
}

int B(int x, int y, int argc, char *argv[ ], char *env[])
{
  int g,h,i;
  printf("enter B\n");
  // write C code to PRINT ADDRESS OF g,h,i
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&g=%8x &h=%8x &i=%8x\n", &g, &h, &i);
  g=7; h=8; i=9;
  C(g,h);
  printf("exit B\n");
    return 0;
}

int C(int x, int y, int argc, char *argv[ ], char *env[])
{
  int u, v, w, i, *p;

  printf("enter C\n");
  // write C cdoe to PRINT ADDRESS OF u,v,w,i,p;
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&u=%8x &v=%8x &w=%8x &i=%8x &p=%8x\n", &u, &v, &w, &i, p);

  u=10; v=11; w=12; i=13;

  FP = (int *)getebp();  // FP = stack frame pointer of the C() function
    printf("ebp=%x\n", ebp);

//(2). Write C code to print the stack frame link list.




 p = (int *)&p;
    printf("address: \n");
    for (i=0;i<128;i++)
    {
        printf("%x\t%x\n", p, *p);
        p++;
    }

//(3). Print the stack contents from p to the frame of main()
//     YOU MAY JUST PRINT 128 entries of the stack contents.
//

//(4). On a hard copy of the print out, identify the stack contents
//     as LOCAL VARIABLES, PARAMETERS, stack frame pointer of each function.
    return 0;
}

