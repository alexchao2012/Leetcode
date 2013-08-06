#include"stage3.h"
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:

        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
void connect(TreeLinkNode *root) {
    if(!root)return;

	TreeLinkNode *joint=root->next;
	while(joint){//����һ��ע�⣬���ӵ���һ��λ�ÿ��ܿգ�Ҫѭ���������Ǹ�λ��
		if(joint->left || joint->right){
			joint=joint->left==NULL?joint->right:joint->left;
			break;
		}
		joint=joint->next;
	}

	if(root->right)
		root->right->next=joint;
	if(root->left)
		root->left->next=(root->right==NULL)?joint:root->right;

	
	connect(root->right);//������˳��һ�£��ʹ��ˣ�������
    connect(root->left);
}
			

		
			