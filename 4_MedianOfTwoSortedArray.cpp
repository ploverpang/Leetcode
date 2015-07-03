#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int count = 0;
		int medianCount = (nums1.size()+nums2.size())/2;
		
		int begin1 = 0;
		int end1 = nums1.size()-1;
		int begin2 = 0;
		int end2 = nums2.size()-1;

		while (1)
		{
			bool from1; 

			if (count < medianCount)
			{
				if ((end1 >= begin1) && (nums1[(end1+begin1)/2] < nums2[(end2+begin2)/2]))
				{
					from1 = true;
					count += ((end1-begin1)/2+1);
					begin1 += ((end1+begin1)/2+1);
				}
				else
				{
					from1 = false;
					count += ((end2-begin2)/2+1);
					begin2 += ((end2+begin2)/2+1);
				}
			}
			if (count > medianCount)
			{
				if ((end2 >= begin2) && (nums1[(end1+begin1)/2] < nums2[(end2+begin2)/2]))
				{
					from1 = false;
					count -= ((end2-begin2)/2+1);
					end2 -= ((end2+begin2)/2+1);
				}
				else
				{
					from1 = true;
					count -= ((end1-begin1)/2+1);
					end1 -= ((end1+begin1)/2+1);
				}
			}

			if (count == medianCount)
			{
				if (from1)
				{
					return nums1[count-begin2-1];
				}
				else
				{
					return nums2[count-begin1-1];
				}
			}
		} // end of while(1)
    } // end of method
};

/*
int main()
{
	int a1[] = {1,3,5};
	int a2[] = {2,4,6};
	vector<int> nums1(a1, a1+sizeof(a1)/sizeof(int));
	vector<int> nums2(a2, a2+sizeof(a2)/sizeof(int));

	Solution sln;
	cout << sln.findMedianSortedArrays(nums1, nums2) << endl;
	system("PAUSE");
	return 0;
}
*/