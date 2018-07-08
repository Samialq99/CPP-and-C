//Full Working Program
#include <iostream>

using namespace std;

int main()
{
    int k,max; //delcare a variable 'k' that holds integer values
    int my_array [10];//an array that will hold 10 integers

        for (k=0; k<10; k++)
           {
        	cout<<"Enter an integer"<<endl;
		cin>>my_array[k];//user will input ten values
           }

    max=my_array[0];//assign max a value to avoid garbage
        
	for (k=0; k<10; k++)
            {
//if 'max' is less than my_array[k] then assign it that value
		if (max < my_array[k])
                    {
                        max=my_array[k];
                    }
            }
    
	cout<<"The highest value is "<<max<<endl;

return 0;
}
