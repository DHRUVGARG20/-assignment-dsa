//		Q.1 Develop a Menu driven program to demonstrate the following operations of Arrays ——MENU——- 1. CREATE 2. DISPLAY 3. INSERT 4. DELETE 5. LINEAR SEARCH 6. EXIT 

#include <iostream>
using namespace std;

int main()
{
    int a[50], n = 0, choice, pos, value, i;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;

                cout << "Enter elements: ";
                for(i = 0; i < n; i++)
                    cin >> a[i];
                break;

            case 2:
                cout << "Array: ";
                for(i = 0; i < n; i++)
                    cout << a[i] << " ";
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;

                cout << "Enter value: ";
                cin >> value;

                for(i = n; i >= pos; i--)
                    a[i] = a[i - 1];

                a[pos - 1] = value;
                n++;
                break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;

                for(i = pos - 1; i < n - 1; i++)
                    a[i] = a[i + 1];

                n--;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == value)
                    {
                        cout << "Element found at position "
                             << i + 1;
                        break;
                    }
                }

                if(i == n)
                    cout << "Element not found";
                break;

            case 6:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 6);

    return 0;
}

//		Q.2 Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.

#include <iostream>
using namespace std;

int main()
{
    int a[50], n, i, j, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];

    // Remove duplicate elements
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                // Shift elements to the left
                for(k = j; k < n - 1; k++)
                    a[k] = a[k + 1];

                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

//		Q.3 Design the logic of a program to rotate a 1-D array by K positions. 
//			e.g., for A = {1,2,3,4,5} and K = 2, the left rotation is {3,4,5,1,2} and the right rotation is {4,5,1,2,3}. 

#include <iostream>
using namespace std;

int main()
{
    int a[50], n, k, i, temp, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter K: ";
    cin >> k;

    cout << "1. Left Rotation\n";
    cout << "2. Right Rotation\n";
    cout << "Enter choice: ";
    cin >> choice;

    k = k % n;

    if(choice == 1)
    {
        // Left Rotation
        for(int r = 0; r < k; r++)
        {
            temp = a[0];

            for(i = 0; i < n - 1; i++)
                a[i] = a[i + 1];

            a[n - 1] = temp;
        }
    }
    else if(choice == 2)
    {
        // Right Rotation
        for(int r = 0; r < k; r++)
        {
            temp = a[n - 1];

            for(i = n - 1; i > 0; i--)
                a[i] = a[i - 1];

            a[0] = temp;
        }
    }
    else
    {
        cout << "Invalid choice";
        return 0;
    }

    cout << "Array after rotation: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

//		Q. 4 Implement the logic to 
//		        a. Reverse the elements of an array 
//				b. Find the matrix multiplication 
//				c. Find the Transpose of a Matrix 

#include <iostream>
using namespace std;

int main() 
{
    //a) to reverse the elements of the array
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Reversed Array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // b) Matrix Multiplication
    int r1, c1, r2, c2;
    cout << "\nEnter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) 
	{
        cout << "Matrix multiplication not possible (c1 != r2).\n";
    } else 
	{
        int A[10][10], B[10][10], C[10][10] = {0};

        cout << "Enter elements of first matrix:\n";
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                cin >> A[i][j];

        cout << "Enter elements of second matrix:\n";
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                cin >> B[i][j];
        for (int i = 0; i < r1; i++) 
		{
            for (int j = 0; j < c2; j++) 
			{
                C[i][j] = 0;
                for (int k = 0; k < c1; k++) 
				{
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "Resultant Matrix after Multiplication:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }

    // c) Transpose of a Matrix
    int r, c;
    cout << "\nEnter rows and columns of matrix for transpose: ";
    cin >> r >> c;
    int M[10][10], T[10][10];
    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];
            
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = M[i][j];

    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < c; i++) 
	{
        for (int j = 0; j < r; j++) 
		{
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//		Q. 5 Write a program to find sum of every row and every column in a two-dimensional array. 

#include <iostream>
using namespace std;

int main()
{
    int a[10][10], r, c, sum;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter elements:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    }

    // Sum of each row
    for(int i = 0; i < r; i++)
    {
        sum = 0;

        for(int j = 0; j < c; j++)
            sum = sum + a[i][j];

        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }

    // Sum of each column
    for(int j = 0; j < c; j++)
    {
        sum = 0;

        for(int i = 0; i < r; i++)
            sum = sum + a[i][j];

        cout << "Sum of column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}



