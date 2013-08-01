#include"stage2.h"

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
*/

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> ret;
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {  
        vector<Interval> ret;  
        for(int i = 0; i < intervals.size(); ++i)  
        {  
            if(intervals[i].end < newInterval.start)//left  
            {  
                ret.push_back(intervals[i]);  
            }  
            else if(intervals[i].start > newInterval.end)//right  
            {  
                ret.push_back(newInterval);  
                while(i < intervals.size())  
                    ret.push_back(intervals[i++]);  
            }  
            else//overlap  
            {  
                newInterval.start = min(newInterval.start, intervals[i].start);  
                newInterval.end = max(newInterval.end, intervals[i].end);  
            }  
        }  
        if(0 == ret.size() || ret.back().end < newInterval.start)  
            ret.push_back(newInterval);  
        return ret;  
    } 
        
}