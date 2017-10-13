#include <iostream>
#include <vector>

using namespace std;

 /* Definition for an interval.*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool merge_two_interval(Interval &it1, Interval &it2)
    {
        int start_max = max(it1.start, it2.start);
        int start_min = min(it1.start, it2.start);
        int end_max = max(it1.end, it2.end);
        int end_min = min(it1.end, it2.end);
        if(end_min - start_max >= 0)
        {
            it1.start = start_min;
            it1.end = end_max;
            return true;
        }
        return false;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        for(int i=0; i<intervals.size(); i++)
        {
            Interval &it1 = intervals[i];
            for(int j=0; j<intervals.size(); j++)
            {
                if(i == j)
                    continue;
                Interval &it2 = intervals[j];
                if(merge_two_interval(it1, it2))
                {
                    intervals.erase(intervals.begin() + j);
                    i--;
                    j = 0;
                    break;
                }
            }
        }
        return intervals;
    }
};

int main(int argc, char *argv[])
{
    Solution sln;
    vector<Interval> cases = {
    Interval(1,3),
    Interval(2,6),
    Interval(8,10),
    Interval(15,18)
    };

    cout << "Before merge" << endl;
    for(int i=0; i<cases.size(); i++)
    {
        cout << "[" << cases[i].start << " ," << cases[i].end << "]" << endl;
    }
    sln.merge(cases);
    cout << "After merge" << endl;
    for(int i=0; i<cases.size(); i++)
    {
        cout << "[" << cases[i].start << " ," << cases[i].end << "]" << endl;
    }
    return 0;
}
