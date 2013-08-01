#include"stage3.h"
/*
Given an absolute path for a file (Unix-style),
simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple 
slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and 
return "/home/foo".
*/

//URL解析时，Normalization File Name 也需要用到这个函数
string simplifyPath(string path) {
    stack<int> sk;
    string p;

    path.append("/"); // normalize the back slash in the end.
    sk.push(0);
    int s=0;
    for (int i=1; i<path.size(); i++) {
        if (path[i] == '/') {
            if (path[i-1] == '/'
                || path[i-1] == '.' && (i-2 < 0 || path[i-2] != '.')) {
                // skip double //  or /./
                s = i;
            }
            else if (path[i-1] == '.' && i-2 >= 0 && path[i-2] == '.') {
                s = i;
                if (sk.top() == 0) continue;
                // popping one part
                int e = sk.top(); sk.pop();
                p.erase(sk.top(), e-sk.top());
            }
            else {
                // add new part
                p.append(path, s, i-s);
                sk.push(p.size());
                s = i;
            }
        }
    }

    return p.size() == 0 ? "/" : p;
}
	
