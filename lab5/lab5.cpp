#include <iostream>
#include <vector>
using namespace std;

unsigned int get_uint(){
    string number;
    int i, stop = 0;
    unsigned int output = 0;
    while (true){
        stop = 0;
        cin >> number;
        cin.sync();
        for(i=0;i< number.length();i++){
            // if ((number[0] == '-') and (i == 0) and (number.length() > 1))
            //     continue;
            if(!isdigit(number[i])){
                stop = 1;
                break;
            }
        }

        if (stop == 0){
            return stoi(number);
            // if(stoi(number) >= 0){
            //     return stoi(number);
            // }
            // if (stoi(number) < 0)
            //     cout << "Incorrect input. Input must be >= 0. ";
        }
        if (stop == 1)
            cout << "Incorrect input. Input should contain only digits. ";
    }
}

void Shell(unsigned int num, unsigned int *b){
    int n = (int)num/2 + 1;
    
    unsigned int c;
    int j,k,count=0;
    for(n = n;n > 0;n--){
        for (j=0;j<num-n;j++){
            if (b[j] > b[j+n]){
                c = b[j+n];
                b[j+n] = b[j];
                b[j] = c;
                count++;
            }
        }
    }
    cout << endl;
    cout << "Sorted array : "; 
    for (j=0;j<num;j++)
        cout << b[j] << " ";
    cout << endl;
    cout << "Number of changes : " << count << endl;
}

void Buble(unsigned int num, unsigned int *a){
    int i,j,c,k,count = 0;
    cout << endl;
    for(i=0;i<num;i++){
        for(j=0;j<num-1;j++){
            if (a[j+1] < a[j]){
                c = a[j+1];
                a[j+1] = a[j];
                a[j] = c;
                count++;
            }
        }
    }
    cout << endl;
    cout << "Sorted array : "; 
    for (i=0;i<num;i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Number of changes : " << count << endl;

}

int main() {
    int num;
    cout << "Enter number of elements";
    num = get_uint();
    int i;
    unsigned int *a = new unsigned int[num];
    for(i=0;i<num;i++){
		cout<<"Input element "<<i+1<<": ";
		a[i] = get_uint();
	}

    cout << endl;
    cout << "Your array is : ";
    for(i=0;i<num;i++){
        cout << a[i] << " ";
    }
    cout << endl;

    unsigned int *b = new unsigned int[num];
    for(i=0;i<num;i++)
        b[i] = a[i];
    Shell(num, b);
    for(i=0;i<num;i++)
        b[i] = a[i];
    Buble(num, b);

    return 0;
}