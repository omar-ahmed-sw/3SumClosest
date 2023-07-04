// 3SumClosest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
//sort the vector
	sort(nums.begin(), nums.end());
	bool AllPos = (*nums.begin() >= 0);
	bool AllNeg = (*(nums.end() - 1) < 0);
	uint32_t Index = 0U;



	//identify the index of our target if exists or the closest number to it
	auto it = find(nums.begin(), nums.end(), target);
	if (it != nums.end())
	{
		Index = it - nums.begin();
	}
	else
	{
		//if element doesn't exist then let's get the bounds for it
		auto LowerBound = lower_bound(nums.begin(), nums.end(), target);
		auto UpperBound = upper_bound(nums.begin(), nums.end(), target);
		
		//and pick the one that's closest to the target
		int newtarget = ((*UpperBound - target) <= (target - *LowerBound)) ? (*UpperBound) : (*LowerBound);
		Index = find(nums.begin(), nums.end(), newtarget) - nums.begin();

	}
	
	//add to it the smallest pos & smallest neg or smallest 2 +ve or 2 -ve
	 int closestvalue = nums[Index];
	 nums.erase(nums.begin() + Index);
	//case all positive or all negative
	if (AllPos || AllNeg)
	{
		closestvalue += nums[0];
		nums.erase(nums.begin());
		closestvalue += nums[0];

		return closestvalue;
	}
	//mix of both
	else
	{
		//identify our 1st positive index
		uint32_t i = 0U;
		auto firstpos = lower_bound(nums.begin(), nums.end(), 0);
		Index = firstpos - nums.begin() - 1;
		closestvalue += nums[Index];
		if (closestvalue < target)  //means what we added was -ve
		{
			closestvalue += nums[Index+1];
			return closestvalue;
		}
		else //means what we added was 0
		{
			//so here we need to decicde which to take is smaller -ve side number or +ve side
			if (nums[Index + 1] > abs(nums[Index - 1]))
			{
				closestvalue += nums[Index - 1];
			}
			else
			{
				closestvalue += nums[Index + 1];
			}
			//return closestvalue;
		}
	}
}

int main()
{
	vector<int> nums = { 1,2,5,3,6 };
	int closestvalue = threeSumClosest(nums, 4);

	while (true)
	{

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
