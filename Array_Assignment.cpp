/*
    PROBLEM STATEMENT:

                            Consider an algorithm that sorts an array of n elements by finding the smallest and largest elements
                            and then exchanges those elements with the elements in the first and last positions in the array.
                            Then the size of the array is reduced by two elements after excluding the two elements that are already
                            in the proper positions, and the process is repeated on the remaining part of the array until the entire array is sorted.
*/

#include<iostream>
#include<array>
#include<vector>
using namespace std;
int ar_Sorted[] ={};

int f_SmallesIndexValue(int arg[],int length)
{
    int var_SmallestValue;
    for(int k=0; k<length-1; k++)
    {

        if(arg[k+1]!= arg[length] && arg[k+1]<arg[k])
        {
            if(var_SmallestValue == 0 || var_SmallestValue>arg[k+1])
             var_SmallestValue = arg[k+1];
            else
                var_SmallestValue = var_SmallestValue;
        }
        else if(arg[k]!= arg[length] && arg[k+1]<arg[k])
        {
            if(var_SmallestValue>arg[k+1] || var_SmallestValue == 0)
                var_SmallestValue = arg[k+1];
            else
                var_SmallestValue =- var_SmallestValue;
        }

        else if(arg[k]!= arg[length] && var_SmallestValue !=0)
        {
            if ( k == 0 || var_SmallestValue>arg[k])
                var_SmallestValue = arg[k];
            else if(arg[k+1]<var_SmallestValue)
                var_SmallestValue = arg[k+1];
            else
                var_SmallestValue = var_SmallestValue;
        }
        else
             var_SmallestValue = arg[k];
    }

    cout <<"The smallest value is: " << var_SmallestValue <<endl;
    for(int l=0; l<=length; ++l)
    {
      if(arg[l] == var_SmallestValue)
      {
        arg[l]=arg[0];
        arg[0] = var_SmallestValue;
      }
    }
    return arg[length];
}

int f_LargestIndexValue(int arg[],int length)
{
    int var_LargestValue =0;
    arg[length] = 0;
    for(int k=0; k<length ; k++)
    {
        if(arg[k+1]> arg[k] && arg[k+1]>var_LargestValue)
        {
            if (arg[k+1]== arg[length])
                var_LargestValue = var_LargestValue;
            else
                var_LargestValue = arg[k+1];
        }
        else if(arg[k+1]<arg[k] && arg[k]>var_LargestValue)
            var_LargestValue = arg[k];
    }

  cout << "The largest value is: " << var_LargestValue <<endl;
  for(int l=0; l<length; ++l)
  {
      if(arg[l] == var_LargestValue)
      {
        arg[l]=arg[length-1];
        arg[length-1] = var_LargestValue;
      }
  }
 return arg[length];

}

int main()
{
    int var_N,var_ArrayIndex;
    cout << "Please Enter The Numbers of Element(n):";
    cin >> var_N;
    while(var_N <= 1)
    {
        cout << "The number of indexes should be more than 1.Please Enter again: ";
        cin >>var_N;
    }
    int ar_Input[var_N];
    int main_array[]{};
    //vector<int> ar_Input[var_N];

    for(int i = 0; i<var_N; ++i)
    {
        cout << "Fill Up the array indexes: " << "[" << i << "]";
        cin >> var_ArrayIndex;
        ar_Input[i] = var_ArrayIndex;
    }
    cout << "The ORIGINAL ARRAY is:" ;
    for(int j = 0 ; j<var_N; j++)
    {
        cout << ar_Input[j] << '\0';
    }
    //f_LargestIndexValue(ar_Input, var_N);

    for(int var_loopcount = 1, var_CutOff = 0; var_loopcount<=var_N - 1; ++var_loopcount, var_CutOff =var_CutOff+2)
    {
            int var_loopcount1 = 1;
            if(var_loopcount>1)
            {

                cout<< " *** The length of the array is " << var_N - var_CutOff << endl;
                //f_SmallesIndexValue(ar_Sorted, var_N-(var_loopcount-1)); //Calling to get the smallest value
                f_LargestIndexValue(ar_Sorted,var_loopcount);
            }

            else
            {
                cout<< " *** The length of the array is: " << var_N <<endl;
                f_SmallesIndexValue(ar_Input, var_N); //Calling to get the smallest value
                f_LargestIndexValue(ar_Input,var_N);
            }

            cout << "The new array after finding[" << var_loopcount << "]iteration of finding smallest and largest index function : ";
            if(var_loopcount>1)
            {

               for(int m = 0; m<var_N - var_loopcount; m++)
                {
                    cout << ar_Sorted[m] << '\0';
                }

            }
            else
            {
                for(int m = 0; m<var_N; m++)
                {
                    cout << ar_Input[m] << '\0';
                }
            }

            cout << '\n';

            //The new array to be sent to any outer function
            if(ar_Sorted)
            if(var_loopcount<var_N-1)
            {

                    if(var_loopcount>1)
                    {
                        for (int x=0; x<=var_N - (var_loopcount+1);++x)
                        {
                            ar_Sorted[x] = ar_Sorted[var_loopcount1];
                            var_loopcount1++;
                        }
                    }
                    else
                    {
                        for (int x=0; x<var_N - (var_loopcount+1);++x)
                        {
                            ar_Sorted[x] = ar_Input[var_loopcount1];
                            var_loopcount1++;
                        }
                    }
                cout<<'\n';
                cout<<"The new array to sort: ";
                for(int y =0; y<var_N - (var_loopcount+1); ++y)
                {
                    cout<<ar_Sorted[y] << '\0';
                }
            }
            else
            {

            }

            //main_array[] = {1};

    }
    return 0;
}


