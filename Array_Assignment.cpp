#include<iostream>
#include<array>
#include<vector>
using namespace std;
int ar_Sorted[] ={};

int f_SmallesIndexValue(int arg[],int length)
{
    int var_SmallestValue;
    for(int k=0; k<length  ; k++)
    {
        if(arg[k+1]!= arg[length] && arg[k+1]<arg[k])
        {
            if(var_SmallestValue>arg[k+1] && var_SmallestValue == 0)
             var_SmallestValue = arg[k+1];
            else
                var_SmallestValue = var_SmallestValue;
        }
        else
        {
            if(arg[k]!= arg[length] && var_SmallestValue !=0)
            {
                if (var_SmallestValue>arg[k])
                    var_SmallestValue = arg[k];
                else if(k == 0)
                    var_SmallestValue = arg[k];
                else
                    var_SmallestValue = var_SmallestValue;
            }
            else
                var_SmallestValue = arg[k];
        }
    }

  cout << '\n'<<"The smallest value is: " << var_SmallestValue <<endl;
  for(int l=0; l<length; ++l)
  {
      if(arg[l] == var_SmallestValue)
      {
        arg[l]=arg[0];
        arg[0] = var_SmallestValue;
      }
  }
 /*cout << "After finding small value: ";
    for(int m = 0; m<length; m++)
    {
        cout << arg[m] << '\0';
    }
cout << '\n';*/
return arg[length];
}

int f_LargestIndexValue(int arg[],int length)
{
    int var_LargestValue;
    arg[length] = 0;
    for(int k=0; k<length ; k++)
    {
        if(arg[k+1]> arg[k] && arg[k+1]>var_LargestValue)
        {
            var_LargestValue = arg[k+1];
        }
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
 cout << "After finding largest value: ";
    for(int m = 0; m<length; m++)
    {
        cout << arg[m] << '\0';
    }


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

    for(int var_loopcount = 1; var_loopcount<=var_N - 1; ++var_loopcount)
    {
            int var_loopcount1 = 1;
            if(var_loopcount>1)
             f_SmallesIndexValue(ar_Sorted, var_N-(var_loopcount-1)); //Calling to get the smallest value
            else
             f_SmallesIndexValue(ar_Input, var_N); //Calling to get the smallest value
            cout << "The new array after finding[" << var_loopcount << "]iteration of finding smallest index function : ";
            if(var_loopcount>1)
            {

               for(int m = 0; m<var_N-1; m++)
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
            if(var_loopcount<var_N-1)
            {
                //int var_count = 1;

                    if(var_loopcount>1)
                    {
                        //int var_CountSecArray=0;
                        for (int x=0; x<=var_N - (var_loopcount+1);++x)
                        {
                            ar_Sorted[x] = ar_Sorted[var_loopcount1];
                            var_loopcount1++;
                            //var_CountSecArray++; //array counter working here
                        }
                       // var_count = var_count +1;
                    }
                    else
                    {
                        for (int x=0; x<var_N - var_loopcount;++x)
                        {
                            ar_Sorted[x] = ar_Input[var_loopcount1];
                            var_loopcount1++;
                        }
                    }
                cout<<'\n';
                cout<<"The new array to sort: ";
                for(int y =0; y<=var_N - (var_loopcount+1); ++y)
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


