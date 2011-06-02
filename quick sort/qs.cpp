#include <iostream>
using namespace std;
////////////////////////////////////////////////////////
/////////////Function Prototypes/////////////////////
//////////////////////////////////////////////////////


void Quicksort( int *a, int first, int last );
int Pivot( int *a, int first, int last );
void  Swap( int &v1, int &v2 );
void  PrintArray( int *A, int nElements );
bool isSorted(int *A, int nElements);

int main()
{
    //Entry of Array size
    int nA ;
    cout<<"Give me the array size:";
    cin>>nA;
       
    int *testArray=new int [nA+1];
    
    //Initialize the array with random numbers
    srand ( time(NULL) );
    for(int i =0;i<nA;i++)
        testArray[i]=rand()%(100*nA);
        
    //Print the contents of the array
    cout << "Initial array contents:" << endl;
    PrintArray(testArray, nA );
    
    //Check if tha array is sorted
    cout<<"The array is "<<((isSorted(testArray,nA)==0)?"NOT sorted":"sorted")<<"!!!"<<endl;
    
    //Sort the array
    Quicksort( testArray, 0, nA-1 );

    //Print the contents of the array
    cout << "Final array contents:" << endl;
    PrintArray( testArray, nA );
    
    //Check if tha array is sorted
    cout<<"The array is "<<((isSorted(testArray,nA)==0)?"NOT sorted":"sorted")<<"!!!"<<endl;
    
    system("PAUSE");
}

////////////////////////////////////////////////////////
/////////////Function Declarations/////////////////////
//////////////////////////////////////////////////////


/*  Quicksort:  Sort an array a, using the quicksort
 *  algorithm.
 */

void Quicksort( int *a, int first, int last ) 
{
    int pivot;

    if( first < last ) {
        pivot = Pivot( a, first, last );
        Quicksort( a, first, pivot-1 );
        Quicksort( a, pivot+1, last );
    }
}


/*  Pivot:  Find and return the index of pivot element.
 */

int Pivot( int *a, int first, int last ) 
{
    int  p = first;
    int pivot = a[first];
    
    for( int i = first+1 ; i <= last ; i++ ) {
        if( a[i] <= pivot ) {
            p++;
            Swap( a[i], a[p] );
        }
    }

    Swap( a[p], a[first] );

    return p;
}


/*  Swap:  Swap two item (by reference).
 */

void  Swap( int &v1, int &v2 )
{
    int  tmpVal;

    tmpVal = v1;
    v1 = v2;
    v2 = tmpVal;
}


/*  PrintArray:  Print contents of an array.
 */

void  PrintArray( int *A, int nElements )
{
    cout << "[ ";

    for( int i = 0 ; i < nElements ; i++ )
    {
        cout << A[i] ;
        if( i < nElements-1 )
           cout << "\t";
    }

    cout << " ] " << endl;
}

/* isSorted: Check if the array is sorted or not.
*/
bool isSorted(int *A, int nElements)
{

     for(int i=1;i<nElements;i++)
             if(A[i-1]>A[i])
                return false;
     return true;
}
