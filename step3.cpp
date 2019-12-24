#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t start,end;
    srand( time( 0 ) );
    start = clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
    system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
    end = clock();
    if(tortoise==70)
    cout<<"tortoise win!!!  YAY!!!"<<endl;
    else
    cout<<"hare win!!!  YAY!!!"<<endl;
	cout<<"time elapsed: "<<(end-start)/1000<<"seconds"<<endl;
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=0 ;i<7;i++)
	cout<<"---------|";
	cout<<endl;
	cout<<setw(*bunnyPtr)<<"H"<<endl;
	cout<<setw(*snapperPtr)<<"T"<<endl;	
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int a;
	a=rand()%10;
	*turtlePtr+=(a>=0 &&a<=4)?3:(a>=5 && a<=6)?-6:1;
	*turtlePtr=(*turtlePtr<=0)?1:(*turtlePtr>=70)?70:*turtlePtr;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int b;
	b=rand()%10;
	*rabbitPtr+=(b>=0 &&b<=1)?*rabbitPtr:(b>=2 && b<=3)?9:(b==4)?-12:(b>=5 && b<=6)?-2:1;
	*rabbitPtr=(*rabbitPtr<=0)?1:(*rabbitPtr>=70)?70:*rabbitPtr;
}
