#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

int findLastNonConflictingJob(vector<Job> const &jobs, int n)
{
    int low = 0;
    int high = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[n].start)
        {
            if (jobs[mid + 1].finish <= jobs[n].start)
            { // just ek previous needed!
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int findMaxProfit(vector<Job> jobs)
{

    sort(jobs.begin(),
         jobs.end(),
         [](Job &x, Job &y)
         {
             return x.finish < y.finish;
         });

    int n = jobs.size();

    int maxprofit[n];

    maxprofit[0] = jobs[0].profit;

    for (int i = 1; i < n; i++)
    {
        int index = findLastNonConflictingJob(jobs, i);
        int incl = jobs[i].profit;

        if (index != -1)
        {
            incl += maxprofit[index];
        }

        maxprofit[i] = max(incl, maxprofit[i - 1]);
    }
    return maxprofit[n - 1];
}

void main()
{
    vector<Job> jobs{
        {0, 6, 60},
        {1, 4, 30},
        {3, 5, 10},
        {5, 7, 30},
        {5, 9, 50},
        {7, 8, 10}};

    cout << findMaxProfit(jobs);
}