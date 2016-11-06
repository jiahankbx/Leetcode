class Solution {  
public:  
    vector<int> findSubstring(string s, vector<string>& words) {  
        vector<int>result;  
        if (s == "" || words.empty())//空  
        {  
            return result;  
        }  
        int sLen = s.size();//母串的总长度  
        int wordLen = words[0].size();//单个单词的长度  
        int wordCount = words.size();//单词的个数  
        int subLen = wordLen * wordCount;//每次需要从母串中拿来进行匹配的子串的长度  
        map<string, int> myWords;  
        int i;  
        int j;  
        int k;  
        for (i = 0; i < wordCount; i++)  
        {  
            myWords[words[i]] = myWords[words[i]] + 1;  
        }//用来记录words中所有word出现的次数用于后面的计算  
        i = 0;  
        int count;  
        while (i < sLen - subLen + 1)  
        {  
            map <string, int> tempMap(myWords);  
            count = 0;  
            int subCount = i + subLen;//临时保存母串中需要拿出来匹配的长度  
            //不能直接while(k<subLen + i)因为满足当i自增后会循环条件变化，内循环会多循环一次  
            k = i;  
            //while (k < subCount + 1)  
            while (k < subCount)  
            {  
                string temp = s.substr(k, wordLen);//取出一个与word长度一样的子串  
                if (tempMap.find(temp) == tempMap.end())//没有找到说明从i开头的子串中没有需要的单词，这个直接时候i++，并跳出循环   
                {  
                    i++;  
                    break;  
                }  
                else  
                {  
                    if (tempMap[temp] > 0)  
                    {  
                        tempMap[temp]--;//”用过“的单词从临时Map中剔除  
                        k += wordLen;//k跳到下一个单词  
                        count++;  
                    }  
                    //虽然找到，但多余了，也要剔除  
                    else  
                    {  
                        i++;  
                        break;  
                    }  
                }  
                //关于何时往结果集中添加。我目前的办法是，在子串中每找到一个  
                //单词count++，直到找到所有单词，即count==wordCount  
                //希望有更好的办法  
                if (count == wordCount)  
                {  
                    result.push_back(i);  
                    tempMap.clear();  
                    i++;  
                }  
            }  
        }  
        return result;  
    }  
};  

882ms beat 20%
