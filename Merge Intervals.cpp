#include"stage2.h"
/*
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
*/
void swap(Interval &x,Interval &y){
    Interval temp;
	temp.start=x.start;
	temp.end=x.end;

	x.start=y.start;
	x.end=y.end;

	y.start=temp.start;
	y.end=temp.end;
}

int partition(vector<Interval> &intervals,int l,int r){
	if(l>r)return -1;

	srand(time(NULL));
	int x=l+rand()%(r-l+1);
	swap(intervals[r],intervals[x]);

	int pivot=intervals[r].start;
	int i=l-1,j=l;
	while(j<r){
		if(intervals[j].start<pivot){
			++i;
			swap(intervals[i],intervals[j]);
		}
		++j;
	}
	swap(intervals[i+1],intervals[r]);
	return i+1;
}

void quickSort(vector<Interval> &intervals,int l,int r){
	if(l>=r)return;
	//int n=intervals.size();
	if(l<r){
		int q=partition(intervals,l,r);
		quickSort(intervals,l,q-1);
		quickSort(intervals,q+1,r);
	}
}

//bool isLessThan(const Interval &i1,const Interval &i2){//操作符的比较函数，一定要写到类体的外面，否则报错
//	bool isLessThan(const Interval &i1,const Interval &i2){//这种在类外定义的一个比较函数，在大数据集上测试不能通过，需要采用static的方式来处理
//}
class SolutionInterval{
	static bool  isLessThan(const Interval &i1,const Interval &i2){
		 return i1.start<i2.start;
	}
public:
    static bool compareInterval(const Interval& a, const Interval& b)  
    {  
        return a.start < b.start;  
    }  
    vector<Interval> merge(vector<Interval> &intervals) {  
        vector<Interval> ret;  
        if(intervals.size() > 0)  
        {  
            sort(intervals.begin(), intervals.end(), SolutionInterval::compareInterval);  
            Interval temp = intervals.at(0);  
            for(int i = 1; i < intervals.size(); ++i)  
            {  
                if(intervals.at(i).end < temp.start || intervals.at(i).start > temp.end)  
                {  
                    ret.push_back(temp);  
                    temp = intervals.at(i);  
                }  
                else  
                {  
                    temp.start = min(temp.start, intervals.at(i).start);  
                    temp.end = max(temp.end, intervals.at(i).end);  
                }  
            }  
            ret.push_back(temp);  
        }  
        return ret;  
    }
};

static bool isLess(const Interval &x,const Interval &y){
	return x.start<y.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> ret;
	if(intervals.size()==0)return ret;
	sort(intervals.begin(),intervals.end(),isLess);
	ret.push_back(intervals[0]);
	int tail=intervals[0].end;
	for(int i=1;i<intervals.size();++i){
		if(intervals[i].start > tail){
			ret.push_back(intervals[i]);
			tail=intervals[i].end;
		}
		else
			if(intervals[i].end>tail){
				ret.back().end=intervals[i].end;
				tail=intervals[i].end;
			}
	}
	return ret;
}
