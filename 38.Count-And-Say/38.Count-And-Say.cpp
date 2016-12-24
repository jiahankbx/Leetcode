class Solution {
string cs(string str){
    string s="";
    int temp=1;
    for(int j=0;j<str.size();j++){ //j用来对前一个数的进行遍历
        if(str[j]!=str[j+1]) s=s+'1'+str[j];
        else if(str[j]==str[j+1]){
            temp++;
            while(j+temp<str.size()&&str[j]==str[j+temp]){ //temp用来记录有多少个连续的相同元素
                temp++;
            }
            string test=to_string(temp); //to_string把temp转换为字符串
            s=s+test+str[j];
            j=j+temp-1;
            temp=1;
        }
    }
    return s;
}   
//程序优化空间很大
    
public:
    string countAndSay(int n) {
        int i;
        string st="1";
        if(n<=0) return "";
        else if(n==1) return "1";
        else{ //i用来计算循环次数
            for(i=1;i<n;i++){st=cs(st);}
            return st;
        }
        return "";
    }
};

6ms beat 9%  编程基础太差，搞了半个下午
