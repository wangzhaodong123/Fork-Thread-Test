/* 
 *  fork_test.c 
 *  version 2 
 *  Created on: 2010-5-29 
 *      Author: wangth 
 */
#include <unistd.h>  
#include <stdio.h>
#include <iostream>

using namespace std;

int main( int argc, char** argv)  
{  
	int i=0;  
	cout<<"i 父子关系 父进程ID 本进程ID 子进程ID"<<endl;  
	
	//ppid指当前进程的父进程pid  
	//pid指当前进程的pid,  
	//fpid指fork返回给当前进程的值  
	for(i=0;i<2;i++)
	{  
		pid_t fpid=fork();  
		if(fpid==0)  
			cout<<i<<"   子进程"<<"   "<<getppid()<<"   "<<getpid()<<"   "<<fpid<<endl;  
		else  
			cout<<i<<"   父进程"<<"   "<<getppid()<<"   "<<getpid()<<"   "<<fpid<<endl;  
	}  
	return 0;  
}
