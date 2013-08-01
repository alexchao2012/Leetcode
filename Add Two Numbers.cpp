#include"head.h"

ListNode *addTwoNumbers(ListNode *l1,ListNode *l2)
{
	ListNode *res=NULL;//构造一个新的头结点，专门用来进行生成新的链表并返回
	ListNode **p=&res;//指针的指针，这个技巧需要掌握

	if(!l1 || !l2)
		return res;

	ListNode *cur1=l1;
	ListNode *cur2=l2;
	int carry=0;//carry很重要，携带需要的信息

	while(cur1 ||cur2)
	{
		int i1=0,i2=0;
		if(cur1)i1=cur1->val;
		if(cur2)i2=cur2->val;
		int temp=i1+i2+carry;
		carry=temp/10;

		*p=new ListNode(temp%10);
		p=&((*p)->next);

		if(cur1)cur1=cur1->next;
		if(cur2)cur2=cur2->next;
	}
	if(carry)
		*p=new ListNode(1);

	return res;
}
	
void bigAdditon(char str1[],char str2[],int n)
{
	int i,j;
	
	int *arr1=new int[n+10];
	int *arr2=new int[n+10];

	memset(arr1,0,sizeof(int)*(n+10));//这里的memset不要使用sizeof(arr1),有问题
	memset(arr2,0,sizeof(int)*(n+10));

	int nLen1=strlen(str1);
	for(i=nLen1-1,j=0;i>=0;i--)
		arr1[j++]=str1[i]-'0';

	int nLen2=strlen(str2);
	for(i=nLen2-1,j=0;i>=0;i--)
		arr2[j++]=str2[i]-'0';

	for(i=0;i<n;i++)
	{
		arr1[i]+=arr2[i];
		if(arr1[i]>=10)
		{
			arr1[i]-=10;
			arr1[i+1]++;
		}
	}

	bool flag=false;

	for(i=n;i>=0;i--)
	{
		if(flag)
			printf("%d",arr1[i]);
		else if(arr1[i])
		{
			printf("%d",arr1[i]);
			flag=true;
		}
	}

	if(!flag)
		printf("0");

	delete [] arr1;
	delete [] arr2;

	return;
}