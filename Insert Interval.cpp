#include"stage2.h"

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
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