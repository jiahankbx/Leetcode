class Solution {
string cs(string str){
    string s="";
    int temp=1;
    for(int j=0;j<str.size();j++){
        if(str[j]!=str[j+1]) s=s+'1'+str[j];
        else if(str[j]==str[j+1]){
            temp++;
            while(j+temp<str.size()&&str[j]==str[j+temp]){
                temp++;
            }
            string test=to_string(temp);
            s=s+test+str[j];
            j=j+temp-1;
            temp=1;
        }
    }
    return s;
}    
    
public:
    string countAndSay(int n) {
        int i;
        string st="1";
        if(n<=0) return "";
        else if(n==1) return "1";
        else{
            for(i=1;i<n;i++){st=cs(st);}
            return st;
        }
        return "";
    }
};

6ms beat 9%  编程基础太差，搞了半个下午
