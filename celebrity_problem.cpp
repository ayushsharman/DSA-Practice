#include <iostream>
#include <stack>

using namespace std;

// Define the size of the 2D matrix
const int MAX_N = 100;

// 2D matrix to represent relationships
int matrix[MAX_N][MAX_N];

// Function to check if a knows b
bool knows(int a, int b)
{
    return matrix[a][b] == 1;
}

// Function to find the celebrity using a stack
int findCelebrity(int n)
{
    stack<int> candidates;

    // Initialize the stack with all people
    for (int i = 0; i < n; i++)
    {
        candidates.push(i);
    }

    while (candidates.size() > 1)
    {
        int a = candidates.top();
        candidates.pop();
        int b = candidates.top();
        candidates.pop();

        if (knows(a, b))
        {
            // If a knows b, 'a' cannot be the celebrity, so 'b' is a potential celebrity
            candidates.push(b);
        }
        else
        {
            // If a doesn't know b, 'b' cannot be the celebrity, so 'a' is a potential celebrity
            candidates.push(a);
        }
    }

    int potentialCelebrity = candidates.top();

    // Check if the potential celebrity is known by everyone and knows no one
    for (int i = 0; i < n; i++)
    {
        if (i != potentialCelebrity && (knows(potentialCelebrity, i) || !knows(i, potentialCelebrity)))
        {
            return -1; // No celebrity found
        }
    }

    return potentialCelebrity;
}

int main()
{
    int n; // Number of people at the party
    cout << "Enter the number of people: ";
    cin >> n;

    // Input the relationships into the matrix
    cout << "Enter the relationships (0 for unknown, 1 if i knows j):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int celebrity = findCelebrity(n);

    if (celebrity == -1)
    {
        cout << "No celebrity found." << endl;
    }
    else
    {
        cout << "The celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}
