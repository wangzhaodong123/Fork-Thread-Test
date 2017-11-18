#include <iostream>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <utility>
#include <functional>
#include <atomic>

using namespace std;

void delay( int m )
{
	for ( int i=0 ; i<m ; i++)
		for ( int j=0; j<1000 ; j++);	
}

void func1 ( int n )
{
	n++;
	cout<<" n = "<<n<<" in func1(). "<<endl;
}

void func2 ( int &n )
{
	delay(10);
	n++;
	cout<<" n = "<<n<<" in func2(). "<<endl<<endl;
}

int main( int argc, char** argv )
{
	int n=1;
	
	cout<<"########## join() ##############"<<endl;
	//通过值传递
	thread t1( func1, n );
	t1.join();
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;
	
	//通过引用传递
	thread t2( func2, ref(n) );
	t2.join();
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;

	cout<<"######### detach() #############"<<endl;
	//detch测试
	thread t3( func2, ref(n) );
	t3.detach();
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;
	delay(10);	
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;
	delay(10);
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;
	delay(10);	
	cout<<" n = "<<n<<" in main(). "<<endl<<endl;
	
	
	return 0;
}
