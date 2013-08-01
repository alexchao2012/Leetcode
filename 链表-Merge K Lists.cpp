#include"stage3.h"

ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2){
	ListNode *head=NULL,**p;//使用**p，非常重要，通过每次修改next中的值实现整条链的重建
	p=&head;

	while(l1 && l2){
		if(l1->val<=l2->val){
			*p=l1;
			p=&(*p)->next;
			l1=l1->next;
		}
		else{
			*p=l2;
			p=&(*p)->next;
			l2=l2->next;
		}
	}
	if(l1)
		*p=l1;
	else
		*p=l2;
	return head;
}



ListNode *mergeKLists2(vector<ListNode *> &lists){//偷工减料版本
	if(lists.size()==0)
		return NULL;
	ListNode *res=lists[0];
	for(int i=1;i<lists.size();++i)
		res=mergeTwoLists1(res,lists[i]);
	return res;
}

class comp {
public:
	bool operator() (const ListNode* l, const ListNode* r) const {
	 return (l->val > r->val);
	}
};
ListNode *mergeKLists5(vector<ListNode *> &lists) {//STL 版本
    vector<ListNode*>::iterator it = lists.begin();
    while(it != lists.end()) {
        if(*it == NULL) lists.erase(it);
        else ++it;
    }
    if(lists.size() < 1) return NULL;

    ListNode *head = NULL, *cur = NULL;
    make_heap(lists.begin(), lists.end(), comp());

    while(lists.size() > 0) {
        if(head == NULL) head = cur = lists[0];
        else cur = cur->next = lists[0];

        pop_heap(lists.begin(), lists.end(), comp());
        int last = lists.size() - 1;
        if(lists[last]->next != NULL) {
            lists[last] = lists[last]->next;
            push_heap(lists.begin(), lists.end(), comp());
        }
        else lists.pop_back();
    }

    return head;
}



int left(int i){
	return (i<<1)+1;
}
int right(int i){
	return ((i+1)<<1);
}
void swap(ListNode *&l1,ListNode *&l2){
	ListNode *temp=l1;
	l1=l2;
	l2=temp;
}

void heapIfy(vector<ListNode *> &lists,int idx){
	if(lists.size()==0 || idx<0)return;

	int l=left(idx),r=right(idx);
	int leng=lists.size();
	int smallest=idx;

	if(l<leng && lists[l]->val < lists[idx]->val)
		smallest=l;
	if(r<leng && lists[r]->val < lists[smallest]->val)
		smallest=r;

	if(smallest != idx){
		swap(lists[idx],lists[smallest]);
		heapIfy(lists,smallest);
	}
}

void buildHeap(vector<ListNode *> &lists){
	int n=lists.size();
	for(int i=(n>>1)-1;i>=0;--i)
		heapIfy(lists,i);
}

ListNode *mergeKLists11(vector<ListNode *> &lists){//自建堆版本
	vector<ListNode *>::iterator iter=lists.begin();
	while(iter != lists.end()){
		if(*iter == NULL)
			lists.erase(iter);
		else
			++iter;
	}

	if(lists.size()==0) return NULL;

	ListNode *head=NULL,**cur=&head;
	buildHeap(lists);

	while(lists.size()!=0){
		*cur=lists[0];
		cur=&(*cur)->next;

		if(lists[0]->next != NULL)
			lists[0]=lists[0]->next;	
		else if(lists.size()!=0){
			lists[0]=lists[lists.size()-1];
			lists.pop_back();
		}

		heapIfy(lists,0);		
	}

	return head;
}
